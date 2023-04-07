#include <stdlib.h>
#include "PilhaSequencial.h"

struct pilha
{
    int qtd;
    struct aluno dados[MAX];
};

Pilha *cria_Pilha()
{
    Pilha *pi;
    pi = (Pilha *)malloc(sizeof(struct pilha));

    if (pi != NULL)
    {
        pi->qtd = 0;
    }

    return pi;
}

void libera_Pilha(Pilha *pi)
{
    free(pi);
}

int tamanho_Pilha(Pilha *pi)
{
    if (pi == NULL)
    {
        return -1;
    }
    else
    {
        return pi->qtd;
    }
}

int Pilha_cheia(Pilha *pi)
{
    if (pi == NULL)
    {
        return -1;
    }

    return (pi->qtd == MAX);
}

int Pilha_vazia(Pilha *pi)
{
    if (pi == NULL)
    {
        return -1;
    }

    return (pi->qtd == 0);
}