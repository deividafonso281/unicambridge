#include <stdio.h>
#include <stdlib.h>
#include "heapsort.h"

Heap cria_heap(int* lista, int tamanho) {

	int i;
	int max;
	int aux;
	Heap prioridade;
	prioridade.heap = (int*) malloc((tamanho+1)*sizeof(int));
	printf("Tamanho: %d\n", tamanho);
	for (i=0; i<(tamanho+1); i++) {
		scanf("%d", &aux);
		prioridade.heap[i] = aux;
		printf("%d\n", i);
	}
	printf("%d", i);
	prioridade.removidos = 0;
	prioridade.tamanho = tamanho;
	printf("porra");
	for (i=tamanho; i>=2; i--) {
		if (i%2==0) {
			printf("i//2");
			if( prioridade.heap[i] > prioridade.heap[i-1] ) { 
				max = i;
			}
			else {
				max = (i-1);
			}
			if (prioridade.heap[i/2-1] < prioridade.heap[max]) {
				aux = prioridade.heap[i/2-1];
				prioridade.heap[i/2-1] = prioridade.heap[max];
				prioridade.heap[max] = aux;
			}
		}
	}
	printf("retorno");
	return prioridade;
	
}

Heap removemax(Heap prioridade) {

	int aux;
	int i = 0;
	int max;
	int j;
	int k;
	aux = prioridade.heap[prioridade.tamanho];
	prioridade.heap[prioridade.tamanho] = prioridade.heap[0];
	prioridade.heap[0] = aux;
	while (i < prioridade.tamanho) {
		j = 2i + 1;
		k = 2i + 2;
		if( prioridade.heap[j] > prioridade.heap[k] ) {
			max = j;
		}
		else {
		max = k;
		}
		if (prioridade.heap[i] < prioridade.heap[max]) {
			aux = prioridade.heap[max];
        		prioridade.heap[max] = prioridade.heap[i];
        		prioridade.heap[i] = aux;
			i = max;
		}
		else {
			break;
		}
	}
	prioridade.tamanho--;
	prioridade.removidos++;
	return prioridade;

}

void print_heap(Heap prioridade) {

	int i;
	for (i = 0; i <= prioridade.tamanho; i++) {
		printf("%d ", prioridade.heap[i]);
	}
	printf("\n");

}

Heap ordenar(Heap prioridade) {

	while(prioridade.tamanho != 0) {
		prioridade = removemax(prioridade);
	}
	prioridade.tamanho = prioridade.removidos;
	prioridade.removidos = 0; 
	return prioridade;

}
