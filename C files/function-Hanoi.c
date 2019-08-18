#include<stdio.h>
int main()
{
	int power(int);
	int n;
	printf("please input n:");
		scanf("%d",&n);
    printf("%d\n",power(n));
	return 0;
}

int power(int n)
{
	int a;
	if(n==1)
		a=1;
	else
		a=power(n-1)*power(n-1)+2*power(n-1);//p(n)=2^(2^(n-1))-1
	return a;
}
