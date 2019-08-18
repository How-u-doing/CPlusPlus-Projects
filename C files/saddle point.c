#include<stdio.h>
int main()
{
	int a[3][4]={{2,37,21,18},{7,25,8,20},{13,19,18,6}};
	int i,j,k,t,row=0,colum=0,flag=0,max_row;
	for(i=0;i<3;i++)
	{
		for(j=0;j<4;j++)
			printf("%2d   ",a[i][j]);
		printf("\n");
	}
	for(i=0;i<3;i++)
	{
		max_row=a[i][0];
		for(j=1;j<4;j++)
			if(max_row<a[i][j])
			{max_row=a[i][j];
			row=i;
			colum=j;
			}
		for(k=0,t=0;k<3;k++)
			if(max_row<=a[k][colum])
				t++;
		if(t==3)
			{flag=1;
			break;
			}
	}
	if(flag==1)
		printf("This array has saddle point:a[%d][%d]=%d\n",row,colum,a[row][colum]);
	else printf("This array doesn't have sadddle point!\n");
	return 0;
}



				







