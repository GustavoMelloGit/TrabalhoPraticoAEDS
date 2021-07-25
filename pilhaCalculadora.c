#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilhaCaluladora.h"

//Função responsável por criar uma pilha vazia
void criaPilhaVazia(Pilha *pilha) {
    pilha->topo = (Celula *) malloc(sizeof(Celula));
    pilha->fundo = pilha->topo;
    pilha->topo->proximo = NULL;
    pilha->tamanho = 0;
}

//Verifica se a pilha recebida está vazia
int estaVazia(Pilha pilha) {
    return (pilha.tamanho == 0);
}

//Empilha um item no topo da pilha
int empilha(Pilha *pPilha, Item *pItem) {
    Celula *pNovo;
    pNovo = (Celula *) malloc(sizeof(Celula));
    pPilha->topo->item = *pItem;
    pNovo->proximo = pPilha->topo;
    pPilha->topo = pNovo;
    pPilha->tamanho++;
    return 1;
}

//Desempilha item no topo da pilha
int desempilha(Pilha *pPilha, Item *pItem) {
    Celula *pAux;

    if (estaVazia(*pPilha)) return 0;

    pAux = pPilha->topo;
    pPilha->topo = pAux->proximo;
    *pItem = pAux->proximo->item;
    free(pAux);
    pPilha->tamanho--;

    return 1;
}

//Função responsável por validar a expressão infixa digitada pelo usuário
int verificaExpressao(char expr[]) {
    int contAbre = 0, contFecha = 0;

    //Verifica se a expressão se inicia com um abre parênteses
    if (expr[0] != '(') return 0;

    //Verifica se a quantidade de parênteses abertos são o mesmo dos fechados
    if (expr[0] == '(') {
        for (int i = 0; i < strlen(expr); ++i) {
            if (expr[i] == '(') contAbre++;
            else if (expr[i] == ')') contFecha++;
        }
    } else exit(1);

    return (contAbre == contFecha);
}

//Função responsável por verificar se o caractere recebido é uma operação válida
int verificaSimboloMatematico(char *valor) {
    if (valor[0] == '+' || valor[0] == '-' || valor[0] == '*' || valor[0] == '/') return 1;
    return 0;
}

//Função responsável por realizar as contas da expressao pós-fixa
void resolveExpressao(Pilha *pilha, char *x) {
    Item i1, i2, iAux;

    //Percorre a expressão pós-fixa
    for (int i = 0; x[i] != '\0'; ++i) {

        //Verifica se a string está em um espaço e se a próxima posição não é uma operação
        if (x[i] == ' ' && !verificaSimboloMatematico(&x[i + 1])) {
            iAux.valor = 0;
            empilha(pilha, &iAux);
            imprime(*pilha);
        }

            //Verifica se a string está na posição de um número
        else if (x[i] != ' ' && !verificaSimboloMatematico(&x[i])) {
            desempilha(pilha, &iAux);
            iAux.valor = iAux.valor * 10 + (x[i] - '0');
            empilha(pilha, &iAux);
            imprime(*pilha);
        }

            //Verifica se está em uma operação e então realiza as contas
        else if (x[i] != ' ') {
            desempilha(pilha, &i1);
            desempilha(pilha, &i2);

            switch (x[i]) {
                case '+':
                    printf("=================================\n");
                    printf("Somando valores da pilha: %d + %d\n", i2.valor, i1.valor);
                    i1.valor = i2.valor + i1.valor;
                    empilha(pilha, &i1);
                    imprime(*pilha);
                    break;
                case '-':
                    printf("=================================\n");
                    printf("Subtraindo valores da pilha: %d - %d\n", i2.valor, i1.valor);
                    i1.valor = i2.valor - i1.valor;
                    empilha(pilha, &i1);
                    imprime(*pilha);
                    break;
                case '*':
                    printf("=================================\n");
                    printf("Multiplicando valores da pilha: %d * %d\n", i2.valor, i1.valor);
                    i1.valor = i2.valor * i1.valor;
                    empilha(pilha, &i1);
                    imprime(*pilha);
                    break;
                case '/':
                    printf("=================================\n");
                    printf("Dividindo valores da pilha: %d / %d\n", i2.valor, i1.valor);
                    i1.valor = i2.valor / i1.valor;
                    empilha(pilha, &i1);
                    imprime(*pilha);
                    break;
            }
        }
    }
}

//Transforma a expressão infixa digitada pelo usuário para pós-fixa
char *infixaParaPosfixa(char *exp) {
    int n = strlen(exp), j = 0;
    char *posFixa;
    Pilha pAux;
    Item iAux;

    criaPilhaVazia(&pAux);

    posFixa = (char *) malloc((n + 1) * sizeof(char));
    iAux.valor = (int) exp[0];

    empilha(&pAux, &iAux);

    //Caso a expressão não seja válida, o programa é interrompido
    if (!verificaExpressao(exp)) {
        printf("Expressao invalida");
        exit(1);
    }

    //Percorre a expressão infixa e então a transforma para pós-fixa
    for (int i = 0; exp[i] != '\n'; i++) {
        if (i == 0) posFixa[j++] = ' ';
        switch (exp[i]) {
            case '(':
                iAux.valor = (int) exp[i];
                empilha(&pAux, &iAux);
                break;
            case ')':
                desempilha(&pAux, &iAux);
                while (iAux.valor != '(') {
                    posFixa[j++] = ' ';
                    posFixa[j++] = (char) iAux.valor;
                    desempilha(&pAux, &iAux);
                }
                break;
            case '+':
            case '-':
                posFixa[j++] = ' ';
                desempilha(&pAux, &iAux);
                while (iAux.valor != '(') {
                    posFixa[j++] = (char) iAux.valor;
                    desempilha(&pAux, &iAux);
                }
                empilha(&pAux, &iAux);
                iAux.valor = (int) exp[i];
                empilha(&pAux, &iAux);
                break;
            case '*':
            case '/':
                posFixa[j++] = ' ';
                desempilha(&pAux, &iAux);
                while (iAux.valor != '(' && iAux.valor != '+' && iAux.valor != '-') {
                    posFixa[j++] = (char) iAux.valor;
                    desempilha(&pAux, &iAux);
                }
                empilha(&pAux, &iAux);
                iAux.valor = (int) exp[i];
                empilha(&pAux, &iAux);
                break;
            default:
                posFixa[j++] = exp[i];
        }
    }
    posFixa[j] = '\0';
    imprime(pAux);
    return posFixa;
}

//Imprime a pilha na tela
void imprime(Pilha pilha) {
    pilha.topo = pilha.topo->proximo;
    printf("Pilha: \n");

    while (pilha.topo != NULL) {
        printf("%d ", pilha.topo->item.valor);
        pilha.topo = pilha.topo->proximo;
    }
    printf("\n");
}
