#include<stdio.h>
int main()
{
	int i,n,deno;
	float x,sum=1,nume;
	printf("please input x and n:");
	scanf("%f%d",&x,&n);
	for(i=1,deno=1,nume=1;i<=n;i++)//Çó1+x+x^2/2!+...+x^n/n!
	{
		deno=deno*i;
	    nume=nume*x;
	    sum=sum+nume/deno;
	}
	printf("sum=%f\n",sum);
	return 0;
}