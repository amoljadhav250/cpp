#include <bits/stdc++.h>
using namespace std;

bool compVector(vector<int> A,vector<int> B){
	if(A[0]<B[0]){
		return true;
	}else if(A[0]==B[0] && A[1]<B[1]){
		return true;
	}else if(A[0]==B[0] && A[1]==B[1] && A[2]<B[2]){
		return true;
	}else if(A[0]==B[0] && A[1]==B[1] && A[2]==B[2] && A[3]<B[3]){
		return true;
	}else{
		return false;
	}
}

vector<int>  equal(vector<int> &A){
	int l=A.size();
	vector<int> D;
	map<int, pair<int,int> > M;
	for(int i=0;i<l-1;i++){
		for(int j=i+1;j<l;j++){
			if(M.find(A[i]+A[j])==M.end()){
				M.insert({A[i]+A[j], make_pair(i,j)});
			}else{
				auto it=M.find(A[i]+A[j]);
				int i1=(*it).second.first;
				int j1=(*it).second.second;
				if(i>i1 && j1!=i && j1!=j){
					//cout<<i1<<" "<<j1<<" "<<i<<" "<<j<<endl;
					//cout<<A[i1]<<" "<<A[j1]<<" "<<A[i]<<" "<<A[j]<<endl;
					vector<int> C;
					C.push_back(i1);
					C.push_back(j1);
					C.push_back(i);
					C.push_back(j);
					if(D.size()==0){
						D=C;
					}else{
						if(compVector(D,C)==false){
							D.clear();
							D=C;
						}
					}
				}
			}
		}
	}
	/*sort(B.begin(),B.end());
	if(B.size()==0){
		return D;
	}else{
		auto it=B.begin();
		it++;
		B.erase(it,B.end());
		D=B[0];
	}*/
	return D;
}

int main() {
	vector<int>A{3, 4, 7, 1, 2, 9, 8};
	vector<int>  D=equal(A);
	cout<<"Printing B:\n";

		for(int j=0;j<D.size();j++){
			cout<<D[j]<<" ";
		}
		cout<<endl;

	return 0;
}
