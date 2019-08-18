#include<stdio.h>
int main()
{
	int s;
	printf("please enter score:");
	scanf("%d",&s);
	printf("The grade is:");
	if(s>=90)printf("A");
	else
		if(s>=80)printf("B");
	else
		if(s>=70)printf("C");
	else
		if(s>=60)printf("D");
	else printf("E");
	printf("\n");//putchar('\n')
	return 0;
}
