#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>


#define MAX 20
#define M_PI 3.14

typedef struct{
    float radijus;
    float povrsina;
    char boja[11];
    int kolicina;
}Krug;

typedef struct{
    int iZadnji;
    Krug elementi[MAX];
}Lista;

//voidi ubaci, ispis, unos

void ubaci(Krug noviElement,int iUbaci, Lista* plista);
void ispis(Lista* plista);
void unosKruga(Krug* pkrug);

int main()
{
    Krug krug;
    Lista lista;
    lista.iZadnji=-1;
    int i=0;
    char odgovor;

    do{
        unosKruga(&krug);
        ubaci(krug, i, &lista);
        printf("Zelite li unijeti podatke za jos jedan krug\n");
        scanf(" %c", &odgovor);
        i++;

    }while(odgovor!='n');

    ispis(&lista);

    return 0;
}

void ubaci(Krug noviElement, int iUbaci, Lista* plista)
{
    int i;
    if(plista->iZadnji>=MAX-1)
        printf("Lista je puna");
    else if((iUbaci>plista->iZadnji+1) || (iUbaci<0))
        printf("Pozicija ne postoji!");
    else{
        for(i=plista->iZadnji; i>= iUbaci; i--)
            plista->elementi[i+1]=plista->elementi[i];
            plista->iZadnji++;
            plista->elementi[iUbaci]=noviElement;
    }

}

void ispis(Lista* plista)
{
    int i;
    printf("\n\nIspis liste: ");
    for(i=0; i<=plista->iZadnji; i++)
    {
        printf("Radijus kruga %.2f \n", plista->elementi[i].radijus);
        printf("Povrsina kruga je %.2f \n", plista->elementi[i].povrsina);
        printf("Boja kruga je %s\n", plista->elementi[i].boja);
        printf("Kolicina krugova je %d\n", plista->elementi[i].kolicina);


    }
}

void unosKruga(Krug* pkrug)
{
    printf("Unesite radijus kruga \n");
    scanf("%f", &pkrug->radijus);
    pkrug->povrsina = pow(pkrug->radijus, 2) * M_PI;
    printf("Unesite boju kruga\n");
    scanf("%10s", pkrug->boja, 11);
    printf("Unesite kolicinu krugova");
    scanf("%d", &pkrug->kolicina);
}


