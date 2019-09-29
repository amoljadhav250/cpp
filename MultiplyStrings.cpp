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

string multiplySI(string a,int b){
	string s="";
	reverse(a.begin(),a.end());
	int c=0;
	for(int i=0;i<a.length();i++){
		int d=a[i]-'0';
		d=d*b+c;
		s.push_back(d%10+'0');
		c=d/10;
	}
	if(c!=0){
		s.push_back(c+'0');
	}
	reverse(s.begin(),s.end());
	return s;
}

string addSS(string a, string b){
	string s="";
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	
	int al=a.size();
	int bl=b.size();
	
	if(al>bl){
		int d=al-bl;
		while(d--){
			b.push_back('0');
		}
	}
	
	if(bl>al){
		int d=bl-al;
		while(d--){
			a.push_back('0');
		}
	}
	
	int c=0;
	for(int i=0;i<a.length();i++){
		int ac=a[i]-'0';
		int bc=b[i]-'0';
		
		int d=ac+bc+c;
		
		s.push_back(d%10+'0');
		c=d/10;
	}
	
	if(c!=0){
		while(c){
			s.push_back(c%10+'0');
			c/=10;
		}
	}
	
	reverse(s.begin(),s.end());
	return s;
}

string multiplySS(string a, string b){
	string s="0";
	reverse(b.begin(),b.end());
	for(int i=0;i<b.size();i++){
		int j=b[i]-'0';
		string az=a;
		int k=i;
		while(k--){
			az.push_back('0');
		}
		//cout<<"i="<<i<<" az="<<az<<endl;
		//cout<<multiplySI(az,j)<<endl;
		s=addSS(s,multiplySI(az,j));
	}
	while(s[0]=='0'){
		s=s.substr(1,s.size()-1);
	}

	if(s.size()==0){
		return "0";
	}
	return s;
}

int main() {
	cout<<multiplySS("12","2")<<endl;
	cout<<multiplySS("954","9")<<endl;
	cout<<multiplySS("12345","123")<<endl;
	cout<<multiplySS("99","999")<<endl;
/*	string s="00000";
		while(s[0]=='0'){
		s=s.substr(1,s.size()-1);
		cout<<s<<endl;
	}
	if(s.size()==0){
		cout<<"#0"<<endl;
	}*/
	return 0;
}
