// definir: o tipo de dados "fila"; implementar as suas funções.

#include <stdlib.h>
#include "FilaEstatica.h"

struct fila
{
    int inicio, final, qtd;
    struct aluno dados[MAX];
};

Fila *cria_Fila()
{
    Fila *fi = (Fila *)malloc(sizeof(struct fila));

    if (fi != NULL)
    {
        fi->inicio = 0;
        fi->final = 0;
        fi->qtd = 0;
    }

    return fi;
}

void libera_Fila(Fila *fi)
{
    free(fi);
}

int tamanho_Fila(Fila *fi)
{
    if (fi == NULL)
    {
        return -1;
    }

    return fi->qtd;
}

int Fila_cheia(Fila *fi)
{
    if (fi == NULL)
    {
        return -1;
    }

    if (fi->qtd == MAX)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Fila_vazia(Fila *fi)
{
    if (fi == NULL)
    {
        return -1;
    }

    if (fi->qtd == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}