/* Constantes exportadas */
#define infinite -51


/* Estruturas exportadas */

struct node {

    int distance;
    int teste;

};

typedef struct node node;

struct gr {

	int* vizinhos;
    int* indices;
	node* vertices;
    int tamanho;
};

typedef struct gr graph;

/* Funcoes exportadas */

/* Funcao cria grafo */
/* Recebe como entrada as arestas e retorna um vetor de adjacencia representando o grafo */
graph c_grafo(void);
/* Funcao busca em largura */
/* Percorre o grafo a partir da origem indicada e imprime todos os vertices acessiveis e sua respectiva distancia do ponto de origem */
void b_largura(graph grafo, int first);