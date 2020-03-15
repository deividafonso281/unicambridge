#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estrutura.h"

int main (void) {

	int n;
	int r;
	int i;
	int custom = 0;
	int custot = 0;
	int custoc = 0;
	scanf("%d %d", &n, &r);
	node* listam;
	node* listat;
	node* listac;
	listam = lista_cria();
	listat = lista_cria();
	listac = lista_cria();
	for ( i=0; i<n; i++ ) {
		listam = lista_insere(listam,(n-i));
		listat = lista_insere(listat,(n-i));
		listac = lista_insere(listac,(n-i));
}
	node** plistam = &listam;
	node** plistat = &listat;
	node** plistac = &listac;
	for (i=0; i<r; i++) {
		int req;
		scanf("%d", &req);
		custom += move_to_front(plistam,req);
		custot += transpose(plistat,req);
		custoc += count(plistac,req);
		lista_print(listac);
}
	printf("%d %d %d\n", custom, custot, custoc);
	lista_libera(listam);
	lista_libera(listat);
	lista_libera(listac);
}	
