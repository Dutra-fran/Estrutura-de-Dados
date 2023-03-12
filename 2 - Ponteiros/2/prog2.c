// Usando ponteiros

#include <stdio.h>

int main() {
    int n; // variável que guarda seu valor na memória

    // declarando
    int* p; // ponteiro é um valor que aponta para um endereço de memória

    printf("Informe um número: ");
    scanf("%d", &n);

    // inicializando o ponteiro
    p = &n;

    printf("O número informado foi %d\n", n);

    printf("Endereço de memória: %p\n", &n);

    printf("Endereço do ponteiro: %p\n", p);

    return 0;
}
