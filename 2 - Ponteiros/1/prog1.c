#include <stdio.h>

// endereço de memória como parâmetro de entrada
void incrementa(int* valor) {
    printf("Antes de incrementar.\n");
    printf("O contador vale %d\n", (*valor)); // valor
    printf("O endereço de memória é %d\n", valor); // endereço de memória que ele aponta

    printf("Depois de incrementar.\n");
    printf("O contador vale %d\n", ++(*valor));
    printf("O endereço de memória é %d\n", valor);
}

int main(void) {
    // quando declaramos uma variável, a linguagem C
    // aloca um espaço em memória para colocar
    // este valor
    int contador = 10;

    printf("Antes de incrementar.\n");
    printf("O contador vale %d\n", contador);
    printf("O endereço de memória é %d\n", &contador); // endereço de memória

    // cópia por valor
    incrementa(&contador);

    printf("Depois de incrementar.\n");
    printf("O contador vale %d\n", contador);
    printf("O endereço de memória é %d\n", &contador);

    return 0;
}
