#include<stdio.h>
int main()
{
	int a[15]={2,4,6,8,10,12,14,16,18,20,22,24,26,28,30};
	int num,sta=0,end=14,mid,flag=0;
	mid=(sta+end)/2;
	printf("The number you wanna search is:");
	scanf("%d",&num);
	for(;sta<=end;mid=(sta+end)/2)
	{
		if(num==a[mid])//事实上,如果要查找的数在其中,那么一定可以用a[mid]表示.比如查找26,与第二轮中间值24比较后,
		{
			printf("It's the No.%d number",mid+1);//锁定区间为[26,30]后,与28 比较,在左边,然后sta=end=12,mid=12,a[mid]==num.
			flag=1;
			break;
		}
		else if(num>a[mid])
			sta=mid+1;
		else 
			end=mid-1;
	}
	if(flag==0)
		printf("It's not in this array");
	printf("\n");
	return 0;
}






