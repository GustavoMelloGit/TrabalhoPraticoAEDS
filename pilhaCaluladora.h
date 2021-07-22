typedef struct{
    int numero;
}Item;

typedef struct TCelula{
    Item item;
    struct TCelula *proximo;
}Celula;

typedef struct{
    Celula *fundo;
    Celula *topo;
    int tamanho;
}Pilha;

int desempilha(Pilha*, Item*);
int estaVazia(Pilha);
int empilha(Pilha*, Item*);
int tamanho(Pilha);
void criaPilhaVazia(Pilha*);
void entraValor();
void imprimePilha(Pilha);