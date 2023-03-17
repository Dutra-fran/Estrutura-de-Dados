#include <stdio.h>

// Compilação via terminal

/*
    gcc arquivo-fonte (opcional) -o nome-programa
    gcc nome-do-programa.c -o nome-do-programa-executavel-.qualquer-coisa
*/

int main(void) {
    int qntd, soma = 0;

    printf("Quantos números você quer somar: ");
    scanf("%d", &qntd);

    for(int i = 0; i < qntd; i++) {
        soma += i * 2 + 3;
    }

    printf("A soma é %d", soma);

    return 0;
}