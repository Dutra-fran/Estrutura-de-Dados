// definir: o tipo de dados "lista"; implementar as suas funções.

#include <stdlib.h>
#include "ListaDinEncadCirc.h"

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
    if (li != NULL && (*li) != NULL)
    {
        Elem *aux, *no = *li;
        // Como é uma lista dinâmica circular, ele vai rodar a lista toda até chegar no primeiro elemento novamente.
        while ((*li) != no->prox)
        {
            aux = no;
            no = no->prox;
            free(aux);
        }
        free(no);
        free(li);
    }
}

int tamanho_lista(Lista *li)
{
    if (li == NULL || (*li) == NULL)
    {
        return 0;
    }

    int cont = 0;
    Elem *no = *li;
    do
    {
        cont++;
        no = no->prox;
    } while (no != (*li));

    return cont;
}

int lista_cheia(Lista *li)
{
    return 0;
}

int lista_vazia(Lista *li)
{
    if (li == NULL && (*li) == NULL)
    {
        return 1;
    }

    return 0;
}