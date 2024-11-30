#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char ime[50];
    char spol;
    int godina_rodenja;
} Natjecatelj;

typedef struct CelijaNatjecatelj {
    Natjecatelj element;
    struct CelijaNatjecatelj* psljedeca;
} CelijaNatjecatelj;

void ispis_podataka(CelijaNatjecatelj* lista);
void obrisi_natjecatelja(CelijaNatjecatelj** lista, char* ime);

int main() {
    CelijaNatjecatelj* lista = NULL;
    char odgovor;

    do {
        Natjecatelj natjecatelj;
        printf("Unesite ime: ");
        scanf("%s", natjecatelj.ime);
        do {
            printf("Unesite spol (M/Z): ");
            scanf(" %c", &natjecatelj.spol);
            if (natjecatelj.spol != 'M' && natjecatelj.spol != 'Z') {
                printf("Neispravan unos spola!\n");
            }
        } while (natjecatelj.spol != 'M' && natjecatelj.spol != 'Z');
        do {
            printf("Unesite godinu rodjenja (1930-2005): ");
            scanf("%d", &natjecatelj.godina_rodenja);
            if (natjecatelj.godina_rodenja < 1930 || natjecatelj.godina_rodenja > 2005) {
                printf("Neispravan unos godine rodjenja!\n");
            }
        } while (natjecatelj.godina_rodenja < 1930 || natjecatelj.godina_rodenja > 2005);

        CelijaNatjecatelj* nova_celija = (CelijaNatjecatelj*)malloc(sizeof(CelijaNatjecatelj));
        nova_celija->element = natjecatelj;
        nova_celija->psljedeca = lista;
        lista = nova_celija;

        printf("Želite li unijeti nove podatke? (D/N): ");
        scanf(" %c", &odgovor);
    } while (odgovor == 'D' || odgovor == 'd');

    ispis_podataka(lista);

    char ime_brisanja[50];
    printf("Unesite ime natjecatelja kojeg želite obrisati iz liste: ");
    scanf("%s", ime_brisanja);
    obrisi_natjecatelja(&lista, ime_brisanja);

    while (lista != NULL) {
        CelijaNatjecatelj* temp = lista;
        lista = lista->psljedeca;
        free(temp);
    }

    return 0;
}

void obrisi_natjecatelja(CelijaNatjecatelj** lista, char* ime) {
    CelijaNatjecatelj* trenutna = *lista;
    CelijaNatjecatelj* prethodna = NULL;
    while (trenutna != NULL) {
        if (strcmp(trenutna->element.ime, ime) == 0) {
            if (prethodna == NULL) {
                *lista = trenutna->psljedeca;
            } else {
                prethodna->psljedeca = trenutna->psljedeca;
            }
            free(trenutna);
            printf("Natjecatelj '%s' obrisan iz liste.\n", ime);
            return;
        }
        prethodna = trenutna;
        trenutna = trenutna->psljedeca;
    }
    printf("Natjecatelj '%s' nije pronađen u listi.\n", ime);
}

void ispis_podataka(CelijaNatjecatelj* lista) {
    int muskih = 0, zenskih = 0;
    printf("\n");
    CelijaNatjecatelj* trenutna = lista;
    while (trenutna != NULL) {
        printf("Ime: %s\nSpol: %c\nGodina rodjenja: %d\n\n", trenutna->element.ime, trenutna->element.spol, trenutna->element.godina_rodenja);
        if (trenutna->element.spol == 'M') {
            muskih++;
        } else if (trenutna->element.spol == 'Z') {
            zenskih++;
        }
        trenutna = trenutna->psljedeca;
    }
    printf("UKUPNO NATJECATELJA Muskih: %d; Zenskih: %d.\n", muskih, zenskih);
}
