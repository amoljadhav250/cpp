#include <iostream>
using namespace std;

void merge(int a[],int l,int m,int h){
	int n1=m-l+1;
	int n2=h-m;
	int L[n1];
	int R[n2];
	for(int i=l;i<=m;i++){
		L[i-l]=a[i];
	}
	for(int i=m+1;i<=h;i++){
		R[i-m-1]=a[i];
	}
	int i=0,j=0,k=l;
	while(i<n1 && j<n2){
		if(L[i]<R[j]){
			a[k]=L[i];
			i++;
		}else{
			a[k]=R[j];
			j++;
		}
		k++;
	}
	while(i<n1){
		a[k]=L[i];
		i++;
		k++;
	}
	while(j<n2){
		a[k]=R[j];
		j++;
		k++;
	}
}

void mergeSort(int a[],int l, int r){
	if(l<r){
		int mid=(l+r)/2;
		mergeSort(a,l,mid);
		mergeSort(a,mid+1,r);
		merge(a,l,mid,r);
	}
}

void printArray(int a[],int size){
	for(int i=0;i<size;i++){
		cout<<a[i]<<"\n";
	}
	cout<<endl;
}

int main() {
	
	//printArray(a,10);
	int t;
	cin>>t;
	int *a=new int[t];
	for(int i=0;i<t;i++){
		cin>>a[i];
	}
	//printArray(a,t);
	mergeSort(a,0,t-1);
	printArray(a,t);
	return 0;
}
