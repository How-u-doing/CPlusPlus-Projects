#include<stdio.h>
int main()
{
	int i,n,m=0;
	for(n=1978;n<=2018;n++)//�ж�100-200������
	{for(i=2;i<=n/2;i++)//����i<=sqrt(n),ǰ�����#include<math,h>;ע��forǰ��Ļ����ŵ�λ��
	if(n%i==0)break;
	if(i>n/2){printf("%d\t",n);m++;if(m%10==0)printf("\n");}//m���ƻ��У�10��һ�У�
	}
		putchar('\n');
	return 0;
}