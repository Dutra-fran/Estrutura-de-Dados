// Usando funções

#include <stdio.h>

void mensagem() {
    printf("Bem-vindo!\n");
}

int soma(int num1, int num2) {
    return num1 + num2;
}

void proximo_char(char caractere) {
    printf("%c", caractere + 1);
}

int main(void) {
    printf("Olá...\n");

    mensagem();

    //int retorno = soma(4, 6);
    //printf("Retorno = %d", retorno);

    printf("Retorno = %d\n", soma(4, 6));

    char cara = 104;
    proximo_char(cara);

    return 0;
}