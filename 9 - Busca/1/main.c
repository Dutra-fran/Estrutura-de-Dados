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

    if (buscaLinear(vet, 10, 4) != -1)
    {
        printf("Ok\n");
    }
    else
    {
        printf("ERRO\n");
    }

    return 0;
}

int buscaLinear(int *V, int N, int elem)
{
    int i;
    for (i = 0; i < N; i++)
    {
        if (elem == V[i])
        {
            return i; // elemento encontrado
        }
    }
    return -1; // elemento não encontrado
}
