#include <stdio.h>
#include <string.h>

// Struct -> estrutura de dados

struct st_aluno {
    char matricula[10];
    char nome[100];
    char curso[50];
    int ano_nascimento;
} aluno1, aluno2;

int main(void) {
    printf("Informe a matrícula do aluno: ");
    fgets(aluno1.matricula, 10, stdin);

    printf("Informe o nome do aluno: ");
    fgets(aluno1.nome, 100, stdin);

    printf("Informe o curso do aluno: ");
    fgets(aluno1.curso, 50, stdin);

    printf("Informe o ano de nascimento do aluno: ");
    scanf("%d", &aluno1.ano_nascimento);

    printf("========== Dados do Aluno ==========\n");
    printf("Matrícula: %s\n", aluno1.matricula);
    printf("Nome: %s\n", aluno1.nome);
    printf("Curso: %s\n", aluno1.curso);
    printf("Ano de nascimento: %d\n", aluno1.ano_nascimento);


    return 0;
}