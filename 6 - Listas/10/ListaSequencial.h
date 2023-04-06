#define MAX 100

struct aluno
{
    int matricula;
    char nome[30];
    float n1, n2, n3;
};

typedef struct lista Lista;

Lista *cria_lista();
void libera_lista(Lista *li);
int tamanho_lista(Lista *li);
int lista_cheia(Lista *li);
int insere_lista_final(Lista *li, struct aluno al);
int insere_lista_inicio(Lista *li, struct aluno al);
int insere_lista_ordenada(Lista *li, struct aluno al);
int remove_lista_final(Lista *li);
int remove_lista_incio(Lista *li);
int remove_lista(Lista *li, int mat); // remove o aluno de matrícula informada