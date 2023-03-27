#include <stdio.h>
#include <stdlib.h>

struct ponto
{
    float x;
    float y;
    struct ponto *prox;
};

typedef struct ponto Ponto;

Ponto *listaPontos; // aponta para o início da lista

int length = 0;

void addIndex(float x, float y, int index)
{
    Ponto *p = (Ponto *)malloc(sizeof(Ponto));
    p->x = x;
    p->y = y;

    if (index > length)
    {
        printf("Posição inválida!");
    }
    else
    {
        if (index == 0)
        {
            p->prox = listaPontos;
            listaPontos = p;
        }
        else
        {
            Ponto *auxLista = listaPontos;
            int i = 0;
            while (i != index - 1)
            {
                auxLista = auxLista->prox;
                i++;
            }
            p->prox = auxLista->prox;
            auxLista->prox = p;
        }
        length++;
    }
}

void imprime(Ponto *p)
{
    if (p != NULL)
    {
        printf("Ponto(%.1f, %.1f)\n", p->x, p->y);
        imprime(p->prox);
    }
}

int main(void)
{
    addIndex(1, 1, 0);
    addIndex(2, 4, 1);
    addIndex(4, 16, 2);
    addIndex(3, 9, 2);
    addIndex(0, 0, 0);

    Ponto *auxLista = listaPontos;
    imprime(auxLista);

    return 0;
}