#include <stdio.h>
int main()
{
	void order_output(int);
	int n;
	printf("������һ��������:\n");
	scanf("%d",&n);
	order_output(n);
	return 0;

}

void order_output(int n)
{
	if(n==0)
		return;
	else 
	{
		order_output(n/10);
		printf("%d\n",n%10);
	}
}


	
