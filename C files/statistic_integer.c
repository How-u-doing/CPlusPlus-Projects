#include<stdio.h>
int main()
{
	int char_int(char *t,int n);
	char str[80],*s=str,b[50],*t=b;//�ַ�����b���Ⱥ�˳��洢str�ַ�������������
	int num=0,N[20]={0},i=0;//numΪstr�ַ�������������,N[i]Ϊ��i�������ַ����ĳ���(���ָ���)
	int isDigital=0,a[20];//����a�����Щ����,isDigitalΪ�Ƿ�������ֵı�־,��Ϊ1,��Ϊ0. 
	printf("������һ���ַ���:\n");
	gets(str);
	for(;*s!='\0';s++)
	{
		if(*s<'0'||*s>'9')isDigital=0;
		else if(isDigital==0)//�����ǰ�ַ�Ϊ������ǰһ���ַ���������
		{isDigital=1;
		num++;
		i++;//iΪ��i�������ַ���
		}
		if(isDigital==1)
		{*t++=*s;
		N[i]++;
		}
	}
	for(i=0;i<num;i++)
	{a[i]=char2int(b+N[i],N[i+1]);
	N[i+1]+=N[i];
	}
	printf("����ַ�������%d������,�ֱ���:\n",num);
	for(i=0;i<num;i++)
		printf("%d\t",a[i]);
	putchar(10);
	return 0;
}

int char2int(char *p,int n)/*  ���ַ������ִ�ת����int������,pָ�������ַ���
							��ʼ��ַ,nΪÿ�������ַ���������(0~9)����  */
{
	int i,sum=0,e=1;
	for(i=n-1;i>=0;i--)
	{
		sum+=(*(p+i)-48)*e;//��ĳ�����ַ���Ϊ012306,ת���󽫵�һ��0ʡ��,ֱ�����ֵ�һ����Ϊ0������
		e*=10;
	}
	return sum;
}


