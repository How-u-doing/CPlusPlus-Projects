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

int main()
{
	void stu_sort(int m,struct Stu *a);
	float aver(int k,float score[]);
	FILE *fp;
	struct Stu *p=stud;
	int i=0;
	if((fp=fopen("stud.dat","r"))==NULL)
	{
		printf("Error!Can't open this file.\n");
		exit(0);
	}
	for(i=0;i<N;i++)
		fscanf(fp,"%d%s%f%f%f%f",&stud[i].num,stud[i].name,&stud[i].score[0], 
		&stud[i].score[1],&stud[i].score[2],&stud[i].aver);
	fclose(fp);

	if((fp=fopen("stu_sort.dat","w"))==NULL)
	{
		printf("Error!Can't open this file.\n");
		exit(0);
	}
	for(i=0;i<N;i++)
	{
		stud[i].aver=aver(n,stud[i].score);
		printf("%s's average score is:%6.1f\n",stud[i].name,stud[i].aver);
	}
	printf("The sorted scores are as follow:\n");
	stu_sort(N,p);

	fprintf(fp,"Student data:\nranking  #        name       scores        average \n");
	for(i=0;i<N;i++)
		fprintf(fp,"No.%d:  %5d%10s%6.1f%6.1f%6.1f%7.1f\n",i+1,stud[i].num,
		stud[i].name,stud[i].score[0],stud[i].score[1],stud[i].score[2],stud[i].aver);
	fclose(fp);
	return 0;
}

float aver(int k,float score[])
{
	int i;
	float sum=0;
	for(i=0;i<k;i++)
		sum=sum+score[i];
	return sum/k;
}

void stu_sort(int m,struct Stu *a)
{
	int i,j,k;
	struct Stu t;
	for(i=0;i<m-1;i++)
	{
		k=i;
		for(j=i+1;j<m;j++)
			if((*(a+k)).aver<(*(a+j)).aver)
				k=j;
		if(k!=i)
		{t=*(a+i);*(a+i)=*(a+k);*(a+k)=t;}	
	}
	for(i=0;i<m;i++)
		printf("%6.1f\n",(*(a+i)).aver);
}



	






