#include <stdio.h>
#include "pilhaCaluladora.h"

void mostraMenu(){
    printf("\n========Calculadora========\n");
    printf("      | 1    2    3 |\n");
    printf("      | 4    5    6 |\n");
    printf("      | 7    8    9 |\n");
    printf("      | C    0    E |\n");
    printf("===========================\n");
    printf("Operacoes: + - * /\n");
}

int main() {
    mostraMenu();

    Pilha calculadora;
    Item i1, i2;
    i1.numero = 1;
    i2.numero = 2;

    criaPilhaVazia(&calculadora);
    empilha(&calculadora, &i1);
    empilha(&calculadora, &i2);
    imprimePilha(calculadora);



    return 0;
}
