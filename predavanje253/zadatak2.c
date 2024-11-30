#include<stdio.h>
#include<math.h>
#include<string.h>

    typedef struct
    {
        int jmbag;
        char ime[11];
        char prezime[11];
        int godina_rodenja;
        int broj_ocjena;
        int ocjene[10];
    } Student;

void upisOcjena(Student *stud);
void ispisOcjena(Student stud);

int main()
{
    int i;
    int brStud;
    printf("\nUnesite broj studenata koje zelite unjeti: ");
    scanf("%d", &brStud);
    Student stud[brStud];
    for(i=0; i<brStud; i++)
    {
        upisOcjena(&stud[i]);
    }
    for(i=0; i<brStud; i++)
    {
        ispisOcjena(stud[i]);
    }
    printf("\n\n");
}

void upisOcjena(Student *stud)
{
    int i;
    printf("\tUnesite JMBAG studenta: ");
    scanf("%d", &stud->jmbag);
    printf("\nUnesite ime studenta: ");
    scanf("%s", stud->ime);
    printf("\nUnesite prezime studenta: ");
    scanf("%s", stud->prezime);
    printf("\nUnesite godinu rodenja studenta: ");
    scanf("%d", &stud->godina_rodenja);
    printf("\nUnesite broj ocjena studenta: ");
    scanf("%d", &stud->broj_ocjena);
    printf("\nUnesite ocjene studenta: ");
    for(i=0; i< stud->broj_ocjena; i++)
    {
        scanf("%d", &stud->ocjene[i]);
    }
}

void ispisOcjena(Student stud)
{
    int i;
   float pros_ocjena;
   float suma;
   for (i=0; i<stud.broj_ocjena; i++)
   {
    suma=stud.ocjene[i]+suma;
   }

   pros_ocjena=suma/stud.broj_ocjena;

   printf("\n---Podaci za studenta---\n");
   printf("JMBAG: %d", stud.jmbag);
   printf("\nIme: %s", stud.ime);
   printf("\nPrezime %s", stud.prezime);
   printf("\nGodina rodenja: %d", stud.godina_rodenja);
   printf("\nOcjene: ");
    for(i=0; i<stud.broj_ocjena; i++)
    {
        printf("%d. ocjena: %d\n", i, stud.ocjene[i]);
    }
    printf("\nProsjecna ocjena je: %.2f", pros_ocjena);
}