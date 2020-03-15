#include <stdio.h>
#include <stdlib.h>
#include "estrutura.h"

struct node {

	int valor;
	int count;
	struct node* next;
};

typedef struct node node;

node* lista_cria(void){

	return NULL;
}

node* lista_insere(node* lista, int i) {

	node* novo;
	novo = (node*) malloc(sizeof(node));
	novo->valor = i;
	novo->count = 0;
	novo->next = lista;
	return novo;
}

int move_to_front (node** lista, int valor) {

	node* p;
        node* ant;
        ant = NULL;
        p = *lista;
	int teste = 1;
        while ((p->valor != valor) && (p->next != NULL)) {

                ant = p;
                p = p->next;
		teste += 1;
}
        if (ant == NULL)
                return 1;
        else {
                ant->next = p->next;
        	p->next = *lista;
		*lista = p;
		return teste;
}
}

int transpose (node** lista, int valor) {
	
	node* p;
	node* ant;
	int custo;
	p = *lista;
	ant = NULL;
	custo = 1;
	while ((p->next != NULL) && (p->valor != valor)) {

		ant = p;
		p = p->next;
		custo += 1;
}
	if (custo >= 3) {
		int j;
		ant->next = p->next;
		p->next = ant;
		node* t = *lista;
		for (j=0; j<(custo-3); j++) {
			t = t->next;
}
		t->next = p;
		return custo;
}
	else if (custo == 2) {
		ant->next = p->next;
		p->next = ant;
		*lista = p;
		return custo;
}
	else 
		return 1;
}

/* int count (node** lista, int valor) {

	node* p;
	node* ant;
	int custo;
	p = *lista;
	ant = NULL;
	custo = 1;
	while ((p != NULL) && (p->valor != valor)) {
		ant = p;
		p = p->next;
		custo += 1;
}
	if (ant != NULL) {
		p->count += 1;
		ant->next = p -> next;
		node* t = *lista;
		if (t->count <= p->count) { 
			p->next = *lista;
			*lista = p;
			return custo;
}
		while ( (t->next)->count  > p->count && t->next != NULL) {
			t = t->next;
}
		p->next = t->next;
		t->next = p;
		return custo;
}
	else {
		p->count += 1;
		return 1;
}
} */

void lista_libera (node* lista) {
	node* p;
	p = lista;
	node* t;
	while (p != NULL) {
		t = p->next;
		free(p);
		p = t;
}
}

void lista_print(node* lista) {

	node* p;
	p = lista;
	while (p!=NULL) {
		printf("(%d,%d)", p->valor, p->count);
		p = p->next;
}
	printf("\n");
}

int count (node** lista, int valor) {

	node* nozinho = *lista;
	node* aux = NULL;
	int i, indice = 1, j;
	for (i = 0; nozinho!= NULL; i++) {
		if (nozinho-> valor == valor) {
			nozinho->count +=1;
			if (aux == NULL) {
				return 1;
}
			else {
				aux->next = nozinho->next;
				indice += i;
				break;
}
}
		else {
			aux = nozinho;
			nozinho = nozinho->next;
}
}
	for (aux = *lista; aux->next!=NULL; aux = aux->next) {
		if (nozinho->count >= (*lista)->count) {
			nozinho->next = (*lista);
			(*lista) = nozinho;
			return indice;
}
		else {
			if (aux->next->count <= nozinho->count){
				nozinho->next = aux->next;
				aux->next = nozinho;
				return indice;
}
}
}
}
