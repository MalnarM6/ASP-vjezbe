#include<stdio.h>
#include<string.h>

int izracunajASCIIsumu(char polje[], int duljina);

int main()
{
    char poljerec[100];
    printf("Unesi jednu recenicu: ");
    fgets(poljerec, sizeof(poljerec), stdin);
    if (poljerec[strlen(poljerec)-1] == '\n') {
        poljerec[strlen(poljerec)-1] = '\0';
    }
    int suma =izracunajASCIIsumu(poljerec, strlen(poljerec));
    printf("Recenica: \"%s\"\n", poljerec);
    printf("Suma ASCII koda u recenici je: %d \n", suma);
    return 0;
}

int izracunajASCIIsumu(char polje[], int duljina)
{
    int suma=0;
    for (int i=0; i<duljina; i++)
    {
        suma+=(int)polje[i];
    }
    return suma;
}
