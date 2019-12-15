#include <iostream>
using namespace std;


void printArray(int A[],int size);

int partition(int A[],int l,int h){
	int pvt=A[h];
	int j=l-1;
	for(int i=l;i<h;i++){
		if(A[i]<pvt){
			j++;
			int t=A[i];
			A[i]=A[j];
			A[j]=t;
		}
	}
	j++;
	int t=A[h];
	A[h]=A[j];
	A[j]=t;
//	cout<<"pvt="<<pvt<<endl;
	//printArray(A,h-l+1);
//	for(int i=l;i<=h;i++){
//		cout<<A[i]<<" ";
//	}
//	cout<<endl;
	return j;
}

void quickSort(int A[],int l,int h){
	if(l<h){
		int p=partition(A,l,h);
		quickSort(A,l,p-1);
		quickSort(A,p+1,h);
	}else{
		return;
	}
}

void printArray(int A[],int size);

int main() {
	int A[10]={5,3,6,5,1,9,8,7,2,0};
	printArray(A,10);
	quickSort(A,0,9);
	printArray(A,10);
	return 0;
}

void printArray(int A[],int size){
	for(int i=0;i<size;i++){
		cout<<A[i]<<" ";
	}
	cout<<endl;
}
