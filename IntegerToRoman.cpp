#include <iostream>
using namespace std;
 
string integerToRoman(int A){
	string S[14]={"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M","Z"};
	int V[14]={1,4,5,9,10,40,50,90,100,400,500,900,1000,5000};
string ans;
while(A){
//	cout<<"A="<<A<<endl;
//	cout<<"ans="<<ans<<endl;
//	cout<<endl;
	int i=0;
	for(i=0;i<14;i++){
		if(V[i]>A){
			break;
		}
	}
	int d=A/V[i-1];
	A=A%V[i-1];
	while(d--){
		ans+=S[i-1];
	}
}
//	cout<<"\n\nAnd the answer is:"<<ans<<endl;
return ans;
}
 
int main() {
	// your code goes here
	cout<<integerToRoman(3549)<<endl;
	cout<<integerToRoman(1954)<<endl;
	cout<<integerToRoman(1854)<<endl;
	cout<<integerToRoman(37)<<endl;
	cout<<integerToRoman(19)<<endl;
	return 0;
}
