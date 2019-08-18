#include<stdio.h>
#include<string.h>
int main()
{
	int i,j;
	struct Person
	{char name[20];
	int count;
	}candidate[3]={"Alice",0,"Tom",0,"Jack",0};
	char candidate_name[20];
	for(i=1;i<=10;i++)
	{
		gets(candidate_name);
		for(j=0;j<3;j++)
			if(strcmp(candidate_name,candidate[j].name)==0)
				candidate[j].count++;
	}
	printf("\nResult:\n");
	for(i=0;i<3;i++)
		printf("%5s:%d\n",candidate[i].name,candidate[i].count);
	return 0;
}
