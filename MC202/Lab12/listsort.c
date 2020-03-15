#include <stdio.h>
#include <stdlib.h>
#include "listsort.h"

int* cria_heap(int* lista, int tamanho) {

	int i;
	int max;
	int aux;
    int pai;
    int j;
    int k;
	for (i=tamanho; i>=2; i--) {
		if (i%2==0) {
            pai = i/2-1;
            k = i;
            j = i-1;
			if( lista[k] > lista[j] ) { 
				max = k;
			}
			else {
				max = (j);
			}
			if (lista[pai] < lista[max]) {
				aux = lista[pai];
				lista[pai] = lista[max];
				lista[max] = aux;
                k= 2*max+1;
                j= 2*max+2;
                pai = max;
                while (k <= tamanho ){
                    if (k <tamanho) {
                        if( lista[k] > lista[j] ) { 
				            max = k;
			            }
			            else {
				            max = (j);
			            }
                    }
                    else if (2*max+1== tamanho) {
                        max = k;
                    }
                    if (lista[pai] < lista[max]) {
				        aux = lista[pai];
				        lista[pai] = lista[max];
				        lista[max] = aux;
                    }
                    k= 2*max+1;
                    j= 2*max+2;
                    pai = max;
                }
			}
		}
	}
	return lista;
	
}

int* removemax(int* lista, int tamanho) {
    
	int aux;
	int i = 0;
	int max;
	int j;
	int k;
	aux = lista[tamanho];
	lista[tamanho] = lista[0];
	lista[0] = aux;
	while (i < (tamanho-1)/2) {
		j = 2*i + 1;
		k = 2*i + 2;
		if( lista[j] > lista[k] ) {
			max = j;
		}
		else {
		    max = k;
		}
		if (lista[i] < lista[max]) {
			aux = lista[max];
        		lista[max] = lista[i];
        		lista[i] = aux;
			i = max;
		}
		else {
			break;
		}
	}
	return lista;

}

void print_heap(int* lista, int tamanho) {

	int i;
	for (i = 0; i < tamanho; i++) {
		printf("%d ", lista[i]);
	}
    printf("%d ", lista[tamanho]);
	printf("\n");

}

int* ordenar(int* lista, int tamanho) {

	int contador = tamanho;
	while( contador > 0) {
		lista = removemax(lista, contador);
	contador --;
	} 
	return lista;

}
