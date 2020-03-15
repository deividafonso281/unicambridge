#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sequencia.h"
#define PI -10000000
struct sequencia {

	int* vetor;
	int indice_i;
	int indice_f;
	int tamanho;
};

typedef struct sequencia sequencia;


void insertfirst (int n, sequencia* seq) {
	if (seq->vetor[seq->indice_i]!=PI) {
		if (seq->indice_i != 0) {
			seq->vetor[seq->indice_i-1] = n;
			seq->indice_i -=1;
}
		else {
			seq->vetor[seq->tamanho-1] = n;
			seq->indice_i = seq->tamanho-1;
}
}
	else {
		seq->vetor[seq->indice_i] = n;
}
	teste(seq);
}


void removefirst (sequencia* seq) {
	if (seq->indice_i != seq->indice_f) {
		if (seq->indice_i == seq->tamanho-1) {
			seq->vetor[seq->indice_i] = PI;
			seq->indice_i = 0;
			teste(seq);
}
		else {
			seq->vetor[seq->indice_i] = PI;
			seq->indice_i += 1;
			teste(seq);
}
}
	else {
		seq->vetor[seq->indice_i] = PI;
}
}


void printfirst (sequencia* seq) {
	if (seq->vetor[seq->indice_i] != PI) {
		printf("%d\n", seq->vetor[seq->indice_i]);
}
}


void insertlast (int n, sequencia* seq) {

	if (seq->vetor[seq->indice_f]!= PI) {
		if (seq->indice_f == seq->tamanho-1) {
			seq->vetor[0] = n;
			seq->indice_f = 0;
}
		else {
			seq->vetor[seq->indice_f+1] = n;
			seq->indice_f += 1;
}
}
	else {
		seq->vetor[seq->indice_f] = n;
}
			teste(seq);
}


void removelast (sequencia* seq) {
	if (seq->indice_i != seq->indice_f) {
		if (seq->indice_f != 0) {
			seq->vetor[seq->indice_f] = PI;
        		seq->indice_f -= 1;
			teste(seq);
}
		else {
			seq->vetor[seq->indice_f] = PI;
			seq->indice_f = seq->tamanho-1;
			teste(seq);
}
}
	 else {
                seq->vetor[seq->indice_f] = PI;
}
}


void printlast (sequencia* seq) {
	if (seq->vetor[seq->indice_f] != PI) {
		printf("%d\n", seq->vetor[seq->indice_f]);
}
}


void isempty (sequencia* seq) {
	if ((seq->indice_i == seq->indice_f)&&(seq->vetor[seq->indice_f]==PI)) {
		printf("yes\n");
}
	else {
		printf("no\n");
}
}

void teste (sequencia* seq) {
	
	int i;
	int x= (seq)->tamanho - (seq)->indice_i;
	int dim;
	dim  = ((seq)->indice_f - (seq)->indice_i);
	if (dim < 0) {
		dim = x + (seq)->indice_f+1;
		if ((dim <= ((seq)->tamanho/4)) && (dim>3) ) {
			sequencia* seq_n;
			seq_n = (sequencia*) malloc(sizeof(sequencia));
			seq_n->vetor = (int*) malloc((((seq)->tamanho+1)/2)*sizeof(int));
			for (i = 0; i <= x; i++) {
				seq_n->vetor[i] = (seq)->vetor[(seq)->indice_i+i];
}
			for (i=0; i <= (seq)->indice_f; i++) {
				seq_n->vetor[x+i] = (seq)->vetor[i];
}
			seq_n->indice_i = 0;
                        seq_n->indice_f = dim - 1;
                        seq_n->tamanho = (((seq)->tamanho+1)/2);
			*seq = *seq_n;
			free(seq_n);

}
		else if (dim == (seq)->tamanho) {
			sequencia* seq_n;
			seq_n = (sequencia*) malloc(sizeof(sequencia));
                        seq_n->vetor = (int*) malloc((seq)->tamanho*2*sizeof(int));
			for (i = 0; i <= x; i++) {
                                seq_n->vetor[i] = (seq)->vetor[(seq)->indice_i+i];
}
                        for (i=0; i <= (seq)->indice_f; i++) {
                                seq_n->vetor[x+i] = (seq)->vetor[i];
}
			seq_n->indice_i = 0;
                        seq_n->indice_f = dim - 1;
                        seq_n->tamanho = 2*(seq)->tamanho;
                        *seq = *seq_n;
			free(seq_n);
}
}
	else if (dim > 0) {
		dim += 1;
		if ((dim <= ((seq)->tamanho/4))&& (dim>3)) {
			printf("dim = %d, tamanho = %d\n", dim, (seq)->tamanho);
                        sequencia* seq_n;
			seq_n = (sequencia*) malloc(sizeof(sequencia));
                        seq_n->vetor = (int*) malloc((((seq)->tamanho+1)/2)*sizeof(int));
			for (i=0; i<dim; i++) {
				seq_n->vetor[i] = (seq)->vetor[(seq)->indice_i+i];
}				
			seq_n->indice_i = 0;
			seq_n->indice_f = dim - 1;
			seq_n->tamanho = (((seq)->tamanho+1)/2);
			*seq = *seq_n;
			free(seq_n);
}
		else if (dim == (seq)->tamanho) {
			sequencia* seq_n;
			seq_n = (sequencia*) malloc(sizeof(sequencia));
                        seq_n->vetor = (int*) malloc((seq)->tamanho*2*sizeof(int));
                        for (i = 0; i < dim; i++) {
                                seq_n->vetor[i] = (seq)->vetor[i];
}
                        seq_n->indice_i = 0;
                        seq_n->indice_f = dim - 1;
                        seq_n->tamanho = 2*(seq)->tamanho;
			*seq = *seq_n;
			free(seq_n);			
}
}
			printf("%d\n",(seq)->tamanho);
			printf("%d\n",dim);
}

sequencia* seq_cria (void) {

	sequencia* seq;
	seq = (sequencia*) malloc(sizeof(sequencia));
        seq->vetor = (int*) malloc(128*sizeof(int));
	seq->vetor[0] = PI;
        seq->indice_i = 0;
        seq->indice_f = 0;
        seq->tamanho = 128;
        return seq;
}
