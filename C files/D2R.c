#include <stdio.h>
#define R 16			//2<=R<=16
char c[]="0123456789ABCDEF",a[20]="",*s=a;
int main()
{
	void D2R(unsigned int);
	unsigned n;
	char ch;
	printf("������һ������(С��2^32):\n");//����Ϊ����
	while(scanf("%d",&n)!=1)
	{printf("�������!����������һ������(С��2^32):\n");
	while((ch=getchar())!='\n');//�൱��fflush(stdin);
	}
    D2R(n);
	s=a;
	while(*s)
		printf("%c",*s++);
	putchar(10);
	return 0;
}

void D2R(unsigned int n)
{
	if(n/R)
		D2R(n/R);
	*s++=c[n%R];
}