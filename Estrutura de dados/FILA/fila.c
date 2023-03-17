#include "fila.h"

FILA** criarFILA(){
	FILA **novo;
	novo = (FILA**) malloc (sizeof(FILA*));
	if(novo == NULL){
		return NULL;
	}
	*novo = NULL;
	return novo;
}
int ehvaziaFILA(FILA **inicio){
	if(*inicio == NULL){
		return 1;
	}
	return 0;
}

int emFILera(FILA **inicio,DATA elemento){
	FILA *novo;
	FILA *aux;
	aux = *inicio;
	
	novo = (FILA*) malloc(sizeof(FILA*));
	novo->elem = elemento;
	novo->prox = NULL;
	
	if(ehvaziaFILA(inicio) == 1){
		*inicio = novo;
		return 1;
	}
	else{
		while(aux->prox != NULL){
			aux = aux->prox;
		}
		aux->prox = novo;
		return 1;
	}
	return 0;
}

int desemFILera (FILA **inicio){
	FILA *aux=*inicio;
	if(ehvaziaFILA(inicio) == 1){
		return 0;
	}	
	*inicio = aux->prox;
	free(aux);
	return 1;
}

int existeFILA (FILA**inicio){
	if(inicio == NULL){
		return 0;
	}
	else{
		return 1;
	}
}
	
//desconsidere essa implementação de imprimir a FILA
void imprimeFILA(FILA **inicio){
	
	FILA *aux;
	aux = *inicio;
	if(ehvaziaFILA(inicio) == 1){
		printf("lista vazia!\n");
	}
	else{
		printf("|| %d ||\t",(aux->elem).num);
		while(aux->prox != NULL){
			aux = aux->prox;
			printf("|| %d ||\t",(aux->elem).num);
		}
		printf("\n\n\n");
	}
}
	

void liberaFILA(FILA **inicio){
	FILA *aux = *inicio;
	int op;
	if(ehvaziaFILA(inicio) == 0){
		while(aux->prox != NULL){
			op = desemFILera(inicio);
			aux = *inicio;
		}
	}
	free(inicio);
}
	
