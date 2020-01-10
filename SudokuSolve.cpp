#include <bits/stdc++.h>
using namespace std;

void printSolution(int A[9][9]){
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			cout<<setw(5)<<A[i][j]<<" ";
		}
		cout<<endl;
	}
}

bool findUnAssigned(int A[9][9],int &i,int &j){
//	bool flag=false;
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			if(A[i][j]==0){
				return true;
			}
		}
	}
	return false;
}

bool ifRowSafe(int A[9][9],int r,int c,int d){
	for(int i=0;i<9;i++){
		if(A[r][i]==d){
			return false;
		}
	}
	return true;
}

bool ifColSafe(int A[9][9],int r,int c,int d){
	for(int i=0;i<9;i++){
		if(A[i][c]==d){
			return false;
		}
	}
	return true;
}

bool ifGridSafe(int A[9][9],int r,int c,int d){
	for(int i=r;i<r+3;i++){
		for(int j=c;j<c+3;j++){
			if(A[i][j]==d){
				return false;
			}
		}
	}
	return true;
}



int solve(int A[9][9]){
	int r,c;
	if(findUnAssigned(A,r,c)==false){
		return 1;
	}
//	cout<<"Unassigned Location found. row="<<r<<" col="<<c<<endl;
	//printSolution(A);
	for(int i=1;i<=9;i++){
		if(ifRowSafe(A,r,c,i) && ifColSafe(A,r,c,i) && ifGridSafe(A,r-r%3,c-c%3,i) ){
			A[r][c]=i;
			if(solve(A)==1){
				return 1;
			}
			A[r][c]=0;
		}
	}
	return 0;
}



int main() {
	int A[9][9]={
		{5,3,0,0,7,0,0,0,0},
		{6,0,0,1,9,5,0,0,0},
		{0,9,8,0,0,0,0,6,0},
		{8,0,0,0,6,0,0,0,3},
		{4,0,0,8,0,3,0,0,1},
		{7,0,0,0,2,0,0,0,6},
		{0,6,0,0,0,0,2,8,0},
		{0,0,0,4,1,9,0,0,5},
		{0,0,0,0,8,0,0,7,9}
	};
	
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			cout<<setw(5)<<A[i][j];
		}
		cout<<endl;
	}
	cout<<"Printing Solution:\n";
	if(solve(A)==1){
		printSolution(A);
	}
	
	cout<<"Printing Array:\n";
	printSolution(A);
	return 0;
}
