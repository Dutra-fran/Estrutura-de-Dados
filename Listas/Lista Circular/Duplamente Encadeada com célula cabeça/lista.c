#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

typedef struct no {
    TipoRegistro registro;
    struct no *prox;
    struct no *ant;
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
            lista->cabeca->prox = lista->cabeca;
            lista->cabeca->ant = lista->cabeca;
        }
        lista->tamanho = 0;
    }

    return lista;
}

int pegarElemento(Lista *lista, TipoRegistro *registro, TipoChave chave) {
    if(lista == NULL || lista->cabeca->prox == lista->cabeca) {
        return 0;
    }

    No *atual = lista->cabeca->prox;

    do {
        if(atual->registro.chave == chave) {
            *registro = atual->registro;
            return 1;
        }

        atual = atual->prox;
    } while(atual != lista->cabeca);

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

    if(lista->cabeca->prox == lista->cabeca) {
        novoNo->prox = lista->cabeca;
        novoNo->ant = lista->cabeca;
        lista->cabeca->prox = novoNo;
        lista->cabeca->ant = novoNo;
    } else {
        novoNo->prox = lista->cabeca->prox;
        novoNo->ant = lista->cabeca;
        lista->cabeca->prox->ant = novoNo;
        lista->cabeca->prox = novoNo;
    }

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

    No *ultimo = lista->cabeca->ant;

    if(ultimo == lista->cabeca) {
        novoNo->ant = lista->cabeca;
        novoNo->prox = lista->cabeca;
        lista->cabeca->prox = novoNo;
        lista->cabeca->ant = novoNo;
    } else {
        novoNo->prox = lista->cabeca;
        novoNo->ant = ultimo;
        ultimo->prox = novoNo;
        lista->cabeca->ant = novoNo;
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

    if(lista->cabeca->prox == lista->cabeca) {
        novoNo->prox = lista->cabeca;
        novoNo->ant = lista->cabeca;
        lista->cabeca->prox = novoNo;
        lista->cabeca->ant = novoNo;
    } else {
        if(indice == 0) {
            novoNo->prox = lista->cabeca->prox;
            novoNo->ant = lista->cabeca;
            lista->cabeca->prox->ant = novoNo;
            lista->cabeca->prox = novoNo;
        } else if(indice == lista->tamanho) {
            No *ultimo = lista->cabeca->ant;

            novoNo->prox = lista->cabeca;
            novoNo->ant = ultimo;
            ultimo->prox = novoNo;
            lista->cabeca->ant = novoNo;
        } else {
            No *atual = lista->cabeca->prox;
            No *anterior = NULL;

            for(int i=0; i <= indice-1; i++) {
                anterior = atual;
                atual = atual->prox;
                if(atual == lista->cabeca) {
                    break;
                }
            }

            novoNo->prox = atual;
            novoNo->ant = anterior;
            anterior->prox = novoNo;
            atual->ant = novoNo;
        }
    }

    lista->tamanho++;

    return 1;
}

int removerElementoDoInicio(Lista *lista) {
    if(lista == NULL || lista->cabeca->prox == lista->cabeca) {
        return 0;
    }

    No *primeiro = lista->cabeca->prox;
    lista->cabeca->prox = lista->cabeca->prox->prox;

    if(lista->cabeca->prox != lista->cabeca) {
        lista->cabeca->prox->ant = primeiro->ant;
    } else {
        lista->cabeca->prox = lista->cabeca;
        lista->cabeca->ant = lista->cabeca;
    }

    free(primeiro);
    lista->tamanho--;
    return 1;
}

int removerElementoDoFinal(Lista *lista) {
    if(lista == NULL || lista->cabeca->prox == lista->cabeca) {
        return 0;
    }

    No *ultimo = lista->cabeca->ant;

    if(ultimo->ant == lista->cabeca) {
        lista->cabeca->prox = lista->cabeca;
        lista->cabeca->ant = lista->cabeca;
    } else {
        ultimo->ant->prox = lista->cabeca;
        lista->cabeca->ant = ultimo->ant;
    }

    free(ultimo);
    lista->tamanho--;

    return 1;
}

int removerElementoDaLista(Lista *lista, TipoChave chave) {
    if(lista == NULL || lista->cabeca->prox == lista->cabeca) {
        return 0;
    }

    No *atual = lista->cabeca->prox;
    No *anterior = NULL;

    if(atual->prox == lista->cabeca) {
        if(atual->registro.chave == chave) {
            lista->cabeca->prox = lista->cabeca;
            lista->cabeca->ant = lista->cabeca;
            free(atual);
            lista->tamanho--;
            return 1;
        }
    } else {
        while(atual->prox != lista->cabeca) {
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
    }

    return 0;
}

int alterarElementoDaLista(Lista *lista, TipoRegistro registro, int indice) {
    if(lista == NULL || lista->cabeca->prox == lista->cabeca || lista->tamanho <= indice) {
        return 0;
    }

    No *atual = lista->cabeca->prox;

    for(int i=0; i < indice && atual->prox != lista->cabeca; i++) {
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

    if(lista->cabeca->prox == lista->cabeca) {
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

        if(no != lista->cabeca) {
            if(no->prox == lista->cabeca) {
                printf("%d->", no->registro.chave);
                printf("CELULA CABECA->DE VOLTA AO PRIMEIRO ELEMENTO: %d\n", no->prox->prox->registro.chave);
            } else {
                do {
                    printf("%d->", no->registro.chave);
                    no = no->prox;
                } while(no != lista->cabeca);

                printf("CELULA CABECA->DE VOLTA AO PRIMEIRO ELEMENTO: %d\n", no->prox->registro.chave);
                no = lista->cabeca->prox;

                while(no != lista->cabeca) {
                    if(no->ant == lista->cabeca) {
                        printf("CAB ");
                    } else {
                        printf("%d  ", no->ant->registro.chave);
                    }
                    no = no->prox;
                }
                printf("\n");
            }
        } else {
            printf("CAB\n");
        }
    }
}

int destruirLista(Lista *lista) {
    if(!lista) {
        No *atual = lista->cabeca;
        No *anterior = NULL;

        do {
            anterior = atual;
            atual = atual->prox;
            free(anterior);
        } while(atual != lista->cabeca);

        free(lista);

        return 1;
    }

    return 0;
}
