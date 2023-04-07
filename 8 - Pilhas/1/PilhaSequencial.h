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