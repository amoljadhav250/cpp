#include <bits/stdc++.h>
using namespace std;
#define N 1024
#define LGN 11
int P[11][1024];

struct suffix{
	int index;
	int rank[2];
} suffixes[N];

int cmp(suffix a, suffix b) 
{ 
    return (a.rank[0] == b.rank[0])? (a.rank[1] < b.rank[1] ?1: 0): 
               (a.rank[0] < b.rank[0] ?1: 0); 
}

void printp(){
	for(int i=0;i<5;i++){
		for(int j=0;j<25;j++){
			cout<<setw(4)<<P[i][j];
		}
		cout<<endl;
	}
}

int *constructArray(string a){
	int n=a.length();
	for(int i=0;i<n;i++){
		P[0][i]=a[i]-'a';
	}
	int stp=1,cnt=1;
	for(int stp=1,cnt=1;cnt<n;cnt*=2,stp++){
		for(int i=0;i<n;i++){
		suffixes[i].rank[0]=P[stp-1][i];
		suffixes[i].rank[1]=i+cnt<n ? P[stp-1][i+cnt]:-1;
		suffixes[i].index=i;			
		}
		
			sort(suffixes,suffixes+n,cmp);
			for(int i=0;i<n;i++){
				P[stp][suffixes[i].index]=i>0 && suffixes[i].rank[0]==suffixes[i-1].rank[0] && suffixes[i].rank[1]==suffixes[i-1].rank[1] ? P[stp][suffixes[i-1].index] : i;
			}
	}

	int *suffix_array = new int[n];
	for(int i=0;i<n;i++){
		suffix_array[i]=suffixes[i].index;
		cout<<suffixes[i].index<<" ";
	}
	cout<<endl;
	return suffix_array;
}


int main() {
	string a;
	cin>>a;
	int *array=constructArray(a);
	for(int i=0;i<a.length();i++){
		cout<<array[i]<<" "<<a.substr(array[i])<<endl;
	}
	//printp();
	return 0;
}
