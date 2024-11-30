#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 20

typedef struct{
    char datum[11];
    char vrstaNastavngSata;
    int brojOdrzanihSati;

}Nastava;

typedef struct{
   int iUlaz;
   int iIzlaz;
   Nastava elementi[MAX];
}Red;

//voidi
void unosNastave(Nastava* pnastava);
void ubaci(Nastava noviElement, Red* pred);
void ispisi(Red* pred);


int main()
{
    Nastava nastava;
    Red redNastave;
    redNastave.iUlaz = 0;
    redNastave.iIzlaz = 0;

    int i;
    int brT;
    char odgovor;

    printf("\nUnos podataka\n");
    printf("Unesite broj termina nastave");
    scanf("%d", &brT);
    for(i=0; i<brT; i++)
    {

        unosNastave(&nastava);
        ubaci(nastava, &redNastave);


    }

    ispisi(&redNastave);
    return 0;

}

void unosNastave(Nastava* pnastava)
{
    printf("Unesite datum nastave\n");
    scanf("%10s", pnastava->datum);

    do{
    printf("Unesite vrstu nastavnog sata s P, V ili S\n");
    scanf("%c", &pnastava->vrstaNastavngSata);
    }
    while(pnastava->vrstaNastavngSata != 'P' && pnastava->vrstaNastavngSata != 'V' && pnastava->vrstaNastavngSata != 'S');

    printf("Unesite broj odrzanih sati\n");
    scanf("%d", &pnastava->brojOdrzanihSati);
    if(pnastava->brojOdrzanihSati<=0)
    {
        printf("Broj odrzanih sati mora biti veci od nula\n");
        scanf("%d", &pnastava->brojOdrzanihSati);
    }


}

void ubaci(Nastava noviElement, Red* pred)
{
    if ((pred->iUlaz + 1) % MAX == pred->iIzlaz)
    {
        printf("Red je pun");
    }
    else{
        pred->iUlaz = (pred->iUlaz + 1) % MAX;
        pred->elementi[pred->iUlaz] = noviElement;
    }

}

void ispisi(Red* pred)
{
    int i;
    int ukP=0, ukV=0, ukS=0;

    i = (pred->iIzlaz + 1) % MAX;

    while (i != (pred->iUlaz + 1) % MAX)
    {
        printf("\nDatum %s", pred->elementi->datum);
        printf("\nVrsta sata %c", pred->elementi->vrstaNastavngSata);
        printf("\nBroj odrzanih sati %d", pred->elementi->brojOdrzanihSati);

        		if (pred->elementi[i].vrstaNastavngSata == 'P')
			ukP += pred->elementi[i].brojOdrzanihSati;

		if (pred->elementi[i].vrstaNastavngSata == 'V')
			ukV += pred->elementi[i].brojOdrzanihSati;

		if (pred->elementi[i].vrstaNastavngSata == 'S')
			ukS += pred->elementi[i].brojOdrzanihSati;

		i = (i + 1) % MAX;
	}
	printf("\n\n UKUPNO - Predavanja: %d; Vjezbe: %d; Seminar: %d. ", ukP, ukV, ukS);
    }











