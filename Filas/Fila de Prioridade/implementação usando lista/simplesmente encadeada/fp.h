#ifndef FP_H
#define FP_H
#include "registro.h"

typedef struct fila Fila;

Fila *criarFila();
int enqueue(Fila *f, TipoRegistro registro, int prioridade);
int dequeue(Fila *f, TipoRegistro *registro);
int peek(Fila *f, TipoRegistro *registro);
int alterarPrioridade(Fila *f, TipoChave chave, int prioridade);
int tamanho(Fila *f);
int estaVazia(Fila *f);
int estaCheia(Fila *f);
void exibirElementos(Fila *f);
int destruirFila(Fila *f);

#endif // FP_H
