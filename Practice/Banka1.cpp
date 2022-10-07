#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct calisma{
	char *ad;
	char *soyad;
	int *gun;
	int *saat;
	float maas;
};

int main(){
	char ad[20];
	char soyad[30];
	int gun;
	int saat;
	float maas;
	float kesinti;
	kesinti = 0.15;
	typedef calisma isci;
	while(1){
        printf("1. Isci bilgileri gir\n");
        printf("2. Maas Hesapla\n");
        printf("3.Ucret kesintisi\n");
        printf("4. cikis\n");
        printf("bir secim yapiniz\n");
        int secim;
        scanf("%d",&secim);
        if(secim == 1){
                 FILE *fp = fopen("calisma.txt","a");
                 isci a;
                 a.ad=(char*)malloc(sizeof(char)*20);  
				 a.soyad =(char*)malloc(sizeof(char)*20); 
				 a.gun=(int*)malloc(sizeof(int)*gun); 
				 a.saat=(int*)malloc(sizeof(int)*saat);
				 printf("Ad  \t Soyad \t Gun  \t  Saat\t\n ");
				 scanf("\n%s %s %d %d",a.ad,a.soyad,a.gun,a.saat);
				 fprintf(fp,"%s %s %d %d\n",a.ad,a.soyad,a.gun,a.saat);
                 fclose(fp);
		 }
		if(secim==2){
			printf("Calisma gunu ve saatini giriniz:");
			scanf("%d %d",&gun,&saat);
			if(saat<=6){
				maas=(saat*2)*gun;
				printf("Maas:%d\n");
				scanf("%d",&maas);
			}
			if(saat>6 || saat<8){
				maas=(saat*2)+(saat*2.5)*gun;
				printf("Maas:%d\n");
				scanf("%d",&maas);
			}
			return 0;
		}	
		if(secim==3){
			printf("Iscinin gelmedigi gun sayisi:");
			scanf("%d",&gun);
			printf("Iscinin maasi:");
			scanf("%d",&maas);
			if(gun>5){
				maas=maas-maas*0,15;
				printf("Ucret kesintisine ugrayan maas:%f\n");
				scanf("%lf",&maas);
			}
			else 
			printf("Ucret kesintisine ugramayan maas:%f\n");
			scanf("%lf",&maas);
		}
		if(secim==4){
			break;
		}
    }
}

				
