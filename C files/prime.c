//Program that print prime numbers range from n1 to n2
#include<stdio.h>
int main()
{
	int i, n, n1, n2, tmp, t;
	char c = 'y';
	while (c == 'y' || c == 'Y') {
		printf("Please enter n1 and n2:");
		scanf("%d,%d", &n1, &n2);
		if (n1 > n2) {
			tmp = n1; n1 = n2; n2 = tmp;
		}
		for (n = n1; n <= n2; ++n) {
			t = n / 2;
			for (i = 2; i < t; ++i) {
				if (n%i == 0) {
					break;
				}
			}
			if (i >= t)
				printf("%d\t", n);
		}
		putchar(10);
		putchar(10);
		while ((c = getchar()) != '\n');
		printf("Would you like to do it again?(y or n)\n");		
		c=getchar();
		putchar(10);
	}

	return 0;
}