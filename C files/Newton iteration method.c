#include<stdio.h>
int main()
{
	double f(double);
	double f_1(double);
	int n,i;
	double x0,x;
	printf("please input n and x0:");//����x0=1.5,nԽ�󾫶�Խ��,��ϵͳ���ֻ�ṩ���15λ��Ч����
	scanf("%d,%lf",&n,&x0);//attention:����double(8�ֽ�)������ʱҪ��"lf"(8�ֽ�),"f"��ʽΪ4�ֽ�
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

double f_1(double x)//��һ�׵�����f'(x)
{
	return 6*x*x-8*x+3;//��Ȼ��ʱf'(x)>0�����
}