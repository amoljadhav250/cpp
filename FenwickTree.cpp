#include <iostream>
using namespace std;

int A[10],B[15];

void update(int i, int d, int n){
	int idx=i+1;
	while(idx<=n){
		B[idx]+=d;
		idx+=idx&(-idx);
	}
}

int getSum(int i,int n){
	int idx=i+1;
	int sum=0;
	while(idx>0){
		sum+=B[idx];
		idx-=idx&(-idx);
	}
	return sum;
}

int main() {
	for(int i=0;i<10;i++){
		A[i]=i+1;
	}
	for(int i=0;i<15;i++){
		B[i]=0;
	}
	for(int i=0;i<10;i++){
		update(i,A[i],10);
	}
	for(int i=0;i<10;i++){
		cout<<i<<"="<<getSum(i,10)<<endl;
	}
	return 0;
}
