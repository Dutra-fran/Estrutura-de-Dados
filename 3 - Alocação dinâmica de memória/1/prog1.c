// Funções para alocação de memória - Malloc

#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    int qnt, *p;

    printf("Informe a quantidade de elementos para o vetor: ");
    scanf("%d", &qnt);

    int bytes = qnt * sizeof(int);
    p = (int *)malloc(bytes);

    // Verificar se foi possível ou não alocar memória
    if (p)
    {
        for (int i = 0; i < qnt; i++)
        {
            printf("Informe o valor para a posição %d do vetor: ", i);
            scanf("%d", &p[i]);
        }

        for (int i = 0; i < qnt; i++)
        {
            printf("No vetor 'p[%d]' está o valor: %d\n", i, p[i]);
        }

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