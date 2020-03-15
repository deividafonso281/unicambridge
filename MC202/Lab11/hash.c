#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

int transforma(string* cc) {
	int i;
	long long soma = 0;
	for (i=0;cc->cadeia[i]!= '\0';i++) {
	soma += (i%7)*cc->cadeia[i];
	}
	return soma;
}

int hash_i(int soma) {
	int hash;
	hash = (soma % 6961);
	return hash;
}

int hash_d(string* cc, string** tabela) {
	int soma;
	int hash;
	int hash_aux;
	int hash2;
	soma = transforma(cc);
	hash = hash_i(soma);
	hash2 = hash_i(soma);
        hash_aux = (6959)-soma%(6959);
	while (tabela[hash] != NULL) {
		if (strcmp(tabela[hash]->cadeia,cc->cadeia)==0){
			return ((-1)*hash);
		}
		else if (transforma(tabela[hash])!=transforma(cc)){
		if ((hash == hash2) && (strcmp(tabela[hash]->cadeia,cc->cadeia)!=0)) {
			return -1;
		}
		hash += hash_aux;
                hash %= 6959;
		}
		else{
			hash = (hash+ 51)%6959;
		}		
	}
	return hash;
}

string** inserir(string* cc, string** tabela,unsigned long id) {
	int indice;
	indice = hash_d(cc,tabela);
	if (indice > -1) {
		tabela[indice] = (string*) malloc(sizeof(string));
		strcpy(tabela[indice]->cadeia,cc->cadeia);
		tabela[indice]->id = id;
		tabela[indice]->chave = indice;
	}
	return tabela;
}

int buscar(string* cc, string** tabela) {
	int indice;
	indice = hash_d(cc,tabela);
	if (indice >= -1) {
			return -1;
	}
	else {
		return (-1)*indice;
	}
}

string** remover(string* cc, string** tabela) {
	int indice;
	indice = hash_d(cc,tabela);
	if (indice < -1) {
		indice *= -1;
                tabela[indice] = NULL;
	}
	return tabela;
}

void liberar(string** tabela) {
	free(tabela);
}
