#include <stdio.h>
#include <string.h>

#define MAX 20

typedef struct {
    char datum[12];
    char vrstans[3];
    int brojodrs;
} Nastava;

typedef struct {
    int iZadnji;
    Nastava nastava[MAX];
} Lista;

void upisNastava(Lista *plista);

int main() {
    Lista lista;
    lista.iZadnji = -1; 

    upisNastava(&lista);

    int ukupno_predavanja = 0, ukupno_vjezbi = 0, ukupno_seminara = 0;

    printf("\nUneseni podaci o nastavi:\n");
    for (int i = 0; i < lista.iZadnji; i++) {
        printf("%d. termin: Datum: %s, Vrsta sata: %s, Broj sati: %d\n", i + 1, lista.nastava[i].datum, lista.nastava[i].vrstans, lista.nastava[i].brojodrs);

        if (strcmp(lista.nastava[i].vrstans, "P") == 0) {
            ukupno_predavanja += lista.nastava[i].brojodrs;
        } else if (strcmp(lista.nastava[i].vrstans, "V") == 0) {
            ukupno_vjezbi += lista.nastava[i].brojodrs;
        } else if (strcmp(lista.nastava[i].vrstans, "S") == 0) {
            ukupno_seminara += lista.nastava[i].brojodrs;
        }
    }

    printf("\nUkupno odrađeni sati:\n");
    printf("Predavanja: %d sati\n", ukupno_predavanja);
    printf("Vježbe: %d sati\n", ukupno_vjezbi);
    printf("Seminar: %d sati\n", ukupno_seminara);

    return 0;
}

void upisNastava(Lista *plista) {
    printf("\nUnesite broj termina nastave za koje zelite unijeti podatke: ");
    scanf("%d", &plista->iZadnji); 

    for (int i = 0; i < plista->iZadnji; i++) {
        printf("\nUnesite datum kada je nastava odradena: ");
        scanf("%s", plista->nastava[i].datum);

        do {
            printf("Vrsta sata (P, V ili S): ");
            scanf("%s", plista->nastava[i].vrstans);
            if (strcmp(plista->nastava[i].vrstans, "P") != 0 && strcmp(plista->nastava[i].vrstans, "V") != 0 && strcmp(plista->nastava[i].vrstans, "S") != 0) {
                printf("Vrsta sata treba biti P, S ili V.\n");
            }
        } while (strcmp(plista->nastava[i].vrstans, "P") != 0 && strcmp(plista->nastava[i].vrstans, "V") != 0 && strcmp(plista->nastava[i].vrstans, "S") != 0);

        do {
            printf("Broj odrzanih sati: ");
            scanf("%d", &plista->nastava[i].brojodrs);
            if (plista->nastava[i].brojodrs <= 0) {
                printf("Broj odrzanih sati treba biti veci od nula.\n");
            }
        } while (plista->nastava[i].brojodrs <= 0);
    }
}
