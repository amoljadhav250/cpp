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

bool isValid(string s){
	if(s=="0"){
		return true;
	}else if(s.size()>1 && s[0]=='0'){
		return false;
	}else if(stoi(s)>1 && stoi(s)<=255){
		return true;
	}else{
			return false;
	}
	return false;
}

string validIp(string a){
	int count=0;
	int al=a.length();
		for(int i=1;i<=3;i++){
		for(int j=i+1;j<=i+3;j++){
			for(int k=j+1;k<=j+3;k++){
			//	cout<<i<<" "<<j<<" "<<k<<"\n";
			//	cout<<count++<<"\n";
			//	cout<<a.substr(0,i)<<" ";
			//	cout<<a.substr(i,j-i)<<" ";
			//	cout<<a.substr(j,k-j)<<" ";
			//	cout<<a.substr(k,al-k)<<"\n";
			string x1,x2,x3,x4;
			x1=a.substr(0,i);
			x2=a.substr(i,j-i);
			x3=a.substr(j,k-j);
			x4=a.substr(k,al-k);
			
			if(isValid(x1) && isValid(x2) && isValid(x3) && isValid(x4) ){
				cout<<x1<<"."<<x2<<"."<<x3<<"."<<x4<<endl;
			}
			}
		}
	}
	return "a";
}

int main(){
	validIp("25525511135");

}
