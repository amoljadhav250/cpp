#include <bits/stdc++.h>
using namespace std;

void printA(vector<int> A){
	for(int i:A){
		cout<<i<<" ";
	}
	cout<<endl;
}

void solveUtil(vector<int> A,vector<vector<int> > &B, int l, int r ){
	if(l==r){
		B.push_back(A);//cout<<"6\n";
		//printA(A);
		//return;
	}else{
		for(int i=l;i<=r;i++){
			int t=A[l];
			A[l]=A[i];
			A[i]=t;//cout<<"12\n";
			solveUtil(A,B,l+1,r);
			t=A[l];
			A[l]=A[i];
			A[i]=t;
		}
	}
}

vector<vector<int> > solve(vector<int> A){
	vector<vector<int> > B;
	int r=A.size()-1;//cout<<"23\n";
	solveUtil(A,B,0,r);
	return B;
}

int main() {//cout<<"28\n";
	vector<int> A{1,2,3};
	vector<vector<int> > B=solve(A);
	//cout<<"31\n";
	for(int i=0;i<B.size();i++){
		for(int j=0;j<B[i].size();j++){
			cout<<setw(4)<<B[i][j];
		}
		cout<<endl;
	}
	return 0;
}
