#include<stdio.h>
int main()
{
	double i,sign=1, sum=0;
	for(i=1;1/i>=1e-6;i=i+2)
	{sum=sum+sign/i;
	sign=-sign;
	}
	printf("pi=%10.8f\n",4.0*sum);
	return 0;
}