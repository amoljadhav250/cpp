#include <bits/stdc++.h>
using namespace std;


void solveUtil(map<string, int> main, string S, vector<int> &ans,int start,int l,int tl){
	
	
	for(int i=start;i<start+tl;i+=l){
		string temp=S.substr(i,l);
		if(main.find(temp)==main.end()){
			return;
		}else{
			main[temp]--;
		}
	}
	for(auto it=main.begin();it!=main.end();it++){
		if((*it).second!=0){
			return;
		}
	}
	ans.push_back(start);
}

vector<int> solve(string A, const vector<string> &B){
	string S=A;
	vector<string> L=B;
	vector<int> ans;
	if(L.size()==0 || S.size()==0){
		return ans;
	}
	
	map<string, int> main;
	for(int i=0;i<L.size();i++){
		main[L[i]]++;
	}
	
	int l=L[0].length();
	int tl=L.size()*l;
	
	for(int i=0;i<=S.length()-tl;i++){
		solveUtil(main, S, ans, i, l, tl);
	}
	
	return ans;
}

int main() {
	string S="barfoothefoobarmanbarfoothefoobarmanbarbarfoo";
	cout<<S.length()<<endl;
	vector<string> L={"foo", "bar"};
	vector<int> ans=solve(S, L);
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return 0;
}
