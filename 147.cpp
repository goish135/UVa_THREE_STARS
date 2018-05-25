// uva 147
#include<stdio.h>
#include<string.h>

#define max 30000

int dollars[11]={10000,5000,2000,1000,500,200,100,50,20,10,5};
long long int c[max+1]; // imp.1

void solve()
{
	memset(c,0,sizeof(c)+1);
	c[0] = 1;
	for(int i=0;i<11;i++)
	{
		for(int j=dollars[i];j<=max;j++)
		{
			c[j] += c[j-dollars[i]];	
		}	
	}		
}

int main()
{
	// freopen("147.in.txt","r",stdin);
	// freopen("147.out.txt","w",stdout);
	//freopen();
	
	double in;
	// 50*0.01 = 0.5 
	// 20*0.01 = 0.2
	// 10*0.01 = 0.1
	// 5 *0.01 = 0.05
	// double dollar[11]={100,50,20,10,5,2,1,0.5,0.2,0.1,0.05};
	solve();
	while(scanf("%lf",&in))
	{
		if(in==0.00) break;
		int inin = in*100.00 + 0.00001; // double precision // imp.2
		// printf("inin:%d\n",inin); 
		printf("%6.2lf%17lld\n",in,c[inin]);
	}
	return 0;
}
