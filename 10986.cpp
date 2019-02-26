#include<stdio.h>
#include<vector>
#include<string.h>
#include<limits>
#define inf 99999
#include<iostream> 
#include<queue> 
using namespace std;

int main()
{
	//freopen("10986in.txt","r",stdin);
	//freopen("10986out.txt","w",stdout);
	int tc;
	scanf("%d",&tc);
	for(int c=1;c<=tc;c++)
	{
	  
 	int n,m,s,t;
 	scanf("%d %d %d %d",&n,&m,&s,&t);
 	vector< pair<int,int> > adj[n+1];
 	
 	for(int i=0;i<m;i++)
 	{
 		int a,b,w;
 		scanf("%d %d %d",&a,&b,&w);
		adj[a].push_back({b,w});
		adj[b].push_back({a,w});	
	}
	int dis[n+1];
	int visited[n+1];
	
	for(int i=0;i<n;i++)
	{
		dis[i] = inf ;
		visited[i] = 0;
	}
	dis[s] = 0;
	visited[s] = 1;
	priority_queue< pair<int,int> > pq;
	pq.push({0,s});
	while(!pq.empty())
	{
		int b = pq.top().second;
		int w = pq.top().first;
		pq.pop();
		visited[b]=1;
		
		for(int i=0;i<adj[b].size();i++)
		{
			int tb = adj[b][i].first;
			int tw = adj[b][i].second;
			if(dis[tb]>dis[b]+tw && visited[tb]==0)
			{
				dis[tb] = dis[b]+tw;
				pq.push({-dis[tb],tb});
			}
		}
	}
	cout << "Case #" << c <<": "; 
	if(dis[t]!=inf)
		cout << dis[t] << endl;
	else
		cout << "unreachable" << endl;	
	}
	return 0;
} 
