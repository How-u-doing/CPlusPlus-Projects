#include<stdio.h>
int main()
{
	int u,v;
	printf("please enter u,v\n");
    scanf("u=%d,v=%d",&u,&v);
	while(v!=0)
	{int temp=u%v;
	u=v;
	v=temp;}
	printf("%d\n",u);
	return 0;
}