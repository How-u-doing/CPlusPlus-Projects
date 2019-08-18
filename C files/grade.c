#include<stdio.h>
int main()
{
	int s,t;
	printf("please enter score:");
		scanf("%d",&s);
		t=s/10;
		switch(t)
		{
		case 10:
		case 9:t='A';break;
		case 8:t='B';break;
		case 7:t='C';break;
		case 6:t='D';break;
		case 5:
		case 4:
		case 3:
		case 2:
		case 1:
		case 0:t='E';break;
		}
			printf("The grade is: %c\n",t);
			return 0;
}




