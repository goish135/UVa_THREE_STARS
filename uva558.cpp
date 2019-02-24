#include<stdio.h>
#include<tuple>
#include<vector>
#include<string.h>

using namespace std;

int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		int n,m;
		scanf("%d %d",&n,&m);
		vector< tuple<int,int,int> > edge;
		for(int i=0;i<m;i++)
		{
			int a,b,w; 
			scanf("%d %d %d",&a,&b,&w);
			edge.push_back({a,b,w});
		}
		
		//int flag = 1;
		int dis[n+1];
		dis[1] = 0;
		for(int i=2;i<=n;i++)
		{
			dis[i] = 1001;
		}
		//int pre[n+1];
		//memset(pre,0,sizeof pre);
		//while(flag)
		//{
		for(int k=0;k<n-1;k++)
		{
			for(int i=0;i<edge.size();i++)
			{
				int ta,tb,tw;
				tie(ta,tb,tw) = edge[i];
				if(dis[tb]>dis[ta]+tw)
				{
					dis[tb] = dis[ta]+tw;
				}
			}
			/*
			flag = 0;
			for(int i=1;i<=n;i++)
			{
				if(pre[i]!=dis[i]) flag = 1;
			}
			*/
		//}
		}
		
		int flag = 0;
		for(int i=0;i<edge.size();i++)
		{
			int ta,tb,tw;
			tie(ta,tb,tw) = edge[i];
			
			if(dis[tb]>dis[ta]+tw)
			{
				//dis[tb] = dis[ta]+w;
				flag = 1; // exist negative cycle //
				break;
			}
		}
		if(flag) printf("possible\n");
		else printf("not possible\n");
	}
	return 0;	
} 
