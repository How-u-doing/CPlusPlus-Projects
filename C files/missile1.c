#include<stdio.h>//为简化问题，设飞机一直水平飞行
#include<math.h>
void main()
{
	float t,s,m,n,x,y,p,q;
	int flag=1;
	int i=0;
	scanf("%f",&t);
	m=4000,n=10000;
	x=0,y=0;
	do
	{
		s=sqrt((n-y)*(n-y)+(m-x)*(m-x));
		if(s<=5)
		{
			flag=0;
		}
		p=(n-y)/s;
		q=(m-x)/s;
		m=m-t*q;
		n=n-t*p;
		x=5*t;
		i=i+1;
	}
	while(flag==1);
	printf("%d\n",i);
}
