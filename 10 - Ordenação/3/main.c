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

    selectionSort(vet, 10);

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", vet[i]);
    }

    printf("\n");

    return 0;
}

// "SelectionSort" ou "Ordenação por Seleção"
// - A cada passo, procura o menor valor do array e
// o coloca na primeira posição do array
// - Descarta-se a primeira posição do array e
// repete-se o processo para a segunda posição
// - Isso é feito para todas as posições do array

// "Performance"
// - Melhor caso: O(N^2)
// - Pior caso: O(N^2)
// - Ineficiente para grandes conjuntos de dados
// - Estável: não altera a ordem de dados iguais
void selectionSort(int *V, int N)
{
    int i, j, menor, troca;
    for (i = 0; i < N - 1; i++)
    {
        menor = i;
        for (j = i + 1; j < N; j++)
        {
            if (V[j] < V[menor])
            {
                menor = j;
            }
        }

        if (i != menor)
        {
            troca = V[i];
            V[i] = V[menor];
            V[menor] = troca;
        }
    }
}