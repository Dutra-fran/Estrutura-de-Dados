#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

#define TAM_MAX 101

struct fila {
    TipoRegistro *vetor;
    int inicio;
    int fim;
    int tamanho;
};

Fila *criarFila() {
    Fila *f = (Fila *)malloc(sizeof(Fila));

    if(f != NULL) {
        f->vetor = (TipoRegistro *)malloc(TAM_MAX * sizeof(TipoRegistro));
        f->inicio = 0;
        f->fim = 0;
        f->tamanho = 0;
    }

    return f;
}

int enqueue(Fila *f, TipoRegistro registro) {
    if(f == NULL || estaCheia(f)) {
        return 0;
    }

    f->vetor[f->fim] = registro;
    f->fim = (f->fim + 1) % TAM_MAX;
    f->tamanho++;
    return 1;
}

int dequeue(Fila *f, TipoRegistro *registro) {
    if(f == NULL || registro == NULL || estaVazia(f)) {
        return 0;
    }

    *registro = f->vetor[f->inicio++];
    f->inicio = f->inicio % TAM_MAX;
    f->tamanho--;
    return 1;
}

int peek(Fila *f, TipoRegistro *registro) {
    if(f == NULL || registro == NULL || estaVazia(f)) {
        return 0;
    }

    *registro = f->vetor[f->inicio];
    return 1;
}

int tamanho(Fila *f) {
    if(f == NULL) {
        return -1;
    }

    return f->tamanho;
}

int estaVazia(Fila *f) {
    if(f == NULL) {
        return -1;
    }

    if(f->inicio == f->fim) {
        return 1;
    }

    return 0;
}

int estaCheia(Fila *f) {
    if(f == NULL) {
        return -1;
    }

    if(f->fim + 1 == f->inicio || (f->fim + 1 == TAM_MAX && f->inicio == 0)) {
        return 1;
    }

    return 0;
}

void exibirElementos(Fila *f) {
    if(f != NULL) {
        if(estaVazia(f)) {
            printf("NULL\n");
        } else {
            for(int i = f->inicio; i < f->fim; i++) {
                printf("%d", f->vetor[i].chave);
                if(i != f->fim - 1) {
                    printf("->");
                }
            }
            printf("\n");
        }
    }
}

int destruirFila(Fila *f) {
    if(f == NULL) {
        return 0;
    }

    free(f->vetor);
    free(f);

    return 1;
}
