#include<stdio.h>
#include<math.h>

#define M_PI 3.14159265358979323846

typedef struct
{
	float radijus;
	float povrsina;
	char boja[11];
	int kolicina;
} Krug;

void upisKrugovi(Krug krugovi[], int brElem);
void ispisKrugovi(Krug krugovi[], int brElem);


int main()
{
	Krug krugovi[4];

	upisKrugovi(krugovi, 4);
	// ili: upisKrugovi(&krugovi[0], 4);

	ispisKrugovi(krugovi, 4);

	printf("\n\n");
	return 0;
}


void upisKrugovi(Krug krugovi[], int brElem)
{
	int i;

	for (i = 0; i < brElem; i++)
	{
		printf("\n\n krugovi[%d]:", i);
		printf("\n\t radijus = ");
		scanf("%f", &krugovi[i].radijus);

		krugovi[i].povrsina = pow(krugovi[i].radijus, 2) * M_PI;

		printf("\n\t boja = ");
		scanf("%s", krugovi[i].boja, 11);

		printf("\n\t kolicina = ");
		scanf("%d", &krugovi[i].kolicina);
	}	
}


void ispisKrugovi(Krug krugovi[], int brElem)
{
	int i;

	for (i = 0; i < brElem; i++)
	{
		printf("\n\n krugovi[%d]:", i);
		printf("\n\t  radijus = %.2f", krugovi[i].radijus);
		printf("\n\t povrsina = %.2f", krugovi[i].povrsina);
		printf("\n\t     boja = %s",   krugovi[i].boja);
		printf("\n\t kolicina = %d ",  krugovi[i].kolicina);		
	}
}




