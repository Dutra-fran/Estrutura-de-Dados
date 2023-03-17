// Enum

#include <stdio.h>

// Enumeração
enum dias_da_semana {
    segunda,
    terca,
    quarta,
    quinta,
    sexta,
    sabado,
    domingo
};

int main(void) {
    enum dias_da_semana d1, d2;

    d1 = quinta; // 3

    // errado
    //d2 = outro;

    d2 = 4; // sexta

    if(d1 == d2) {
        printf("Os dias são iguais...");
    } else {
        printf("Os dias não são iguais...");
    }

    return 0;
}