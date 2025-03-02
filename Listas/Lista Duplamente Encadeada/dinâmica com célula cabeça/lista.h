#ifndef LISTA_H
#define LISTA_H
#include "registro.h"

typedef struct lista Lista;

Lista *criarLista();
int pegarElemento(Lista *lista, TipoRegistro *registro, TipoChave chave);
int insereElementoNoInicio(Lista *lista, TipoRegistro registro);
int insereElementoNoFinal(Lista *lista, TipoRegistro registro);
int insereElementoNaLista(Lista *lista, TipoRegistro registro, int indice);
int removerElementoDoInicio(Lista *lista);
int removerElementoDoFinal(Lista *lista);
int removerElementoDaLista(Lista *lista, TipoChave chave);
int alterarElementoDaLista(Lista *lista, TipoRegistro registro, int indice);
int tamanhoDaLista(Lista *lista);
int estaVazia(Lista *lista);
int estaCheia(Lista *lista);
void exibirElementos(Lista *lista);
int destruirLista(Lista *lista);

#endif // LISTA_H
