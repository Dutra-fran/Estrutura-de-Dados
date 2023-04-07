// Pilha Estática: tipo de "Pilha" onde o sucessor de um elemento ocupa a posição física seguinte
// do mesmo (uso de "array").
// Uma "Pilha" é um tipo especial de "lista": inserções e exclusões de elementos ocorrem apenas
// no início da "lista".

#define MAX 100

struct aluno
{
    int matricula;
    char nome[30];
    float n1, n2, n3;
};

typedef struct pilha Pilha;

Pilha *cria_Pilha();
void libera_Pilha(Pilha *pi);
int tamanho_Pilha(Pilha *pi);
int Pilha_cheia(Pilha *pi);
int Pilha_vazia(Pilha *pi);
// Em uma "pilha" a inserção é sempre no seu início (topo)
int insere_Pilha(Pilha *pi, struct aluno al);
// Em uma "pilha" a remoção é sempre no seu início (topo)
int remove_Pilha(Pilha *pi);
// Em uma "pilha" a consulta se dá apenas ao elemento que está no seu início
int consulta_topo_Pilha(Pilha *pi, struct aluno *al);