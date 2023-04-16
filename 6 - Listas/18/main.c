#include <stdio.h>
#include "ListaDinEncadDupla.h"

int main(void)
{
    Lista *li;
    li = cria_lista();

    // int x = tamanho_lista(li);
    // int x = lista_cheia(li);
    // if(lista_cheia(li))
    // int x = lista_vazia(li);
    // if(lista_vazia(li))

    libera_lista(li);

    return 0;
}