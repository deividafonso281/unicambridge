/* Estruturas exportadas */

struct heap {

	int* heap;
	int tamanho;
	int removidos;
};

typedef struct heap Heap;

/* Funcoes exportadas */

/* Funcao cria heap
Recebe como parametro uma lista de inteiros e retorna um heap
*/

Heap cria_heap(int* lista, int tamanho);

/* Funcao remove maximo
Recebe como parametro um heap e remove seu maximo
*/

Heap removemax(Heap prioridade);

/* Funcao print heap 
Recebe como parametro um heap e o printa
*/

void print_heap(Heap prioridade);

/* Funcao ordenar heap
Recebe como parametro um heap e retorna um heap ordenado em ordem crescente
*/

Heap ordenar(Heap prioridade);
