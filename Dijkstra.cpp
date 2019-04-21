#include <set>
#include <vector>
#include <algorithm>
#include <iostream>
#define LL long long int
#define sc(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define pf(x) printf("%d\n",x)
#define pl(x) printf("%lld\n",x)
#define F first
#define S second
#define MAX 405
#define M 1000000007
using namespace std;
 
 
int main ()
{
	int t;
	sc(t);
	while(t--)
	{
		
		int n,k,x,m,s,A,B,C,u,v,sz,wt,flag=1;
	sc(n);
	sc(k);
	sc(x);
	sc(m);
	sc(s);
	
	vector<pair<int,int> >g[n+2];
	
	
	
	
	while(m--)
	{
		sc(A);
		sc(B);
		sc(C);
		g[A].push_back(make_pair(B,C));
		g[B].push_back(make_pair(A,C));
	}
	
    bool visited[n+2];
    LL dist[n+2];
    
    for(int i=1;i<=n;i++)
    {
    	visited[i]=false;
    	dist[i]=1e16;
    }
    
    dist[s]=0;
    
	set<pair<LL,int> >a;
	
	set<pair<LL,int> >::iterator it;
	a.insert(make_pair(0,s));
	
	while(!a.empty())
	{
		it=a.begin();
		u=it->second;
		a.erase(it);
		sz=g[u].size();
	
		if(u<=k && flag==1)
		{
			for(int i=0;i<u;i++)
			{
				dist[i]=min(dist[i],dist[u]+(LL)x);
			//	visited[i]=true;
			a.insert(make_pair(dist[i],i));
			}
			
			for(int i=u+1;i<=k;i++)
			{
				dist[i]=min(dist[i],dist[u]+(LL)x);
			//	visited[i]=true;
			a.insert(make_pair(dist[i],i));
			}
			flag=0;
		}	
	
		for(int i=0;i<sz;i++)
		{
			wt=g[u][i].second;
			v=g[u][i].first;
			if(!visited[v] && dist[v]>(LL)dist[u]+(LL)wt)
			{
				dist[v]=dist[u]+wt;
				a.insert(make_pair(dist[v],v));
			}
		}
		visited[u]=true;
	}
	
	for(int i=1;i<=n;i++)
	{
		cout<<dist[i]<<" ";
	}
	cout<<endl;
	}
	
	return 0;
}  
