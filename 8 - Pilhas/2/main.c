#include <stdio.h>
#include "PilhaSequencial.h"

int main(void)
{
    Pilha *pi;
    pi = cria_Pilha();

    // int x = tamanho_Pilha(pi);
    // int x = Pilha_cheia(pi);
    // if(Pilha_cheia(pi))
    // int x = Pilha_vazia(pi);
    // if(Pilha_vazia(pi))

    libera_Pilha(pi);

    return 0;
}