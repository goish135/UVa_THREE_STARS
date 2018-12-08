#include<stdio.h>
#include<math.h>
#define _USE_MATH_DEFINES
#include<iostream>
using namespace std;
#define pi 3.141592653589793 // 題目有給 //  

int main()
{
	// cout << M_PI << endl;
	double x1,y1,x2,y2,x3,y3;
	while(cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3)
	{
		double a,b,c,s,r;
		a = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
		b = sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
		c = sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
	
		s = (a+b+c)/2;
	
		r = a*b*c / (4*sqrt(s*(s-a)*(s-b)*(s-c)));
	
		// double  ans = 2*M_PI*r;
		double ans = 2*pi*r;
		// cout << ans << endl;
		printf("%.2lf\n",ans);
	}
	return 0;		
} 
