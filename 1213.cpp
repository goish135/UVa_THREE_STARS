#include<stdio.h>
#include<string.h> // memset(...)
#include<math.h> // sqrt(x) 

#define max 1120
#define total 14

bool prime[max+1];
int ans[max+1][total+1];
int box[max];
int np = 0;

void sieve()
{
	// initial
	for(int i=2;i<=max;i++)
	{
		prime[i] = true;
	}
	
	// begin sieve
	for(int j=2;j<=sqrt(max);j++)
	{
		if(prime[j])
		{
			for(int k=j*j;k<=max;k+=j)
			{
				prime[k] = false;
			}
		}
	}
			
}

void solve()
{
	int a = max+1;
	int b = total+1;
	
	memset(ans,0,a*b*sizeof(int));
	
	ans[0][0] = 1;
	
	for(int i=0;i<np;i++)
	{
		for(int j=max;j>=box[i];j--)
		{
			for(int k=total;k>=1;k--)
			{
					ans[j][k] += ans[j-box[i]][k-1];
			}	
		}	
	}	
}

int main()
{
	freopen("1213.in.txt","r",stdin);
	freopen("1213.out.txt","w",stdout);
	
	sieve();
	
	for(int i=2;i<=max;i++)
	{
		if(prime[i])
		{
			box[np++] = i ;	
		}	
	}
	
	solve();
	
	int n,k;
	while(scanf("%d %d",&n,&k))
	{
		if(n==0&&k==0) break;
		printf("%d\n",ans[n][k]);
	}
	return 0;
} 
