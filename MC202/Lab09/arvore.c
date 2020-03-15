#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

struct arvore {

	int key;
	arv* left;
	arv* right;
};

void inserir (arv** arvore, int chave) {

	if (*arvore ==NULL) {
		*arvore = (arv*) malloc(sizeof(arv));
		(*arvore)->key = chave;
		(*arvore)->left = NULL;
		(*arvore)->right = NULL;
	}
	else if (chave < (*arvore)->key) {
		inserir(&((*arvore)->left),chave);
	}
	else if (chave > (*arvore)->key) {
		inserir(&((*arvore)->right),chave);
	}
}

void buscar (arv* arvore, int chave) {
	
	if (arvore == NULL) 
		printf("%d nao pertence\n", chave);
	else if (chave > arvore->key) {
		buscar(arvore->right,chave);
	}
	else if (chave < arvore->key) {
		buscar(arvore->left,chave);
	}
	else if (chave == arvore->key) {
		printf("%d pertence\n", chave);
	}
}

void pos (arv* arvore) {

	if (arvore != NULL) {	
		pos(arvore->left);
		pos(arvore->right);
		printf("%d ", arvore->key);
	}	

}

void pre (arv* arvore) {

	if (arvore != NULL) {
		printf("%d ", arvore->key);
		pre(arvore->left);
		pre(arvore->right);
	}

}

void em (arv* arvore) {

	if (arvore != NULL) {
		em(arvore->left);
		printf("%d ", arvore->key);
		em(arvore->right);
	}

}

void largura (arv* arvore, arv** fila) {

	fila[0]= arvore;
	int i = 0;
	int j;
	for (j = 0; fila[j] != NULL; j++) {
		arv* p = fila[j];
		if ( p->left != NULL ) {
			i += 1;
			fila[i] = p->left;
		}
		if ( p->right != NULL ) {
			i += 1;
			fila[i] = p->right;
		}
}
	for (j=0; fila[j] != NULL; j++) {
		printf("%d ", fila[j]->key);
	}
}

