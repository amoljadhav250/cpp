#include <iostream>
using namespace std;

/**when a and b are coprie
x will be modular multiplicative inverse**/
int gcd(int a, int b, int *x, int *y){
	if(a==0){
		*x=0;
		*y=1;
		return b;
	}
	int x1,y1;
	int g = gcd(b%a,a,&x1,&y1);
	*x=y1-(b/a)*x1;
	*y=x1;
	return g;
}

int ppow(int b,int p,int m){
	int res=1;
	while(p){
		if(p&1){
			res=((res%m)*(b%m))%m;
		}
		b=((b%m)*(b%m))%m;
		p/=2;
	}
	return res%m;
}

/**when b is prime and gcd(a,b)=1**/
int mminverse(int a, int b){
	return ppow(a,b-2,b);
}

int main() {
	int x,y,a=3,m=11;
	int g=gcd(a,m,&x,&y);
	cout<<x<<" "<<y<<endl;
	cout<<mminverse(3,11)<<endl;
	return 0;
}
