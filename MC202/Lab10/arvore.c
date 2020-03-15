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

int min(arv* arvore) {
	if (arvore != NULL){	
	int min;
	min = arvore->key;
	arv* p;
	for (p = arvore; p != NULL; p = p->left) {
		min = p->key;
	}
	return min;
	}
	else {
		return -51;
}
}

int max(arv* arvore) {
	if (arvore != NULL) {
	int max;
	max = arvore->key;
	arv* p;
	for (p = arvore; p != NULL; p = p->right) {
		max = p->key;
	}
	return max;
	}
	else {
		return -51;
}
}

 void sucess(arv* arvore, int x) {

 	if (arvore != NULL) {
                int maior = 0;
                arv* t;
		arv* r;
                t = NULL;
                copia(arvore,&t);
                while (t!=NULL) {
                        if (t->key > x) {
                                maior = t->key;
				break;
			}
			r = t;  
                        t = t->right;
                        free(r);
                }
		if (maior == 0) {
			printf("nao ha\n");
		}
		else {
                	printf("%d\n", maior);
		}
        } 
}

void predeces(arv* arvore, int x) {
 	if (arvore != NULL) {
		int menor;
		arv* r;
		arv* t;
        	t = NULL;
        	copia(arvore,&t);
		if (x <= t->key) {
			printf("nao ha\n");
		}
		else {
		
			while (t!=NULL) {
				if (t->key < x) {
					menor = t->key;
				}
				r = t;  
                                t = t->right;
                                free(r);
			}
			printf("%d\n", menor);
		}
	}
 }

void busca_i(arv* arvore, int x, int y) {
        if (arvore != NULL) {
		arv* r;
                arv* t;
		int count = 0;
                t = NULL;
                copia(arvore,&t);
                while (t!=NULL) {
                        if ((t->key >= x) && (t->key <= y)) {
                                printf("%d ", t->key);
				count+=1;
                        }
                        r = t;
                        t = t->right;
                        free(r);
                }
		if (count==0) {
			printf("nenhuma");
		}
		printf("\n");
        }
}

arv* remover(arv* p, int x) {

	if (x < p->key && p->left != NULL) {
		p->left =remover(p->left, x);
	}
	else if (p->key < x && p->right != NULL) {
		p->right = remover(p->right, x);
	}
	else if (p->key == x) {
		if (p->left == NULL && p->right == NULL){
			p = NULL;
		}
		else if(p->left != NULL && p->right != NULL) {
			p->key = min(p->right);
			p->right = remover(p->right,min(p->right));	
		}
		else {
			if( p->right != NULL) {
				arv* t = p;
				p = p->right;
				free(t);
			}
			else {
				arv* t = p;
				p = p->left;
				free(t);
			}
		}
	}
	return p;
}

void copia(arv* arvore, arv** ipe) {
	if (arvore != NULL) {
		copia(arvore->left,ipe);
		inserir2(ipe,arvore->key);
		copia(arvore->right,ipe);
	}
}

void inserir2(arv** ipe, int chave) {
	if (*ipe ==NULL) {
                        *ipe = (arv*) malloc(sizeof(arv));
                        (*ipe)->key = chave;
                        (*ipe)->left = NULL;
                        (*ipe)->right = NULL;
                }

                else {
                        inserir2(&((*ipe)->right),chave);
		}
}
