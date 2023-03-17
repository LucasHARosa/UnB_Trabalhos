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
typedef struct node FILA;

FILA** criarFILA();
	
int ehvaziaFILA(FILA **inicio);

int emFILera(FILA **inicio,DATA elemento);

int desemFILera (FILA **inicio);

int existeFILA (FILA**inicio);
	

void imprimeFILA(FILA **inicio);
	

void liberaFILA(FILA **inicio);
	
