#include <bits/stdc++.h>
using namespace std;

void printSolution(vector<vector<char> > A){
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			cout<<setw(5)<<A[i][j]<<" ";
		}
		cout<<endl;
	}
}

bool findUnAssigned(vector<vector<char> > A,int &i,int &j){
//	bool flag=false;
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			if(A[i][j]=='.'){
				return true;
			}
		}
	}
	return false;
}

bool ifRowSafe(vector<vector<char> > A,int r,int c,char d){
	for(int i=0;i<9;i++){
		if(A[r][i]==d){
			return false;
		}
	}
	return true;
}

bool ifColSafe(vector<vector<char> >A,int r,int c,char d){
	for(int i=0;i<9;i++){
		if(A[i][c]==d){
			return false;
		}
	}
	return true;
}

bool ifGridSafe(vector<vector<char> > A,int r,int c,char d){
	for(int i=r;i<r+3;i++){
		for(int j=c;j<c+3;j++){
			if(A[i][j]==d){
				return false;
			}
		}
	}
	return true;
}



int solve(vector<vector<char> > &A){
	int r,c;
	if(findUnAssigned(A,r,c)==false){
		return 1;
	}
//	cout<<"Unassigned Location found. row="<<r<<" col="<<c<<endl;
//	printSolution(A);
	for(char i='1';i<='9';i++){
		if(ifRowSafe(A,r,c,i) && ifColSafe(A,r,c,i) && ifGridSafe(A,r-r%3,c-c%3,i) &&A[r][c]=='.'){
			A[r][c]=i;
			if(solve(A)==1){
				return 1;
			}
			A[r][c]='.';
		}
	}
	return 0;
}



int main() {
	vector<vector<char> > A
	{
		{'5','3','.','.','7','.','.','.','.'},
		{'6','.','.','1','9','5','.','.','.'},
		{'.','9','8','.','.','.','.','6','.'},
		{'8','.','.','.','6','.','.','.','3'},
		{'4','.','.','8','.','3','.','.','1'},
		{'7','.','.','.','2','.','.','.','6'},
		{'.','6','.','.','.','.','2','8','.'},
		{'.','.','.','4','1','9','.','.','5'},
		{'.','.','.','.','8','.','.','7','9'}
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
	for(char c='1';c<='9';c++){
		cout<<c<<endl;
	}
	return 0;
}
