#include <stdio.h>
#include "PilhaSequencial.h"

int main(void)
{
    Pilha *pi;
    pi = cria_Pilha();

    libera_Pilha(pi);

    return 0;
}