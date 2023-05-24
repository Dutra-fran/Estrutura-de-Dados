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

    mergeSort(vet, 0, 9);

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", vet[i]);
    }

    printf("\n");

    return 0;
}

// "MergeSort" ou "Ordenação por Mistura"
// - Ideia básica: Dividir e Conquistar
// - Divide, recursivamente, o conjunto de dados
// até que cada subconjunto possua 1 elemento
// - Combina 2 subconjuntos de forma
// a obter 1 conjunto maior e ordenado
// Esse processo se repete até que exista
// apenas 1 conjunto

// "Performance"
// - Melhor caso: O(N log N)
// - Pior caso: O(N log N)
// - Estável: não altera a ordem dados iguais
// - Desvantagens: recursivo e usa um vetor
// auxiliar durante a ordenação
void mergeSort(int *V, int inicio, int fim)
{
    int meio;
    if (inicio < fim)
    {
        meio = floor((inicio + fim) / 2);
        mergeSort(V, inicio, meio);
        mergeSort(V, meio + 1, fim);
        merge(V, inicio, meio, fim);
    }
}

void merge(int *V, int inicio, int meio, int fim)
{
    int *temp, p1, p2, tamanho, i, j, k;
    int fim1 = 0, fim2 = 0;

    tamanho = fim - inicio + 1;
    p1 = inicio;
    p2 = meio + 1;
    temp = (int *)malloc(tamanho * sizeof(int));

    if (temp != NULL)
    {
        for (i = 0; i < tamanho; i++)
        {
            if (!fim1 && !fim2)
            {
                if (V[p1] < V[p2])
                {
                    temp[i] = V[p1++];
                }
                else
                {
                    temp[i] = V[p2++];
                }

                if (p1 > meio)
                {
                    fim1 = 1;
                }

                if (p2 > fim)
                {
                    fim2 = 1;
                }
            }
            else
            {
                if (!fim1)
                {
                    temp[i] = V[p1++];
                }
                else
                {
                    temp[i] = V[p2++];
                }
            }
        }
        for (j = 0, k = inicio; j < tamanho; j++, k++)
        {
            V[k] = temp[j];
        }
    }
    free(temp);
}