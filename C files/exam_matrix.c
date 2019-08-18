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
	printf("������һ��4*4����:\n");
	for(i=0;i<16;i++)
		scanf("%d",a+i);
ss:	printf("��ѡ����任��ʽ:\n1--ˮƽ,2--��ֱ\n");
	while(getchar()!='\n');
	scanf("%c",&c);
	if(c=='1')
	{
		horizontal_transform(a,4,4,b);
		printf("�þ����ˮƽ����任����:\n");
	}
	else if(c=='2')
	{
		vertical_transform(a,4,4,b);
		printf("�þ���Ĵ�ֱ����任����:\n");
	}
	else {printf("�������,����������!\n");goto ss;}
	for(i=0;i<16;i++)
		{
			printf("%d  ",b[i]);
			if(i%4==3)putchar(10);
		}
	return 0;
}






