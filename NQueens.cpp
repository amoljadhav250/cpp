#include <bits/stdc++.h>
using namespace std;

void printSol(vector<string > A){
	for(int i=0;i<A.size();i++){
		for(int j=0;j<A[i].size();j++){
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}
	for(int i=0;i<A.size();i++){
		cout<<"--";
	}
	cout<<endl;
}

bool isRowSafe(vector<string > A, int r, int c){
	for(int i=0;i<c;i++){
		if(A[r][i]=='Q'){
			return false;
		}
	}
	return true;
}
bool isUpDiagonalSafe(vector<string > A, int r, int c){
	r--;
	c--;
	while(r>=0 && c>=0){
		if(A[r][c]=='Q'){
			return false;
		}
		r--;
		c--;
	}
	return true;
}
bool isDownDiagonalSafe(vector<string > A, int r, int c,int n){
	r++;
	c--;
	while(r<n && c>=0){
		if(A[r][c]=='Q'){
			return false;
		}
		r++;
		c--;
	}
	return true;
}
int solve(vector<string >  &A,int position,int n,vector<vector<string> > &B){
	if(n==1){
		return 0;
	}
	if(position>=n){
		B.push_back(A);
		return 0;
	}
	for(int i=0;i<n;i++){
		if(isRowSafe(A,i,position) && isUpDiagonalSafe(A,i,position) && isDownDiagonalSafe(A,i,position,n)){
			A[i][position]='Q';
			//printSol(A);
			if(solve(A,position+1,n,B)==1){
				return 1;
			}
			A[i][position]='.';
		}
	}
	return 0;
}

vector<vector<string> > solveNQueens(int A){
	int n=A;
	vector<string > C(n);
	vector<vector<string> > B;
	if(n==1){
		vector<string> S;
		S.push_back("Q");
		B.push_back(S);
		return B;
	}
	if( n==2 || n==3){
		return B;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			C[i].push_back('.');
		}
	}
	solve(C,0,n,B);
	return B;
}

int main() {
	int n=1;
	vector<string > A(n);
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			A[i].push_back('.');
		}
	}
	vector<vector<string> > B=solveNQueens(n);

	for(int i=0;i<B.size();i++){
		for(int j=0;j<B[i].size();j++){
			cout<<B[i][j]<<endl;
		}
		cout<<"-------------------\n";
	}
	return 0;
}
