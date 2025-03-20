#include <stdio.h>
#include <stdlib.h>
#include "fp.h"

int main()
{
    Fila *f = criarFila();
    TipoRegistro registro;

    if(estaVazia(f)) {
        printf("Fila nao esta vazia!\n");
    } else {
        printf("Fila nao esta vazia!\n");
    }

    exibirElementos(f);
    printf("Tamanho da fila: %d\n", tamanho(f));

    registro.chave = 10;
    enqueue(f, registro, 0);
    exibirElementos(f);
    peek(f, &registro);
    printf("Primeiro elemento da fila: %d\n", registro.chave);
    printf("Tamanho da fila: %d\n", tamanho(f));

    registro.chave = 13;
    enqueue(f, registro, 0);
    exibirElementos(f);
    peek(f, &registro);
    printf("Primeiro elemento da fila: %d\n", registro.chave);
    printf("Tamanho da fila: %d\n", tamanho(f));

    registro.chave = 17;
    enqueue(f, registro, 0);
    exibirElementos(f);
    peek(f, &registro);
    printf("Primeiro elemento da fila: %d\n", registro.chave);
    printf("Tamanho da fila: %d\n", tamanho(f));

    registro.chave = 6;
    enqueue(f, registro, 3);
    exibirElementos(f);
    peek(f, &registro);
    printf("Primeiro elemento da fila: %d\n", registro.chave);
    printf("Tamanho da fila: %d\n", tamanho(f));

    registro.chave = 9;
    enqueue(f, registro, 3);
    exibirElementos(f);
    peek(f, &registro);
    printf("Primeiro elemento da fila: %d\n", registro.chave);
    printf("Tamanho da fila: %d\n", tamanho(f));

    registro.chave = 3;
    enqueue(f, registro, 2);
    exibirElementos(f);
    peek(f, &registro);
    printf("Primeiro elemento da fila: %d\n", registro.chave);
    printf("Tamanho da fila: %d\n", tamanho(f));

    registro.chave = 22;
    enqueue(f, registro, 10);
    exibirElementos(f);
    peek(f, &registro);
    printf("Primeiro elemento da fila: %d\n", registro.chave);
    printf("Tamanho da fila: %d\n", tamanho(f));

    if(alterarPrioridade(f, 22, 1)) {
        printf("Prioridade alterada com sucesso do elemento de chave 22 para atual prioridade 1.\n");
        exibirElementos(f);
        peek(f, &registro);
        printf("Primeiro elemento da fila: %d\n", registro.chave);
    } else {
        printf("Erro ao alterar a prioridade do elemento 22.\n");
    }

    if(alterarPrioridade(f, 22, 2)) {
        printf("Prioridade alterada com sucesso do elemento de chave 22 para atual prioridade 2.\n");
        exibirElementos(f);
        peek(f, &registro);
        printf("Primeiro elemento da fila: %d\n", registro.chave);
    } else {
        printf("Erro ao alterar a prioridade do elemento 22.\n");
    }

    if(alterarPrioridade(f, 22, 3)) {
        printf("Prioridade alterada com sucesso do elemento de chave 22 para atual prioridade 3.\n");
        exibirElementos(f);
        peek(f, &registro);
        printf("Primeiro elemento da fila: %d\n", registro.chave);
    } else {
        printf("Erro ao alterar a prioridade do elemento 22.\n");
    }

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
