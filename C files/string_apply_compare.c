#include<stdio.h>
#include<string.h>
int main()
{
	char str[3][20],string[20];
	int i;
	for(i=0;i<3;i++)
	gets(str[i]);
	printf("\n\nThe largest string is:\n");
	if(strcmp(str[0],str[1])>0)
		strcpy(string,str[0]);
	else
		strcpy(string,str[1]);
	if(strcmp(str[2],string)>0)
		puts(strcpy(string,str[2]));
	else	
		puts(string);
	return 0;
}

