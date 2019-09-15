#include <bits/stdc++.h>
using namespace std;
 
string addBinaryString(string A,string B){
	//	cout<<a<<" "<<b<<endl;
	string a=A;
	string b=B;
	int al=a.length();
	int bl=b.length();
 
	if(al<bl){
		int ld=bl-al;
		while(ld--){
			a="0"+a;
		}
	}
 
	if(al>bl){
		int ld=al-bl;
		while(ld--){
			b="0"+b;
		}		
	}
 
	int ansl=max(al,bl)+1;
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
//	cout<<"a="<<a<<endl;
//	cout<<"b="<<b<<endl;
	string c="0";
	string ans;
	for(int i=0;i<max(al,bl);i++){
		if(a[i]=='1' && b[i]=='1' && c=="0"){
			ans=ans+"0";
			c="1";
		}
			else	if(a[i]=='1' && b[i]=='1' && c=="1"){
			ans=ans+"1";
			c="1";
		}
			else	if(a[i]=='1' && b[i]=='0' && c=="1"){
			ans=ans+"0";
			c="1";
		}
		else		if(a[i]=='1' && b[i]=='0' && c=="0"){
			ans=ans+"1";
			c="0";
		}
		else		if(a[i]=='0' && b[i]=='1' && c=="1"){
			ans=ans+"0";
			c="1";
		}
		else		if(a[i]=='0' && b[i]=='1' && c=="0"){
			ans=ans+"1";
			c="0";
		}
		else if(a[i]=='0' && b[i]=='0' && c=="1"){
			ans=ans+"1";
			c="0";
		}
				else if(a[i]=='0' && b[i]=='0' && c=="0"){
			ans=ans+"0";
			c="0";
		}
	//	cout<<ans<<endl;
	}
	if(c=="1"){
		ans+="1";
	}
	while(ans[ans.length()-1]=='0'){
		ans=ans.substr(0,ans.length()-1);
	}
	reverse(ans.begin(),ans.end());
	return ans;
}
 
int main() {
cout<<addBinaryString("101010","1");
cout<<endl;
cout<<addBinaryString("101","11");
cout<<endl;
cout<<addBinaryString("1010","1010");
cout<<endl;
cout<<addBinaryString("100","11");
cout<<endl;
return 0;
}
