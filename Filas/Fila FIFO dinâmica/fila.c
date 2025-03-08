#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

typedef struct no {
    TipoRegistro registro;
    struct no *prox;
} No;

struct fila {
    No *primeiro;
    int tamanho;
};

Fila *criarFila() {
    Fila *f = (Fila *)malloc(sizeof(Fila));

    if(f != NULL) {
        f->primeiro = NULL;
        f->tamanho = 0;
    }

    return f;
}

int enqueue(Fila *f, TipoRegistro registro) {
    if(f == NULL) {
        return 0;
    }

    No *no = (No *)malloc(sizeof(No));

    if(no == NULL) {
        return 0;
    }

    no->registro = registro;
    no->prox = NULL;

    if(f->primeiro == NULL) {
        f->primeiro = no;
    } else {
        No *atual = f->primeiro;
        while(atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = no;
    }

    f->tamanho++;
    return 1;
}

int dequeue(Fila *f, TipoRegistro *registro) {
    if(f == NULL || registro == NULL || f->primeiro == NULL) {
        return 0;
    }

    No *no = f->primeiro;
    f->primeiro = f->primeiro->prox;
    *registro = no->registro;
    free(no);
    f->tamanho--;
    return 1;
}

int peek(Fila *f, TipoRegistro *registro) {
    if(f == NULL || registro == NULL || f->primeiro == NULL) {
        return 0;
    }

    *registro = f->primeiro->registro;
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

    if(f->primeiro == NULL) {
        return 1;
    }

    return 0;
}

int estaCheia(Fila *f) {
    if(f == NULL) {
        return -1;
    }

    return 0;
}

void exibirElementos(Fila *f) {
    if(f != NULL) {
        No *no = f->primeiro;
        if(no == NULL) {
            printf("NULL\n");
        } else {
            do {
                printf("%d->", no->registro.chave);
                no = no->prox;
            } while(no != NULL);
            printf("NULL\n");
        }
    }
}

int destruirFila(Fila *f) {
    if(f == NULL) {
        return 0;
    }

    if(f->primeiro != NULL) {
        No *anterior = NULL, *atual = f->primeiro;
        do {
            anterior = atual;
            atual = atual->prox;
            free(anterior);
        } while(atual != NULL);
    }

    free(f);

    return 1;
}
