#include <stdio.h>
#include "ListaDinEncadDupla.h"

int main(void)
{
    Lista *li;
    li = cria_lista();

    // int x = tamanho_lista(li);
    // int x = lista_cheia(li);
    // if(lista_cheia(li))
    // int x = lista_vazia(li);
    // if(lista_vazia(li))

    // int x = insere_lista_inicio(li, dados_aluno);
    // int x = insere_lista_final(li, dados_aluno);
    // int x = insere_lista_ordenada(li, dados_aluno);

    // int x = remove_lista_inicio(li);
    // int x = remove_lista_final(li);
    // int x = remove_lista(li, matricula_aluno);

    libera_lista(li);

    return 0;
}