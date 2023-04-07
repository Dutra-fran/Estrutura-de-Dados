#include <stdio.h>
#include "PilhaSequencial.h"

int main(void)
{
    Pilha *pi;
    pi = cria_Pilha();

    // int x = tamanho_Pilha(pi);
    // int x = Pilha_cheia(pi);
    // if(Pilha_cheia(pi))
    // int x = Pilha_vazia(pi);
    // if(Pilha_vazia(pi))

    // int x = insere_Pilha(pi, dados_aluno);
    // int x = remove_Pilha(pi);
    // int x = consulta_topo_Pilha(pi, &dados_aluno);

    libera_Pilha(pi);

    return 0;
}