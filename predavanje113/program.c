#include <stdio.h>
#include <math.h>
#include <string.h>

int traziMin(int poljeB[], int indeks, int *povratna);

int main() {
    int poljeB[6], i;
    int trazimin;
    int indeks;
    int povratna;
    int adresa;

    printf("Unesite 6 cijelih brojeva: \n");
    for(i = 0; i < 6; i++) {
        printf("\nBroj %d: ", i);
        scanf("%d", &poljeB[i]);
    }

    trazimin = traziMin(poljeB, 6, &povratna);
    printf("Najmanji element polja je %d, na indeksu %d, na adresi %p", povratna, trazimin, &poljeB[trazimin]);
    return 0;
}

int traziMin(int poljeB[], int indeks, int *povratna) {
    int i;
    int najmanji = poljeB[0]; 
    int indeksNajmanjeg = 0;

    for(i = 1; i < indeks; i++) {
        if (poljeB[i] < najmanji) {
            najmanji = poljeB[i];
            indeksNajmanjeg = i;
        }
    }

    *povratna = najmanji;
    return indeksNajmanjeg;
}
