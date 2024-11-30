#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct{
    char vrsta[11];
    char sobna[3];
    char bojaCvijeta[11];

}Biljka;

typedef struct{
    Biljka element;
    struct Celija* psljedeca;

}CelijaBiljka;

//voidi
CelijaBiljka* pronadjiZadnju(CelijaBiljka* ppolaznaCelija);
void ubaciBiljku(Biljka noviElement, CelijaBiljka* pcelija);
void upisBiljke(Biljka* pbiljka);
void ispisBiljke(CelijaBiljka* ppolaznaCelija);
void pronadjiBiljku(CelijaBiljka* ppolaznaCelija, char bojaCvijeta[]);


int main()
{
    int brB, i;
    char bojaCvijeta[11];
    Biljka biljka;
    CelijaBiljka* ppolaznaCelija;
    ppolaznaCelija = (CelijaBiljka*)malloc(sizeof(CelijaBiljka));
    ppolaznaCelija->psljedeca=NULL;
    CelijaBiljka* pzadnjaCelija;
    
    printf("Koliko biljaka zelite unijeti u listu?\n");
    scanf("%d", &brB);

    for(i=0; i<brB; i++)
    {
        upisBiljke(&biljka);
        pzadnjaCelija=pronadjiZadnju(ppolaznaCelija);
        ubaciBiljku(biljka, pzadnjaCelija);

    }

    ispisBiljke(ppolaznaCelija);

    printf("\nKoju boju cvijeta zelite naci: ");
    scanf("%10s", bojaCvijeta);
    pronadjiBiljku(ppolaznaCelija, bojaCvijeta);

    ispisBiljke(ppolaznaCelija);





}

CelijaBiljka* pronadjiZadnju(CelijaBiljka* ppolaznaCelija)
{
    CelijaBiljka* pzadnjaCelija = ppolaznaCelija;
    
    while (pzadnjaCelija->psljedeca != NULL)
    {
        pzadnjaCelija = pzadnjaCelija->psljedeca;
    }
    return pzadnjaCelija;
}

void ubaciBiljku(Biljka noviElement, CelijaBiljka* pcelija)
{
    CelijaBiljka* novaCelija = (CelijaBiljka*)malloc(sizeof(CelijaBiljka));
    novaCelija->element = noviElement;
    novaCelija->psljedeca = NULL;

    CelijaBiljka* zadnjaCelija = pronadjiZadnju(pcelija);
    zadnjaCelija->psljedeca = novaCelija;
}

void upisBiljke(Biljka* pbiljka)
{
    char enter;
    printf("\nUnesite vrstu biljke: ");
    scanf("%10s", pbiljka->vrsta);
    scanf("%c", &enter);
;
	do {
		printf("\t Sobna? (da/ne): ");
		scanf("%2s", pbiljka->sobna, 3);
		
		if (strcmp(pbiljka->sobna, "da") != 0 && strcmp(pbiljka->sobna, "ne") != 0)
			printf("\n\t Moguci odgovori su da/ne: ");
    	} while (strcmp(pbiljka->sobna, "da") != 0 && strcmp(pbiljka->sobna, "ne") != 0);
    printf("\nUnesite boju cvijeta: ");
    scanf("%10s", pbiljka->bojaCvijeta);
}

void ispisBiljke(CelijaBiljka* ppolaznaCelija)
{
    int el=0;
    CelijaBiljka* ptrenutnaCelija =ppolaznaCelija;
    while (ptrenutnaCelija->psljedeca != NULL)
    {
        ptrenutnaCelija = ptrenutnaCelija->psljedeca;
        el++;
        printf("\n%d biljka: ", el);
        printf("\n vrsta: %s", ptrenutnaCelija->element.vrsta);
        printf("\n sobna: %s", ppolaznaCelija->element.sobna);
        printf("\n bojaCvijeta: %s", ppolaznaCelija->element.bojaCvijeta);
    }
    printf("Ukupan broj biljaka je %d", el);
}

void pronadjiBiljku(CelijaBiljka* ppolaznaCelija, char bojaCvijeta[])
{
	CelijaBiljka* ptrenutnaCelija = ppolaznaCelija;
	int brBoje = 0;

	printf("\n\n\n --- BILJKE BOJE %s --- ", bojaCvijeta);

	while (ptrenutnaCelija->psljedeca != NULL)
	{
		ptrenutnaCelija = ptrenutnaCelija->psljedeca;

		if (strcmp(ptrenutnaCelija->element.bojaCvijeta, bojaCvijeta) == 0)
		{
			printf("\n\n\t\t           vrsta: %s ", ptrenutnaCelija->element.vrsta);
			printf("\n\t\t           sobna: %s ", ptrenutnaCelija->element.sobna);
			brBoje++;
		}
	}

	if (brBoje == 0)
		printf("\n U listi nema biljaka te boje");
}