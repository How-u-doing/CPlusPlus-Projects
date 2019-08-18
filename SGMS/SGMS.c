#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <windows.h>
#include<math.h>
//#define NL printf("\n")
#define PS printf("*********************************************************************************************\n")
#define CLS system("cls")//�൱��DOS�е���Ļ����
#define M 3//MΪѧ������
#define N 50
typedef struct Student_data
{
	int num;
	char name[15];
	float score[M];//��ѧ,Ӣ��,�����
	float aver;
	float variance;//����
	short ranking;//ƽ��������
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
	printf("**********************************��ӭ����ѧ���ɼ�����ϵͳ***********************************\n");
	printf("					  �˵�\n");
	printf("			����ɼ�---------------------------------1\n");
	printf("			�鿴�ɼ����ɼ�����-----------------------2\n");
	printf("			��ѯѧ���ɼ�-----------------------------3\n");
	printf("			�ɼ�ͳ��---------------------------------4\n");
	printf("			�޸ĳɼ�---------------------------------5\n");
	printf("			��ӳɼ�---------------------------------6\n");
	printf("			ɾ���ɼ�---------------------------------7\n");
	printf("			����ɼ�������---------------------------8\n");
	printf("			�˳�ϵͳ---------------------------------9\n");
	PS;
	printf("����������ѡ��:");
	do
	{
		flag=1;
		fflush(stdin);//��while(getchar()!='\n');��ϸ΢��ͬ:���ʼ����'2',��getchar()����,�����scanf���ղ���,�����Բ���fflush,��while(getchar()!='\n');����scanf֮��,Ч��һ��
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
		default:flag=0;printf("�������!\n����������:");
		}
	}while(flag==0);
}

void input()
{
	int i=0;
	CLS;
	PS;
	printf("������ѧ����:ѧ�� ���� ��ѧ Ӣ�� �����(��ʾ:ѧ������-1��������)\n");
	scanf("%d",&stu[i].num);/*����һ������һ��,�����(����~�����)���ڼ��̻�����,�´�scanf��ȡ����ʱ�����ڼ���������
							  ����,�Զ��Ӽ��̻�������ȡ*/
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
	printf("�˴ι�������%d��ѧ��������\n",n);
	save();
}

void save()//�����ڴ��еĽṹ������stu�����ݵ�����
{
	short i,flag=1;
	char c;
	FILE *fp;
	if(n==0)
	{
		printf("��ѧ������,����¼��ѧ������!3���Ӻ��Զ��������˵�,���Ƚ���¼������\n");
		Sleep(3000);
		menu();
	}
	fflush(stdin);
	printf("�Ƿ񱣴�����������(y��,��������)\n");
	fflush(stdin);c=getchar();
	if(c=='y'||c=='Y')
	{
		char fileName[30];
		printf("Please input the file name that you wanna save: ");
		fflush(stdin);scanf("%s",fileName);

		if((fp=fopen(fileName,"wb"))==NULL)
		{
			printf("�ļ�%s��ʧ��\n",fileName);
			return;
		}
		for(i=0;i<n;i++)
			if(fwrite(&stu[i],sizeof(STU),1,fp)!=1)
			{
				printf("�ļ�����ʧ��!\n");
				flag=0;
			}
		if(flag==1)
			printf("����ɹ�!\n");
		fclose(fp);
	}
	PS;
	printf("�Ƿ񷵻����˵�������������(y��,�������˳�ϵͳ)\n");
	fflush(stdin);c=getchar();            
	if(c=='y'||c=='Y')
		menu();
	else exit(0);
}

void look()//��ʾ�����ڴ������е�����
{
	short i;
	char c;
	CLS;
	if(n==0)
	{
		printf("��ѧ������,����¼��ѧ������!3���Ӻ��Զ��������˵�,���Ƚ���¼������\n");
		Sleep(3000);
		menu();
	}
	stuaver_sort(n,stu);
	printf("***********************************ѧ���ɼ���************************************************\n");
	printf("����      ѧ��     ����     ��ѧ     Ӣ��    �����   ƽ����     ����\n");
	for(i=0;i<n;i++)  
	{
		printf("No.%-2d    ",stu[i].ranking);
		printf("%5d    %-10s%-9.1f%-9.1f%-9.1f%-7.1f  %-7.4f\n",stu[i].num,stu[i].name,
			stu[i].score[0],stu[i].score[1],stu[i].score[2],stu[i].aver,stu[i].variance);
	}
	PS;
	printf("�Ƿ񷵻����˵�������������(y��,�������˳�ϵͳ)\n");
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
		printf("�ļ�%s��������,3���Ӻ��Զ��������˵�,�����½�����������!\n",fileName);
		Sleep(3000);
		menu();
	}
	/* ע��:feof�ж��ļ�������ͨ����ȡ����fread/fscanf�ȷ��ش�����ʶ���,�ʶ��ж��ļ��Ƿ����
	Ӧ�����ڶ�ȡ����֮������ж�.����,��whileѭ����ȡһ���ļ�ʱ,������ڶ�ȡ����֮ǰ�����ж�,
	������ļ����һ���ǿհ���,���ܻ�����ڴ����.��������������ļ��нṹ��Ԫ�ظ���nʱ������
	while(feof(fp)==0)��Ϊѭ����ȡ����*/
	for(i=0,n=0;i<N;i++)
		if(fread(&stu[i],sizeof(STU),1,fp)!=1)
		{	
			if(feof(fp))
			{
				fclose(fp);
				break; //�˴���Ӧ��return,��Ϊ���к�������.��Ӧ��break����ѭ��,ֹͣ����
			}/*    ��û��break,�����ļ��нṹ��Ԫ�ظ���(��n)֮��,�ļ�λ�ñ�ʶ�����ļ�ĩβ,��i<N,��Ҫ����
			 ִ�в����ж��Ƿ�fread!=1,��Ȼfread!=1(���������),������ִ�йر��ļ�.��һ���ж��Ƿ�ѭ��,��
			 i<N�Գ���,��Ȼ����fread!=1,�����һֱִ�в���printf("��ȡ�ļ�%sʧ��\n",fileName);
			 �����ʵ������n==5,N==15,��ִ�б���"��ȡ�ļ�fileNameʧ��\n",����(N-n-1==9)��,����һ��
			 Ϊ�ر��ļ�����.*/
			 else 
			{
				printf("��ȡ�ļ�%sʧ��\n",fileName);//�������
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
		printf("��ѧ������,����¼��ѧ������!3���Ӻ��Զ��������˵�,���Ƚ���¼������\n");
		Sleep(3000);
		menu();
	}
	PS;
	printf("�����������ѯ��ѧ����ѧ��:(��ʾ:������ѯѧ������-1)\n");
	stunum_sort(n,stu);/*�Ƚ�ѧ����ѧ���ź���,���ö��ַ�����(����ѧ�������϶�����).��ʵ����,���ʼ����,
						����ѡ������ʱҪ�ж�����n*(n-1)/2��,�������漰���ܶ�ν���,��������δ����������
						ѡ��˳����Ҹ���*/
	fflush(stdin);scanf("%d",&k);
	while(k!=-1)
	{
		i=binarysearch(1,n,k,stu);
		if(i!=-1)
			{
				printf("����      ѧ��     ����     ��ѧ     Ӣ��    �����   ƽ����   ����\n");
				printf("No.%-2d    ",stu[i].ranking);
				printf("%5d    %-10s%-9.1f%-9.1f%-9.1f%-7.1f%-7.4f\n",stu[i].num,stu[i].name,
					stu[i].score[0],stu[i].score[1],stu[i].score[2],stu[i].aver,stu[i].variance);
			}
		else printf("��ѧ��%d��Ϣ!\n",k);	
		fflush(stdin);scanf("%d",&k);
	}
	printf("�Ƿ񷵻����˵�������������(y��,�������˳�ϵͳ)\n");
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
		printf("��ѧ������,����¼��ѧ������!3���Ӻ��Զ��������˵�,���Ƚ���¼������\n");
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
	printf("�ð����ƽ��������:\n");
	printf(" ��ѧ      Ӣ��      �����\n");
	printf("%5.1f   %7.1f   %7.1f\n",classaver[0],classaver[1],classaver[2]);
	printf("�ð���Ƴɼ���������:\n");
	printf(" ��ѧ      Ӣ��      �����\n");
	printf("%7.4f   %7.4f    %7.4f\n",classvari[0],classvari[1],classvari[2]);
	PS;
	printf("�ð��������,������ѧ��,������,������������:\n");
	printf("��ѧ:\n����ѧ��:\n");
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

		printf("ѧ��    ����    ��ѧ����   ��ѧ����    ������\n"); 
		for(i=0;i<n;i++)
			if(stu[i].score[0]>=90)
				printf("%d   %-10s%-8.1f   No.%-2d      No.%d\n",stu[i].num,stu[i].name,stu[i].score[0],a[i],stu[i].ranking);
		printf("��ѧ�ɼ������ѧ������%d��\n�ð���ѧ������Ϊ:%-6.2f%%\n",k,(float)k/n*100);
	}
	else
		printf("��\n");				
	printf("������ѧ��:\n"); 
	for(i=0,k=0;i<n;i++)
		if(stu[i].score[0]<60)
			k++;		
	if(k>=1) 
	{
		printf("ѧ��    ����    ��ѧ����   ��ѧ����    ������\n"); 
		for(i=0;i<n;i++)
			if(stu[i].score[0]<60)
				printf("%d   %-10s%-8.1f   No.%-2d      No.%d\n",stu[i].num,stu[i].name,stu[i].score[0],a[i],stu[i].ranking);
		printf("��ѧ�ɼ��������ѧ������%d��\n�ð���ѧ��������Ϊ:%-6.2f%%\n",k,(float)k/n*100);
	}
	else
		printf("��\n");
	PS;
	printf("Ӣ��:\n����ѧ��:\n");
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
		printf("ѧ��    ����    Ӣ�����   Ӣ������    ������\n");
		for(i=0;i<n;i++)	
			if(stu[i].score[1]>=90)
				printf("%d   %-10s%-8.1f   No.%-2d       No.%d\n",stu[i].num,stu[i].name,stu[i].score[1],a[i],stu[i].ranking);
		printf("Ӣ��ɼ������ѧ������%d��\n�ð�Ӣ��ѧ������Ϊ:%-6.2f%%\n",k,(float)k/n*100);
	}
	else
		printf("��\n");				
	printf("������ѧ��:\n");  
	for(i=0,k=0;i<n;i++)
		if(stu[i].score[1]<60)
			k++;	
	if(k>=1) 
	{
		printf("ѧ��    ����    Ӣ�����   Ӣ������    ������\n");
		for(i=0;i<n;i++)	
			if(stu[i].score[1]<60)
				printf("%d   %-10s%-8.1f   No.%-2d      No.%d\n",stu[i].num,stu[i].name,stu[i].score[1],a[i],stu[i].ranking);
		printf("Ӣ��ɼ��������ѧ������%d��\n�ð�Ӣ�ﲻ������Ϊ:%-6.2f%%\n",k,(float)k/n*100);
	}
	else
		printf("��\n");
	PS;
	printf("�����:\n����ѧ��:\n");
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
		printf("ѧ��    ����    ���������    ���������     ������\n");
		for(i=0;i<n;i++)
			if(stu[i].score[2]>=90)
				printf("%-8d%-10s%-15.1fNo.%-10dNo.%d\n",stu[i].num,stu[i].name,stu[i].score[2],a[i],stu[i].ranking);
		printf("������ɼ������ѧ������%d��\n�ð�����������Ϊ:%-6.2f%%\n",k,(float)k/n*100);
	}
	else
		printf("��\n");				
	printf("������ѧ��:\n");
	for(i=0,k=0;i<n;i++)
		if(stu[i].score[2]<60)
			k++;
	if(k>=1) 
	{
		printf("ѧ��    ����    ���������    ���������     ������\n"); 
		for(i=0;i<n;i++)
			if(stu[i].score[2]<60)
				printf("%-8d%-10s%-15.1fNo.%-10dNo.%d\n",stu[i].num,stu[i].name,stu[i].score[2],a[i],stu[i].ranking);
		printf("������ɼ��������ѧ������%d��\n�ð�������������Ϊ:%-6.2f%%\n",k,(float)k/n*100);
	}
	else
		printf("��\n");
	PS;
	printf("�Ƿ񷵻����˵�������������(y��,�������˳�ϵͳ)\n");
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
		printf("��ѧ������,����¼��ѧ������!3���Ӻ��Զ��������˵�,���Ƚ���¼������\n");
		Sleep(3000);
		menu();
	}
	PS;
	n1=n;//��ԭ��ѧ��������Ϊn1
	i=n;
	if(n<N){
	printf("�����������ѧ����:ѧ�� ���� ��ѧ Ӣ�� �����(��ʾ:ѧ������-1��������)\n");
	scanf("%d",&stu[i].num);
	while(stu[i].num!=-1&&i<N)
	{
		scanf("%s%f%f%f",stu[i].name,&stu[i].score[0],&stu[i].score[1],&stu[i].score[2]);
		i++;
		scanf("%d",&stu[i].num);
	}
	if(i>n){
	if(i==N)printf("ѧ�������Ѵ�����,�޷��ٽ������!\n");
	n=i;
	for(i=n1;i<n;i++)
	{
		stu[i].aver=aver(M,stu[i].score);
		stu[i].variance=vari(M,stu[i].score);
	}
	ranking(n,stu);
	printf("��������%d��ѧ��������,���ڹ���%d��ѧ������\n",n-n1,n);
	save();
	}
	}
	PS;
	printf("�Ƿ񷵻����˵�������������(y��,�������˳�ϵͳ)\n");
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
		printf("��ѧ������,����¼��ѧ������!3���Ӻ��Զ��������˵�,���Ƚ���¼������\n");
		Sleep(3000);
		menu();
	}
	PS;
	printf("������ϣ��ɾ����ѧ���ɼ�(����ѧ��,����-1��������)\n");
	scanf("%d",&t);
	while(t!=-1)
	{
		for(i=0;i<n;i++)
			if(t==stu[i].num)
			{a[j++]=i+1;//���ɾ�����ǵڼ���
			printf("����:%d  ѧ��:%d  ����:%s  ��ѧ:%4.1f  Ӣ��:%4.1f  �����:%4.1f  ƽ����:%4.1f ����:%4.1f\n",
				stu[i].ranking,stu[i].num,stu[i].name,stu[i].score[0],stu[i].score[1],stu[i].score[2],stu[i].aver,stu[i].variance);
			break;
			}					
		if(n==i) 
			printf("��ѧ��%d��Ϣ!\n",t);
		fflush(stdin);scanf("%d",&t);
	}
	if(j>0)
	{
		printf("�Ƿ�ɾ����%d��ѧ���ĳɼ�(y/n)\n",j);
		fflush(stdin);scanf("%c",&c);
		if(c=='y'||c=='Y')
		{for(i=0;i<j;i++,n--)//�ⲿ��Ҳ����ѡ���㷨:�Ѳ���Ҫɾ���ı���
			for(k=a[i]-1;k<n-1;k++)
				stu[k]=stu[k+1];
		ranking(n,stu);
		printf("ɾ���ɹ�!\n");
		save();
		}
		else printf("��ȡ��ɾ��!\n");
	}	
	PS;
	printf("�Ƿ񷵻����˵�������������(y��,�������˳�ϵͳ)\n");
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
		printf("��ѧ������,����¼��ѧ������!3���Ӻ��Զ��������˵�,���Ƚ���¼������\n");
		Sleep(3000);
		menu();
	}
	PS;
	printf("��������Ҫ�޸ĵ�ѧ���ɼ�:(����ѧ��,����-1��������);\n");
	fflush(stdin);scanf("%d",&k);
	while(k!=-1)
	{
		for(i=0;i<n;i++)
			if(k==stu[i].num)//һ��Ҫ��֤ѧ��(�ؼ���)��Ψһ��,��Ȼֻ��˳����������һ����ѧ����Ϣ
			{
				flag=1;
				printf("����:%d  ѧ��:%d  ����:%s  ��ѧ:%-4.1f  Ӣ��:%-4.1f  �����:%-4.1f  ƽ����:%-4.1f  ����:%-7.4f\n",
				stu[i].ranking,stu[i].num,stu[i].name,stu[i].score[0],stu[i].score[1],stu[i].score[2],stu[i].aver,stu[i].variance);
				printf("�Ƿ�ȷ���޸ĸ�ѧ����Ϣ(y/n)\n");
				fflush(stdin);scanf("%c",&c);
				if(c=='y'||c=='Y')
				{
					printf("�����������ѧ����Ϣ(ѧ�� ���� ��ѧ Ӣ�� �����):\n");
					scanf("%d%s%f%f%f",&stu[i].num,stu[i].name,&stu[i].score[0],&stu[i].score[1],&stu[i].score[2]);fflush(stdin);
					stu[i].aver=aver(M,stu[i].score);
					stu[i].variance=vari(M,stu[i].score);
					ranking(n,stu);
					printf("�޸ĳɹ�!\n");j++;//jΪ�޸ĳɹ�������
				}
				else printf("��ȡ���޸�!\n");
				break;
			}
		if(flag==0) printf("��ѧ��%d��Ϣ!\n",k);
		fflush(stdin);scanf("%d",&k);
	}
	if(j)save();
	PS;
	printf("�Ƿ񷵻����˵�������������(y��,�������˳�ϵͳ)\n");
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