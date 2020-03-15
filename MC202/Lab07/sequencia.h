/* Estruturas exportadas */

typedef struct sequencia sequencia;

/* Funcoes exportadas */

void removefirst(sequencia* seq); 
 
/* Remove o inteiro no início da seqüência. Se a seqüência estiver vazia, não faz nada.*/

void printfirst(sequencia* seq);

/* Imprime o inteiro no início da seqüência. Se a seqüência estiver vazia, não faz nada.*/

void insertlast(int n, sequencia* seq); 

/* Insere um inteiro no fim da seqüência.*/

void removelast(sequencia* seq);

/* Remove o inteiro no fim da seqüência. Se a seqüência estiver vazia, não faz nada.*/

void printlast(sequencia* seq);

/* Imprime o inteiro no fim da seqüência. Se a seqüência estiver vazia, não faz nada.*/

void isempty(sequencia* seq);
/* Imprime "yes" se a seqüência estiver vazia e "no" se não estiver. */



/* Termina o programa.*/

void teste(sequencia* seq);

void insertfirst(int n, sequencia* seq);

sequencia* seq_cria (void);
