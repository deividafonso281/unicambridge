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
