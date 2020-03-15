#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

int main (void) {

	char caractere;
	string* cc;
	string** tabela;
	tabela = (string**) malloc(6961*sizeof(string*));
	unsigned long id = 0;
	int teste;
	scanf("%c", &caractere);
	while (1) {
		if (caractere == 'i') {
			cc = (string*) malloc(sizeof(string));
			scanf("%s", cc->cadeia);
			teste = hash_d(cc,tabela);
			if (teste > -1) {
				tabela = inserir(cc, tabela, id);
				free(cc);
				id++;
			}
		}
		if (caractere == 'b') {
			cc = (string*) malloc(sizeof(string));
			scanf("%s", cc->cadeia);
			teste = buscar(cc,tabela);
			if (teste == -1) {
				printf("%s nao encontrada\n", cc->cadeia);
			}
			else {
				printf("%s encontrada, id %lu\n", tabela[teste]->cadeia, tabela[teste]->id);
			}
			free(cc);
		}	
		if (caractere == 'r') {
			cc = (string*) malloc(sizeof(string));
			scanf("%s", cc->cadeia);
			tabela = remover(cc,tabela);
			free(cc);
		}
		if (caractere == 'f') {
			liberar(tabela);
			exit(0);
		}
		scanf("%c", &caractere);
	}
}
