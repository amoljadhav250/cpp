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

vector<int> maxContSeries(vector<int> A, int B){

        int M=B;
    int s=0;
    int e=0;
    int ss=0;
    int ee=0;
    int z=0;
    int n=A.size();

    int ans=0;
    
    while( e<n){
      //  cout<<"s="<<s<<" e="<<e<<" z="<<z<<endl;
        if(z<=M){
            e++;
            //ans=max(ans,e-s);
            if(ans<e-s){
                ans=e-s;
                ee=e;
                ss=s;
            }
            if(A[e]==0){
                z++;
            }
        }
        if(z>M){
            s++;
            if(A[s-1]==0){
                z--;
            }
        }
    }
    
   // d(ss);
   // dn(ee);

    vector<int> answer;
    
    for(int i=ss;i<ee;i++){
        answer.push_back(i);
    }
    return answer;
}

int main() {
	vector<int> A{0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 1, 1, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0 };
	//{0};
	int M=8;
	vector<int> B=maxContSeries(A,M);
	
	for(int i=0;i<B.size();i++){
		cout<<B[i]<<" ";
	}
	cout<<endl;
	return 0;
}
