#include<stdio.h>
#include<iostream>
#include<algorithm> // sort(...) 
#include<string.h>  // memset(...) 
#define max 30000+10
#define maxi 200000+10

using namespace std;

int dp[maxi+1];
struct adv
{
	int from; // A
	int to;   // B
	int value; // C	
};

bool cmp(adv x,adv y)
{
	return 	x.from < y.from;
}

adv A[max+1];

int main()
{
	//freopen("11908.in.txt","r",stdin);
	//freopen("11908.out.txt","w",stdout);
	
	int tc;
	scanf("%d",&tc);
	int ce = 1;
	while(tc--)
	{
		int n; // advertises
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			int a,b,c;
			scanf("%d %d %d",&a,&b,&c);
			A[i].from = a; // ex : 1
		
			A[i].to = a+b-1; // ex : 1 2 3 4 [5] // cal: a+b-1  
			A[i].value = c;  
			// cout << A[i].from << " " << A[i].to << " " << A[i].value << '\n'; 
			// cout << A[i].to  << '\n'; 
		}			
		
	
		// Dynamic Programing // 
		sort(A,A+n,cmp); // use our own comparator
		memset(dp,0,sizeof(dp));
	
		int ix = 0 ; // ?th advertise
		int acc_cost = 0 ;  // accumulator
		for (int i=0 ; i<maxi ; i++) // 
		{
			while(ix<n && A[ix].from == i) 
			{
				int temp ;
				if(i==0) temp = A[ix].value;
				else     temp = dp[i-1] + A[ix].value;
				if( dp[A[ix].to] < temp ) dp[A[ix].to] = temp ; // after add
				ix++;
			}
		
			if(acc_cost<dp[i]) acc_cost = dp[i];
			dp[i] = acc_cost;
		}
		
		// int mx = 0;
		// for ( int i = 0; i < maxi ; i++ ) { if ( mx < dp [i] ) mx = dp [i]; }
		printf("Case %d: %d\n",ce,acc_cost);
		ce++;
	}
		
	return 0;
}
