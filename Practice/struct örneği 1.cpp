#include <stdio.h>
#include <stdlib.h>

typedef struct ogr{
	int numara;
	int vizenotu;
	int finalnotu;
	char isim[30];
	char soyisim[20];
	double dersnotu;
	struct ogr *next;
}ogr;

void ekle(ogr *r,int num,int vize,int final)
{
	while(r->next!=NULL)
	{
		r=r->next;
	}
	r->next=(ogr*)malloc(sizeof(ogr));
	r->next->numara=num;
	r->next->vizenotu=vize;
	r->next->finalnotu=final;
	printf("isim\n");
	scanf("%s",r->next->isim);
	printf("soyisim\n");
  scanf("%s",r->next->soyisim);
  r->next->dersnotu=(vize*0.4)+(final*0.6);
  r->next->next=NULL;
}

void bastir(ogr *r)
{
	r=r->next;
	while(r!=NULL)
	{
		printf("NO:%d\t",r->numara);
		printf("Ad:%s",r->isim);
		printf("Soyisim:%s\t",r->soyisim);
		printf("Ders notu:%lf",r->dersnotu);
		printf("\n");
		r=r->next;
	}
}

double sinifort(ogr *r)
{
	int i=0;
	double sum=0,ortalama;
	r=r->next;
	while(r!=NULL)
	{
		sum=sum+r->dersnotu;
		i=i+1;
		r=r->next;
	}
	ortalama=(sum/i);
	return ortalama;
}

ogr *sil(ogr *r,int x)
{
	ogr *temp;
	ogr *iter=r;
	if(r->numara==x)
	{
		temp=r;
		r=r->next;
		free(temp);
		return r;
	}
	while(iter->next!=NULL && iter->next->numara!=x)
	{
		iter=iter->next;
	}
	if(iter->next==NULL)
	{
		printf("numara bulunamadi\n");
		return r;
	}
	temp=iter->next;
	iter->next=iter->next->next;
	free(temp);
	return r;
}

int main()
{
	ogr *root;
	root=(ogr*)malloc(sizeof(ogr));
	root->next=NULL;
	ogr *iter;
	iter=root;
	int menu=0,x,i;
	double sum;
	
	do
	{
		printf("menu\n");
		printf("1.kayit ekle\n");
		printf("2.kayit sil\n");
		printf("3.kayitlari listele\n");
		printf("4.sinif ortalamasi hesapla\n");
		printf("5.cikis\n");
		scanf("%d",&menu);
	
	switch(menu)
	{
		case 1:
		printf("numara\n");
		scanf("%d",iter->numara);
		
		printf("vizenotu\n");
		scanf("%d",&iter->vizenotu);
		
		printf("finalnotu\n");
		scanf("%d",&iter->finalnotu);
		
		ekle(iter,iter->numara,iter->vizenotu,iter->finalnotu);
		
		break;
		
		case 2:
		printf("hangi numaraya ait kayit silinsin");
		scanf("%d",&x);
		root=sil(root,x);
		printf("\n");
		 
		break;
		
		case 3:
		bastir(root);
		
	  break;
	
	  case 4:
	  printf("%lf",sinifort(root));
	  
	  break;
	  
	  case 5:
	  break;
	
	  default:
	  printf("yanlis secenek tekrar dene");
	  break;

	}
 }
 
  while(menu!=5);
  
}


