#include<stdio.h>
int main()
{
	int i,j;
	 char a[50],b[50],ch;
	 gets(a);
	 printf("The character you wanna delete is:");
	 scanf("%c",&ch);
	 for(i=0,j=0;a[i]!='\0';i++)
		 if(a[i]!=ch)
		 {b[j]=a[i];
		 j++;
		 }//也可以只用一个数组a[],a[j++]=a[i];(j++为先使用j的值再加1)
		 b[j]='\0';
		 puts(b);
		 return 0;
}