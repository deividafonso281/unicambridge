#include <stdio.h>
#include <stdlib.h>
#include "grafos.h"
#include <string.h>

graph c_grafo(void) {

    int tamanho;
    //Tamanho do grafo
    int count = 0;
    int address;
    //indice para inserir novos elementos no vetor

    int endereco;
    int contador;
    int i;
    int j;
    scanf("%d", &tamanho);
    graph net;
    int* vetor;
    vetor = (int*) malloc(tamanho*(tamanho-1)*sizeof(int));
    for (i=0; i<tamanho*(tamanho-1);i++){
        vetor[i]=0;
    }
    // vetor auxiliar com tamanho maximo necessario
    char aresta[4];
    //entrada do teclado
    scanf("%s", aresta);
    while(strcmp(aresta,"0,0")!=0) {
    //compara a entrada e a condicao de parada
        i = aresta[0] - '0';
        j = aresta[2] - '0';
        address = (i - 1)*(tamanho - 1);
        while (vetor[address] != 0 && address < i*(tamanho-1)) {
            if (vetor[address] == j) {
                break;
            }
            address ++;
        }
        vetor[address] = j;
        //insere o segundo elemento da entrada no vetor

        address = (j - 1)*(tamanho - 1);
        while (vetor[address] != 0 && address < j*tamanho*(tamanho-1)) {
            if (vetor[address] == i) {
                break;
            }
            address ++;
        }
        vetor[address] = i;
        // insere o primeiro elemento da entrada no vetor

        scanf("%s", aresta);
        // le uma nova entrada
    }
    for(i=0; i<tamanho*(tamanho-1); i++) {
        if (vetor[i] != 0) {
            count ++;
        }
    //conta o numero de elementos nao nulos no vetor

    }
    net.vizinhos = (int*) malloc(count*sizeof(int));
    //cria um vetor definitivo com tamanho igual ao numero de elementos nao nulos

    net.indices = (int*) malloc((tamanho+1)*sizeof(int));
    // cria um vetor definitivo com os indices de inicio dos elementos adjacentes

    contador = 0;
    // contador do numero de elementos inseridos

    address = 0;
    // endereco de insercao do indice

    endereco = 0;
    // endereco de insercao do elemento
    for(i=0; i<tamanho*(tamanho-1); i++) {
        if (i % (tamanho-1) == 0) {
            net.indices[address] = contador;
            address ++;
        }
        if (vetor[i] != 0) {
            net.vizinhos[endereco] = vetor[i];
            contador ++;
            endereco ++;
        }
    }
    net.indices[tamanho] = count;
    net.vertices = (node*) malloc(tamanho*sizeof(node));
    for (i=0; i<tamanho; i++) {
        (net.vertices)[i].distance = infinite;
        (net.vertices)[i].teste = 0;
    }
    net.tamanho = tamanho;
        
    return net;      

}

void b_largura(graph grafo, int first) {

    int* fila;
    //cria fila
    int i;
    int atual = 0;
    int adiciona = 1;
    int j;
    int k;
    int l;
    fila = (int*) malloc((grafo.tamanho)*sizeof(int));
    //fila recebe tamanho igual ao numero de elementos do grafo
    // first-1 indice do elemento inicial no vetor de vertices

    (grafo.vertices[(first-1)]).distance = 0;
    (grafo.vertices[(first-1)]).teste = 1;
    // atualiza o elemento inicial no vetor de vertices

    fila[atual] = first;
    while (fila[atual]!= 0){
        k = (grafo.indices)[fila[atual]-1];
        // indice do elemento atual na fila no vetor de indices

        l = (grafo.indices)[fila[atual]];
        // indice do proximo elemento na fila no vetor de indices
  
        for (j = k; j < l; j++) {
            if ((grafo.vertices[(grafo.vizinhos[j])-1]).teste == 0) {
                (grafo.vertices[(grafo.vizinhos[j])-1]).distance = (grafo.vertices[fila[atual]-1]).distance +1;
                (grafo.vertices[(grafo.vizinhos[j])-1]).teste = 1;
                fila[adiciona] = grafo.vizinhos[j];
                adiciona++ ;
                /*for (i=0; i<grafo.tamanho;i++){
                    printf("%d ",fila[i]);
                }
                printf("\n");*/
            }
        }
        atual++;
    }
    printf("Origem da busca: %d\n", first);
    printf("Vertices alcancados e distancias:\n");
    for (i=0; i<(grafo.tamanho); i++) {
        if (fila[i] != 0) {
            printf("%d %d\n", fila[i], (grafo.vertices)[fila[i]-1].distance);
        }
    }
}