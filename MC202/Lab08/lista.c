#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct node {

	double valor;
	node* A;
	node* B;
};

node* lista_cria (void) {

	node* no;
	no = NULL;
	return no;
}

node* next (node* point, node* ant) {

	if ( point->A != ant )
		return point->A;
	else
		return point->B;
}

void inserir (node** lista, int posicao, double valor) {

	node* novo;
        novo = (node*) malloc(sizeof(node));
	novo->valor = valor;
	if (*lista == NULL) {
		novo->A = NULL;
		novo->B = NULL;
		*lista = novo;
}
	else {
		int indice = 0;
		node* ant = NULL;
		node* point = *lista;
		node* prox;
		while (indice < posicao && point != NULL) {
			prox = next(point,ant);
			ant = point;
			point = prox;
			indice++;
		}
		novo->A = ant;
                novo->B = point;
		if (point != NULL) {
			if (point->A == ant) {
				point->A = novo;
			}
			else {
				point->B = novo;
			}
		}
		if (ant != NULL) {
			if (ant->A == point) {
				ant->A = novo;
			}
			else {
				ant->B = novo;
			}
		}
		if (ant == NULL) {
			*lista = novo;
		}
	}
}

void imprimir (node* lista) {

	node* point;
	point = lista;
	if (point == NULL) 
		printf("\n");
	else {
		node* ant;
            	node* prox;
            	ant = NULL;
		while (point != NULL) {
			printf("%.4lf ", point->valor);
			prox = next(point,ant);
			ant = point;
			point = prox;
		}
		printf("\n");
	}
}

void reverter (node** lista, int inicio, int termino) {

	node* point;
	node* ant = NULL;
	node* dps = NULL;
	node* prim = NULL;
	node* ini;
	node* fim;
	node* prox;
	point = *lista;
	int indice = 0;
	if ( inicio != termino ) {
		while (point != NULL) {
			if (indice == inicio-1){
				prim = point;
			}
			else if (indice == inicio){
				ini = point;
			}
			else if (indice == termino){
				fim = point;
			}
			else if (indice == termino+1){
				dps = point;
				break;
			}
			prox = next(point,ant);
                	ant = point;
                	point = prox;
			indice++;
		}
		if (prim != NULL) {
			if (prim->A == ini)
				prim->A = fim;
			else 
				prim->B = fim;
		}
		if (ini->A == prim)
			ini->A = dps;
		else
			ini->B = dps;
		if (fim->A == dps)
			fim->A = prim;
		else
			fim->B = prim;
		if (dps != NULL) {
			if (dps->A == fim)
				dps->A = ini;
			else
				dps->B = ini;
		}
		if (prim == NULL) {
			*lista = fim;
		}
	}
}
