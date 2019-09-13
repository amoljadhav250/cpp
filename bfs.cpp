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
};
 
 
int main(){
	cout<<"Hellow Graph:\n";
	Graph g(5);
	g.addEdge(0,2);
	g.addEdge(0,4);
	g.addEdge(1,3);
	g.addEdge(2,4);
	g.printGraph();
	return 0;
}
