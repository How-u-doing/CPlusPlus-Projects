//Program that print prime numbers range from n1 to n2
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
        int i,n,n1,n2,tmp,sqareroot;
        printf("please enter n1 nad n2:");
        scanf("%d,%d",&n1, &n2);
        
		else
			if(n1>n2){
			tmp = n1; n1 = n2; n2 = tmp;
		}

		for (n = n1; n <= n2; ++n) {
			sqareroot=sqrt(n);		
			for (i = 2; i < sqareroot; ++i) {
				if (n%i == 0) {
					break;
				}
			}
			if(i>=sqareroot)
				printf("%d\t\t\t",n); 

		}
        		
		return 0;  
}