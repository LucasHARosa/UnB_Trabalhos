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
typedef struct node LADAE0;

LADAE0** criarLADAE0();
int ehvaziaLADAE0(LADAE0 **inicio);
void imprimeLADAE0(LADAE0 **inicio);
int buscaLADAE0(LADAE0 **inicio,int elemento);
int insereLADAE0(LADAE0 **inicio, DATA novo );
void liberaLADAE0(LADAE0 **inicio);
int retiraLADAE0(LADAE0**inicio, int elemento);
