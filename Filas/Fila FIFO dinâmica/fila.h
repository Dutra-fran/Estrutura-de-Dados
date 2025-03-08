#ifndef FILA_H
#define FILA_H
#include "registro.h"

typedef struct fila Fila;

Fila *criarFila();
int enqueue(Fila *f, TipoRegistro registro);
int dequeue(Fila *f, TipoRegistro *registro);
int peek(Fila *f, TipoRegistro *registro);
int tamanho(Fila *f);
int estaVazia(Fila *f);
int estaCheia(Fila *f);
void exibirElementos(Fila *f);
int destruirFila(Fila *f);

#endif // FILA_H
