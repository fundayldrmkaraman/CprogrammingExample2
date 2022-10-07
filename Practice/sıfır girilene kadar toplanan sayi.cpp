#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int main()
{
	int sayi;
	int toplam=0;

	while(sayi!=0)
	{	
	printf("sayi:");
	scanf("%d",&sayi);
  toplam=toplam+sayi;	
	}
	printf("%d",toplam);
	
}
