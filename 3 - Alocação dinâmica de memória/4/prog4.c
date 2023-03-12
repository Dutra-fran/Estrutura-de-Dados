// Alocação de arrays multidimensionais

#include <stdio.h>
#include <stdlib.h>

/*  Matriz bi-dimensional
    [00] [01] [02]
    [10] [11] [12]
    [20] [21] [22]
*/

int main(void)
{
    int *p, linhas = 3, colunas = 3;

    p = (int *)malloc(linhas * colunas * sizeof(int));

    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            p[i * colunas + j] = 3 * i + j;
        }
    }

    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            printf("%d\n", p[i * colunas + j]);
        }
    }

    free(p);
    p = NULL;

    return 0;
}