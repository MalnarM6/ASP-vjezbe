#include<stdio.h>
#include<math.h>
#include<string.h>

#define MAX 20
#define M_PI 3.14159265358979323846

typedef struct{
    float radijus;
    float povrsina;
    char boja[11];
    int kolicina;
} Krug;

typedef struct{
    int iZadnji;
    Krug elementi[MAX];
} Lista;

void upisKrug(Krug *pkrug);
void ubaci(Krug noviElement, int iUbaci, Lista* plista);
void ispisi(Lista* plista);

int main() {
    Krug krug;
    Lista listaKrug;
    listaKrug.iZadnji = -1;

    int i = 0;
    char odgovor;
    do {
        upisKrug(&krug);
        ubaci(krug, i, &listaKrug);
        printf("Zelite li unijeti podatke za jos jedan krug (d/n)?\n");
        scanf(" %c", &odgovor);
        i++;
    } while (odgovor != 'n');
    
    ispisi(&listaKrug);

    return 0;
}

void upisKrug(Krug *pkrug) {
    printf("Unesite radijus kruga\n");
    scanf("%f", &pkrug->radijus);
    pkrug->povrsina = pow(pkrug->radijus, 2) * M_PI;
    printf("Unesite boju kruga\n");
    scanf("%10s", pkrug->boja);
    printf("Unesite kolicinu krugova\n");
    scanf("%d", &pkrug->kolicina);
}

void ubaci(Krug noviElement, int iUbaci, Lista* plista) {
    int i;
    for (i = plista->iZadnji; i >= iUbaci; i--) {
        plista->elementi[i + 1] = plista->elementi[i];
    }
    plista->iZadnji++;
    plista->elementi[iUbaci] = noviElement;
}

void ispisi(Lista* plista) {
    int i;
    for (i = 0; i <= plista->iZadnji; i++) {
        printf("\n ELEMENT %d LISTE \n", i + 1);
        printf("Radijus elementa %.2f\n", plista->elementi[i].radijus);
        printf("Povrsina elementa %.2f\n", plista->elementi[i].povrsina);
        printf("Boja kruga %s\n", plista->elementi[i].boja);
        printf("Kolicina krugova %d\n", plista->elementi[i].kolicina);
    }
}
