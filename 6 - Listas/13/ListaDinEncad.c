// definir: o tipo de dados "lista"; implementar as suas funções

#include <stdlib.h>
#include "ListaDinEncad.h"

struct elemento
{
    struct aluno dados;
    struct elemento *prox;
};

typedef struct elemento Elem;

Lista *cria_lista()
{
    Lista *li = (Lista *)malloc(sizeof(Lista));

    if (li != NULL)
    {
        *li = NULL;
    }

    return li;
}

void libera_lista(Lista *li)
{
    if (li != NULL)
    {
        Elem *no;
        while ((*li) != NULL)
        {
            no = *li; // nó
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}

int tamanho_lista(Lista *li)
{
    if (li == NULL)
    {
        return 0;
    }

    int cont = 0;

    // sempre ande com um auxliar para não perder a referência do primeiro elemento da lista.
    Elem *no = *li;
    while (no != NULL)
    {
        cont++;
        no = no->prox;
    }

    return cont;
}

int lista_chiea(Lista *li)
{
    return 0;
}

int lista_vazia(Lista *li)
{
    if (li == NULL)
    {
        return 1;
    }

    if (*li == NULL)
    {
        return 1;
    }

    return 0;
}