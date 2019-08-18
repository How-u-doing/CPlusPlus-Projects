#include<stdio.h>
int main()
{
	int a[10][10]={0},i,j;
	for(i=0,j=0;i<10;i++)
		a[i][j]=1;
	for(i=1;i<10;i++)
		for(j=1;j<10;j++)
			a[i][j]=a[i-1][j-1]+a[i-1][j];
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
			if(a[i][j]!=0)
				printf("%3d   ",a[i][j]);
		printf("\n");
	}
	return 0;
}




