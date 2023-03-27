#include <stdio.h>
#include "ListaSequencial.h"

int main(void)
{
    // Exemplo de como estar utilizando meu TAD de lista
    Lista *li;
    li = cria_lista();

    int x = tamanho_lista(li);
    printf("Tamanho da lista: %d\n", x);

    if (lista_cheia(li))
    {
        printf("A lista está cheia!");
    }

    libera_lista(li);

    return 0;
}