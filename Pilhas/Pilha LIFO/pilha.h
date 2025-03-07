#ifndef PILHA_H
#define PILHA_H
#include "registro.h"

typedef struct pilha Pilha;

Pilha *criarPilha();
int push(Pilha *p, TipoRegistro item);
int pop(Pilha *p, TipoRegistro *item);
int peek(Pilha *p, TipoRegistro *item);
int tamanho(Pilha *p);
int estaVazia(Pilha *p);
int estaCheia(Pilha *p);
void exibirElementos(Pilha *p);
int destruirPilha(Pilha *p);

#endif // PILHA_H
