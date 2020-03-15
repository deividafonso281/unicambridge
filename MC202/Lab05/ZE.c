#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void lerLinha(int numElem, double *ondArmazenar){
    for (int i=0; i<numElem; ++i) {
        scanf(" %lf", ondArmazenar++);
    }
}


void main(){
    int n;
    scanf(" %d\n", &n);
    int N = ( (n*n)+n ) / 2;

    /*  Esse laco contem a alocacao da memoria para a matriz.
    /   A matriz E um vetor de ponteiros que cada elemento E um ponteiro para um vetor de floats*/
    double **matriz = (double**) malloc(n*sizeof(double*));
    for (int i=0; i<n; ++i){
        matriz[i] = (double*) malloc((i+1)*sizeof(double));
    }

    /*Aqui a matriz E recebida*/
    for (int i=0; i<n; ++i){
        lerLinha(i+1, matriz[i]);
    }

    //calculando a media
    double media = 0;
    for (int i=0; i<n; ++i){
        for (int j=0; j<=i; ++j){
            media+=matriz[i][j];
        }
    }
    media/=N;

    //calculando o desv. pad.
    double dp = 0;
    for (int i=0; i<n; ++i){
        for (int j=0; j<=i; ++j){
            double acrescimo = (matriz[i][j]-media)*(matriz[i][j]-media);
            printf("Acrescimo: %lf\n", acrescimo);
            dp += acrescimo;
        }
    }
    dp /= N;
    float x = 2.344534F;
    float y = sqrt(x);
    printf("VALOR DA RAIZ: %.12f\n", y);

    //printf("Media: %.12lf\nDP: %.12lf\n", media, dp);
}
