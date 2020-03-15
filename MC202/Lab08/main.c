#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main (void) {
	
	char teste;
	scanf("%c", &teste);
	node* lista;
	lista = lista_cria();
	while (teste != 0) {
		if (teste == 'i') {
			int posicao;
			double valor;
			scanf("%d %lf", &posicao, &valor);
			inserir(&lista, posicao, valor);
		}
		else if (teste == 'p') {
			imprimir(lista);
		}
		else if (teste == 'v') {
			int inicio;
			int termino;
			scanf("%d %d", &inicio, &termino);
			reverter(&lista, inicio, termino);
		}
		else if (teste == 't') {
			exit(0);
		}
		scanf("%c", &teste);
	}
}
