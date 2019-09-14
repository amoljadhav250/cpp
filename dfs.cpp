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
 
class Graph{
	int v;
	list<int>* adj;
 
	public:
		Graph(int V){
			v=V;
			adj=new list<int>[V];
		}
 
		void addEdge(int u,int v){
			adj[u].push_back(v);
		}
 
		void printGraph(){
			cout<<"Graph:\n";
			for(int i=0;i<v;i++){
				for(auto it=adj[i].begin();it!=adj[i].end();it++){
					cout<<i<<"-->"<<*it<<"\n";
				}
			}cout<<"\n";
 
		}
 
		void bfs(int s){
			bool *visited = new bool[v];
			for(int i=0;i<v;i++){
				visited[v]=false;
			}
			list<int> Q;
			visited[s]=true;
			Q.push_back(s);
 
			while(!Q.empty()){
				int f=Q.front();
				cout<<f<<"\t";
				Q.pop_front();
 
				for(auto it=adj[f].begin();it!=adj[f].end();it++){
					if(visited[*it]==false){
						Q.push_back(*it);
							visited[*it]=true;
					}
				}
			}
		}
		
		void dfsutil(int s,bool visited[]){
			visited[s]=true;
			cout<<s<<"\t";
			
			for(auto it=adj[s].begin();it!=adj[s].end();it++){
				if(visited[*it]==false){
					dfsutil(*it,visited);
				}
			}
		}
		
		void dfs(int s){
			bool visited[v];
			for(int i=0;i<v;i++){
				visited[i]=false;
			}
			
			dfsutil(s,visited);
			cout<<"\n";
		}
};
 
 
int main(){
	cout<<"Hellow Graph:\n";
	Graph g(4);
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
	g.printGraph();
	cout<<"BFS at vertex 2:\n";
	g.bfs(2);
	cout<<"\n";
	cout<<"DFS at vertex 2:\n";
	g.dfs(2);
	return 0;
}
