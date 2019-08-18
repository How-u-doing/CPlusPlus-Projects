// Common functions set

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
void selection_sort(int a[],int n)
{
	int i,j,k,t;
	for(i=0;i<n-1;i++)
	{k=i;
	for(j=i+1;j<n;j++)
			if(a[j]<a[k])
				k=j;
	if(k!=i)
	{t=a[k];a[k]=a[i];a[i]=t;}
	}
	/*for(i=0;i<n;i++)
		printf("%d ",a[i]);*/
}

void bubble_sort(int a[],int n)
{
	int i,j,t;
	for(j=0;j<n-1;j++)
		for(i=0;i<n-1-j;i++)
			if(a[i]>a[i+1])
			{t=a[i];a[i]=a[i+1];a[i+1]=t;}
	/*printf("the sorted numbers:\n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);*/
}

void stunum_sort(int n,struct Student_data *a)
{
	int i,j,k;
	struct Student_data t;
	for(i=0;i<n-1;i++)
	{
		k=i;
		for(j=i+1;j<n;j++)
			if((*(a+k)).num>(*(a+j)).num)
				k=j;
		if(k!=i)
		{t=*(a+i);*(a+i)=*(a+k);*(a+k)=t;}	
	}
	/*for(i=0;i<n;i++)
	{
		if((*(a+i+1)).aver==(*(a+i)).aver)
			if(strcmp((*(a+i+1)).name,(*(a+i)).name)<0)
			{t=*(a+i);*(a+i)=*(a+i+1);*(a+i+1)=t;}
	}*/
}
int binarysearch(int from,int to,int key,struct Student_data *a)
{
	int front=from-1,back=to-1,mid;
	while(front<=back)
	{
		mid=(front+back)/2;
		if(a[mid].num==key)
			return mid;
		if(a[mid].num>key)
			back=mid-1;
		else
			front=mid+1;
	}
	return -1;
}

void horizontal_transform(int orig[],int h,int w,int save[])
{
	int i,j,t;
	for(i=0;i<h;i++)
		for(j=0;j<w/2;j++)
		{t=orig[i*w+j];orig[i*w+j]=orig[i*w+w-1-j];orig[i*w+w-1-j]=t;}
	for(i=0;i<w*h;i++)
		save[i]=orig[i];
}

void vertical_transform(int orig[],int h,int w,int save[])
{
	int i,j,t;
	for(j=0;j<w;j++)
		for(i=0;i<h/2;i++)
		{t=orig[i*w+j];orig[i*w+j]=orig[(h-1-i)*w+j];orig[(h-1-i)*w+j]=t;}
	for(i=0;i<w*h;i++)
		save[i]=orig[i];
}

float aver(int k,float s[])
{
	int i;
	float sum=0;
	for(i=0;i<k;i++)
		sum=sum+s[i];
	return sum/k;
}

float variance(int n,float a[])
{
	int i;
	float t=aver(n,a),s=0;
	for(i=0;i<n;i++)
		s+=(a[i]-t)*(a[i]-t);
	return sqrt(s/n);
}

void print_factors(int x)
{
	int i;
	double k;
	k=sqrt(x);
	for(i=1;i<=k;i++)
	if(x%i==0)
		printf("%d,",i);
	printf("\b.");
}

int fac(int n)
{
	int f;
	if(n<0)
		printf("n<0,data error!");
	else if(n==0||n==1)
		f=1;
	else f=fac(n-1)*n;
	return f;
}

int char_int(char *p,int n)/*  将字符型数字窜转化成int型整数,p指向数字字符串
			     起始地址,n为每个数字字符串的数字(0~9)个数  */
{
	int i,sum=0,e=1;
	for(i=n-1;i>=0;i--)
	{
		sum+=(*(p+i)-48)*e;
		e*=10;
	}
	return sum;
}

void count_char(char a[])
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

int count_words(char *c)
{
	int num=0,word=0;
	for(;*c!='\0';c++)
	{
		if(*c<'A'||*c>'z')
			word=0;
		else if(word==0)
		{word=1;
		num++;
		}
	}
	return num;
}

int count_number(char *s)
{
	int num=0,flag=0;
	for(;*s!='\0';s++)
	{
		if(*s<'0'||*s>'9')flag=0;
		else if(flag==0)
		{flag=1;
		num++;
		//if(num>1)putchar(10);
		}
		//if(flag==1)putchar(*s);
	}
	return num;
}

void delete_string(char *a,char x)
{
	int i,j;
	for(i=0,j=0;*(a+i)!='\0';i++)
		if(*(a+i)!=x)
			*(a+j++)=*(a+i);
		*(a+j)='\0';
}

void copy_string(char *s,char *t)
{
	while(*s++=*t++);
}

void strlink(char *s,char *t)
{
	while(*s++);
	s--;        
	while(*s++=*t++);
}

void string_n_copy(char *s,int n,char *t)
{
	int i=0;
	while(i++<n)
		*s++=*t++;
	*s='\0';
}

void transposed_string(char *s)
{
	int i,n=0;
	char *t;
	while(*s++)/*注意:是先判断,然后马上s++,再执行下面的循环体,容易出处,所以最好用for或者在循环体中实现自增*/
		n++;
	s-=2;
	t=s;
	for(i=0;i<n;i++)
		printf("%c",*t--);
	putchar(10);
}

int string_compare(char *p1,char *p2)
{
	for(;*p1!='\0'&&*p2!='\0';p1++,p2++)
		if(*p1!=*p2)
		{	printf("%c  %c\n",*p1,*p2);
			return *p1-*p2;
		}
	if(*p1==*p2)//p1,p2同时指向'\0'
		return 0;
	else if(*p1>*p2)//p2指向'\0',p1还未指向'\0'
		return *p1;
	else return -*p2;
}

void tell_prime(int n)
{
	int i;
	for(i=2;i<=n/2;i++)
	if(n%i==0)break;
	if(i>n/2)printf("%d is a prime number",n);
		else printf("%d isn't a prime number and i=%d",n,i);
		putchar('\n');
}

void print_prime(int x,int y)
{
	int i,j;
	printf("The prime numbers range from %d to %d are as follows:\n",x,y);
	for(j=x;j<=y;j++)
	{
		for(i=2;i<=j/2;i++)
	if(j%i==0)break;
	if(i>j/2)
		printf("%d ",j);
	}
}

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

void tell_saddle_point(int a[][4],int m,int n)//调用一个二维数组,但只用到m*n的矩阵(n<=4)
{
	int i,j,max_row,row,colum,k,t,flag=0;
	char *format="This array has saddle point:a[%d][%d]=%d\n";//或者用char format[]="..."
	for(i=0;i<m;i++)
	{
		max_row=a[i][0];
		for(j=1;j<n;j++)
			if(max_row<a[i][j])
			{max_row=a[i][j];
			row=i;
			colum=j;
			}
		for(k=0,t=0;k<m;k++)
			if(max_row<=a[k][colum])
				t++;
		if(t==m)
			{flag=1;
			break;
			}
	}
	if(flag==1)
		printf(format,row,colum,a[row][colum]);//可变格式输出函数
	else printf("This array doesn't have sadddle point!\n");
}

void D_R(unsigned int n,int R)
{
	if(n/R)
		D_R(n/R);
	*s++=c[n%R];//其中c[]="0123456789ABCDEF",s,c[i]为全局变量
}