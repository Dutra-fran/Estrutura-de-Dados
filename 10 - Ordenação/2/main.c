#include <stdio.h>
#include <stdlib.h>

// "Ordenação"
// - É a tarefa de colocar um conjunto de
// dados em uma determinada ordem
// - Permite acesso mais eficiente aos dados

// "Algoritmo de ordenação"
// - É o algoritmo que coloca os elementos
// de uma dada sequência em uma certa ordem

int main(void)
{
    int vet[10] = {67, 90, -8, 1, 21, 23, 54, -5, 4, 14};

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", vet[i]);
    }

    printf("\n");

    insertionSort(vet, 10);

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", vet[i]);
    }

    printf("\n");

    return 0;
}

// "InsertionSort" ou "Ordenação por Inserção"
// - Simular a ordenação de cartas de baralho
// com as mãos
// - Pega-se uma carta de cada vez e a coloca em
// seu devido lugar, sempre deixando as cartas
// da mão em ordem

// "Performance"
// - Melhor caso: O(N)
// - Pior caso: O(N^2)
// - Eficiente para conjuntos pequenos de dados
// - Estável: não altera a ordem de dados iguais
// - Capaz de ordenar os dados a medida em que
// os recebe (tempo real)
void insertionSort(int *V, int N)
{
    int i, j, aux;
    for (i = 1; i < N; i++)
    {
        aux = V[i];
        for (j = i; (j > 0) && (aux < V[j - 1]); j--)
        {
            V[j] = V[j - 1];
        }
        V[j] = aux;
    }
}