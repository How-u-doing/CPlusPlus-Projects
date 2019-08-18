#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <windows.h>
#include<math.h>
//#define NL printf("\n")
#define PS printf("*********************************************************************************************\n")
#define CLS system("cls")//相当于DOS中的屏幕清理
#define M 3//M为学科项数
#define N 50
typedef struct Student_data
{
	int num;
	char name[15];
	float score[M];//数学,英语,计算机
	float aver;
	float variance;//方差
	short ranking;//平均分排名
}STU;
STU stu[N];
int n=0;
void menu();
void input();
void save();
void modify();
void look();
void inquiry_score();
void statistic();
void add();
void dele();
float vari(int k,float a[]);
float aver(int k,float a[]);
void stuaver_sort(int m,STU *a);
void stumath_sort(int m,STU *a);
void stuEngl_sort(int m,STU *a);
void stucomp_sort(int m,STU *a);
int binarysearch(int from,int to,int key,STU *a);
void stunum_sort(int n,STU *a);
void ranking(int n,STU *a);
void Read();

int main()
{
	Read();
	menu();
	return 0;
}

void menu()
{
	short flag;
	char c;
	CLS;
	printf("**********************************欢迎来到学生成绩管理系统***********************************\n");
	printf("					  菜单\n");
	printf("			输入成绩---------------------------------1\n");
	printf("			查看成绩及成绩排序-----------------------2\n");
	printf("			查询学生成绩-----------------------------3\n");
	printf("			成绩统计---------------------------------4\n");
	printf("			修改成绩---------------------------------5\n");
	printf("			添加成绩---------------------------------6\n");
	printf("			删除成绩---------------------------------7\n");
	printf("			保存成绩至磁盘---------------------------8\n");
	printf("			退出系统---------------------------------9\n");
	PS;
	printf("请输入您的选择:");
	do
	{
		flag=1;
		fflush(stdin);//与while(getchar()!='\n');有细微不同:若最开始输入'2',被getchar()吸收,下面的scanf接收不到,但可以不用fflush,把while(getchar()!='\n');用在scanf之后,效果一样
		scanf("%c",&c);
		switch(c)
		{
		case '1':input();break;
		case '2':look();break;
		case '3':inquiry_score();break;
		case '4':statistic();break;
		case '5':modify();break;
		case '6':add();break;
		case '7':dele();break;
		case '8':save();break;
		case '9':exit(0);
		default:flag=0;printf("输入错误!\n请重新输入:");
		}
	}while(flag==0);
}

void input()
{
	int i=0;
	CLS;
	PS;
	printf("请输入学生的:学号 姓名 数学 英语 计算机(提示:学号输入-1结束输入)\n");
	scanf("%d",&stu[i].num);/*可以一次输入一排,多余的(姓名~计算机)放在键盘缓冲区,下次scanf读取数据时不必在键盘上输入
							  数据,自动从键盘缓冲区读取*/
	while(stu[i].num!=-1)
	{
		scanf("%s%f%f%f",stu[i].name,&stu[i].score[0],&stu[i].score[1],&stu[i].score[2]);
		i++;
		scanf("%d",&stu[i].num);
	}
	n=i;
	for(i=0;i<n;i++)
	{
		stu[i].aver=aver(M,stu[i].score);
		stu[i].variance=vari(M,stu[i].score);
	}
	ranking(n,stu);
	PS;
	printf("此次共输入了%d个学生的数据\n",n);
	save();
}

void save()//保存内存中的结构体数组stu的数据到磁盘
{
	short i,flag=1;
	char c;
	FILE *fp;
	if(n==0)
	{
		printf("无学生数据,请先录入学生数据!3秒钟后将自动进入主菜单,可先进行录入数据\n");
		Sleep(3000);
		menu();
	}
	fflush(stdin);
	printf("是否保存数据至磁盘(y是,其它键否)\n");
	fflush(stdin);c=getchar();
	if(c=='y'||c=='Y')
	{
		char fileName[30];
		printf("Please input the file name that you wanna save: ");
		fflush(stdin);scanf("%s",fileName);

		if((fp=fopen(fileName,"wb"))==NULL)
		{
			printf("文件%s打开失败\n",fileName);
			return;
		}
		for(i=0;i<n;i++)
			if(fwrite(&stu[i],sizeof(STU),1,fp)!=1)
			{
				printf("文件保存失败!\n");
				flag=0;
			}
		if(flag==1)
			printf("保存成功!\n");
		fclose(fp);
	}
	PS;
	printf("是否返回主菜单进行其它操作(y是,其它键退出系统)\n");
	fflush(stdin);c=getchar();            
	if(c=='y'||c=='Y')
		menu();
	else exit(0);
}

void look()//显示的是内存中已有的数据
{
	short i;
	char c;
	CLS;
	if(n==0)
	{
		printf("无学生数据,请先录入学生数据!3秒钟后将自动进入主菜单,可先进行录入数据\n");
		Sleep(3000);
		menu();
	}
	stuaver_sort(n,stu);
	printf("***********************************学生成绩表************************************************\n");
	printf("名次      学号     姓名     数学     英语    计算机   平均分     方差\n");
	for(i=0;i<n;i++)  
	{
		printf("No.%-2d    ",stu[i].ranking);
		printf("%5d    %-10s%-9.1f%-9.1f%-9.1f%-7.1f  %-7.4f\n",stu[i].num,stu[i].name,
			stu[i].score[0],stu[i].score[1],stu[i].score[2],stu[i].aver,stu[i].variance);
	}
	PS;
	printf("是否返回主菜单进行其它操作(y是,其它键退出系统)\n");
	fflush(stdin);scanf("%c",&c);
	if(c=='y'||c=='Y')
		menu();
	else exit(0);
}

void Read()
{
	int i;
	FILE *fp;
	char fileName[30];
	printf("Please input the file name that you wanna upload:\n");
	fflush(stdin);scanf("%s",fileName);//Here I provide "student.dat" in current file holder
	if((fp=fopen(fileName,"rb"))==NULL)
	{
		printf("文件%s暂无数据,3秒钟后将自动进入主菜单,可重新进行输入数据!\n",fileName);
		Sleep(3000);
		menu();
	}
	/* 注意:feof判断文件结束是通过读取函数fread/fscanf等返回错误来识别的,故而判断文件是否结束
	应该是在读取函数之后进行判断.比如,在while循环读取一个文件时,如果是在读取函数之前进行判断,
	则如果文件最后一行是空白行,可能会造成内存错误.所以下面求磁盘文件中结构体元素个数n时不能用
	while(feof(fp)==0)作为循环读取条件*/
	for(i=0,n=0;i<N;i++)
		if(fread(&stu[i],sizeof(STU),1,fp)!=1)
		{	
			if(feof(fp))
			{
				fclose(fp);
				break; //此处不应是return,因为还有后续操作.故应用break打破循环,停止读入
			}/*    若没有break,读完文件中结构体元素个数(即n)之后,文件位置标识移至文件末尾,若i<N,还要继续
			 执行操作判断是否fread!=1,显然fread!=1(即错误读入),紧接着执行关闭文件.下一次判断是否循环,若
			 i<N仍成立,显然亦有fread!=1,后面就一直执行操作printf("读取文件%s失败\n",fileName);
			 因此若实际数据n==5,N==15,会执行报错"读取文件fileName失败\n",操作(N-n-1==9)次,其中一次
			 为关闭文件操作.*/
			 else 
			{
				printf("读取文件%s失败\n",fileName);//读入错误
				fclose(fp);
			}
		}
		else n++;
}

void inquiry_score()
{
	int i,k;
	char c;
	CLS;
	if(n==0)
	{
		printf("无学生数据,请先录入学生数据!3秒钟后将自动进入主菜单,可先进行录入数据\n");
		Sleep(3000);
		menu();
	}
	PS;
	printf("请输入您想查询的学生的学号:(提示:结束查询学号输入-1)\n");
	stunum_sort(n,stu);/*先将学生按学号排好序,再用二分法查找(用于学生人数较多的情况).但实际上,若最开始无序,
						再用选择排序法时要判断至少n*(n-1)/2次,还可能涉及到很多次交换,故在事先未排序的情况下
						选择顺序查找更快*/
	fflush(stdin);scanf("%d",&k);
	while(k!=-1)
	{
		i=binarysearch(1,n,k,stu);
		if(i!=-1)
			{
				printf("名次      学号     姓名     数学     英语    计算机   平均分   方差\n");
				printf("No.%-2d    ",stu[i].ranking);
				printf("%5d    %-10s%-9.1f%-9.1f%-9.1f%-7.1f%-7.4f\n",stu[i].num,stu[i].name,
					stu[i].score[0],stu[i].score[1],stu[i].score[2],stu[i].aver,stu[i].variance);
			}
		else printf("无学生%d信息!\n",k);	
		fflush(stdin);scanf("%d",&k);
	}
	printf("是否返回主菜单进行其它操作(y是,其它键退出系统)\n");
	fflush(stdin);scanf("%c",&c);
	if(c=='y'||c=='Y')
	menu();
	else exit(0);
}

void statistic()
{
	short i,j,k,a[N];
	char c;
	float classaver[M],sum[M]={0},classvari[M],V[M]={0};
	CLS;
	if(n==0)
	{
		printf("无学生数据,请先录入学生数据!3秒钟后将自动进入主菜单,可先进行录入数据\n");
		Sleep(3000);
		menu();
	}
	PS;
	for(j=0;j<M;j++)
	{
		for(i=0;i<n;i++)
			sum[j]+=stu[i].score[j];
		classaver[j]=sum[j]/n;
		for(i=0;i<n;i++)
			V[j]+=(stu[i].score[j]-classaver[j])*(stu[i].score[j]-classaver[j]);
		classvari[j]=sqrt(V[j]/n);
	}
	printf("该班各科平均分如下:\n");
	printf(" 数学      英语      计算机\n");
	printf("%5.1f   %7.1f   %7.1f\n",classaver[0],classaver[1],classaver[2]);
	printf("该班各科成绩方差如下:\n");
	printf(" 数学      英语      计算机\n");
	printf("%7.4f   %7.4f    %7.4f\n",classvari[0],classvari[1],classvari[2]);
	PS;
	printf("该班各科优秀,不及格学生,优秀率,不及格率如下:\n");
	printf("数学:\n优秀学生:\n");
	stumath_sort(n,stu);
	for(i=0;i<n;i++)
	{
		a[i]=1;
		for(j=0;j<n;j++)
			if(stu[j].score[0]>stu[i].score[0])
				a[i]++;
	}
	for(i=0,k=0;i<n;i++)
		if(stu[i].score[0]>=90)
			k++;
	if(k>=1) 
	{

		printf("学号    姓名    数学分数   数学排名    总排名\n"); 
		for(i=0;i<n;i++)
			if(stu[i].score[0]>=90)
				printf("%d   %-10s%-8.1f   No.%-2d      No.%d\n",stu[i].num,stu[i].name,stu[i].score[0],a[i],stu[i].ranking);
		printf("数学成绩优秀的学生共有%d个\n该班数学优秀率为:%-6.2f%%\n",k,(float)k/n*100);
	}
	else
		printf("无\n");				
	printf("不及格学生:\n"); 
	for(i=0,k=0;i<n;i++)
		if(stu[i].score[0]<60)
			k++;		
	if(k>=1) 
	{
		printf("学号    姓名    数学分数   数学排名    总排名\n"); 
		for(i=0;i<n;i++)
			if(stu[i].score[0]<60)
				printf("%d   %-10s%-8.1f   No.%-2d      No.%d\n",stu[i].num,stu[i].name,stu[i].score[0],a[i],stu[i].ranking);
		printf("数学成绩不及格的学生共有%d个\n该班数学不及格率为:%-6.2f%%\n",k,(float)k/n*100);
	}
	else
		printf("无\n");
	PS;
	printf("英语:\n优秀学生:\n");
	stuEngl_sort(n,stu);
	for(i=0;i<n;i++)
	{
		a[i]=1;
		for(j=0;j<n;j++)
			if(stu[j].score[1]>stu[i].score[1])
				a[i]++;
	}
	for(i=0,k=0;i<n;i++)
		if(stu[i].score[1]>=90)			
			k++;
	if(k>=1) 
	{
		printf("学号    姓名    英语分数   英语排名    总排名\n");
		for(i=0;i<n;i++)	
			if(stu[i].score[1]>=90)
				printf("%d   %-10s%-8.1f   No.%-2d       No.%d\n",stu[i].num,stu[i].name,stu[i].score[1],a[i],stu[i].ranking);
		printf("英语成绩优秀的学生共有%d个\n该班英语学优秀率为:%-6.2f%%\n",k,(float)k/n*100);
	}
	else
		printf("无\n");				
	printf("不及格学生:\n");  
	for(i=0,k=0;i<n;i++)
		if(stu[i].score[1]<60)
			k++;	
	if(k>=1) 
	{
		printf("学号    姓名    英语分数   英语排名    总排名\n");
		for(i=0;i<n;i++)	
			if(stu[i].score[1]<60)
				printf("%d   %-10s%-8.1f   No.%-2d      No.%d\n",stu[i].num,stu[i].name,stu[i].score[1],a[i],stu[i].ranking);
		printf("英语成绩不及格的学生共有%d个\n该班英语不及格率为:%-6.2f%%\n",k,(float)k/n*100);
	}
	else
		printf("无\n");
	PS;
	printf("计算机:\n优秀学生:\n");
	stucomp_sort(n,stu);
	for(i=0;i<n;i++)
	{
		a[i]=1;
		for(j=0;j<n;j++)
			if(stu[j].score[2]>stu[i].score[2])
				a[i]++;
	}
	for(i=0,k=0;i<n;i++)
		if(stu[i].score[2]>=90)	
			k++;
	if(k>=1) 
	{
		printf("学号    姓名    计算机分数    计算机排名     总排名\n");
		for(i=0;i<n;i++)
			if(stu[i].score[2]>=90)
				printf("%-8d%-10s%-15.1fNo.%-10dNo.%d\n",stu[i].num,stu[i].name,stu[i].score[2],a[i],stu[i].ranking);
		printf("计算机成绩优秀的学生共有%d个\n该班计算机优秀率为:%-6.2f%%\n",k,(float)k/n*100);
	}
	else
		printf("无\n");				
	printf("不及格学生:\n");
	for(i=0,k=0;i<n;i++)
		if(stu[i].score[2]<60)
			k++;
	if(k>=1) 
	{
		printf("学号    姓名    计算机分数    计算机排名     总排名\n"); 
		for(i=0;i<n;i++)
			if(stu[i].score[2]<60)
				printf("%-8d%-10s%-15.1fNo.%-10dNo.%d\n",stu[i].num,stu[i].name,stu[i].score[2],a[i],stu[i].ranking);
		printf("计算机成绩不及格的学生共有%d个\n该班计算机不及格率为:%-6.2f%%\n",k,(float)k/n*100);
	}
	else
		printf("无\n");
	PS;
	printf("是否返回主菜单进行其它操作(y是,其它键退出系统)\n");
	fflush(stdin);scanf("%c",&c);
	if(c=='y'||c=='Y')
	menu();
	else exit(0);
}


void add()
{
	int i,n1;
	char c;
	CLS;
	if(n==0)
	{
		printf("无学生数据,请先录入学生数据!3秒钟后将自动进入主菜单,可先进行录入数据\n");
		Sleep(3000);
		menu();
	}
	PS;
	n1=n;//将原有学生个数记为n1
	i=n;
	if(n<N){
	printf("请输入新添加学生的:学号 姓名 数学 英语 计算机(提示:学号输入-1结束输入)\n");
	scanf("%d",&stu[i].num);
	while(stu[i].num!=-1&&i<N)
	{
		scanf("%s%f%f%f",stu[i].name,&stu[i].score[0],&stu[i].score[1],&stu[i].score[2]);
		i++;
		scanf("%d",&stu[i].num);
	}
	if(i>n){
	if(i==N)printf("学生人数已达上限,无法再进行添加!\n");
	n=i;
	for(i=n1;i<n;i++)
	{
		stu[i].aver=aver(M,stu[i].score);
		stu[i].variance=vari(M,stu[i].score);
	}
	ranking(n,stu);
	printf("新输入了%d个学生的数据,现在共有%d个学生数据\n",n-n1,n);
	save();
	}
	}
	PS;
	printf("是否返回主菜单进行其它操作(y是,其它键退出系统)\n");
	fflush(stdin);scanf("%c",&c);
	if(c=='y'||c=='Y')
		menu();
	else exit(0);
}

void dele()
{
	int i,t,k,j=0,a[N];
	char c;
	CLS;
	if(n==0)
	{
		printf("无学生数据,请先录入学生数据!3秒钟后将自动进入主菜单,可先进行录入数据\n");
		Sleep(3000);
		menu();
	}
	PS;
	printf("请输入希望删除的学生成绩(输入学号,输入-1结束输入)\n");
	scanf("%d",&t);
	while(t!=-1)
	{
		for(i=0;i<n;i++)
			if(t==stu[i].num)
			{a[j++]=i+1;//标记删除的是第几名
			printf("名次:%d  学号:%d  姓名:%s  数学:%4.1f  英语:%4.1f  计算机:%4.1f  平均分:%4.1f 方差:%4.1f\n",
				stu[i].ranking,stu[i].num,stu[i].name,stu[i].score[0],stu[i].score[1],stu[i].score[2],stu[i].aver,stu[i].variance);
			break;
			}					
		if(n==i) 
			printf("无学生%d信息!\n",t);
		fflush(stdin);scanf("%d",&t);
	}
	if(j>0)
	{
		printf("是否删除这%d个学生的成绩(y/n)\n",j);
		fflush(stdin);scanf("%c",&c);
		if(c=='y'||c=='Y')
		{for(i=0;i<j;i++,n--)//这部分也可以选择算法:把不需要删除的保留
			for(k=a[i]-1;k<n-1;k++)
				stu[k]=stu[k+1];
		ranking(n,stu);
		printf("删除成功!\n");
		save();
		}
		else printf("已取消删除!\n");
	}	
	PS;
	printf("是否返回主菜单进行其它操作(y是,其它键退出系统)\n");
	fflush(stdin);scanf("%c",&c);
	if(c=='y'||c=='Y')
		menu();
	else exit(0);
}

void modify()
{
	int i,j=0,k,flag=0;
	char c;
	CLS;
	if(n==0)
	{
		printf("无学生数据,请先录入学生数据!3秒钟后将自动进入主菜单,可先进行录入数据\n");
		Sleep(3000);
		menu();
	}
	PS;
	printf("请输入需要修改的学生成绩:(输入学号,输入-1结束输入);\n");
	fflush(stdin);scanf("%d",&k);
	while(k!=-1)
	{
		for(i=0;i<n;i++)
			if(k==stu[i].num)//一定要保证学号(关键字)的唯一性,不然只能顺序搜索到第一个该学号信息
			{
				flag=1;
				printf("名次:%d  学号:%d  姓名:%s  数学:%-4.1f  英语:%-4.1f  计算机:%-4.1f  平均分:%-4.1f  方差:%-7.4f\n",
				stu[i].ranking,stu[i].num,stu[i].name,stu[i].score[0],stu[i].score[1],stu[i].score[2],stu[i].aver,stu[i].variance);
				printf("是否确认修改该学生信息(y/n)\n");
				fflush(stdin);scanf("%c",&c);
				if(c=='y'||c=='Y')
				{
					printf("请重新输入该学生信息(学号 姓名 数学 英语 计算机):\n");
					scanf("%d%s%f%f%f",&stu[i].num,stu[i].name,&stu[i].score[0],&stu[i].score[1],&stu[i].score[2]);fflush(stdin);
					stu[i].aver=aver(M,stu[i].score);
					stu[i].variance=vari(M,stu[i].score);
					ranking(n,stu);
					printf("修改成功!\n");j++;//j为修改成功的人数
				}
				else printf("已取消修改!\n");
				break;
			}
		if(flag==0) printf("无学生%d信息!\n",k);
		fflush(stdin);scanf("%d",&k);
	}
	if(j)save();
	PS;
	printf("是否返回主菜单进行其它操作(y是,其它键退出系统)\n");
	fflush(stdin);scanf("%c",&c);
	if(c=='y'||c=='Y')
		menu();
	else exit(0);
}

float aver(int n,float s[])
{
	int i;
	float sum=0;
	for(i=0;i<n;i++)
		sum=sum+s[i];
	return sum/n;
}

float vari(int n,float a[])
{
	int i;
	float t=aver(n,a),s=0;
	for(i=0;i<n;i++)
		s+=(a[i]-t)*(a[i]-t);
	return sqrt(s/n);
}


void ranking(int n,STU *a)
{
	int i,j;
	for(i=0;i<n;i++)
	{stu[i].ranking=1;
	for(j=0;j<n;j++)
	if(stu[j].aver>stu[i].aver)
	stu[i].ranking++;
	}
}

void stuaver_sort(int n,struct Student_data *a)
{
	int i,j,k;
	STU t;
	for(i=0;i<n-1;i++)
	{
		k=i;
		for(j=i+1;j<n;j++)
			if((a+k)->aver<(a+j)->aver||(((a+k)->aver==(a+j)->aver)&&strcmp((a+k)->name,(a+j)->name)>0))
				k=j;
		if(k!=i)
		{t=*(a+i);*(a+i)=*(a+k);*(a+k)=t;}	
	}
	
}

void stumath_sort(int n,struct Student_data *a)
{
	int i,j,k;
	struct Student_data t;
	for(i=0;i<n-1;i++)
	{
		k=i;
		for(j=i+1;j<n;j++)
			if((a+k)->score[0]<(a+j)->score[0]||(((a+k)->score[0]==(a+j)->score[0])&&strcmp((a+k)->name,(a+j)->name)>0))
				k=j;
		if(k!=i)
		{t=*(a+i);*(a+i)=*(a+k);*(a+k)=t;}	
	}
}
void stuEngl_sort(int n,struct Student_data *a)
{
	int i,j,k;
	struct Student_data t;
	for(i=0;i<n-1;i++)
	{
		k=i;
		for(j=i+1;j<n;j++)
			if((a+k)->score[1]<(a+j)->score[1]||(((a+k)->score[1]==(a+j)->score[1])&&strcmp((a+k)->name,(a+j)->name)>0))
				k=j;
		if(k!=i)
		{t=*(a+i);*(a+i)=*(a+k);*(a+k)=t;}	
	}
}
void stucomp_sort(int n,struct Student_data *a)
{
	int i,j,k;
	struct Student_data t;
	for(i=0;i<n-1;i++)
	{
		k=i;
		for(j=i+1;j<n;j++)
			if((a+k)->score[2]<(a+j)->score[2]||(((a+k)->score[2]==(a+j)->score[2])&&strcmp((a+k)->name,(a+j)->name)>0))
				k=j;
		if(k!=i)
		{t=*(a+i);*(a+i)=*(a+k);*(a+k)=t;}	
	}
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
}
int binarysearch(int from,int to,int key,struct Student_data *a)
{
	int front=from-1,back=to-1,mid;
	while(front<=back)
	{		mid=(front+back)/2;
		if(a[mid].num==key)
			return mid;
		if(a[mid].num>key)
			back=mid-1;
		else
			front=mid+1;
	}
	return -1;
}