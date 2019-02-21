// uva 439 - Knight Moves // 
#include<stdio.h>
#include<queue>
using namespace std;

int main()
{
	//freopen("439in.txt","r",stdin);
	//freopen("439out.txt","w",stdout);
	
	int A[9][9]; // col: a b c d e f g h (8) row: 1~8
	char chsx,chex,ch;
	int sx,sy,ex,ey;
	queue< pair<int,int> > q;
	int mx[] = {1,1,-1,-1,2,2,-2,-2};
	int my[] = {2,-2,2,-2,1,-1,1,-1};
	
	while(scanf("%c%d %c%d",&chsx,&sy,&chex,&ey)==4)
	{
		for(int i=0;i<9;i++)
		{
			for(int j=0;j<9;j++)
			{
				A[i][j] = 0;
			}
		}
		q = queue<pair<int,int> >(); // q 清空  
		sx = (chsx-'a')+1;
		ex = (chex-'a')+1;

		q.push({sx,sy});
		A[sx][sy] = 0;
	
		int ans ;
		while(!q.empty())
		{
			pair<int,int> p = q.front();	
			q.pop();
			int x = p.first;
			int y = p.second;
			if(x==ex&&y==ey)
			{
				ans = A[x][y];
				break;
			}
			for(int i=0;i<8;i++)
			{		
				int tx = x+mx[i];
				int ty = y+my[i];
				if(tx>=1&&tx<=8&&ty>=1&&ty<=8) // 不超出 棋盤範圍 
				{
					A[tx][ty] = A[x][y] + 1;
					q.push({tx,ty});
				}
			}
			
		}
		printf("To get from %c%d to %c%d takes %d knight moves.\n",chsx,sy,chex,ey,ans);
		getchar();
	}
	return 0;	
} 
