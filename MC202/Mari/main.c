#include <stdio.h>
#include <stdlib.h>

int main (void) {
	struct no {
		struct no* prox;
		int valor;
};

	typedef struct no No;

	struct list {
		No* cabeca;
};

typedef struct list list;

list lista = NULL;


for (i = 1; i<31; i++) {
	No no = malloc
	

