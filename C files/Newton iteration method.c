#include<stdio.h>
int main()
{
	double f(double);
	double f_1(double);
	int n,i;
	double x0,x;
	printf("please input n and x0:");//此题x0=1.5,n越大精度越高,但系统最多只提供最多15位有效数字
	scanf("%d,%lf",&n,&x0);//attention:输入double(8字节)型数据时要用"lf"(8字节),"f"形式为4字节
	for(i=1,x=x0;i<=n;i++)
	if(f_1(x)!=0)
	{x=x-f(x)/f_1(x);
	printf("x%d=%20.15f\n",i,x);
	}
	return 0;
}


double f(double x)
{
	return 2*x*x*x-4*x*x+3*x-6;
}

double f_1(double x)//即一阶导函数f'(x)
{
	return 6*x*x-8*x+3;//显然此时f'(x)>0恒成立
}