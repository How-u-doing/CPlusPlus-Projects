#include<stdio.h>
void horizontal_transform(int orig[],int h,int w,int save[])
{
	int i,j,t;
	for(i=0;i<h;i++)
		for(j=0;j<w/2;j++)
		{t=orig[i*w+j];orig[i*w+j]=orig[i*w+w-1-j];orig[i*w+w-1-j]=t;}
	for(i=0;i<w*h;i++)
		save[i]=orig[i];
}

void vertical_transform(int orig[],int h,int w,int save[])
{
	int i,j,t;
	for(j=0;j<w;j++)
		for(i=0;i<h/2;i++)
		{t=orig[i*w+j];orig[i*w+j]=orig[(h-1-i)*w+j];orig[(h-1-i)*w+j]=t;}
	for(i=0;i<w*h;i++)
		save[i]=orig[i];
}

int main()
{
	int a[16],i,b[16];
	char c;
	printf("请输入一组4*4矩阵:\n");
	for(i=0;i<16;i++)
		scanf("%d",a+i);
ss:	printf("请选择镜像变换方式:\n1--水平,2--垂直\n");
	while(getchar()!='\n');
	scanf("%c",&c);
	if(c=='1')
	{
		horizontal_transform(a,4,4,b);
		printf("该矩阵的水平镜像变换如下:\n");
	}
	else if(c=='2')
	{
		vertical_transform(a,4,4,b);
		printf("该矩阵的垂直镜像变换如下:\n");
	}
	else {printf("输入错误,请重新输入!\n");goto ss;}
	for(i=0;i<16;i++)
		{
			printf("%d  ",b[i]);
			if(i%4==3)putchar(10);
		}
	return 0;
}






