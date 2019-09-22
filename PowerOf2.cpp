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



string multiplyBy2(string a){
	reverse(a.begin(),a.end());
	string s="";
	int c=0;
	for(int i=0;i<a.length();i++){
	int d=a[i]-'0';
	int d2=d*2+c;
	s.push_back((d2%10)+'0');
	c=d2/10;
	}
	if(c==1){
		s.push_back('1');
	}
	reverse(s.begin(),s.end());
//	cout<<s<<endl;
	return s;

}

bool powerOf2(string A){
	string a=A;
	int al=a.length();
	string t="2";
	while(multiplyBy2(t).length()<al){
		t=multiplyBy2(t);
	//	cout<<t<<" ";
	}
	for(int i=0;i<5;i++){
		t=multiplyBy2(t);
		if(t==a){
			return 1;
		}
	}
	return 0;
}

int main(){
	if(powerOf2("128")){
		cout<<"128"<<endl;
	}
		if(powerOf2("127")){
		cout<<"127"<<endl;
	}
	
	if(powerOf2("9223372036854775807")){
		cout<<"9223372036854775807"<<endl;
	}
		if(powerOf2("9223372036854775808")){
		cout<<"9223372036854775808"<<endl;
	}
}
