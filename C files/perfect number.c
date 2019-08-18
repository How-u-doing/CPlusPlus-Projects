#include<stdio.h>
int main()
{
	void factors(int);
	int n,i,j,sum;
	printf("please input n:");
	scanf("%d",&n);
	for(j=1;j<=n;j++)
	{
	    for(i=1,sum=0;i<=j/2;i++)
		if(j%i==0)
			sum=sum+i;
		if(j==sum)
		{
			printf("%d its factors are ",j);
			factors(j);
			printf("\n");
		}

	}
	return 0;
}

void factors(int x)
{
	int i;
	for(i=1;i<=x/2;i++)
	if(x%i==0)
		printf("%d,",i);
	printf("\b.");
}

