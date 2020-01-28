#include <bits/stdc++.h>
using namespace std;




int main() {
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		string S[n];
		for(int i=0;i<n;i++){
			cin>>S[i];
		}
		
		int dist[n];
		dist[0]=0;
		for(int i=1;i<n;i++){
		    dist[i]=100000000;
		}
		
		bool visited[n];
		memset(visited, false, sizeof visited);
		
		list<int> Q;
		Q.push_back(0);
		visited[0]=true;
		
		while(!Q.empty()){
		    int b=Q.front();
		    Q.pop_front();
		   // cout<<b<<" "<<endl;
		    for(int i=max(0,b-k);i<=min(n-1,b+k);i++){
		        if(visited[i]==false && S[b][i]=='1'){
		            Q.push_back(i);
		            visited[i]=true;
		            if(dist[i]>dist[b]+1){
		                dist[i]=dist[b]+1;
		            }
		        }
		    }
		}
		
		if(dist[n-1]==100000000){
		    cout<<-1<<endl;
		}else{
		    cout<<dist[n-1]<<endl;
		}
		
		
	}
	return 0;
}
