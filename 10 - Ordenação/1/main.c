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

    bubbleSort(vet, 10);

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", vet[i]);
    }

    printf("\n");

    return 0;
}

// "BubbleSort" ou "Ordenação por Bolha"
// - Compara pares de elementos adjacentes e
// os troca de lugar se estiverem na ordem errada
// - Esse processo se repete até que mais nenhuma
// troca seja necessária (elementos já ordenados)

// "Performance"
// - Melhor caso: O(N)
// - Pior caso: O(N^2)
// Não recomendado para grandes conjuntos de dados
void bubbleSort(int *V, int N)
{
    int i, continua, aux, fim = N;
    do
    {
        continua = 0;
        for (i = 0; i < fim - 1; i++)
        {
            if (V[i] > V[i + 1])
            {
                aux = V[i];
                V[i] = V[i + 1];
                V[i + 1] = aux;
                continua = i;
            }
        }
        fim--;
    } while (continua != 0);
}