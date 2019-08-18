void count_char(char a[])
{
	int i,digit=0,blank=0,letter=0,other=0;
	for(i=0;a[i]!='\0';i++)
	{
		if ((a[i]>='a'&&a[i]<='z')||(a[i]>='A'&&a[i]<='Z'))
		    letter ++;
		else if (a[i]>='0'&&a[i]<='9')
			digit ++;
		else if (a[i]==' ')
			blank++;
		else
		    other++;
	}
	printf("letter=%d,digit=%d,blank=%d,other=%d\n",letter,digit,blank,other);
}

void delete_string(char a[],char x)
{
	int i,j;
	for(i=0,j=0;a[i]!='\0';i++)
		if(a[i]!=x)
			a[j++]=a[i];
		a[j]='\0';
}

void copy_string(char *s,char *t)
{
	while(*s++=*t++);
}

void string_n_copy(char *s,int n,char *t)
{
	int i=0;
	while(i++<n)
		*s++=*t++;
	*s='\0';
}

void strlink(char *s,char *t)
{
	while(*s++);
	s--;        
	while(*s++=*t++);
}

void transposed_string(char *s)
{
	int i,n=0;
	while(*s++)
		n++;
	s-=2;
	for(i=0;i<n;i++)
		printf("%c",*s--);
	putchar(10);
}
