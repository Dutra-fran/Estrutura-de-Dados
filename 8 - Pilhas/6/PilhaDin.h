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
int tamanho_Pilha(Pilha *pi);
int Pilha_cheia(Pilha *pi);
int Pilha_vazia(Pilha *pi);
int insere_Pilha(Pilha *pi, struct aluno al);
int remove_Pilha(Pilha *pi);
int consulta_topo_Pilha(Pilha *pi, struct aluno *al);