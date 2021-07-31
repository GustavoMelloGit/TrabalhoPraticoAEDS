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
No final, imprima o valor **2**, que é o resultado de **90 20 15 13 - \* 5 + /**, ou seja, **(90/((20\*(15-13))+5))** na notação habitual infixa. 

O programa deve criar um vetor de caracteres (string) e pedir ao usuário para digitar a expressão na **notação habitual infixa**. Converta a expressão para a notação Polonesa Reversa e imprima o resultado da conversão na tela (**Dica:** para mais informações de como converter, acesse[ este link)](https://www.ime.usp.br/~pf/algoritmos/aulas/pilha.html). Posteriormente, execute cada uma das ações da expressão, imprimindo na tela, **passo a passo**, o conteúdo da pilha. 

Para resolver o trabalho, é necessário implementar o **TAD PILHA.** Considere uma pilha sem limite de TAMANHO. 

**O que deve ser entregue** 

Código fonte do programa em C (bem indentado e comentado) e documentação do trabalho. Entre outras coisas, a documentação deve conter: 

1. **Introdução:** descrição do problema a ser resolvido e visão geral sobre o funcionamento do programa. 
1. **Implementação:** descrição sobre a implementação do programa. Deve ser detalhada a estrutura de dados utilizada (de preferência com diagramas ilustrativos), o funcionamento das principais sub-rotinas utilizadas, bem  como  decisões  tomadas  relativas  aos  casos  e  detalhes  de  especificação  que  porventura  estejam omissos no enunciado. **Muito importante:** os códigos utilizados nas implementações devem ser inseridos na documentação. 
1. **Estudo de complexidade:** estudo da complexidade do tempo de execução das sub-rotinas implementadas e do programa como um todo (notação O). 
1. **Listagem de testes executados:** os testes executados devem ser apresentados, analisados e discutidos. 
1. **Conclusão:**  comentários  gerais  sobre  o  trabalho  e  as  principais  dificuldades  encontradas  em  sua implementação. 
1. **Bibliografia:** bibliografia utilizada para o desenvolvimento do trabalho, incluindo sites da Internet se for o caso. Uma referência bibliográfica deve ser citada no texto quando da sua utilização. 
1. **Formato:** mandatoriamente em **PDF**. 

**Como deve ser feita a entrega** 

A entrega deve ser feita via *Plataforma Moodle* na forma de um único arquivo em formato **.rar** ou **.zip**, contendo os arquivos do código e a documentação.  

**Comentário Gerais** 

1. O trabalho é individual (grupo de **UM** aluno); 
1. Comece a fazer este trabalho logo, pois o prazo para terminá-lo está tão longe quanto jamais poderá estar; 
1. Clareza, indentação e comentários no programa também serão avaliados; 
1. Trabalhos copiados (e FONTE) terão nota zero; Devido  a  recorrentes  problemas  com  cópias  de  trabalhos  (plágios),  os  autores  de  trabalhos  copiados também terão todos os demais trabalhos zerados, como forma de punição e coação ao plágio acadêmico; 
1. Evite discussões inócuas com o professor em tentar postergar a data de entrega do referido trabalho. 
Página **PAGE3** de **NUMPAGES3** 
