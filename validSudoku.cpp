#include <bits/stdc++.h>
using namespace std;


vector<vector<int> > generateSudoku(vector<string> A){
	vector<vector<int> > B(9);
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			B[i].push_back(0);
		}
	}
	for(int i=0;i<A.size();i++){
		for(int j=0;j<A[i].length();j++){
			if(A[i][j]>='0' && A[i][j]<='9'){
				B[i][j]=A[i][j]-'0';
			}
		}
	}
	return B;
}


int isValidSudoku(vector<string> A){
	vector<vector<int> >B=generateSudoku(A);
	int flag=1;
	
	for(int i=0;i<9;i++){
		unordered_set<int> S;
		for(int j=0;j<9;j++){
			if(B[i][j]>=1 && B[i][j]<=9){
				if(S.find(B[i][j])!=S.end()){
					flag=0;
					//cout<<i<<" "<<j<<"horizantal"<<endl;
				}else{
					S.insert(B[i][j]);
				}
			}
		}
		
	}
	
	for(int i=0;i<9;i++){
		unordered_set<int> S;
		for(int j=0;j<9;j++){
			if(B[j][i]>=1 && B[j][i]<=9){
				if(S.find(B[j][i])!=S.end()){
					flag=0;
					//cout<<i<<" "<<j<<"vertical"<<endl;
				}else{
					S.insert(B[j][i]);
				}
			}
		}
	}
	
	
	for(int i=0;i<9;i+=3){
		for(int j=0;j<9;j+=3){
			int l=i;
			int m=j;
			//cout<<"i="<<i<<" j="<<j<<endl;
			unordered_set<int> S;
			for(;l<i+3;l++){
				for(;m<j+3;m++){
					//cout<<B[l][m]<<"  ";
					if(B[l][m]>=1 && B[l][m]<=9){
						if(S.find(B[l][m])!=S.end()){
					flag=0;
				//	cout<<l<<" "<<m<<" 3*3"<<endl;
				}else{
					S.insert(B[l][m]);
				}
					}
					
				}
				m=j;
				//cout<<endl;
			}
		}
	}
	return flag;
}

int main() {
	vector<string> A{"53..7....", "6..195...", ".98....6.", "8...6...3", "4..8.3..1", "7...2...6", ".6....28.", "...419..5", "....8.579"};
	vector<vector<int> >
	B=generateSudoku(A);
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			cout<<B[i][j]<<" ";
		}cout<<"\n";
	}
	
	cout<<isValidSudoku(A)<<endl;
	return 0;
}
