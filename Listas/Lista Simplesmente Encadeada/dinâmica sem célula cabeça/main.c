#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main()
{
    // Criando endereco de memoria para a nossa lista
    Lista *lista = criarLista();
    TipoRegistro registro;

    // Testando funcao que verifica se a lista esta vazia (ele entra no if)
    if(estaVazia(lista)) {
        printf("Lista esta vazia!\n");
    } else {
        printf("Lista nao esta vazia!\n");
    }

    // Testando lista vazia
    exibirElementos(lista);
    printf("Tamanho da lista: %d\n", tamanhoDaLista(lista));

    // Testando insercao no inicio da lista
    registro.chave = 10;
    insereElementoNoInicio(lista, registro);
    exibirElementos(lista);
    printf("Tamanho da lista: %d\n", tamanhoDaLista(lista));

    // Testando funcao que verifica se a lista esta vazia ou nao (caira no else)
    if(estaVazia(lista)) {
        printf("Lista esta vazia!\n");
    } else {
        printf("Lista nao esta vazia!\n");
    }

    // Testando insercao no inicio da lista
    registro.chave = 20;
    insereElementoNoInicio(lista, registro);
    exibirElementos(lista);
    printf("Tamanho da lista: %d\n", tamanhoDaLista(lista));

    // Testando procura de elementos pela chave informada (abaixo ele nao encontra)
    if(pegarElemento(lista, &registro, 11)) {
        printf("Registro resgatado: %d\n", registro.chave);
    } else {
        printf("Elemento nao encontrado!\n");
    }

    // Testando procura de elementos pela chave informada (abaixo ele encontra)
    if(pegarElemento(lista, &registro, 10)) {
        printf("Registro resgatado: %d\n", registro.chave);
    } else {
        printf("Elemento nao encontrado!\n");
    }

    // Testando insercao ao final da lista
    registro.chave = 5;
    insereElementoNoFinal(lista, registro);
    exibirElementos(lista);
    printf("Tamanho da lista: %d\n", tamanhoDaLista(lista));

    // Testando insercao ao final da lista
    registro.chave = 8;
    insereElementoNoFinal(lista, registro);
    exibirElementos(lista);
    printf("Tamanho da lista: %d\n", tamanhoDaLista(lista));

    // Testando com indice no inicio da lista
    registro.chave = 23;
    insereElementoNaLista(lista, registro, 0);
    exibirElementos(lista);
    printf("Tamanho da lista: %d\n", tamanhoDaLista(lista));

    // Testando com indice maior do que elementos adicionados
    registro.chave = 27;
    insereElementoNaLista(lista, registro, 6);
    exibirElementos(lista);
    printf("Tamanho da lista: %d\n", tamanhoDaLista(lista));

    // Testando adicionar ao final da lista
    registro.chave = 29;
    insereElementoNaLista(lista, registro, 5);
    exibirElementos(lista);
    printf("Tamanho da lista: %d\n", tamanhoDaLista(lista));

    // Testando remover primeiro elemento da lista
    removerElementoDoInicio(lista);
    exibirElementos(lista);
    printf("Tamanho da lista: %d\n", tamanhoDaLista(lista));

    // Testando remover o ultimo elemento da lista
    removerElementoDoFinal(lista);
    exibirElementos(lista);
    printf("Tamanho da lista: %d\n", tamanhoDaLista(lista));

    // Testando remover elemento informando sua chave
    removerElementoDaLista(lista, 5);
    exibirElementos(lista);
    printf("Tamanho da lista: %d\n", tamanhoDaLista(lista));

    // Testando alteracao de informacao de algum elemento da lista, informando seu indice
    registro.chave = 91;
    alterarElementoDaLista(lista, registro, 2);
    exibirElementos(lista);
    printf("Tamanho da lista: %d\n", tamanhoDaLista(lista));

    // Testando alteracao de informacao de algum elemento da lista, informando seu indice
    registro.chave = 3;
    alterarElementoDaLista(lista, registro, 0);
    exibirElementos(lista);
    printf("Tamanho da lista: %d\n", tamanhoDaLista(lista));

    // Testando funcao que verifica se a lista esta cheia ou nao (caira no else)
    if(estaCheia(lista)) {
        printf("Lista esta cheia!\n");
    } else {
        printf("Lista nao esta cheia!\n");
    }

    // Funcao para excluir nossa lista da memoria ao final da execucao do programa
    destruirLista(lista);

    return 0;
}
