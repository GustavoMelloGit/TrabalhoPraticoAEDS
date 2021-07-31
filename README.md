**CSI 488 – Algoritmos e Estruturas de Dados I** 

**Trabalho Prático 1** 

**Prof. Mateus Ferreira Satler DECSI – ICEA - UFOP** 

**Descrição** 

O trabalho consiste na implementação de uma calculadora simples, que permite trabalhar apenas com números inteiros não negativos. A calculadora possui 16 teclas, que são representadas pelos caracteres: 

**0 1 2 3 4 5 6 7 8 9 + - \* / C E** 

Sendo assim, ela pode realizar apenas 4 operações: soma, subtração, multiplicação e **divisão** **inteira**. 

**C** representa “clear” e **E** representa “enter”, indicando que vai ser fornecido um número. A máquina usa notação Polonesa Reversa, onde o operador vem depois dos operandos. 

Escreva  um  programa  na  Linguagem  **C**  que  usa  **OBRIGATORIAMENTE**  uma  **pilha  de  inteiros**  para  simular  a calculadora. Cada caractere que entra na pilha é tratado, e a resposta é o conteúdo  da pilha da calculadora. Inicialmente, a pilha está vazia. As ações correspondentes a cada caractere são: 



|**Caractere** |**Ação** |
| - | - |
|i = 0, 1, 2, ..., 9 |Troque o valor **x** do topo da pilha por **x\*10+i** |
|E |Empilhe um **0** (zero) |
|op = +, -, /, \*|Tire 2 elementos **y** e **x** do topo da pilha e empilhe o valor de **x op y**  |
|C |Esvazie a pilha |
Por exemplo, se o usuário digitasse os seguintes valores: **E 9 0 E 2 0 E 1 5 E 1 3 - \* E 5 + /** a pilha teria sucessivamente os seguintes conteúdos: 



|**Caractere** |**Pilha** |
| - | - |
|(incial)|[ ] |
|E |[ 0 ] |
|9 |[ 9 ] |
|0 |[ 90 ] |
|E |[ 90 / 0 ] |
|2 |[ 90 / 2 ] |
|0 |[ 90 / 20 ] |
|E |[ 90 / 20 / 0 ] |
|1 |[ 90 / 20 / 1 ] |
|5 |[ 90 / 20 / 15 ] |
|E |[ 90 / 20 / 15 / 0 ] |
|1 |[ 90 / 20 / 15 / 1 ] |
|3 |[ 90 / 20 / 15 / 13 ] |
|- |[ 90 / 20 / 2 ] |
|\* |[ 90 / 40 ] |
|E |[ 90 / 40 / 0 ] |
|5 |[ 90 / 40 / 5 ] |
|+ |[ 90 / 45 ] |
|/ |[ 2 ] |


O programa deve criar um vetor de caracteres (string) e pedir ao usuário para digitar a expressão na **notação habitual infixa**. Converta a expressão para a notação Polonesa Reversa e imprima o resultado da conversão na tela (**Dica:** para mais informações de como converter, acesse[ este link)](https://www.ime.usp.br/~pf/algoritmos/aulas/pilha.html). Posteriormente, execute cada uma das ações da expressão, imprimindo na tela, **passo a passo**, o conteúdo da pilha. 

Para resolver o trabalho, é necessário implementar o **TAD PILHA.** Considere uma pilha sem limite de TAMANHO. 
