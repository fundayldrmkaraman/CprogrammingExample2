#include <stdio.h>
int main()
{
	FILE *fp;
	int ch;
	char c;
	fp=fopen("test1.txt","w");
	if(fp==NULL)
	{
		printf("dosya yazdirma icin acilamadi");
		return -1;
	}
	else
	for(ch='a';ch<='z';ch++)
	{
		fputc(ch,fp);
	}
	fclose(fp);
	fp=fopen("test1.txt","r");
	printf("dosyadaki bilgiler\n");
	while(!feof(fp))
	{
		c=fgetc(fp);
		printf("%c\n",c);
	}
	return 0;
}
