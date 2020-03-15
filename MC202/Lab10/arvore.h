//Tipos Exportados
/* Avore Binaria */
typedef struct arvore arv;

//Funcoes Exportadas

/*Funcao Inserir
Insere a chave x na arvore de busca binaria. A arvore nao deve ter elementos repetidos, entao se x ja pertence a arvore ele nao deve ser inserido de novo
*/
void inserir (arv** arvore, int chave);

/*Funcao buscar
Busca a chave x na arvore e imprime "x pertence" ou "x nao pertence" em uma linha
*/
void buscar (arv* arvore, int chave);

/*Funcao pos-ordem
Deve imprimir as chaves na ordem em que forem visitadas por um percurso em pos-ordem
*/
void pos(arv* arvore);

/*Funcao pre-ordem
Deve imprimir as chaves na ordem em que forem visitadas por um percurso em pre-o
rdem
*/
void pre(arv* arvore);

/*Funcao em-ordem
Deve imprimir as chaves na ordem em que forem visitadas por um percurso em em-o
rdem
*/
void em(arv* arvore);

/*Funcao largura
Deve imprimir as chaves na ordem em que forem visitadas por um percurso em largura
*/
void largura(arv* arvore, arv** fila);

/*Funcao cria
Cria uma arvore vazia e retorna um ponteiro nulo pra arvore
*/
arv* arvore_cria(void);

/*Funcao Remover
Deve remover a chave x da arvore de busca, se houver. O programa deve sempre usar o sucessor de um no para a substituicao de um no que tenha dois filhos.
*/
arv* remover(arv* arvore, int x);

/*Funcoes minimo e maximo
O programa deve imprimir a menor ou a maior chave da arvore, respectivamente
*/
int min(arv* arvore);
int max(arv* arvore);

/*Funcoes sucessor, predecessor
O programa deve imprimir o sucessor de x ou o predecessor de x, rspectivamente.
*/
void sucess(arv* arvore, int x);
void predeces(arv* arvore, int x);

/*Funcao buscar intervalo
O programa deve imprimir todas as chaves contidas np intervalo [x,y] em ordem crescente separadas por espaco em uma linha, se nao houver chaves o programa deve imprimir nenhuma.
*/
void busca_i(arv* arvore, int x, int y);

void copia(arv* arvore,arv** ipe);

void inserir2(arv** ipe, int chave);
