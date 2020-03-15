/* Funcoes exportadas */

/* Funcao cria heap
Recebe como parametro uma lista de inteiros e retorna um heap
*/

int* cria_heap(int* lista, int tamanho);

/* Funcao remove maximo
Recebe como parametro um heap e remove seu maximo
*/

int* removemax(int* lista, int tamanho);

/* Funcao print heap 
Recebe como parametro um heap e o printa
*/

void print_heap(int* lista, int tamanho);

/* Funcao ordenar heap
Recebe como parametro um heap e retorna um heap ordenado em ordem crescente
*/

int* ordenar(int* lista, int tamanho);

