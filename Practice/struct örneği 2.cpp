#include <stdio.h>
#include <math.h>
#include <conio.h>

enum mantiksal {var, yok};

typedef struct {
	int a, b, c;
	enum mantiksal kok;
	float bk, kk;
} denklem;

void degis(denklem *a, denklem *b) {
	denklem t = *a;
	*a = *b;
	*b = t;
	return;
}

void yazdir(denklem d[]) {
	int i;
	
	for(i = 0; i < 3; i++) {
		
		printf("  ");
		if (d[i].a != 0)
		{
			if (d[i].a > 0)
			{
				if (d[i].a > 1)
					printf("%d", d[i].a);
			}
			else
			{
				printf("-");
				if (d[i].a < -1)
					printf("%d", -d[i].a);
			}
			
			printf("(x^2)");
		}

		if (d[i].b != 0)
		{
			if (d[i].b > 0)
			{
				printf(" + ");
				if (d[i].b > 1)
					printf("%d", d[i].b);
			}
			else
			{
				printf(" - ");
				if (d[i].b < -1)
					printf("%d", -d[i].b);
			}
			printf("x");
		}
		
		if (d[i].c != 0)
			if (d[i].c > 0)
				printf(" + %d", d[i].c);
			else
				printf(" - %d", -d[i].c);


		printf(" = 0");
		
		if (d[i].kok == yok)
			printf("   --->   Reel koku yok (delta < 0)\n");
		else
			printf("   --->   %.2f %.2f\n", d[i].bk, d[i].kk);
	}
	
	return;
}

void kokbul(denklem *d) {
	
	if (d->a == 0) {
		d->kok = var;
		d->bk = d->kk = -((float)d->c/d->b);
		return;
	}

	float k1, k2, delta = (d->b*d->b) - 4*d->a*d->c;
	
	if (delta < 0)
		d->kok = yok;
	else {
		d->kok = var;
		k1 = (-d->b + sqrt(delta)) / (2*d->a);
		k2 = (-d->b - sqrt(delta)) / (2*d->a);
		
		if (k1 > k2) {
			d->bk = k1;
			d->kk = k2;
		} else {
			d->bk = k2;
			d->kk = k1;
		}
	}
	return;
}

void sirala(denklem d[]) {
	int i;
	
	if (d[1].kok == var && (d[0].bk < d[1].bk || d[0].kok == yok))
		degis(&d[0], &d[1]);
	
	if (d[2].kok == var && (d[0].bk < d[2].bk || d[0].kok == yok))
		degis(&d[0], &d[2]);
		
	if (d[2].kok == var && (d[1].bk < d[2].bk || d[1].kok == yok))
		degis(&d[1], &d[2]);

	return;
}

int main() {
	denklem d[3];
	int i;
	
	printf("\na(x^2) + bx + c = 0 olmak uzere:\n");
	
	for (i = 0; i < 3; i++) {
		printf("\n%d. denklemin a, b ve c degerlerini girin.\n", i+1);
		scanf("%d %d %d", &d[i].a, &d[i].b, &d[i].c);
		kokbul(&d[i]);
	}
	
	printf("\nDenklemler ve Kok Durumlari:\n\n");
	yazdir(d);
	
	sirala(d);
	printf("\nBuyuk Koklerine Gore Sirali:\n\n");
	yazdir(d);
	
	getch();
	
	return 0;
}
