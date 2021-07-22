#include <stdio.h>
#include <stdlib.h>

#include "pilhaCaluladora.h"


void criaPilhaVazia(Pilha* pilha) {
    pilha->topo = (Celula*)malloc(sizeof(Celula));
    pilha->fundo = pilha->topo;
    pilha->topo->proximo = NULL;
    pilha->tamanho = 0;
}

int estaVazia(Pilha pilha){
    return (pilha.topo == pilha.fundo);
}

int empilha(Pilha* pilha, Item* item){
    Celula *novo;

    novo = (Celula*) malloc(sizeof(Celula));
    pilha->topo->item = *item;
    novo->proximo = pilha->topo;
    pilha->topo = novo;
    pilha->tamanho++;

    return 1;
}

void entraValor(){

}

int desempilha(Pilha* pilha, Item* item){
    Celula *aux;
    if(estaVazia(*pilha)) return 0;

    aux = pilha->topo;
    pilha->topo = aux->proximo;
    *item = aux->proximo->item;
    free(aux);
    pilha->tamanho--;

    return 1;
}

void imprimePilha(Pilha pilha){
    pilha.topo = pilha.topo->proximo;

    if(!estaVazia(pilha)) {
        for (int i = 0; i < pilha.tamanho; ++i) {
            printf("%d ", pilha.topo->item.numero);
            pilha.topo = pilha.topo->proximo;
        }
    }
}

int tamanho(Pilha pilha){
    return (pilha.tamanho);
}