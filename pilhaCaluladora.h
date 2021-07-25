#define tam 50

//Definindo as estruturas

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


//Definindo as funções

char *infixaParaPosfixa(char *);

int empilha(Pilha *, Item *);

int desempilha(Pilha *, Item *);

int verificaExpressao(char []);

int estaVazia(Pilha);

int verificaSimboloMatematico(char *);

void criaPilhaVazia(Pilha *pilha);

void imprime(Pilha);

void resolveExpressao(Pilha *, char *);

void liberaPilha(Pilha *);
