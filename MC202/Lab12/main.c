#include <stdio.h>
#include <stdlib.h>
#include "heapsort.h"

int main (void) {

	int tamanho;
	int i;
	int* lista;
	int aux;
	Heap prioridade;
	scanf("%d", &tamanho);
	/*lista = (int*) malloc(tamanho*sizeof(int));
	for (i=0; i < tamanho; i++) {
		scanf("%d", &aux);
		lista[i] = aux;
	}*/
/* ------------------------------------------ Chega ate aqui --------------------------------------*/
	prioridade = cria_heap(lista,tamanho-1);
	printf("cira");
	prioridade = ordenar(prioridade);
	printf("ordenar");
	print_heap(prioridade);
	printf("prioridade");
	free(lista);
	free(prioridade.heap);
	return 0;

}
