#include<stdio.h>
int main()
{
	int i,n,m=0;
	for(n=1978;n<=2018;n++)//判断100-200的素数
	{for(i=2;i<=n/2;i++)//或者i<=sqrt(n),前面加上#include<math,h>;注意for前面的花括号的位置
	if(n%i==0)break;
	if(i>n/2){printf("%d\t",n);m++;if(m%10==0)printf("\n");}//m控制换行（10个一行）
	}
		putchar('\n');
	return 0;
}