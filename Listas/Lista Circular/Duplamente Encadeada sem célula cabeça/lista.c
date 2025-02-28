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

    do {
        if(atual->registro.chave == chave) {
            *registro = atual->registro;
            return 1;
        }

        atual = atual->prox;
    } while(atual != lista->primeiro);

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

    if(lista->primeiro == NULL) {
        novoNo->prox = novoNo;
        novoNo->ant = novoNo;
        lista->primeiro = novoNo;
    } else {
        novoNo->prox = lista->primeiro;
        lista->primeiro->ant = novoNo;

        No *ultimoNo = lista->primeiro;
        do {
            ultimoNo = ultimoNo->prox;
        } while(ultimoNo->prox != lista->primeiro);

        novoNo->ant = ultimoNo;
        ultimoNo->prox = novoNo;
        lista->primeiro = novoNo;
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

    No *atual = lista->primeiro;
    No *anterior = NULL;

    if(atual == NULL) {
        novoNo->ant = novoNo;
        novoNo->prox = novoNo;
        lista->primeiro = novoNo;
    } else {
        do {
            anterior = atual;
            atual = atual->prox;
        } while(atual != lista->primeiro);

        novoNo->prox = atual;
        atual->ant = novoNo;
        anterior->prox = novoNo;
        novoNo->ant = anterior;
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

    No *atual = lista->primeiro;
    No *anterior = NULL;

    if(lista->primeiro == NULL) {
        novoNo->prox = novoNo;
        novoNo->ant = novoNo;
        lista->primeiro = novoNo;
    } else {
        if(indice == 0) {
            novoNo->prox = lista->primeiro;
            No *ultimoNo = lista->primeiro;

            do {
                ultimoNo = ultimoNo->prox;
            } while(ultimoNo->prox != lista->primeiro);

            novoNo->ant = ultimoNo;
            ultimoNo->prox = novoNo;
            lista->primeiro->ant = novoNo;
            lista->primeiro = novoNo;
        } else if(indice == lista->tamanho) {
            do {
                anterior = atual;
                atual = atual->prox;
            } while(atual != lista->primeiro);

            novoNo->prox = atual;
            atual->ant = novoNo;
            anterior->prox = novoNo;
            novoNo->ant = anterior;
        } else {
            for(int i=0; i <= indice-1; i++) {
                anterior = atual;
                atual = atual->prox;
                if(atual == lista->primeiro) {
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
    if(lista == NULL || lista->primeiro == NULL) {
        return 0;
    }

    No *primeiro = lista->primeiro;
    lista->primeiro = lista->primeiro->prox;

    if(lista->primeiro != primeiro) {
        primeiro->ant->prox = lista->primeiro;
        lista->primeiro->ant = primeiro->ant;
    } else {
        lista->primeiro = NULL;
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

    if(atual->prox == lista->primeiro) {
        lista->primeiro = NULL;
    } else {
        while(atual->prox != lista->primeiro) {
            anterior = atual;
            atual = atual->prox;
        }

        anterior->prox = atual->prox;
        atual->prox->ant = anterior;
    }

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

    if(atual->prox == lista->primeiro) {
        if(atual->registro.chave == chave) {
            lista->primeiro = NULL;
            free(atual);
            lista->tamanho--;
            return 1;
        }
    } else {
        while(atual->prox != lista->primeiro) {
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
    if(lista == NULL || lista->primeiro == NULL || lista->tamanho <= indice) {
        return 0;
    }

    No *atual = lista->primeiro;

    for(int i=0; i < indice && atual->prox != lista->primeiro; i++) {
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

        if(no != NULL) {
            if(no->prox == lista->primeiro) {
                printf("%d->", no->registro.chave);
                printf("DE VOLTA AO PRIMEIRO ELEMENTO: %d\n", no->registro.chave);
            } else {
                do {
                    printf("%d->", no->registro.chave);
                    no = no->prox;
                } while(no != lista->primeiro);

                printf("DE VOLTA AO PRIMEIRO ELEMENTO: %d\n", no->registro.chave);

                do {
                    printf("%d  ", no->ant->registro.chave);
                    no = no->prox;
                } while(no != lista->primeiro);
                printf("\n");
            }
        } else {
            printf("NULL\n");
        }
    }
}

int destruirLista(Lista *lista) {
    if(!lista) {
        No *atual = lista->primeiro;
        No *anterior = NULL;

        do {
            anterior = atual;
            atual = atual->prox;
            free(anterior);
        } while(atual != lista->primeiro);

        free(lista);

        return 1;
    }

    return 0;
}
