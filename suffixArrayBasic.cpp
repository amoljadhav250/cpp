#include <bits/stdc++.h>
#define ll long long int
using namespace std;

vector<int> suffixArray(const string &A){
    map<string, int> m;
    vector<string> v;
    for(int i=0;i<A.length();i++){
        m[A.substr(i)]=i;
        v.push_back(A.substr(i));
    }
    sort(v.begin(),v.end());
    vector<int> ans;
    for(int i=0;i<v.size();i++){
        ans.push_back(m[v[i]]);
    }
    return ans;
}

int main(){
    string a="abac";
    for(int i=0;i<a.length();i++){
        cout<<a.substr(i,a.length())<<endl;
    }
    vector<int> A=suffixArray(a);
    for(int i=0;i<A.size();i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
    return 0;
}
