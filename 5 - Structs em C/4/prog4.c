#include <stdio.h>
#include <string.h>

// Struct -> estrutura de dados

struct st_contato
{
    char nome[100];
    int ano_nascimento;
    char telefone[20];
    char email[100];
};

// Struct de struct
struct st_agenda
{
    struct st_contato contatos[100];
} agenda;

int main(void)
{

    // nossa agenda cabem 100 contatos, mas coloquei 3 no for para questão de testes
    for (int i = 0; i < 3; i++)
    {

        printf("Informe o nome: ");
        fgets(agenda.contatos[i].nome, 100, stdin);

        printf("Informe o ano de nascimento: ");
        scanf("%d", &agenda.contatos[i].ano_nascimento);
        getchar();

        printf("Informe o telefone: ");
        fgets(agenda.contatos[i].telefone, 20, stdin);

        printf("Informe o email: ");
        fgets(agenda.contatos[i].email, 100, stdin);
    }

    printf("========== Agenda de Contato ==========\n");
    for (int i = 0; i < 3; i++)
    {
        printf("============= Contato %d =============\n", (i + 1));
        // strtok é uma função que serve para retirar algum valor especificado dentro da string passada. Nesse exemplo, estamos omitindo o \n que ele captura do teclado.
        printf("Nome: %s\n", strtok(agenda.contatos[i].nome, "\n"));
        printf("Ano de nascimento: %d\n", agenda.contatos[i].ano_nascimento);
        printf("Telefone: %s\n", strtok(agenda.contatos[i].telefone, "\n"));
        printf("Email: %s\n", strtok(agenda.contatos[i].email, "\n"));
    }

    return 0;
}