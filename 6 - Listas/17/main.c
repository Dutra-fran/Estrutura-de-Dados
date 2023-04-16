#include <stdio.h>
#include "ListaDinEncadDupla.h"

int main(void)
{
    Lista *li;
    li = cria_lista();

    libera_lista(li);

    return 0;
}