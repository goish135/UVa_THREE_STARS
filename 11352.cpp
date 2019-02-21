// 11352 Crazy King //
#include<stdio.h>
#include<queue>
#include<string.h>

using namespace std;
int main()
{
	//freopen("11352in.txt","r",stdin);
	//freopen("11352out.txt","w",stdout);
	int tc;
	scanf("%d",&tc);
	int row,col;
	int mx[] = {1,1,2,2,-1,-1,-2,-2};
	int my[] = {2,-2,1,-1,2,-2,1,-1};
	
	int kx[] = {-1,-1,-1,1,1,1,0,0};
	int ky[] = {-1,0,1,-1,0,1,-1,1};
	
	queue< pair<int,int> > q;
	
	while(tc--)
	{	
		q = queue< pair<int,int> > (); 
		scanf("%d %d",&row,&col);
		getchar();
		int dis[row+1][col+1];
		memset(dis,0,sizeof(dis));
		
		char B[row+1][col+1];
		for(int i=1;i<=row;i++)
		{
			for(int j=1;j<=col;j++)
			{
				scanf("%c",&B[i][j]);
			}
			getchar();	
		}
		//printf("test\n");
		// mark dangerous area //
		int sx,sy,ex,ey;
		
		for(int i=1;i<=row;i++)
		{
			for(int j=1;j<=col;j++)
			{	
				if(B[i][j]=='Z')
				{
					for(int k=0;k<8;k++)
					{
						int tx = i+mx[k];
						int ty = j+my[k];
						if(tx>=1&&tx<=row&&ty>=1&&ty<=col&&B[tx][ty]=='.')
						{
							//printf("err:%d %d\n",tx,ty);
							B[tx][ty] = 'X';
						}
					}
				}
				else if(B[i][j]=='A')
				{
					sx = i;
					sy = j;
				}
				else if(B[i][j]=='B')
				{
					ex = i;
					ey = j;
				}
				
			}
		}
		
		/*
		for(int i=1;i<=row;i++)
		{
			for(int j=1;j<=col;j++)
			{
				printf("%c",B[i][j]);		
			}
			printf("\n");
		}
		*/
		
		
		//printf("try2\n");
		int ans=-1;
		q.push({sx,sy});
		
		//printf("dis :%d\n",dis[sx][sy]);
		int visited[row+1][col+1];
		memset(visited,0,sizeof visited);
		visited[sx][sy] = 1;
		while(!q.empty())
		{
			// printf("qq\n"); OO // 
			pair<int,int> p =q.front();
			q.pop();
			int x = p.first;
			int y = p.second;
			//cprintf("--> %d %d\n",x,y);
			if(B[x][y]=='B')
			{
				//printf("Bingo\n");
				ans = dis[x][y];
				break;
			}
			int flag = 0;
			for(int i=0;i<8;i++)
			{
			 	int xx = x + kx[i];
				int yy = y + ky[i];
				//printf(">>> %d %d\n",xx,yy);
				//printf("%c",B[xx][yy]);
		
				if(xx>=1&&xx<=row&&yy>=1&&yy<=col)
				{
					/* speed up 
					if(B[xx][yy]=='B') 
					{
						//printf("%d %d\n",xx,yy);
						ans = dis[x][y] + 1;
						flag = 1;
						break;
					}
					*/
					//printf("OK\n");
					//printf("%d\n",i);
					if(B[xx][yy]!='X'&&B[xx][yy]!='Z'&&visited[xx][yy]==0)
					{
						//printf("fff\n");
						//printf("-> %d %d\n",xx,yy);
						q.push({xx,yy});
						visited[xx][yy]=1;
						dis[xx][yy] = dis[x][y] + 1;
						//printf("%d %d : %d\n",xx,yy,dis[xx][yy]);
						
					}	
				} 
			}
			if(flag) break;	
		}
		if(ans==-1)
		{
			printf("King Peter, you can't go now!\n");	
		} 
		else
		{
			printf("Minimal possible length of a trip is %d\n",ans);
		}
		
	}
		
	return 0;
}

