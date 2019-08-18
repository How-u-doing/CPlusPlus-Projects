#include<stdio.h>
int main()
{
	int y,m,d;
	int date_count(int,int,int);
	printf("please enter date:");
	scanf("%d.%d.%d",&y,&m,&d);
	printf("It's the No.%d day of this year.\n",date_count(y,m,d));
	return 0;
}

int date_count(int year,int month,int day)
{
	int i,sum;
	int m[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	if((year%4==0&&year%100!=0)||(year%400==0))
		m[1]=29;
	for(i=0,sum=0;i<month-1;i++)
		sum=sum+m[i];
	sum=sum+day;
	return sum;
}


	