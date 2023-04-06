#include <stdio.h>
#include <stdlib.h>
#include "ListaDinEncad.h"

int main(void)
{
    Lista *li;
    li = cria_lista();

    // int x = lista_cheia(li);
    // if(lista_cheia(li))

    // int x = lista_vazia(Lista *li);
    // if(lista_vazia(li))

    libera_lista(li);

    return 0;
}