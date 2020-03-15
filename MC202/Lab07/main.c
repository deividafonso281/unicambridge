#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sequencia.h"

int main (void) {

	int n;
	sequencia* seq;
	seq = seq_cria();
	char command[15];
	scanf(" %s", command);
	while (0!=1) {
		if (strcmp("is-empty",command)==0)
			isempty (seq);
		else if(strcmp("insert-first",command)==0) {
			scanf("%d", &n);
			insertfirst(n,seq);
}
		else if(strcmp("remove-first",command)==0) {
			removefirst(seq);
}
		else if(strcmp("print-first",command)==0)
			printfirst(seq);
		else if(strcmp("insert-last",command)==0) {
			scanf("%d", &n);
			insertlast(n,seq);
}
		else if(strcmp("remove-last",command)==0) {
			removelast(seq);
}
		else if(strcmp("print-last",command)==0)
			printlast(seq);
		else if(strcmp("exit",command)==0) {
			free(seq);
			exit(0);
}
		scanf(" %s", command);
}
}
