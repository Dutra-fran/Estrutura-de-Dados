#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

typedef struct no {
    TipoRegistro registro;
    struct no *prox;
} No;

struct pilha {
    No *primeiro;
    int tamanho;
};

Pilha *criarPilha() {
    Pilha *pilha = (Pilha *)malloc(sizeof(Pilha));

    if(pilha != NULL) {
        pilha->primeiro = NULL;
        pilha->tamanho = 0;
    }

    return pilha;
}

int push(Pilha *p, TipoRegistro item) {
    if(p == NULL) {
        return 0;
    }

    No *no = (No *)malloc(sizeof(No));
    if(no == NULL) {
        return 0;
    }
    no->registro = item;
    no->prox = NULL;

    if(p->primeiro == NULL) {
        p->primeiro = no;
    } else {
        No *atual = p->primeiro;
        while(atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = no;
    }

    p->tamanho++;
    return 1;
}

int pop(Pilha *p, TipoRegistro *item) {
    if(p == NULL || item == NULL || p->primeiro == NULL) {
        return 0;
    }

    No *no = p->primeiro;

    if(no->prox == NULL) {
        p->primeiro = NULL;
    } else {
        No *anterior = NULL;
        while(no->prox != NULL) {
            anterior = no;
            no = no->prox;
        }
        anterior->prox = NULL;
    }

    *item = no->registro;
    free(no);
    p->tamanho--;
    return 1;
}

int peek(Pilha *p, TipoRegistro *item) {
    if(p == NULL || item == NULL || p->primeiro == NULL) {
        return 0;
    }

    No *no = p->primeiro;

    while(no->prox != NULL) {
        no = no->prox;
    }

    *item = no->registro;
    return 1;
}

int tamanho(Pilha *p) {
    if(p == NULL) {
        return -1;
    }

    return p->tamanho;
}

int estaVazia(Pilha *p) {
    if(p == NULL) {
        return -1;
    }

    if(p->primeiro == NULL) {
        return 1;
    }

    return 0;
}

int estaCheia(Pilha *p) {
    if(p == NULL) {
        return -1;
    }

    return 0;
}

void exibirElementos(Pilha *p) {
    if(p != NULL) {
        No *no = p->primeiro;
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

int destruirPilha(Pilha *p) {
    if(p == NULL) {
        return -1;
    }

    No *no = p->primeiro;

    if(no != NULL) {
        No *anterior = NULL;
        do {
            anterior = no;
            no = no->prox;
            free(anterior);
        } while(no != NULL);
    }

    free(p);
    return 1;
}
