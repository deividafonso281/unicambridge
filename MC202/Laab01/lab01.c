#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int sub(int** matriz, int n, int m, int r, int s);// funcao que acha a soma

int main (void) {
	int n; //numero de linhas da matriz
	int m; //numero de colunas da matriz
	int r; // numero de linhas da submatriz
	int s; // numero de colunas da submatriz
	int i; // contador entrada da matriz
	int j; // contador linha da matriz
	int k; // contador coluna da matriz
	int result; // resultado da operacao
	int** matriz; //matriz
	scanf("%d %d %d %d", &n, &m, &r, &s); //leitura n,m,r,s
	matriz = (int**) malloc(n*sizeof(int*)); /*reserva de espaco na memoria para a matriz*/
	for (i = 0; i < n; i++) {
		matriz[i] = (int*) malloc(m*(sizeof(int)));
} //reserva espaco na memoria para as linhas
	for (j = 0; j < n; j++) {
		for (k = 0; k < m; k++) {
			scanf("%d", &matriz[j][k]);
}
}//leitura da matriz
	result = sub(matriz,n,m,r,s);
	printf("%d\n", result);
	return 0;
}

int sub (int** matriz, int n, int m, int r, int s) {
	int g; // contador da linha
	int h; // contador da coluna
	int f; // muda linha
	int e; // muda coluna
	int soma; 
	int soma_max;
	soma = 0;
	soma_max = 0;
	for (f = 0; f < (n-r+1); f++){
		for (e = 0; e < (m-s+1); e++){
			for (g = f; g < (f+r); g++){
				for (h = e; h < (e+s); h++){
					soma += matriz[g][h];
}
}
			if (soma > soma_max) {
				soma_max = soma;
}			
			soma = 0;
}
}
	return soma_max;
}
