// 建質數表 -> 質因數分解 
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define max 30000000 
#define ll long long  
ll prime[max+1];
ll pm[max+1];
int pcount = 0;
// 1:代表是質數 0:不是質數
void sieve() // 篩子法 //篩出3*10^7範圍內的所有質數 
{
	// 一開始 將範圍內數字 都設為是質數 
	for(ll int i=0;i<=max;i++)
		prime[i] = 1;
	
	prime[0]=0;
	prime[1]=1;
	
	for(ll i=2;i<=sqrt(max);i++) //刪掉質數的倍數  剩下的為範圍內的質數 
	{
			if(prime[i]==1) 
			{
				for(int j=i*i;j<=max;j+=i)
					prime[j]=0;
			} 
	}	
	
	for(ll k=2;k<=max;k++)
	{ 
		if(prime[k]==1) pcount++; 
	}
	int c;
	for(ll i=2,j=0;i<=max;i++)
	{
			if(prime[i]==1) {
				pm[j]=i;
				j++;
			}
	}	
}  
int main()
{
	//int check=sqrtl(mx); // sqrtl:參數為long double 
	//printf("check:%d\n",check);
	sieve();
	ll N; 
	while(scanf("%lld",&N)!=EOF)// start 質因數分解
	{
		if(N==0) 
		{
			printf("1\n");
			continue;
		}
		
		while(N%2==0)
		{
			N/=2;	
		}
		ll ans = 1;
		ll tN = N;
		for(int w=0;w<pcount&&pm[w]<=tN;w++)
		{
				ll count=0; 
				while(N%pm[w]==0&&N!=0)
				{
						N/=pm[w];
						count++;
				}
				ans*=(count+1);
				if(N==1) break;
		}
		
		if(N!=1) // imp.
		{
			ans*=2;
		}
		printf("%lld\n",ans);	
	} 
	return 0;
 } 
