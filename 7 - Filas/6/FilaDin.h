// definir: os protótipos das funções; o tipo de dados armazenado na lista; o ponteiro "fila".
// Fila Dinâmica: tipo de "Fila" onde cada elemento aponta para o seu sucessor na "fila"
// Usa um "nó descritor" para representar o início e final da fila e uma indicação de final de fila.

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
int insere_Fila(Fila *fi, struct aluno al);
int remove_Fila(Fila *fi);
int consulta_Fila(Fila *fi, struct aluno *al);