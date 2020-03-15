#include <stdio.h>
#include <stdlib.h>

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
	int l;
        int** matriz; //matriz
        scanf("%d %d %d %d", &n, &m, &r, &s); //leitura n,m,r,s
        matriz = (int**) malloc((n+1)*sizeof(int*)); /*reserva de espaco na memoria para a matriz*/
        for (i = 0; i < n+1; i++) {
                matriz[i] = (int*) malloc((m+1)*(sizeof(int)));
} //reserva espaco na memoria para as linhas
        for (l = 0; l < m+1; l++){
		matriz[0][l] = 0;
}	
	for (j = 1; j < n+1; j++) {
		matriz[j][0] = 0;
		for (k = 1; k < m+1; k++) {
                        scanf("%d", &matriz[j][k]);
}
}//leitura da matriz
        result = sub(matriz,n,m,r,s);
        printf("%d\n", result);
        return 0;
}

int sub(int** matriz, int n, int m, int r, int s){
	int** temp;
	int k;
	int i;
	int j;
	int l;
	int soma;
	int soma_max;
	soma = 0;
	soma_max =0;
	temp = (int**) malloc((n+1)*sizeof(int*));
	for (k = 0; k < n+1; k++){
		temp[k] = (int*) malloc((m+1)*sizeof(int));
}
	for (l = 0; l < m+1; l++){
                matriz[0][l] = 0;
}
	for (i=1; i<n+1; i++){
		temp[i][0] = 0;
		for (j=1; j<m+1; j++){
			temp[i][j] = (matriz[i][j] + temp[i][j-1] + temp[i-1][j] - temp[i-1][j-1]);
}
}
	for (i=1; i< (n-r+2); i++){
		for (j=1; j< (m-s+2); j++){
			soma = (temp[i+r-1][j+s-1]- temp[i+r-1][j-1] - temp[i-1][j+s-1] + temp[i-1][j-1]);
			if (soma > soma_max){
				soma_max = soma;
}
}
}
	return soma_max;
}
