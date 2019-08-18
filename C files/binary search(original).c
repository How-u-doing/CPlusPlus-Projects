#include<stdio.h>
int main()
{
	int a[15]={2,4,6,8,10,12,14,16,18,20,22,24,26,28,30};
	int num;
	int sta=0,end=14,mid;
	mid=(sta+end)/2;
	printf("The number you wanna search is:");
	scanf("%d",&num);
	if(num==a[mid])
		printf("It's the No.%d number",mid+1);
	else if(num>a[mid])
	{
		sta=mid+1;
		mid=(sta+end)/2;
		if(num==a[mid])
			printf("It's the No.%d number",mid+1);
		else if(num>a[mid])
		{
			sta=mid+1;
			mid=(sta+end)/2;
			if(num==a[mid])
				printf("It's the No.%d number",mid+1);
			else if(num>a[mid])
			{
				if(num==a[end])
					printf("It's the No.%d number",end+1);
				else printf("It's not in this array");
			}
			else
			{	
				if(num==a[sta])
					printf("It's the No.%d number",sta+1);
				else
					printf("It's not in this array");
			}
		}
		else
		{
			end=mid-1;
			mid=(sta+end)/2;
			if(num==a[mid])
				printf("It's the No.%d number",mid+1);
			else if(num>a[mid])
			{
				if(num==a[end])
					printf("It's the No.%d number",end+1);
				else printf("It's not in this array");
			}
			else
			{
				if(num==a[sta])
					printf("It's the No.%d number",sta+1);
				else
					printf("It's not in this array");
			}
		}
	}
	else
	{
		end=mid-1;
		mid=(sta+end)/2;
		if(num==a[mid])
			printf("It's the No.%d number",mid+1);
		else if(num>a[mid])
		{
			sta=mid+1;
			mid=(sta+end)/2;
			if(num==a[mid])
				printf("It's the No.%d number",mid+1);
			else if(num>a[mid])
			{
				if(num==a[end])
					printf("It's the No.%d number",end+1);
				else printf("It's not in this array");
			}
			else
			{	
				if(num==a[sta])
					printf("It's the No.%d number",sta+1);
				else
					printf("It's not in this array");
			}
		}
		else
		{
			end=mid-1;
			mid=(sta+end)/2;
			if(num==a[mid])
				printf("It's the No.%d number",mid+1);
			else if(num>a[mid])
			{
				if(num==a[end])
					printf("It's the No.%d number",end+1);
				else printf("It's not in this array");
			}
			else
			{
				if(num==a[sta])
					printf("It's the No.%d number",sta+1);
				else
					printf("It's not in this array");
			}
		}
	}
	printf("\n");
	return 0;
}






					
				
			




