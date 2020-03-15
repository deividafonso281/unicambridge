#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int bigger (int* contador, int sorrys);
int main (void) {
	
	int loop = 0;
	int k_words;
	int sorrys;
	char** block;
	int* contador;
	int i;
	int j;
	int k;
	char* result;
	int maior;
	char* teste;

while (scanf(" %d %d", &k_words, &sorrys) != EOF) {
	teste = (char*) malloc(100*sizeof(char));
	scanf("%d %d", &k_words, &sorrys);
	block = (char**) malloc((k_words+sorrys)*sizeof(char*));
	for (i=0; i<k_words; i++)
		block[i] = (char*) malloc(20*sizeof(char));
	for (j=k_words; j<(k_words+sorrys); j++)
		block[j] = (char*) malloc(100*sizeof(char));
	contador = (int*) malloc(sorrys*sizeof(int));
	for (i=0; i<sorrys; i++)
		contador[i] = 0;
	for (i=0; i<(k_words+sorrys); i++)
		scanf(" %[^\n]", block[i]);
	for (i=k_words; i<(k_words+sorrys); i++) {
		for (j=0; j<k_words; j++) {
			strcpy(teste, block[i]);
			for(k=0; k<strlen(teste);k++)
				if (teste[k]>= 'A' && teste[k]<='Z')
					teste[k] += 'a' - 'A';
			result = strstr(teste, block[j]);
				while (result != NULL) {
					contador[i-k_words]+=1;
					result = strstr(result+1, block[j]);
}
}
}
	maior = bigger(contador,sorrys);
	printf("Conjunto de desculpas #%d\n", loop+1);
	for (i=0;i<sorrys;i++)
		if (contador[i] == maior)
			printf("%s\n", block[i+k_words]);
	printf("\n");
	free (contador);
	free (teste);
	for (i=0; i<(k_words+sorrys); i++)
		free (block[i]);
	free (block);
	loop += 1;
}
	return 0;
}

int bigger (int* contador, int sorrys) {
	int i;
	int maior = contador[0];
	for (i=1; i<sorrys; i++)
		if (contador[i] > maior)
			maior = contador[i];
	return maior;

}				
