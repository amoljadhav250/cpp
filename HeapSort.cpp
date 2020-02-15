#include <bits/stdc++.h>
using namespace std;

int left(int i){
	return 2*i+1;
}

int right(int i){
	return 2*i+2;
}

void swap(int *x, int *y){
	int t=*x;
	*x=*y;
	*y=t;
}

void heapify(int a[], int n, int i){
	int largest=i;
	if(left(i)<n && a[i]<a[left(i)]){
		largest=left(i);
	}
	
	if(right(i)<n && a[largest]<a[right(i)]){
		largest=right(i);
	}
	
	if(i!=largest){
		swap(&a[i],&a[largest]);
		heapify(a,n,largest);
	}
	
}
void printArray(int a[],int n){
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

void heapSort(int a[],int n){
	for(int i=n-1;i>=0;i--){
		swap(a[0],a[i]);
		heapify(a,i,0);
	}
}

int main() {
	int a[10]={1,2,3,4,5,6,7,8,9,10};
	printArray(a,10);
	for(int i=4;i>=0;i--){
		heapify(a,10,i);
	}
	printArray(a,10);
	
	heapSort(a,10);
	printArray(a,10);
	return 0;
}
