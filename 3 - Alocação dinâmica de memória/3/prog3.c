// Funções para alocação de memória - Realloc
// Realocação de memória

#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    int qnt, *p;

    printf("Informe a quantidade de elementos para o vetor: ");
    scanf("%d", &qnt);

    int bytes = qnt * sizeof(int);
    p = (int *)malloc(bytes);

    if (p)
    {
        printf("A variável 'p' ocupa %d bytes em memória.\n", bytes);

        printf("Informe a quantidade de elementos para o vetor: ");
        scanf("%d", &qnt);

        bytes = qnt * sizeof(int);
        p = (int *)realloc(p, bytes);

        if (p)
        {
            printf("A variável 'p' ocupa %d bytes em memória.\n", bytes);
        }
        else
        {
            printf("Erro: Memória insuficiente!!!");
        }
    }
    else
    {
        printf("Erro: Memória insuficiente!!!");
    }

    // liberar a memória (desalocar o espaço em memória)
    free(p);
    p = NULL; // medida de segurança

    return 0;
}