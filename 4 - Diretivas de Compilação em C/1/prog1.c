// ifndef - Diretiva de compilação

#include <stdio.h>

#ifndef PI // se não tiver uma definição para PI num include de cabeçalho, então ele define a constante logo abaixo.
    #define PI 3.14567 // constante
#endif // encerra o if

int main(void) {
    int valor = 5; // variável

    valor = 467;

    printf("O valor é %d\n", valor);
    printf("PI vale %f\n", PI);

    return 0;
}