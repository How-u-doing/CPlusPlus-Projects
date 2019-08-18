#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int date_count(int year,int month,int day)//�����Ǹ���ĵڼ���
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

int leap_year_tell(int year)//�ж��Ƿ�Ϊ���겢���ظ��������
{
	if((year%4==0&&year%100!=0)||(year%400==0))
		return 366;
	else return 365;
}

int rest(int year,int month,int day)//����ĳ��ʣ�¶�����(��������),����Ҫ��1
{
	return leap_year_tell(year)-date_count(year,month,day)+1;
}

int main()
{
	int year,month,day;
	int i,y,m,d,sum=0;//y>=year

	time_t rawtime;
	struct tm *timeinfo;
	time(&rawtime);
	timeinfo=localtime(&rawtime);
	year=timeinfo->tm_year+1900;
	month=timeinfo->tm_mon+1;
	day=timeinfo->tm_mday;//��ȡ��ǰʱ��

	printf("please input the particular future date you wanna inquiry(year month day):\n");
	scanf("%d%d%d",&y,&m,&d);
	if(y>year)
	{
		for(i=year+1;i<y;i++)//�����굽ָ����ǰһ��
		{	
			if(leap_year_tell(i)==366)
			sum=sum+366;
			else
			sum=sum+365;
		}	
		sum=sum+date_count(y,m,d)-1+rest(year,month,day);//δ�����겻������,-1
	}
	else//��Ϊ����δ����ĳ��
		sum=date_count(y,m,d)-date_count(year,month,day);

	printf("���������(%d.%d.%d)����%d��\n",year,month,day,sum);
	return 0;
}


		

