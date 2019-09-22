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
	}else if(stoi(s)>=1 && stoi(s)<=255){
		return true;
	}else{
			return false;
	}
	return false;
}
 
vector<string> validIp(string A){

	string a=A;
	vector<string>v;
	if(a.length()>12){
		return v;
	}
//	int count=0;
	int al=a.length();
		for(int i=1;i<=3;i++){
		for(int j=i+1;j<=i+3;j++){
			for(int k=j+1;k<=j+3;k++){
			//	cout<<++count<<" ";
			if(k<al){
			string x1,x2,x3,x4;
			x1=a.substr(0,min(i,al));
			x2=a.substr(i,min(j-i,al-i));
			x3=a.substr(j,min(k-j,al-j));
			x4=a.substr(k,al-k);
 
			if(isValid(x1) && isValid(x2) && isValid(x3) && isValid(x4) ){
				string v1=x1+"."+x2+"."+x3+"."+x4;
			v.push_back(v1);
			}
			}
 
			}
		}
	}
	sort(v.begin(),v.end());
	return v;
}
 
int main(){
	vector<string> k=validIp("010010");
	for(int i=0;i<k.size();i++){
		cout<<k[i]<<endl;
	}
 
}
