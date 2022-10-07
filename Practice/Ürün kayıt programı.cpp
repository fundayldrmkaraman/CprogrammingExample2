#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct {
int no;
char ad[10], skt[15];
} kayit;


int main() {
FILE *f;
kayit x;
int sayi;
char sec;
anamenu:

printf("\n\tURUN KAYIT PROGRAMI\n"); 
printf("\nUrun kaydetmek icin\t\t(1)\n"); 
printf("\nTum kayitlari okumak icin\t\t(2)\n"); 
printf("\nBelirli bir urunu okumak icin\t(3)\n"); 
sec = getche();

switch (sec) {
case '1':
system("cls");

if ((f = fopen("kayit.dat", "ab")) == NULL) 
{ printf("Dosya Acilamadi!\n");
break;
}
do {
printf("\nUrun adi: "); scanf("%s", x.ad);
printf("Urun numarasi: "); scanf("%d", &x.no);
printf("Urun SKT: "); scanf("%s", x.skt);
fwrite(&x, sizeof(kayit), 1, f);
printf("Kayda devam icin 'e' tusuna basin... ");

} while (getche() == 'e'); fclose(f);
break;


case '2':
system("cls");

if ((f = fopen("kayit.dat", "rb")) == NULL) 
{ printf("Dosya Acilamadi!\n");
break;
}
sayi = 0;

while (fread(&x, sizeof(kayit), 1, f) == 1) 
{ sayi++;
printf("\n%d. Urun\n", sayi); 
printf("\nAdi: %s\n", x.ad); 
printf("Numarasi: %d\n", x.no); 
printf("SKT: %s\n", x.skt);
}
fclose(f);
break;


case '3': 
system("cls");

if ((f = fopen("kayit.dat", "rb")) == NULL) 
{ printf("Dosya Acilamadi!\n");
break;
}
do {
printf("\nKacinci urunu gormek istiyorsunuz?\n");
scanf("%d", &sayi);
fseek(f, sizeof(kayit) * (sayi - 1), SEEK_SET); 
if (fread(&x, sizeof(kayit), 1, f) == 1) {
  printf("\n%d. Urun\n", sayi); 
  printf("\nAdi: %s\n", x.ad); 
  printf("Numarasi: %d\n", x.no); 
  printf("SKT: %s\n", x.skt);
} else
  printf("Boyle bir urun yok urun yok!\n"); 
	printf("Urun aramaya etmek icin 'e' tusuna basin... ");

} while (getche() == 'e'); fclose(f);
break;
default: printf("\n\nGecersiz bir secim yaptiniz!\n\n");
}

printf("\n\nAna menuye donmek icin 'e' tusuna" "basin... ");
if (getche() == 'e') {
system("cls");
goto anamenu;
}
printf("\n\nProgrami kapatmak icin herhangi "
"bir tusa basin... ");
getch();
return 0;
}
 





























