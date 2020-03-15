#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void imprime (double** vet, int ordem);

int main (void) {
	int ordem;
	int i;
	int j;
	double media=0;
	double desvio=0;
	double contador=0;
	double** vet;
	scanf("%d", &ordem);
	vet = (double**) malloc(ordem*sizeof(double*));
	for (i=1; i<(ordem+1); i++){
		vet[i-1] = (double*) malloc(i*sizeof(double));
		for (j=0; j<i; j++){
			scanf("%lf", &vet[i-1][j]);
			media += vet[i-1][j];
			contador += 1;
}
}
	for (i=1; i<(ordem+1); i++)
                for (j=0; j<i; j++)
			desvio += pow((vet[i-1][j]-media/contador),2);
	desvio = (desvio/contador);
	desvio = pow(desvio,0.5);
	for (i=1; i<(ordem+1); i++){
                for (j=0; j<i; j++){
			vet[i-1][j] = ((vet[i-1][j]-media/contador)/desvio);
}
}
	imprime(vet,ordem);
	printf("\n");
	printf("%.12lf %.12lf ", (media/contador), desvio);
	printf("\n");
	for (i=0; i<ordem; i++){
		free(vet[i]);
}
	free(vet);
}

void imprime (double** vet, int ordem) {
	int i;
	int j;
	for (i=1; i<(ordem+1); i++){
                for (j=0; j<i; j++){
                        printf("%.12lf ", vet[i-1][j]);
}
                printf("\n");
}
}
