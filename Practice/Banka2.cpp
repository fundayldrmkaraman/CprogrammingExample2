#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct banka{
	int hesapNo;
	int telefonNo;
	char isim[10];
	char soyisim[20];
	struct banka *next;
}banka;

void ekle(banka *a,int hes,int tel )
{
	while(a->next!=NULL)
	{
		a=a->next;
	}
	a->next=(banka*)malloc(sizeof(banka));
	a->next->hesapNo=hes;
	a->next->telefonNo=tel;
	printf("isim\n");
	scanf("%s",a->next->isim);
	printf("soyisim\n");
  scanf("%s",a->next->soyisim);
  a->next->next=NULL;
}

void bastir(banka *a)
{
	a=a->next;
	while(a!=NULL)
	{
		printf("NO:%d\t",a->hesapNo);
		printf("Ad:%s",a->isim);
		printf("Soyisim:%s\t",a->soyisim);
		printf("TEL NO:%lf",a->telefonNo);
		printf("\n");
		a=a->next;
	}
}

banka *sil(banka *a,int x)
{
	banka *temp;
	banka *jump=a;
	if(a->hesapNo==x)
	{
		temp=a;
		a=a->next;
		free(temp);
		return a;
	}
	while(jump->next!=NULL && jump->next->hesapNo!=x)
	{
		jump=jump->next;
	}
	if(jump->next==NULL)
	{
		printf("Hesap numarasý bulunamadi\n");
		return a;
	}
	temp=jump->next;
	jump->next=jump->next->next;
	free(temp);
	return a;
}

int main()
{
	banka *ptr;
	ptr=(banka*)malloc(sizeof(banka));
	ptr->next=NULL;
	banka *jump;
	jump=ptr;
	int menu=0,x;
	
	do
	{
		printf("Ana Menu\n");
		printf("1.Kayit Ekle\n");
		printf("2.Kayit Sil\n");
		printf("3.Kayitlari Listele\n");
		printf("4.Cikis\n");
		scanf("%d",&menu);
	
	switch(menu)
	{
		case 1:
		printf("Hesap Numarasi\n");
		scanf("%d",jump->hesapNo);
		
		printf("Telefon Numarasi\n");
		scanf("%d",&jump->telefonNo);
		
		ekle(jump,jump->hesapNo,jump->telefonNo);
		
		break;
		
		case 2:
		printf("hangi numaraya ait kayit silinsin");
		scanf("%d",&x);
		ptr=sil(ptr,x);
		printf("\n");
		 
		break;
		
		case 3:
		bastir(ptr);
		
	  break;
	  
	  case 4:
	  break;
	
	  default:
	  printf("yanlis secenek tekrar dene");
	  break;

	}
 }
 
  while(menu!=5);
  
}




