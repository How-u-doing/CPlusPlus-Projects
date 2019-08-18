#include<stdio.h>
int main()
{
	void count(int a[]);
	int a[10]={'T','@',' ','*','W','6','8','\0','q','x'};
	count(a);

	
	return 0;
}


void count(int a[])
{
	int i,digit=0,blank=0,letter=0,other=0;
	for(i=0;a[i]!='\0';i++)
	{
		if ((a[i]>='a'&&a[i]<='z')||(a[i]>='A'&&a[i]<='Z'))
		    letter ++;
		else if (a[i]>='0'&&a[i]<='9')
			digit ++;
		else if (a[i]==' ')
			blank++;
		else
		    other++;
	}
	printf("letter=%d,digit=%d,blank=%d,other=%d\n",letter,digit,blank,other);
}

