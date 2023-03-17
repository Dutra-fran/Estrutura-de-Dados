// ifdef - Diretiva de compilação

#include <stdio.h>

//#ifndef PI
//    #define PI 3.14567
//#endif

int main(void) {
    int valor = 5;

    valor = 467;

    printf("O valor é %d\n", valor);
    //printf("2 vezes PI vale %f\n", (2 * PI));

    // O código abaixo só irá executar caso PI exista.
    #ifdef PI
        printf("O valor de PI é %f\n", PI);
    #endif

}