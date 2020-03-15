/* TAD: No */

/* Tipo exportado */
typedef struct node node;

/* Funcoes exportadas */

/* Funcao cria 
** Cria uma lista vazia
*/

node* lista_cria (void);

/* Funcao insercao
** Insere um novo no na lista

*/

node* lista_insere (node* lista, int i);

/* Funcao Move to Front
** Move um no para o inicio da lista 

*/

int move_to_front (node** lista, int valor);

/* Funcao Transpose
** Troca o registro com o que o precede

*/

int transpose (node** list, int valor);

/* Funcao Count
**  Incrementa o contador do registro e ele e movido uma posicao anterior a todos os registros com contador menor ou igual ao dele

*/

int count (node** lista, int valor);

/* Funcao libera
** Funcao que libera o espaco alocado para uma lista

*/

void lista_libera (node* lista);

void lista_print(node* lista);
