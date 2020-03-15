/*Tipos exportados */

typedef struct node node;

/* Funcoes exportadas */

/* Funcao inserir

Insere um novo no em uma posicao especifica (cabeca = posicao 0),
se nao for possivel inserir na posicao especifica entao a insercao deve ser feita no fim da lista
*/

void inserir (node** lista, int posicao, double valor);

/* Funcao imprimir

Imprime os valores na lista a partir da cabeca em uma unica linha, a lista vazia e impressa como uma linha em branco
*/

void imprimir (node* lista);


/* Funcao reverter 

Reverte o trecho delimitado pelas posicoes inicio e termino
*/

void reverter (node** lista, int inicio, int termino);

/* Funcao cria lista 

Retorna uma lista vazia 
*/

node* lista_cria (void); 

/* Funcao next

Retorna um ponteiro para o proximo elemento da lista
*/

node* next (node* point, node* ant); 
