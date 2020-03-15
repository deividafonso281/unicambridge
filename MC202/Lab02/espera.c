#include <stdio.h>
#include <stdlib.h>

int menor (int* v, int atendentes);

int main (void) {
	int** matriz;
	int atendentes;
	int clientes;
	int* v_atendentes; // vetor de atendentes
	int i;
	int j;
	int p_atendentes; // parametro atendentes
	float tempo_total;
	tempo_total = 0;
	float media;
	int dezmais;
	dezmais = 0;
	scanf("%d%d", &atendentes, &clientes);
	matriz = (int**) malloc((clientes)*sizeof(int*));
	for (i=0; i<(clientes); i++) {
		matriz[i] = (int*) malloc(3*sizeof(int));
}
	for (i=0; i<3; i++){
		matriz[0][i] = 0;
}
	for (i=0; i<(clientes); i++){
		for (j=0; j<2; j++){
			scanf("%d", &matriz[i][j]);
				matriz[i][2] = 0;
}
} /* definindo parametros */
	v_atendentes = (int*) malloc(atendentes*sizeof(int));
	for (i=0; i<atendentes; i++) {
		v_atendentes[i] = 0;
}

/* calculando o tempo de espera */
for (i=0; i<(clientes); i++) {
		p_atendentes = menor(v_atendentes,atendentes);
		matriz[i][2] = v_atendentes[p_atendentes] - matriz[i][0];
		if (matriz[i][2]<0) {
			matriz[i][2] =0;
}
                v_atendentes[p_atendentes] = matriz[i][0] + matriz[i][1] + matriz[i][2];
                tempo_total += matriz[i][2];
		if (matriz[i][2] > 10) {
                dezmais +=1;
}
} 
	media = (tempo_total / clientes);
	printf("Espera media para %d clientes: %.1f minutos\n", clientes, media);
	printf("Numero de clientes que esperaram mais que 10 minutos: %d\n", dezmais);
	return 0;
}

int menor (int* v, int atendentes) {
	int menor;
	int i;
	int retorno;
	retorno = 0;
	menor = v[0];
	for (i=1; i<atendentes; i++) {
		if (v[i] < menor) {
			menor = v[i];
			retorno = i;
}
}
	return retorno;
}
