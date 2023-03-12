// Funções para alocação de memória - Calloc

#include <stdio.h>
#include <stdlib.h>

/*
    qnt 3;

    Malloc
    [3] [66] [99]

    Calloc
    [0] [0] [0]
*/

int main(void)
{

    int qnt, *p;

    printf("Informe a quantidade de elementos para o vetor: ");
    scanf("%d", &qnt);

    int bytes = qnt * sizeof(int);
    // p = (int*)malloc(bytes); // Não remove lixo da memória
    p = (int *)calloc(qnt, sizeof(int)); // zera o espaço em memória

    if (p)
    {
        printf("A variável 'p' ocupa %d bytes em memória.\n", bytes);
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