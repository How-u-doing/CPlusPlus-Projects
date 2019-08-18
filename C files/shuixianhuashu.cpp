#include<stdio.h>
int main()
{
	int a,b, c,i;
	for(i=100;i<=999;i++)
	{a=i/100;
	b=(i-100*a)/10;
	c=i-100*a-10*b;
	if(100*a+10*b+c==a*a*a+b*b*b+c*c*c)
		printf("%d\t",i);/*printf("%d%d%d\t",a,b,c)*/
	}
	printf("\n");
	return 0;
}
