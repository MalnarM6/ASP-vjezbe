#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int izraz1;
    int izraz2;
} Broj;


typedef struct CelijaBroj {
    Broj broj;
    struct CelijaBroj* sljedeca;
} CelijaBroj;

void izracunajIzraze(CelijaBroj* lista) {
    CelijaBroj* trenutna = lista;
    do {
        Broj* trenutni_broj = &trenutna->broj;
        trenutni_broj->izraz1 = trenutni_broj->x * 4 - 2 * trenutni_broj->x * trenutni_broj->x + 1 - trenutni_broj->x + 1;
        trenutni_broj->izraz2 = trenutni_broj->x * trenutni_broj->x - 2 * trenutni_broj->x + 1;
        trenutna = trenutna->sljedeca;
    } while (trenutna != lista);
}

void ispisiListu(CelijaBroj* lista) {
    printf("x\tizraz1\tizraz2\n");
    CelijaBroj* trenutna = lista;
    do {
        printf("%d\t%d\t%d\n", trenutna->broj.x, trenutna->broj.izraz1, trenutna->broj.izraz2);
        trenutna = trenutna->sljedeca;
    } while (trenutna != lista);
}

int main() {
    int pocetak, kraj;

    do {
        printf("Unesite pocetak i kraj (pocetak mora biti veci od kraja, razlika ne smije biti veca od 10): ");
        scanf("%d %d", &pocetak, &kraj);
        if (pocetak <= kraj || abs(pocetak - kraj) > 10) {
            printf("Neispravan unos!\n");
        }
    } while (pocetak <= kraj || abs(pocetak - kraj) > 10);

    CelijaBroj* lista = NULL;
    CelijaBroj* posljednja = NULL;
    for (int i = pocetak; i >= kraj; i--) {
        CelijaBroj* nova_celija = (CelijaBroj*)malloc(sizeof(CelijaBroj));
        nova_celija->broj.x = i;
        if (lista == NULL) {
            lista = nova_celija;
        }
        else {
            posljednja->sljedeca = nova_celija;
        }
        nova_celija->sljedeca = lista;
        posljednja = nova_celija;

        izracunajIzraze(lista);


        ispisiListu(lista);

        CelijaBroj* trenutna = lista;
        do {
            CelijaBroj* temp = trenutna;
            trenutna = trenutna->sljedeca;
            free(temp);
        } while (trenutna != lista);

        return 0;
    }
}