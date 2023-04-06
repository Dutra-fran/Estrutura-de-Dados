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