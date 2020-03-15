#include <stdio.h>
#include <stdlib.h>
#include "grafos.h"

int main(void) {

int n;
graph rede;
rede = c_grafo();
scanf("%d", &n);
b_largura(rede, n);
return 0;

}
