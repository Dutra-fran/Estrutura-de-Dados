// "Pilha Dinâmica": tipo de "pilha" onde cada elemento aponta para o seu sucessor na "pilha"
// Usa um ponteiro especial (ponteiro para ponteiro) para o primeiro elemento da "pilha"
// e uma indicação de final de "pilha"

struct aluno
{
    int matricula;
    char nome[30];
    float n1, n2, n3;
};

typedef struct elemento *Pilha;

Pilha *cria_Pilha();
void libera_Pilha(Pilha *pi);