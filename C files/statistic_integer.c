#include<stdio.h>
int main()
{
	int char_int(char *t,int n);
	char str[80],*s=str,b[50],*t=b;//字符数组b按先后顺序存储str字符串中所有数字
	int num=0,N[20]={0},i=0;//num为str字符串中整数个数,N[i]为第i个数字字符串的长度(数字个数)
	int isDigital=0,a[20];//数组a存放这些整数,isDigital为是否出现数字的标志,是为1,否为0. 
	printf("请输入一行字符串:\n");
	gets(str);
	for(;*s!='\0';s++)
	{
		if(*s<'0'||*s>'9')isDigital=0;
		else if(isDigital==0)//如果当前字符为数字且前一个字符不是数字
		{isDigital=1;
		num++;
		i++;//i为第i个数字字符串
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
	printf("这个字符串共有%d个整数,分别是:\n",num);
	for(i=0;i<num;i++)
		printf("%d\t",a[i]);
	putchar(10);
	return 0;
}

int char2int(char *p,int n)/*  将字符型数字窜转化成int型整数,p指向数字字符串
							起始地址,n为每个数字字符串的数字(0~9)个数  */
{
	int i,sum=0,e=1;
	for(i=n-1;i>=0;i--)
	{
		sum+=(*(p+i)-48)*e;//若某数字字符串为012306,转化后将第一个0省略,直到出现第一个不为0的数字
		e*=10;
	}
	return sum;
}


