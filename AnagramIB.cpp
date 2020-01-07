#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string a,string b){
	if(a.length()!=b.length()){
		return false;
	}
	int A[26], B[26];
	for(int i=0;i<26;i++){
		A[i]=0;
		B[i]=0;
	}
	for(int i=0;i<a.length();i++){
		A[a[i]-'a']++;
	}
	for(int i=0;i<b.length();i++){
		B[b[i]-'a']++;
	}
	
	bool flag=true;
	for(int i=0;i<26;i++){
		if(A[i]!=B[i]){
			flag=false;
			break;
		}
	}
	
	return flag;
}

vector<vector<int> > solve(vector<string> A){
        vector<vector<int> > B;
    
    bool flag[A.size()];
    for(int i=0;i<A.size();i++){
        flag[i]=false;
    }
    
    for(int i=0;i<A.size();i++){
        vector<int> C;
        for(int j=i;j<A.size();j++){
            if(flag[i]==false || flag[j]==false){
            if(isAnagram(A[i],A[j])){
                if(C.empty()==true){
                    if(flag[i]==false){
                        C.push_back(i+1);
                        flag[i]=true;
                    }
                    if(flag[j]==false){
                        C.push_back(j+1);
                        flag[j]=true;
                    }
                }else{
                    if(flag[j]==false){
                        C.push_back(j+1);
                        flag[j]=true;
                    }
                }
            }
            }
        }
        if(C.empty()==false){
            B.push_back(C);
            C.clear();
        }
    }
    return B;
}

int main() {
	vector<string> A{"cat","dog","god","tca","cta","amol"};
	vector<vector<int> > B=solve(A);
	
	for(int i=0;i<B.size();i++){
		for(int j=0;j<B[i].size();j++){
			cout<<B[i][j]<<" ";
		}
		cout<<endl;
	}
	
	return 0;
}
