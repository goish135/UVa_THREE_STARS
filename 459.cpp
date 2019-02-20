// Graph Connectivity //

#include<stdio.h>
#include<vector>
#include<string.h>

using namespace std;

vector<int> mv[26];
bool visited[26];

void dfs(int x)
{
	if(visited[x]==true) return;
	visited[x] = true;
	//printf("%c",x+'A');
	for(int i=0;i<mv[x].size();i++)
	{
		if(visited[mv[x][i]]==false)
		{
			dfs(mv[x][i]);
		}
	}
}
int main()
{
	//freopen("459in.txt","r",stdin);
	//freopen("459out.txt","w",stdout);
	int tc;
	
	scanf("%d",&tc);
	getchar();
	getchar();
	char str[3];
	
	while(tc--)
	{
		for(int i=0;i<26;i++)
		{
			mv[i].clear();
		}
		char ch;
		scanf("%c",&ch);
		getchar();
		//printf("%d",ch-'A'+1);
		int total = ch-'A'+1;
		//printf("%d\n",total);
		for(int i=0;i<total;i++)
		{
			visited[i] = false;
		}
		while(gets(str))
		{		
			if(str[0]=='\0') 
			{
				break;
			}
			//printf("%c %c\n",str[0],str[1]);
			
			mv[str[0]-'A'].push_back(str[1]-'A');
			//printf("%d %d\n",str[0]-'A',str[1]-'A');
			mv[str[1]-'A'].push_back(str[0]-'A');
		}
		// A ~ E //
		int count = 0;
		for(int i=0;i<total;i++)
		{
			if(visited[i]==false)
			{
				count ++ ;
				dfs(i);
			}
		}
		//printf("\n");
		printf("%d\n",count);
		if(tc) printf("\n");
	}
	return 0;
}
