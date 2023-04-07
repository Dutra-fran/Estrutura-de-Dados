#include <stdio.h>
#include <stdlib.h>
#include "FilaEstatica.h"

int main(void)
{
    Fila *fi;
    fi = cria_Fila();

    // int x = tamanho_Fila(fi);
    // int x = Fila_cheia(fi);
    // if(Fila_cheia(fi))
    // int x = Fila_vazia(fi);
    // if(Fila_vazia(fi))

    libera_Fila(fi);

    return 0;
}