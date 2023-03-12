// Escrevendo funções

// Estrutura das funções
/*
- tipo de retorno
- nome
- parâmetros de entrada (opcional)
- implementação
- retorno (opcional)
*/

#include <stdio.h>

void mensagem() {
    printf("Bem-vindo!");
}

int soma(int num1, int num2) {
    return num1 + num2;
}

void proximo_char(char caractere) {
    printf("%c", caractere + 1);
}

int main(void) {
    printf("Olá...");

    return 0;
}