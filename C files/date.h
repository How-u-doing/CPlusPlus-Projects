#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int date_count(int year,int month,int day)//计算今天是今年的第几天
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

int leap_year_tell(int year)//判断是否为闰年并返回该年的天数
{
	if((year%4==0&&year%100!=0)||(year%400==0))
		return 366;
	else return 365;
}

int rest(int year,int month,int day)//计算某年剩下多少天(包括今天),所以要加1
{
	return leap_year_tell(year)-date_count(year,month,day)+1;
}

int countdown(int y,int m,int d)//计算未来某天距今还有多少天
{
	int year,month,day,i,sum=0;

	time_t rawtime;
	struct tm *timeinfo;
	time(&rawtime);
	timeinfo=localtime(&rawtime);
	year=timeinfo->tm_year+1900;
	month=timeinfo->tm_mon+1;
	day=timeinfo->tm_mday;//获取当前日期

	if(y>year)
	{
		for(i=year+1;i<y;i++)//从明年到指定年前一年
		{	
			if(leap_year_tell(i)==366)
			sum=sum+366;
			else
			sum=sum+365;
		}	
		sum=sum+date_count(y,m,d)-1+rest(year,month,day);//未来那年不算那天,-1
	}
	else//即为今年未来的某天
		sum=date_count(y,m,d)-date_count(year,month,day);
	return sum;	
}