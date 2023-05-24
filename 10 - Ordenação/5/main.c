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

    quickSort(vet, 0, 9);

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", vet[i]);
    }

    printf("\n");

    return 0;
}

// "QuickSort" ou "Ordenação por Troca de Partições"
// - Ideia básica: Dividir e Conquistar
// - Um elemento é escolhido como pivô
// - "Particionar": os dados são rearranjados
// (valores menores do que o pivô são colocados
// antes dele e os maiores, depois)
// - Recursivamente ordena as 2 partições

// "Performance"
// - Melhor caso: O(N log N)
// - Pior caso (raro): O(N^2)
// - Estável: não altera a ordem de dados iguais
// - Desvantagens: como escolher o pivô?
void quickSort(int *V, int inicio, int fim)
{
    int pivo;
    if (fim > inicio)
    {
        pivo = particiona(V, inicio, fim);
        quickSort(V, inicio, pivo - 1);
        quickSort(V, pivo + 1, fim);
    }
}

int particiona(int *V, int inicio, int final)
{
    int esq, dir, pivo, aux;
    esq = inicio;
    dir = final;
    pivo = V[inicio];

    while (esq < dir)
    {
        while (esq <= final && V[esq] <= pivo)
        {
            esq++;
        }

        while (dir >= 0 && V[dir] > pivo)
        {
            dir--;
        }

        if (esq < dir)
        {
            aux = V[esq];
            V[esq] = V[dir];
            V[dir] = aux;
        }
    }
    V[inicio] = V[dir];
    V[dir] = pivo;
    return dir;
}