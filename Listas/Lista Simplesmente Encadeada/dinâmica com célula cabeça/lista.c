#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

typedef struct no {
    TipoRegistro registro;
    struct no *prox;
} No;

struct lista {
    No *cabeca;
    int tamanho;
};

Lista *criarLista() {
    Lista *lista = (Lista *)malloc(sizeof(Lista));

    if(lista != NULL) {
        lista->cabeca = (No *)malloc(sizeof(No));
        if(lista->cabeca != NULL) {
            lista->cabeca->prox = NULL;
        }
        lista->tamanho = 0;
    }

    return lista;
}

int pegarElemento(Lista *lista, TipoRegistro *registro, TipoChave chave) {
    if(lista == NULL) {
        return 0;
    }

    No *atual = lista->cabeca->prox;

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
    novoNo->prox = lista->cabeca->prox;
    lista->cabeca->prox = novoNo;
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

    No *atual = lista->cabeca->prox;
    No *anterior = NULL;

    if(atual == NULL) {
        lista->cabeca->prox = novoNo;
    } else {
        while(atual != NULL) {
            anterior = atual;
            atual = atual->prox;
        }

        anterior->prox = novoNo;
    }

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
    novoNo->registro = registro;

    No *atual = lista->cabeca->prox;
    No *anterior = NULL;

    if(lista->cabeca->prox == NULL) {
        novoNo->prox = NULL;
        lista->cabeca->prox = novoNo;
    } else {
        if(indice == 0) {
            novoNo->prox = lista->cabeca->prox;
            lista->cabeca->prox = novoNo;
        } else if(indice == lista->tamanho) {
            while(atual != NULL) {
                anterior = atual;
                atual = atual->prox;
            }

            anterior->prox = novoNo;
            novoNo->prox = NULL;
        } else {
            for(int i=0; i <= indice-1; i++) {
                anterior = atual;
                atual = atual->prox;
                if(atual == NULL) {
                    break;
                }
            }

            anterior->prox = novoNo;
            novoNo->prox = atual;
        }
    }

    lista->tamanho++;

    return 1;
}

int removerElementoDoInicio(Lista *lista) {
    if(lista == NULL || lista->cabeca->prox == NULL) {
        return 0;
    }

    No *primeiro = lista->cabeca->prox;
    lista->cabeca->prox = lista->cabeca->prox->prox;
    free(primeiro);
    lista->tamanho--;
    return 1;
}

int removerElementoDoFinal(Lista *lista) {
    if(lista == NULL || lista->cabeca->prox == NULL) {
        return 0;
    }

    No *atual = lista->cabeca->prox;
    No *anterior = NULL;

    if(atual->prox == NULL) {
        lista->cabeca->prox = NULL;
    } else {
        while(atual->prox != NULL) {
            anterior = atual;
            atual = atual->prox;
        }
        anterior->prox = NULL;
    }


    free(atual);
    lista->tamanho--;
    return 1;
}

int removerElementoDaLista(Lista *lista, TipoChave chave) {
    if(lista == NULL || lista->cabeca->prox == NULL) {
        return 0;
    }

    No *atual = lista->cabeca->prox;
    No *anterior = NULL;

    while(atual != NULL) {
        if(atual->registro.chave == chave) {
            anterior->prox = atual->prox;
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
    if(lista == NULL || lista->cabeca->prox == NULL || lista->tamanho <= indice) {
        return 0;
    }

    No *atual = lista->cabeca->prox;

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

    if(lista->cabeca->prox == NULL) {
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
        No *no = lista->cabeca->prox;

        while(no != NULL) {
            printf("%d->", no->registro.chave);
            no = no->prox;
        }

        printf("NULL\n");
    }
}

int destruirLista(Lista *lista) {
    if(!lista) {
        No *atual = lista->cabeca;
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
