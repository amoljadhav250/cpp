#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> A){
	int l=A.size();
	vector<int> C;
	int lsum[l];
	lsum[0]=A[0];
	int min_int=-1;
	int max_int=-1;
	if(lsum[0]==0){
		min_int=0;
		max_int=0;
	}
	for(int i=1;i<l;i++){
		lsum[i]=lsum[i-1]+A[i];
		if(lsum[i]==0){
			min_int=0;
			max_int=i;
		}
	}
	
	int max_val=*max_element(lsum,lsum+l);
	int min_val=*min_element(lsum,lsum+l);
	
	//cout<<max_val<<" "<<min_val<<endl;
	
	unordered_map<int,int> S;
	
	int max_size;
	
	if(max_int != -1){
		max_size=max_int-min_int+1;
	}else{
		max_size=0;
	}
	
	for(int i=0;i<l;i++){
		if(S.find(lsum[i])!=S.end()){
			auto it=S.find(lsum[i]);
			int sec=it->second;
			if(i-sec>max_size){
				max_size=i-sec;
				min_int=sec+1;
				max_int=i;
			}
		}else{
			S.insert(make_pair(lsum[i],i));
		}
	}
	
	
	if(max_int!=-1){
		for(int i=min_int;i<=max_int;i++){
			C.push_back(A[i]);
		}
	}
	
	
	return C;
}

int main() {
	vector<int> A={0, -1,-2,4, 8};
	vector<int> C=solve(A);
	for(auto it=C.begin();it!=C.end();it++){
		cout<<*it<<" ";
	}
	cout<<endl;
	return 0;
}
