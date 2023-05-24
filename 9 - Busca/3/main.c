#include <stdio.h>
#include <stdlib.h>

// "Busca"
// - recuperação de dados armazenados
// em um repositório ou "base de dados"

// Tipo da busca depende dos dados
// - Dados estão estruturados (vetor, lista,
// árvore). Existe também busca em dados
// não estruturados.
// - Dados ordenados (ou não ordenados).
// - Valores duplicados.

int main(void)
{
    int vet[10] = {-8, -5, 1, 4, 14, 21, 23, 54, 67, 90};

    if (buscaBinaria(vet, 10, 4) != -1)
    {
        printf("Ok\n");
    }
    else
    {
        printf("ERRO\n");
    }

    return 0;
}

int buscaBinaria(int *V, int N, int elem)
{
    int i, inicio, meio, final;
    inicio = 0;
    final = N - 1;

    while (inicio <= final)
    {
        meio = (inicio + final) / 2;
        if (elem < V[meio])
        {
            final = meio - 1; // busca na metade da esquerda
        }
        else
        {
            if (elem > V[meio])
            {
                inicio = meio + 1; // busca na metade da direita
            }
            else
            {
                return meio;
            }
        }
    }
    return -1;
}