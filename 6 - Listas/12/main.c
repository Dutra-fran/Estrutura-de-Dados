#include <stdio.h>
#include <stdlib.h>
#include "ListaDinEncad.h"

int main(void)
{
    Lista *li;
    li = cria_lista();

    libera_lista(li);

    return 0;
}