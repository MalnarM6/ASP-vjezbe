#include<stdio.h>
#include<math.h>
#include<string.h>


typedef struct{
    float radijus;
    float povrsina;
    char boja[11];
    int kolicina;
} Krug;

typedef struct{
    Krug element;
    struct Celija *psljedeca
} CelijaKrug;

void ispis(CelijaKrug* ppolaznaCelija);
void ubaci(Krug noviElement, CelijaKrug* pcelija);



int main()
{
    
}