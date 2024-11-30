#include<stdio.h>
#include<math.h>
#include<string.h>

#define MAX 30

typedef struct{
    char vrsta[11];
    char vegetacijskiPeriod;
    int brojKomada;
} Biljka;

typedef struct{
    int iZadnji;
    Biljka elementi[MAX];
}Lista;

void ubaciBiljku(Biljka noviElement, int iUbaci, Lista* plista);
void pronadjiBiljku(char* vrstaBiljke, Lista* plista);
void ispisiBiljke(Lista* plista);

int main()
{
    Lista listaBiljaka;
    listaBiljaka.iZadnji=-1;
    Biljka biljka;
    int brBiljaka, i;
    char vrstaBiljke[11];


    printf("Koliko biljaka zelite unijeti u listu?\n");
    scanf("%d", &brBiljaka);

    for(i=0; i<brBiljaka; i++)
    {
        printf("BILJKE\n");
        printf("Unesite vrste biljaka\n");
        scanf("%10s", &biljka.vrsta, 11);

    do{
        printf("Unesite vegetacijski period biljke\n");
        scanf("%c", &biljka.vegetacijskiPeriod, 1);

        if(biljka.vegetacijskiPeriod != 'T' && biljka.vegetacijskiPeriod != 'J' && biljka.vegetacijskiPeriod != 'D')
        printf("Period mora biti T J ili D, ponovno unesite period");

    }while (biljka.vegetacijskiPeriod != 'T' && biljka.vegetacijskiPeriod != 'J' && biljka.vegetacijskiPeriod != 'D');

    do
    {
        printf("Unesite broj komada biljaka");
        scanf("%d", &biljka.brojKomada);
        if (biljka.brojKomada<1)
        printf("Broj komada biljke mora biti veći od 0");
    } while (biljka.brojKomada<1);

    ubaciBiljku(biljka, i, &listaBiljaka);

    }

    	printf("\n\n\t Za koju vrstu biljke zelite dobiti podatke o vegetacijskom periodu i broju komada? ");
	scanf("%10s", vrstaBiljke, 11);

	pronadjiBiljku(vrstaBiljke, &listaBiljaka);

	ispisiBiljke(&listaBiljaka);

	printf("\n\n");
    return 0;
}

void ubaciBiljku(Biljka noviElement, int iUbaci, Lista* plista)
{
	int i;

	if (plista->iZadnji == MAX - 1)
		printf("\n Lista je puna. ");

	else if (iUbaci > (plista->iZadnji + 1) || iUbaci < 0)
		printf("\n Indeks ubacivanja iUbaci nije ispravno definiran. ");

	else
	{
		for (i = plista->iZadnji; i >= iUbaci; i--)
		{
			plista->elementi[i + 1] = plista->elementi[i];
		}
		plista->iZadnji++;
		plista->elementi[iUbaci] = noviElement;
	}
}


void pronadjiBiljku(char* vrstaBiljke, Lista* plista)
{
	int i, flag = 0;

	for (i = 0; i <= plista->iZadnji; i++)
	{
		if (strcmp(plista->elementi[i].vrsta, vrstaBiljke) == 0)
		{
			printf("\n\t vegetacijski period: %c ", plista->elementi[i].vegetacijskiPeriod);
			printf("\n\t         broj komada: %d ", plista->elementi[i].brojKomada);
			flag = 1;
		}
	}
	if (flag == 0)
		printf("\n\t Vrsta %s nije pronadjena u listi biljaka.", vrstaBiljke);
}


void ispisiBiljke(Lista* plista)
{
	int i, brT = 0, brJ = 0, brD = 0;

	printf("\n\n MOJE BILJKE: ");

	for (i = 0; i <= plista->iZadnji; i++)
	{
		printf("\n %d. %s ", i+1, plista->elementi[i].vrsta);
		printf("\n\t vegetacijski period: %c ", plista->elementi[i].vegetacijskiPeriod);
		printf("\n\t         broj komada: %d ", plista->elementi[i].brojKomada);
		
		if (plista->elementi[i].vegetacijskiPeriod == 'T')
			brT += plista->elementi[i].brojKomada;

		if (plista->elementi[i].vegetacijskiPeriod == 'J')
			brJ += plista->elementi[i].brojKomada;

		if (plista->elementi[i].vegetacijskiPeriod == 'D')
			brD += plista->elementi[i].brojKomada;
	}

	printf("\n\n UKUPNO: ");
	printf("\n trajnica = %d \n jednogodisnjih = %d \n dvogodisnjih = %d ", brT, brJ, brD);
}
