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
		if(num==a[mid])//��ʵ��,���Ҫ���ҵ���������,��ôһ��������a[mid]��ʾ.�������26,��ڶ����м�ֵ24�ȽϺ�,
		{
			printf("It's the No.%d number",mid+1);//��������Ϊ[26,30]��,��28 �Ƚ�,�����,Ȼ��sta=end=12,mid=12,a[mid]==num.
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






