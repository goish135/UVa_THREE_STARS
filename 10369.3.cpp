// uva 10369
// 

#include<stdio.h>
#include<iostream>
#include<math.h>
#include<algorithm>
#include<string.h>
#define max 500+1

double adj[max][max]; // two-dimention
double d[max];
int parent[max];
bool visit[max];
int p; // number of position

struct node{
	double x;
	double y;	
};

node N[max];

double distance(double x1,double y1,double x2,double y2)
{
	double dis = sqrt(pow(x1-x2,2)+pow(y1-y2,2)); 
	return dis;
}

void prim()
{
	// initial 
	for(int i=0;i<p;i++) visit[i] = false;
	for(int i=0;i<p;i++) d[i] = 1e9 ; // 10^9
	
	// chose any point to be root
	d[0] = 0;
	parent[0] = 0;
	
	for(int i=0;i<p;i++) // link every node
	{
		// 找不在 樹上 , 離樹最近的點
		int a = -1 ; // -1 : 沒找到 
		// int b = -1 ; // 
		int min = 1e9; 
		for(int j=0;j<p;j++)
		{
			if(!visit[j] && d[j]<min) //
			{
				a = j ;
				min = d[j];	
			}		
		}
		
		// 從起點可連通的已經找完 // MST finished
		if(a==-1) break;
		visit[a] = true;
		
		for(int b=0;b<p;b++)
			if(!visit[b] && adj[a][b] < d[b])
			{
				d[b] = adj[a][b];
				parent[b] = a ;	
			} 	
	}	
}

int main()
{
	//freopen("10369.in.txt","r",stdin);
	//freopen("10369.out.txt","w",stdout);
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		// memset(adj,0,sizeof(adj));
		for(int i=0;i<max;i++)
		{
			for(int j=0;j<max;j++)
			{
				adj[i][j] = 1e9 ;
			}
		}
		for(int i=0;i<max;i++)
		{
			N[i].x = 0;
			N[i].y = 0;
		}
		
		int s;
		scanf("%d%d",&s,&p);
	
		for(int i=0;i<p;i++)
		{
			int x,y;
			scanf("%d %d",&x,&y);
			N[i].x=x;
			N[i].y=y;
			// std::cout << i << " "<< N[i].x <<" "<<N[i].y <<'\n';
		}
	
		// distance();
		for(int i=0;i<p;i++)
		{
			for(int j=0;j<p;j++)
			{
				adj[i][j] = distance(N[i].x,N[i].y,N[j].x,N[j].y);
				// std::cout << adj[i][j] << '\n';
				// printf("%.2lf\n",adj[i][j]); 
			}
		}
	
		prim();
		/*
		for(int i=0;i<p;i++)
		{
			 printf("%.2lf\n",d[i]);
		 	std::cout << i << " " << parent[i] << '\n';
		 	std::cout << '\n';
		}
		*/
		std::sort(d,d+p);
		/*
		for(int i=0;i<p;i++)
		{ 
			std::cout << d[i] << '\n'; 
		}
		*/
	
		// std::cout << d[(p-1)-(s-1)] << '\n'; // p-1 : number of wight exclude 自己到自己 
		if(s==0)
			printf("%.2lf\n",d[p-1]);
		else	
			printf("%.2lf\n",d[p-1-(s-1)]);
		
	}
	return 0;
}
