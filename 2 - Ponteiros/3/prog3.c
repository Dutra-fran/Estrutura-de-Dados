// Arrays e ponteiros

#include <stdio.h>

int main(void) {
    /*    0   1   2   3   4
        ---------------------
        |   |   |   |   |   |
        ---------------------
    */
    int valores[5];

    for(int i = 0; i < 5; i++) {
        printf("Informe o %d/5 valor: ", (i+1));
        scanf("%d", &valores[i]);
    }

    printf("Os valores informados foram: \n");
    for(int i = 0; i < 5; i++) {
        printf("%d\n", valores[i]);
    }

    printf("%p %d\n", &valores[0], valores[0]);
    printf("%p %d\n", valores, valores[0]);

    return 0;
}
