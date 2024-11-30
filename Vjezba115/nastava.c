#include<stdio.h>
#include<math.h>
#include<string.h>

#define MAX 20

typedef struct{
    char datum[12];
    char vrstaNastave;
    int brojSati;
}Nastava;

typedef struct{
    int iZadnji;
    Nastava elementi[MAX];
}Lista;

void ubaci(Nastava noviElement, int iUbaci, Lista* plista);
void ispisi(Lista* plista);

int main()
{

    Nastava nastava;
    Lista listaNastave;
    listaNastave.iZadnji=-1;
    int termini, i;
    printf("\nUnesite broj termina nastave za koje zelite unijeti podatke\n");
    scanf("%d", &termini);
    for(i=0; i<termini; i++)
    {
             printf("UNOS\n");
            printf("Unesite datum izvodenja nastave\n");
            scanf("%11s", &nastava.datum, 11);

        do{
            printf("Unesite vrst sata\n");
            scanf("%c", &nastava.vrstaNastave, 1);
            if (nastava.vrstaNastave != 'P' && nastava.vrstaNastave != 'V' && nastava.vrstaNastave != 'S')
            printf("Vrsta sata treba biti P, S ili V\n");

        }while (nastava.vrstaNastave != 'P' && nastava.vrstaNastave != 'V' && nastava.vrstaNastave != 'S');

        do{
            printf("Unesite broj održanih sati\n");
            scanf("%d", &nastava.brojSati);
            if(nastava.brojSati<1)
            printf("Broj odrzanih sati treba biti veci od nula\n");

        }while(nastava.brojSati<1);


        ubaci(nastava, i, &listaNastave);
    }
    printf("\n Ispis elementata liste \n");
    ispisi(&listaNastave);
    printf("\n\n");
}

void ubaci(Nastava noviElement, int iUbaci, Lista* plista)
{
    int i;
    if (plista->iZadnji == MAX -1)
    {
        printf("Lista je popunjena\n");
    }

    else if (iUbaci > (plista->iZadnji + 1 || iUbaci < 0))
    {
        printf("Indeks ubacivanja iUbaci nije ispravno definiran.");
    }

    else{
        for (i=plista->iZadnji; i>= iUbaci; i--)
        {
            plista->elementi[i+1]= plista->elementi[i];
        }
        plista->iZadnji++;
        plista->elementi[iUbaci]=noviElement;
    
    }
}

void ispisi(Lista* plista)
{
	int i;
	int ukP = 0, ukV = 0, ukS = 0;

	for (i = 0; i <= plista->iZadnji; i++)
	{
		printf("\n\n Datum: %s ", plista->elementi[i].datum);

		printf("\n Vrsta sata: %c ", plista->elementi[i].vrstaNastave);

		printf("\n Broj odrzanih sati: %d ", plista->elementi[i].brojSati);

		if (plista->elementi[i].vrstaNastave == 'P')
			ukP += plista->elementi[i].brojSati;

		if (plista->elementi[i].vrstaNastave == 'V')
			ukV += plista->elementi[i].brojSati;

		if (plista->elementi[i].vrstaNastave == 'S')
			ukS += plista->elementi[i].brojSati;
	}

	printf("\n\n UKUPNO - Predavanja: %d; Vjezbe: %d; Seminar: %d. ", ukP, ukV, ukS);
}

