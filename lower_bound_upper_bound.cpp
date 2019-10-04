#include<bits/stdc++.h>
#define LL long long int
#define sc(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define pf(x) printf("%d\n",x)
#define pl(x) printf("%lld\n",x)
#define F first
#define S second
#define M 1000000007
using namespace std;
 
int lower_bound(vector<int> V,int f){
	int s=0;
	int e=V.size()-1;
	int ans=-1;
	while(s<=e){
 
		int mid=(s+e)/2;
		//cout<<s<<" "<<mid<<" "<<e<<endl;
 
		if(V[mid]==f){
			ans=mid;
			e=mid-1;
		}else if(V[mid]>f){
			e=mid-1;
		}else{
			s=mid+1;
		}
	}
	return ans;
	//return -1;
}
 
int upper_bound(vector<int> V,int f){
		int s=0;
	int e=V.size()-1;
	int ans=-1;
	while(s<=e){
		int mid=(s+e)/2;
		if(V[mid]==f){
			ans=mid;
			s=mid+1;
		}else if(V[mid]>f){
			e=mid-1;
		}else{
			s=mid+1;
		}
	}
  if(ans==-1) return ans;
	return ans+1;
}
 
 
int main() {
	// your code goes here
	vector<int> V{1,2,2,2,2,2,3,3,3,5,5,5};
	cout<<lower_bound(V,3)<<endl;
	cout<<upper_bound(V,3)<<endl;
	cout<<lower_bound(V,5)<<endl;
	cout<<upper_bound(V,5)<<endl;
	cout<<upper_bound(V,11)<<endl;
	return 0;
}
