#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct contato {
	char nome[51];
	char endereco[101];
	char telefone[13];
	char data_de_aniversario[9];
	int teste;
};

typedef struct contato Contato;

void inserir(Contato* lista);

void remover(Contato* lista, char* nome);

void busca(Contato* lista, char* nome);

void imprimir(Contato* lista);

int main (void) {
	int i;
	char ent;
	char* nome;
	Contato* lista;
	nome = (char*) malloc(51*sizeof(char));
	lista = (Contato*) malloc(1000*sizeof(Contato));
	lista[0].teste = 0;
	lista[0].nome[0] = 'a'; 
	for (i=1; i<1000; i++) {
		lista[i].nome[0] = 'a';
		lista[i].teste = -1;
}
	scanf("%c", &ent);
	while (ent != 'f') {
		if (ent == 'i') {
			inserir(lista);
}
		else if (ent == 'r') {
			scanf(" %[^\n]", nome);
			remover(lista,nome);
}
		else if (ent == 'b') {
			scanf(" %[^\n]", nome);
			busca(lista,nome);
}
		else if (ent == 'p') {
			imprimir(lista);
}
		scanf("%c", &ent);
}

	return 0;
}

void inserir (Contato* lista) {
	int i;
	int contador = 0;
	for (i=0; i<1000; i++){
		if (lista[i].teste == 0) {
			scanf(" %[^\n]", lista[i].nome);
			scanf(" %[^\n]", lista[i].endereco);
			scanf(" %[^\n]", lista[i].telefone);
			scanf(" %[^\n]", lista[i].data_de_aniversario);
			lista[i].teste = 1;
			lista[i+1].teste = 0;
			contador = i;
			break;
}
}
	printf("Contato para %s inserido.\n\n", lista[contador].nome);
}

void remover (Contato* lista, char* nome) {
	int i = 0;
	int contador = 0;
	while ((lista[i].teste != -1)&&(i<1000)) {
		if (strcmp(lista[i].nome,nome)== 0) {
			lista[i].teste = 0;
			contador += 1;
}
		i+=1;
}
	printf("Contatos de %s removidos: %d.\n\n", nome, contador);
}

void busca (Contato* lista, char* nome) {
	int i = 0;
	int contador = 0;
	while ((lista[i].teste != -1)&&(i<1000)) {
		if (strstr(lista[i].nome,nome)!=NULL) {
			contador += 1;
			if (contador == 1)
				printf("Resultado da busca:\n");
			printf("(%d) %s\t%s\t%s\t%s\n\n",(i+1), lista[i].nome, lista[i].endereco, lista[i].telefone, lista[i].data_de_aniversario);
}
		i+=1;
}
	if (contador == 0) {
	printf("Resultado da busca:\nNenhum contato.\n\n");
}
}

void imprimir(Contato* lista) {
	int i=0;
	int contador = 0;
	printf("Listagem:\n");
	while ((lista[i].teste != -1)&&(i<1000)) {
		if (lista[i].teste != 0) {
		contador +=1;
		printf("(%d) %s\t%s\t%s\t%s\n", contador, lista[i].nome, lista[i].endereco, lista[i].telefone, lista[i].data_de_aniversario);
}
		i+=1;
	
}
	if (contador == 0)
		printf("Nenhum contato.\n");
	printf("\n");
}	
