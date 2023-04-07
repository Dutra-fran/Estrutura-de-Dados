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

    // int x = insere_Fila(fi, dados_aluno);
    // int x = remove_Fila(fi);
    // int x = consulta_Fila(fi, &dados_aluno);

    libera_Fila(fi);

    return 0;
}