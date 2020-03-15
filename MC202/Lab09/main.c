#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"

int main (void) {
		
	arv* arvore;
	arvore = NULL;
	char teste[15];
	scanf(" %s", teste);
	while (1) {
		if (strcmp(teste, "inserir") == 0) {
			int chave;
			scanf("%d", &chave);
			inserir(&arvore,chave);
		}
		else if (strcmp(teste, "buscar")==0) {
			int chave;
			scanf("%d", &chave);
			buscar(arvore,chave);
		}
		else if (strcmp(teste,"pos-ordem")==0) {
			if (arvore == NULL) 
				printf("vazia\n");
			else {
				pos(arvore);
				printf("\n");
			}
		}
		else if (strcmp(teste,"em-ordem")==0) {
			if (arvore == NULL) 
                                printf("vazia\n");
                        else {
				em(arvore);
				printf("\n");
			}
		}
		else if (strcmp(teste,"pre-ordem")==0) {
			if (arvore == NULL) 
                                printf("vazia\n");
                        else {
				pre(arvore);
				printf("\n");
			}
		}
		else if (strcmp(teste,"largura")==0) {
			if (arvore == NULL) 
                                printf("vazia\n");
                        else {
				arv** fila;
				fila = (arv**) malloc(128*sizeof(arv*));
				fila[127] = NULL;
				largura(arvore, fila);
				printf("\n");
				free(fila);
			}
		}
		else if (strcmp(teste,"terminar")==0) {
			exit(1);
		}
		scanf(" %s", teste);
	}
}
