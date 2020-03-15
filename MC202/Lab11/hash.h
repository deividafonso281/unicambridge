
/* Tamanho da tabela de hashing: 6961 */

/* Estruturas exportadas */

struct frase {
        unsigned long id;
        char cadeia[251];
        int chave;
};  
typedef struct frase string;

/* Funcoes exportadas */

int transforma(string* cc);

/* Funcao que transforma uma cadeia de caracteres em um numero e possibilita com que seja dispersa na tabela. */

int hash_i(int soma);

/* Funcao que, em posse da chave da cadeia de caracteres, lhe atribui um valor correspondente na tabela */

int hash_d(string* cc, string** tabela);

/* Funcao que, diante de uma colisao, atribui um novo valor ao indice fornecido */

string** inserir(string* cc, string** tabela, unsigned long id);

/* Funcao que, quando lida a chave "i", insere um novo valor na tabela (valores iguais sao adicionados apenas uma vez) */

int buscar(string* cc, string** tabela);

/* Funcao que busca uma cadeia de caracteres inserida na tabela, retorna a chave se encontrar e -1 se nao. */

string** remover(string* cc, string** tabela);

/* Funcao que, busca uma chave e caso a encontre, remova. */

void liberar(string** tabela);

/* Funcao que libera a tabela */
