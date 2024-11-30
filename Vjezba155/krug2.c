#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAX 20
#define M_PI 3.14159265358979323846

typedef struct {
    float radijus;
    float povrsina;
    char boja[11];
    int kolicina;
} Krug;

typedef struct {
    int iZadnji;
    Krug elementi[MAX];
} Lista;

void upisKruga(Krug* pkrug);
void ubaci(Krug noviElement, int iUbaci, Lista* plista);
void ispis(Lista* plista);
int pronadjiBoju(Lista* plista);
void izmijeni(int iIzmijeni, Lista* plista);

int main() {
    Krug krug;
    Lista listaKrug;
    listaKrug.iZadnji = -1;
    int iBoja;
    char odgovor;

    do {
        printf("\n\n\nUnos podataka\n");
        upisKruga(&krug);
        ubaci(krug, listaKrug.iZadnji + 1, &listaKrug);
        printf("\nZelite li unijeti podatke za jos jedan krug? (d/n): ");
        scanf(" %c", &odgovor);
    } while (odgovor != 'n');

    ispis(&listaKrug);
    iBoja = pronadjiBoju(&listaKrug);
    if (iBoja == -1)
        printf("\nKrug te boje nije pronadjen\n");
    else {
        izmijeni(iBoja, &listaKrug);
        ispis(&listaKrug);
    }

    return 0;
}

void upisKruga(Krug* pkrug) {
    printf("Unesite radijus kruga: \n");
    scanf("%f", &pkrug->radijus);
    pkrug->povrsina = pow(pkrug->radijus, 2) * M_PI;

    printf("Unesite boju kruga: \n");
    scanf("%10s", pkrug->boja);

    printf("Unesite kolicinu krugova: \n");
    scanf("%d", &pkrug->kolicina);
}

void ubaci(Krug noviElement, int iUbaci, Lista *plista) {
    int i;
    if (plista->iZadnji >= MAX - 1)
        printf("Lista je puna!\n");
    else if ((iUbaci > plista->iZadnji + 1) || (iUbaci < 0))
        printf("Pozicija ne postoji\n");
    else {
        for (i = plista->iZadnji; i >= iUbaci; i--)
            plista->elementi[i + 1] = plista->elementi[i];
        plista->iZadnji++;
        plista->elementi[iUbaci] = noviElement;
    }
}

void ispis(Lista* plista) {
    int i;
    printf("\n\nIspis liste: \n");
    for (i = 0; i <= plista->iZadnji; i++) {
        printf("Radijus kruga je %.2f \n", plista->elementi[i].radijus);
        printf("Povrsina kruga je %.2f \n", plista->elementi[i].povrsina);
        printf("Boja kruga je %s \n", plista->elementi[i].boja);
        printf("Kolicina krugova je: %d \n", plista->elementi[i].kolicina);
    }
}

int pronadjiBoju(Lista* plista) {
    int i;
    char bojaK[11];

    printf("\n\nUnesite boju kruga koji zelite pronaci: ");
    scanf("%10s", bojaK);

    for (i = 0; i <= plista->iZadnji; i++) {
        if (strcmp(plista->elementi[i].boja, bojaK) == 0) {
            return i;
        }
    }
    return -1;
}

void izmijeni(int iIzmijeni, Lista* plista) {
    Krug krug;

    upisKruga(&krug);
    plista->elementi[iIzmijeni].radijus = krug.radijus;
    plista->elementi[iIzmijeni].povrsina = krug.povrsina;
    strcpy(plista->elementi[iIzmijeni].boja, krug.boja);
    plista->elementi[iIzmijeni].kolicina = krug.kolicina;
}
