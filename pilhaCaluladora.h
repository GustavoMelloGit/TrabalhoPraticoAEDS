#define tam 50

typedef struct {
    int valor;
} Item;

typedef struct TCelula {
    Item item;
    struct TCelula *proximo;
} Celula;

typedef struct {
    Celula *fundo;
    Celula *topo;
    int tamanho;
} Pilha;

int empilha(Pilha *, Item *);

int desempilha(Pilha *, Item *);

void criaPilhaVazia(Pilha *pilha);

void imprime(Pilha);

char *infixaParaPosfixa(char *);

void resolveExpressao(Pilha *, char *);
