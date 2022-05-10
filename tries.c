#include <stdio.h>
#include <stdlib.h>
typedef struct main
{
    int npizzas;         // nº de pizzas / sizeof *pizzas
    int ningr;           // nº ingredients
    int *pizzas;         // nº da pizza
    struct tries *first[50]; //primeiro ingrediente da pizza //pode ser mudado de 50

} * Main;

typedef struct tries
{
    int ingr;           //hashed ingredient
    struct main *mpt;   // Null or if end main[qq coisa]
    struct tries *next[50];
} *Tries;

#define NPIZZAS 50
typedef Main PizzaMenu[NPIZZAS];

int main (){
    int i=0;
    PizzaMenu m;
    for (; i < NPIZZAS; i++)
        m[i]=NULL;
    
}



