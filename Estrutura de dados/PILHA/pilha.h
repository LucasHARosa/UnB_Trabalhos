#include <stdio.h>
#include <stdlib.h>

struct dados{
	int num;
};
typedef struct dados DATA;

struct node{
	DATA elem;
	struct node *prox;
};
typedef struct node PILHA;

PILHA** criarPILHA();
int ehvaziaPILHA(PILHA **inicio);
int existePILHA(PILHA **inicio);
int emPILHA(PILHA **topo, DATA elemento);
int desemPILHA(PILHA **topo);
void liberaPILHA(PILHA**topo);
void imprimePILHA(PILHA **topo1);
