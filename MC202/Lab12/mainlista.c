#include <stdio.h>
#include <stdlib.h>
#include "listsort.h"

int main (void) {

	int tamanho;
	int* lista;
    int i;
	scanf("%d", &tamanho);
	lista = (int*) malloc(2*tamanho*sizeof(int));
	for (i=(tamanho-1); i>=0; i -= 1) {
		scanf(" %d", &lista[i]);
    if (i == 1) {
        break;
    }
	}
    scanf("%d", &lista[0]);
    tamanho = tamanho-1;
/* ------------------------------------------ Chega ate aqui --------------------------------------*/
	lista = cria_heap(lista,tamanho);
	lista = ordenar(lista,tamanho);
	print_heap(lista,tamanho);
	free(lista);
	return 0;

}

