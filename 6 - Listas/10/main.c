#include <stdio.h>
#include "ListaSequencial.h"

int main(void)
{
    // Exemplo de como estar utilizando meu TAD de lista
    Lista *li;
    li = cria_lista();

    int x = tamanho_lista(li);
    printf("Tamanho da lista: %d\n", x);

    if (lista_cheia(li))
    {
        printf("A lista está cheia!");
    }

    // int x = insere_lista_final(li, dados_aluno);
    // int x = insere_lista_inicio(li, dados_aluno);
    // int x = insere_lista_ordenada(li, dados_aluno);

    // int x = remove_lista_final(li);
    // int x = remove_lista_inicio(li);
    // int x = remove_lista(li, matricula_aluno);

    libera_lista(li);

    return 0;
}