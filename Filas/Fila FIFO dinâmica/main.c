#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main()
{
    Fila *f = criarFila();
    TipoRegistro registro;

    if(estaVazia(f)) {
        printf("Fila esta vazia!\n");
    } else {
        printf("Fila nao esta vazia!\n");
    }

    exibirElementos(f);
    printf("Tamanho da fila: %d\n", tamanho(f));

    registro.chave = 10;
    enqueue(f, registro);
    exibirElementos(f);
    peek(f, &registro);
    printf("Primeiro elemento da fila: %d\n", registro.chave);
    printf("Tamanho da fila: %d\n", tamanho(f));

    if(estaVazia(f)) {
        printf("Fila esta vazia!\n");
    } else {
        printf("Fila nao esta vazia!\n");
    }

    registro.chave = 3;
    enqueue(f, registro);
    exibirElementos(f);
    peek(f, &registro);
    printf("Primeiro elemento da fila: %d\n", registro.chave);
    printf("Tamanho da fila: %d\n", tamanho(f));

    registro.chave = 7;
    enqueue(f, registro);
    exibirElementos(f);
    peek(f, &registro);
    printf("Primeiro elemento da fila: %d\n", registro.chave);
    printf("Tamanho da fila: %d\n", tamanho(f));

    registro.chave = 15;
    enqueue(f, registro);
    exibirElementos(f);
    peek(f, &registro);
    printf("Primeiro elemento da fila: %d\n", registro.chave);
    printf("Tamanho da fila: %d\n", tamanho(f));

    registro.chave = 13;
    enqueue(f, registro);
    exibirElementos(f);
    peek(f, &registro);
    printf("Primeiro elemento da fila: %d\n", registro.chave);
    printf("Tamanho da fila: %d\n", tamanho(f));

    dequeue(f, &registro);
    exibirElementos(f);
    printf("Elemento retirado: %d\n", registro.chave);
    peek(f, &registro);
    printf("Primeiro elemento da fila: %d\n", registro.chave);
    printf("Tamanho da fila: %d\n", tamanho(f));

    dequeue(f, &registro);
    exibirElementos(f);
    printf("Elemento retirado: %d\n", registro.chave);
    peek(f, &registro);
    printf("Primeiro elemento da fila: %d\n", registro.chave);
    printf("Tamanho da fila: %d\n", tamanho(f));

    dequeue(f, &registro);
    exibirElementos(f);
    printf("Elemento retirado: %d\n", registro.chave);
    peek(f, &registro);
    printf("Primeiro elemento da fila: %d\n", registro.chave);
    printf("Tamanho da fila: %d\n", tamanho(f));

    destruirFila(f);

    return 0;
}
