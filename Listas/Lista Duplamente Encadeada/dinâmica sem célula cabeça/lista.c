#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

typedef struct no {
    TipoRegistro registro;
    struct no *prox;
    struct no *ant;
} No;

struct lista {
    No *primeiro;
    int tamanho;
};

Lista *criarLista() {
    Lista *lista = (Lista *)malloc(sizeof(Lista));

    if(lista != NULL) {
        lista->primeiro = NULL;
        lista->tamanho = 0;
    }

    return lista;
}

int pegarElemento(Lista *lista, TipoRegistro *registro, TipoChave chave) {
    if(lista == NULL) {
        return 0;
    }

    No *atual = lista->primeiro;

    while(atual != NULL) {
        if(atual->registro.chave == chave) {
            *registro = atual->registro;
            return 1;
        }

        atual = atual->prox;
    }

    return 0;
}

int insereElementoNoInicio(Lista *lista, TipoRegistro registro) {
    if(lista == NULL) {
        return 0;
    }

    No *novoNo = (No *)malloc(sizeof(No));
    if(novoNo == NULL) {
        return 0;
    }

    novoNo->registro = registro;
    novoNo->prox = lista->primeiro;
    novoNo->ant = NULL;

    if(lista->primeiro != NULL) {
        lista->primeiro->ant = novoNo;
    }

    lista->primeiro = novoNo;
    lista->tamanho++;

    return 1;
}

int insereElementoNoFinal(Lista *lista, TipoRegistro registro) {
    if(lista == NULL) {
        return 0;
    }

    No *novoNo = (No *)malloc(sizeof(No));
    if(novoNo == NULL) {
        return 0;
    }

    novoNo->registro = registro;
    novoNo->prox = NULL;

    No *atual = lista->primeiro;
    No *anterior = NULL;

    if(atual == NULL) {
        novoNo->ant = NULL;
        lista->primeiro->ant = novoNo;
        lista->primeiro = novoNo;
        lista->tamanho++;
        return 1;
    }

    while(atual != NULL) {
        anterior = atual;
        atual = atual->prox;
    }

    anterior->prox = novoNo;
    novoNo->ant = anterior;
    lista->tamanho++;
    return 1;
}

int insereElementoNaLista(Lista *lista, TipoRegistro registro, int indice) {
    if(lista == NULL || lista->tamanho < indice) {
        return 0;
    }

    No *novoNo = (No *)malloc(sizeof(No));
    if(novoNo == NULL) {
        return 0;
    }

    No *atual = lista->primeiro;
    No *anterior = NULL;

    if(atual == NULL || indice == 0) {
        novoNo->registro = registro;
        novoNo->prox = NULL;

        if(indice == 0) {
            novoNo->prox = lista->primeiro;
        }

        if(lista->primeiro != NULL) {
            novoNo->ant = lista->primeiro;
            lista->primeiro->ant = novoNo;
        }

        lista->primeiro = novoNo;
        lista->tamanho++;
        return 1;
    }

    for(int i=0; i <= indice-1; i++) {
        anterior = atual;
        atual = atual->prox;
        if(atual == NULL) {
            break;
        }
    }

    novoNo->registro = registro;
    anterior->prox = novoNo;
    novoNo->ant = anterior;
    novoNo->prox = atual;
    lista->tamanho++;
    return 1;
}

int removerElementoDoInicio(Lista *lista) {
    if(lista == NULL || lista->primeiro == NULL) {
        return 0;
    }

    No *primeiro = lista->primeiro;
    lista->primeiro = lista->primeiro->prox;

    if(lista->primeiro != NULL) {
        lista->primeiro->ant = NULL;
    }

    free(primeiro);
    lista->tamanho--;
    return 1;
}

int removerElementoDoFinal(Lista *lista) {
    if(lista == NULL || lista->primeiro == NULL) {
        return 0;
    }

    No *atual = lista->primeiro;
    No *anterior = NULL;

    if(atual->prox == NULL) {
        lista->primeiro = NULL;
        free(atual);
        lista->tamanho--;
        return 1;
    }

    while(atual->prox != NULL) {
        anterior = atual;
        atual = atual->prox;
    }

    anterior->prox = NULL;
    free(atual);
    lista->tamanho--;
    return 1;
}

int removerElementoDaLista(Lista *lista, TipoChave chave) {
    if(lista == NULL || lista->primeiro == NULL) {
        return 0;
    }

    No *atual = lista->primeiro;
    No *anterior = NULL;

    while(atual != NULL) {
        if(atual->registro.chave == chave) {
            anterior->prox = atual->prox;
            atual->prox->ant = anterior;
            free(atual);
            lista->tamanho--;
            return 1;
        }
        anterior = atual;
        atual = atual->prox;
    }

    return 0;
}

int alterarElementoDaLista(Lista *lista, TipoRegistro registro, int indice) {
    if(lista == NULL || lista->primeiro == NULL || lista->tamanho <= indice) {
        return 0;
    }

    No *atual = lista->primeiro;

    for(int i=0; i < indice; i++) {
        atual = atual->prox;
    }

    atual->registro = registro;
    return 1;
}

int tamanhoDaLista(Lista *lista) {
    if(lista == NULL) {
        return -1;
    }

    return lista->tamanho;
}

int estaVazia(Lista *lista) {
    if(lista == NULL) {
        return -1;
    }

    if(lista->primeiro == NULL) {
        return 1;
    }

    return 0;
}

int estaCheia(Lista *lista) {
    if(lista == NULL) {
        return -1;
    }

    return 0;
}

void exibirElementos(Lista *lista) {
    if(lista != NULL) {
        No *no = lista->primeiro;

        while(no != NULL) {
            printf("%d->", no->registro.chave);
            no = no->prox;
        }

        printf("NULL\n");
    }
}

int destruirLista(Lista *lista) {
    if(!lista) {
        No *atual = lista->primeiro;
        No *anterior = NULL;

        while(atual != NULL) {
            anterior = atual;
            atual = atual->prox;
            free(anterior);
        }

        free(lista);

        return 1;
    }

    return 0;
}
