// definir: o tipo de dados "lista"; implementar as suas funções.
// Lista Dinâmica Duplamente Encadeada

#include <stdlib.h>
#include "ListaDinEncadDupla.h"

struct elemento
{
    struct elemento *ant;
    struct aluno dados;
    struct elemento *prox;
};

typedef struct elemento Elem;

Lista *cria_lista()
{
    Lista *li = (Lista *)malloc(sizeof(Lista));

    if (li != NULL)
    {
        *li = NULL; // primeiro elemento da lista é vazio
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
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}