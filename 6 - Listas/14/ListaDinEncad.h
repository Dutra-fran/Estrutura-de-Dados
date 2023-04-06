// definir: os protótipos das funções; o tipo de dado armazenado na lista; o ponteiro "lista"

struct aluno
{
    int matricula;
    char nome[30];
    float n1, n2, n3;
};

typedef struct elemento *Lista;

Lista *cria_lista();
void libera_lista(Lista *li);
int tamanho_lista(Lista *li);
int lista_cheia(Lista *li); // em lista dinâmica não existe o conceito de cheio. A lista estará cheia somente quando a memória do computador estiver cheia.
int lista_vazia(Lista *li);
int insere_lista_inicio(Lista *li, struct aluno al);
int insere_lista_final(Lista *li, struct aluno al);
int insere_lista_ordenada(Lista *li, struct aluno al);