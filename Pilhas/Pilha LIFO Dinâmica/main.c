#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main()
{
    Pilha *p = criarPilha();
    TipoRegistro registro;

    exibirElementos(p);
    if(estaVazia(p)) {
        printf("Pilha esta vazia!\n");
    } else {
        printf("Pilha nao esta vazia!\n");
    }
    printf("Tamanho da pilha: %d\n", tamanho(p));

    registro.chave = 10;
    push(p, registro);
    exibirElementos(p);
    peek(p, &registro);
    printf("Elemento no topo da pilha: %d\n", registro.chave);
    if(estaVazia(p)) {
        printf("Pilha esta vazia!\n");
    } else {
        printf("Pilha nao esta vazia!\n");
    }
    printf("Tamanho da pilha: %d\n", tamanho(p));

    registro.chave = 20;
    push(p, registro);
    exibirElementos(p);
    peek(p, &registro);
    printf("Elemento no topo da pilha: %d\n", registro.chave);
    printf("Tamanho da pilha: %d\n", tamanho(p));

    registro.chave = 7;
    push(p, registro);
    exibirElementos(p);
    peek(p, &registro);
    printf("Elemento no topo da pilha: %d\n", registro.chave);
    printf("Tamanho da pilha: %d\n", tamanho(p));

    registro.chave = 14;
    push(p, registro);
    exibirElementos(p);
    peek(p, &registro);
    printf("Elemento no topo da pilha: %d\n", registro.chave);
    printf("Tamanho da pilha: %d\n", tamanho(p));

    registro.chave = 31;
    push(p, registro);
    exibirElementos(p);
    peek(p, &registro);
    printf("Elemento no topo da pilha: %d\n", registro.chave);
    printf("Tamanho da pilha: %d\n", tamanho(p));

    pop(p, &registro);
    printf("Elemento retirado: %d\n", registro.chave);
    exibirElementos(p);
    peek(p, &registro);
    printf("Elemento no topo da pilha: %d\n", registro.chave);
    printf("Tamanho da pilha: %d\n", tamanho(p));

    pop(p, &registro);
    printf("Elemento retirado: %d\n", registro.chave);
    exibirElementos(p);
    peek(p, &registro);
    printf("Elemento no topo da pilha: %d\n", registro.chave);
    printf("Tamanho da pilha: %d\n", tamanho(p));

    pop(p, &registro);
    printf("Elemento retirado: %d\n", registro.chave);
    exibirElementos(p);
    peek(p, &registro);
    printf("Elemento no topo da pilha: %d\n", registro.chave);
    printf("Tamanho da pilha: %d\n", tamanho(p));

    pop(p, &registro);
    printf("Elemento retirado: %d\n", registro.chave);
    exibirElementos(p);
    peek(p, &registro);
    printf("Elemento no topo da pilha: %d\n", registro.chave);
    printf("Tamanho da pilha: %d\n", tamanho(p));

    if(estaCheia(p)) {
        printf("Pilha esta cheia!\n");
    } else {
        printf("Pilha nao esta cheia!\n");
    }

    destruirPilha(p);
    return 0;
}
