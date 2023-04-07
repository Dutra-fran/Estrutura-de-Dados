// definir: os protótipos das funções; o tipo de dado armazenado na fila; o ponteiro "fila"; tamanho do vetor usado na fila.

#define MAX 100

struct aluno
{
    int matricula;
    char nome[30];
    float n1, n2, n3;
};

typedef struct fila Fila;

Fila *cria_Fila();
void libera_Fila(Fila *fi);
int tamanho_Fila(Fila *fi);
int Fila_cheia(Fila *fi);
int Fila_vazia(Fila *fi);