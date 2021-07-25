#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilhaCaluladora.h"


void criaPilhaVazia(Pilha *pilha) {
    pilha->topo = (Celula *) malloc(sizeof(Celula));
    pilha->fundo = pilha->topo;
    pilha->topo->proximo = NULL;
    pilha->tamanho = 0;
}

int estaVazia(Pilha pilha) {
    return (pilha.tamanho == 0);
}

int empilha(Pilha *pPilha, Item *pItem) {
    Celula *pNovo;
    pNovo = (Celula *) malloc(sizeof(Celula));
    pPilha->topo->item = *pItem;
    pNovo->proximo = pPilha->topo;
    pPilha->topo = pNovo;
    pPilha->tamanho++;
    return 1;
}

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

int verificaExpressao(char expr[]) {
    int contAbre = 0, contFecha = 0;

    if (expr[0] != '(') return 0;

    if (expr[0] == '(') {
        for (int i = 0; i < strlen(expr); ++i) {
            if (expr[i] == '(') contAbre++;
            else if (expr[i] == ')') contFecha++;
        }
    } else exit(1);

    return (contAbre == contFecha);
}

int verificaSimboloMatematico(char *valor) {
    if (valor[0] == '+' || valor[0] == '-' || valor[0] == '*' || valor[0] == '/') return 1;
    return 0;
}

void resolveExpressao(Pilha *pilha, char *x) {
    Item i1, i2, iAux;

    for (int i = 0; x[i] != '\0'; ++i) {
        if (x[i] == ' ' && !verificaSimboloMatematico(&x[i + 1])) {
            iAux.valor = 0;
            empilha(pilha, &iAux);
            imprime(*pilha);
        } else if (x[i] != ' ' && !verificaSimboloMatematico(&x[i])) {
            desempilha(pilha, &iAux);
            iAux.valor = iAux.valor * 10 + (x[i] - '0');
            empilha(pilha, &iAux);
            imprime(*pilha);
        } else if (x[i] != ' ') {
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

char *infixaParaPosfixa(char *exp) {
    int n = strlen(exp);
    char *posFix;
    Pilha pAux;
    Item iAux;

    criaPilhaVazia(&pAux);

    posFix = (char *) malloc((n + 1) * sizeof(char));
    iAux.valor = (int) exp[0];
    empilha(&pAux, &iAux);

    if (!verificaExpressao(exp)) {
        printf("Expressao invalida");
        exit(1);
    }

    int j = 0;
    for (int i = 0; exp[i] != '\n'; i++) {
        if (i == 0)
            posFix[j++] = ' ';
        switch (exp[i]) {
            case '(':
                iAux.valor = (int) exp[i];
                empilha(&pAux, &iAux);
                break;
            case ')':
                desempilha(&pAux, &iAux);
                while (iAux.valor != '(') {
                    posFix[j++] = ' ';
                    posFix[j++] = (char) iAux.valor;
                    desempilha(&pAux, &iAux);
                }
                break;
            case '+':
            case '-':
                posFix[j++] = ' ';
                desempilha(&pAux, &iAux);
                while (iAux.valor != '(') {
                    posFix[j++] = (char) iAux.valor;
                    desempilha(&pAux, &iAux);
                }
                empilha(&pAux, &iAux);
                iAux.valor = (int) exp[i];
                empilha(&pAux, &iAux);
                break;
            case '*':
            case '/':
                posFix[j++] = ' ';
                desempilha(&pAux, &iAux);
                while (iAux.valor != '(' && iAux.valor != '+' && iAux.valor != '-') {
                    posFix[j++] = (char) iAux.valor;
                    desempilha(&pAux, &iAux);
                }
                empilha(&pAux, &iAux);
                iAux.valor = (int) exp[i];
                empilha(&pAux, &iAux);
                break;
            default:
                posFix[j++] = exp[i];
        }
    }
    posFix[j] = '\0';
    imprime(pAux);
    return posFix;
}


void imprime(Pilha pilha) {
    pilha.topo = pilha.topo->proximo;
    printf("Pilha: \n");

    while (pilha.topo != NULL) {
        printf("%d ", pilha.topo->item.valor);
        pilha.topo = pilha.topo->proximo;
    }
    printf("\n");
}
