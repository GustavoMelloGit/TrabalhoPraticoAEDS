#include <stdio.h>
#include "pilhaCaluladora.h"

//Função responsável por imprimir um menu na tela (apenas visual)
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
    Pilha pilha;
    criaPilhaVazia(&pilha);

    char expressaoInfixa[tam], *expressaoPosfixa;

    mostraMenu();

    //Recebe a expressão infixa digitada pelo usuário
    fgets(expressaoInfixa, tam, stdin);

    //Transforma a expressão para pós-fixa
    expressaoPosfixa = infixaParaPosfixa(expressaoInfixa);

    //imprime a expressão pós-fixa
    puts(expressaoPosfixa);

    //Realiza as operações
    resolveExpressao(&pilha, expressaoPosfixa);

    return 0;
}
