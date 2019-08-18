#include<stdio.h>
int main()
{
	int num=0,word=0;
	char a[50],*c=a;
	gets(a);
	for(;*c!='\0';c++)
	{
		if(*c<'A'||*c>'z')
			word=0;
		else if(word==0)
		{word=1;
		num++;
		}
	}
	printf("There are totally %d words in this line.\n",num);
	return 0;
}

