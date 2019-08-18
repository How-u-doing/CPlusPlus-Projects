#include<stdio.h>
#include<stdlib.h>
#define N 5 
#define n 3
struct Stu
{
	int num;
	char name[10];
	float score[n];
	float aver;
}stud[N];
float aver(int k,float score[])
{
	int i;
	float sum=0;
	for(i=0;i<k;i++)
		sum=sum+score[i];
	return sum/k;
}

int main()
{
	float aver(int,float score[]);
	FILE *fp;
	int i;
	printf("please input data(student #,name,scores):\n");
	for(i=0;i<N;i++)
		scanf("%d%s%f%f%f",&stud[i].num,stud[i].name,&stud[i].score[0],&stud[i].score[1],&stud[i].score[2]);
	for(i=0;i<N;i++)
	{
		stud[i].aver=aver(n,stud[i].score);
		printf("%10s's average score is:%6.1f\n",stud[i].name,stud[i].aver);
	}

	if((fp=fopen("stu.dat","w"))==NULL)
	{
		printf("Error!Can't open this file.\n");
		exit(0);
	}
	fprintf(fp,"Student data:\n  #        name       scores        average \n");
	for(i=0;i<N;i++)
		fprintf(fp,"%5d%10s%6.1f%6.1f%6.1f%7.1f\n",stud[i].num,stud[i].name,stud[i].score[0], 
		stud[i].score[1],stud[i].score[2],stud[i].aver);
	fclose(fp);
	return 0;
}


	






