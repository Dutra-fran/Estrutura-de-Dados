#include <stdio.h>
#include "FilaDin.h"

int main(void)
{
    Fila *fi;
    fi = cria_Fila();

    libera_Fila(fi);

    return 0;
}