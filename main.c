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
    Pilha pilha;

    char expressaoInfixa[tam], *expressaoPosfixa;
    fgets(expressaoInfixa, tam, stdin);

    criaPilhaVazia(&pilha);
    expressaoPosfixa = infixaParaPosfixa(expressaoInfixa);
    puts(expressaoPosfixa);

    resolveExpressao(&pilha, expressaoPosfixa);

    return 0;
}
