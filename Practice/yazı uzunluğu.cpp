#include <stdio.h>
#include <stdlib.h>
char *yaziGirisi(int);
int main()
{
    int yaziUzunlugu;
    printf("Yazýnýn uzunluðunu giriniz: ");
    fscanf(stdin,"%u",&yaziUzunlugu);
    getc(stdin);
    fgetc(stdin);
    char *tut = yaziGirisi(yaziUzunlugu);
    for(int i = 0; i < yaziUzunlugu; i++)
    {
        fprintf(stdout,"%c\n",tut[i]);
    }
    free(tut);
    return 0;
}
char *yaziGirisi(int uzunluk)
{
    char *string = (char *)malloc(sizeof(char)*uzunluk);
    fprintf(stdout,"Yazý giriniz: ");
    fgets(string,uzunluk+1,stdin);
    return string;
}
