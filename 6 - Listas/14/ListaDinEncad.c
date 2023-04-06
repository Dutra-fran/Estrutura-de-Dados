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

int insere_lista_inicio(Lista *li, struct aluno al)
{
    if (li == NULL)
    {
        return 0;
    }

    Elem *no = (Elem *)malloc(sizeof(Elem));
    if (no == NULL)
    {
        return 0;
    }

    no->dados = al;
    no->prox = (*li);
    *li = no;

    return 1;
}

int insere_lista_final(Lista *li, struct aluno al)
{
    if (li == NULL)
    {
        return 0;
    }

    Elem *no = (Elem *)malloc(sizeof(Elem));
    if (no == NULL)
    {
        return 0;
    }

    no->dados = al;
    no->prox = NULL;

    if ((*li) == NULL)
    { // lista vazia: insere início
        *li = no;
    }
    else
    {
        Elem *aux = *li;
        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }
        aux->prox = no;
    }

    return 1;
}

int insere_lista_ordenada(Lista *li, struct aluno al)
{
    if (li == NULL)
    {
        return 0;
    }

    Elem *no = (Elem *)malloc(sizeof(Elem));
    if (no == NULL)
    {
        return 0;
    }

    no->dados = al;
    if (lista_vazia(li))
    { // insere início
        no->prox = (*li);
        *li = no;
        return 1;
    }
    else
    { // procura onde inserir
        Elem *ant, *atual = *li;
        while (atual != NULL && atual->dados.matricula < al.matricula)
        {
            ant = atual;
            atual = atual->prox;
        }

        if (atual == *li)
        { // insere início
            no->prox = (*li);
            *li = no;
        }
        else
        {
            no->prox = ant->prox;
            ant->prox = no;
        }
    }

    return 1;
}