#include<stdio.h>
#include<math.h>
#define s0 5
int main()
{
	float t,s,a=40000,b=100000,x=0,y=0,sin,cos;
	int i;
	printf("please input the time interval,t=:");
	scanf("%f",&t);
	s=sqrt((a-x)*(a-x)+(b-y)*(b-y));
	for(i=0;s>=s0;i++)
	{
		sin=(b-y)/s;
		cos=(a-x)/s;//同sin一样，可正可负，与t的取值有关
		a-=1000*t*cos;
		b-=1000*t*sin;
		x-=500*t;//为简化问题，假设飞机水平飞行（沿x轴负方向匀速飞行）
		s=sqrt((a-x)*(a-x)+(b-y)*(b-y));
	}
	printf("The times that the massile changes its flight direction to hit the target is:%d\n",i);
	return 0;
}




