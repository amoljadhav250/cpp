#include <bits/stdc++.h>
#define ll long long int
using namespace std;
 
bool isPossible(vector<int> &v, int d,int count){
    int c=1;
    int prev=v[0];
    for(int i=1;i<v.size();i++){
        if(v[i]-prev>=d){
            c++;
            prev=v[i];
        }
    }
    if(c>=count){
        return true;
    }else{
        return false;
    }
}
 
void solve(){
    int n,c;
    cin>>n>>c;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    sort(v.begin(),v.end());
    
    int low=0;
    int high=v[n-1];
    int ans=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(isPossible(v,mid,c) && !isPossible(v,mid+1,c)){
            ans=mid;
            break;
        }else if(isPossible(v,mid,c) && isPossible(v,mid+1,c)){
            low=mid+1;
        }else if(!isPossible(v,mid,c) && !isPossible(v,mid+1,c)){
            high=mid-1;
        }
    }
    cout<<ans<<endl;
}
 
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
} 
