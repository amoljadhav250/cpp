#include<bits/stdc++.h>
#define LL long long int
#define sc(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define pf(x) printf("%d\n",x)
#define pl(x) printf("%lld\n",x)
#define F first
#define S second
#define d(x) cout<<#x<<":"<<x<<"\t"
#define dn(x) cout<<#x<<":"<<x<<"\n"
using namespace std;

class MinStack{
	int size;
	int t;
	int *A;
	stack<int>S;
	public:
	MinStack();
	void push(int x);
	void pop();
	int top() ;
	int getMin() ;
};

MinStack::MinStack() {
	 size=1000005;
	 t=-1;
	A = new int[size];
}

void MinStack::push(int x) {
	A[++t]=x;//cout<<"33"<<endl;
	if(S.empty()==true){
		S.push(x);//cout<<"35"<<endl;
	}else{//cout<<"36"<<endl;
		int y=S.top();
		if(x<y){
			S.push(x);
		}else{
			S.push(y);
		}
	}
}

void MinStack::pop() {
	if(t>=0){
		t--;
		S.pop();
	}
}

int MinStack::top() {
	return A[t];
}

int MinStack::getMin() {
	if(S.empty()==true){
		return -1;
	}else{
		return S.top();
	}
	
}

int main() {
	MinStack s;//cout<<"59"<<endl;
	s.push(3);//cout<<"60"<<endl;
	s.push(2);
	s.push(4);
	cout<<s.getMin()<<endl;//cout<<"63"<<endl;
	s.pop();//cout<<"64"<<endl;
	cout<<s.getMin()<<endl;//cout<<"65"<<endl;
	s.pop();//cout<<"66"<<endl;
	cout<<s.getMin()<<endl;//cout<<"67"<<endl;
	return 0;
}
