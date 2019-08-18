#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i;
	float f;
	char str[100];
	FILE*fp;
	if((fp=fopen("D:\\temp files\\file2.dat","r"))==NULL)
	{
		printf("Error!Can't open this file\n");
		exit(0);
	}

	
	fscanf(fp,"%d,%f,%[^\n]",&i,&f,str);
	fclose(fp);
	printf("%d\n%d\n%f\n%s\n",sizeof(*fp),i,f,str);
	if((fp=fopen("D:\\temp files\\file3.dat","a"))==NULL)
	{
		printf("Error!Can't open this file\n");
		exit(0);
	}
	fprintf(fp,"%d,%f,%s",i,f,str);
	fclose(fp);
	return 0;
}







