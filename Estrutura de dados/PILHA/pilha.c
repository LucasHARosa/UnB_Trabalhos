#include "pilha.h"

PILHA** criarPILHA(){
	PILHA **novo;
	novo = (PILHA**) malloc (sizeof(PILHA*));
	if(novo == NULL){
		return NULL;
	}
	*novo = NULL;
	return novo;
}

int ehvaziaPILHA(PILHA **inicio){
	if(*inicio == NULL){
		return 1;
	}
	return 0;
}

int existePILHA(PILHA **inicio){
	if(inicio == NULL){
		return 0;
	}
	else{
		return 1;
	}
}
int emPILHA(PILHA **topo, DATA elemento){
	PILHA *aux,*novono;
	
	novono = (PILHA*) malloc(sizeof(PILHA));
	novono->elem = elemento;
	
	aux = *topo;
	
	if(ehvaziaPILHA(topo)){
		*topo = novono;
		novono->prox = NULL;
		return 1;
	}
	else{
		*topo = novono;
		novono->prox = aux;	
		return 1;
	}
	return 0;
}

int desemPILHA(PILHA **topo){
	PILHA *aux;
	aux = *topo;
	if(ehvaziaPILHA(topo)){
		return 0;
	}
	*topo = aux->prox;
	free(aux);
	return 1;
}
void liberaPILHA(PILHA**topo){
	while(ehvaziaPILHA(topo) == 0){
		desemPILHA(topo);
	}
	free(topo);	
}
	
	
void imprimePILHA(PILHA **topo1){
	PILHA **topo2;
	topo2 = (PILHA**) malloc (sizeof(PILHA*));
	*topo2 = NULL;
	PILHA *aux2 = *topo2;
	PILHA *aux1 = *topo1;
	while(*topo1 != NULL){
		emPILHA(topo2,aux1->elem);
		desemPILHA(topo1);
		aux2 = *topo2;
		printf("|| %d ||\n",(aux2->elem).num);
		aux1 = *topo1;
	}
	while(*topo2 != NULL){
		emPILHA(topo1,aux2->elem);
		desemPILHA(topo2);
		aux1 = *topo1;
		aux2 = *topo2;
	}
	free(topo2);
	printf("\n\n\n\n");
}
