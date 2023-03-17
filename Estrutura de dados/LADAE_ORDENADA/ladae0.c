#include "ladae0.h"

LADAE0** criarLADAE0(){
	LADAE0 **novo;
	novo = (LADAE0**) malloc (sizeof(LADAE0**));
	if(novo == NULL){
		return NULL;
	}
	*novo = NULL;
	return novo;
}

int ehvaziaLADAE0(LADAE0 **inicio){
	if(*inicio == NULL){
		return 1;
	}
	return 0;
}
void imprimeLADAE0(LADAE0 **inicio)
{
    LADAE0 *aux;
    aux = *inicio;
    
    printf("\n\n\t\t\tImprime lista\n");
    
    
    if(aux == NULL)
    {
        printf("Lista vazia\n");
    }
    else
    {
        while(aux != NULL)
        {
            printf("%d => ",(aux->elem).num);
            aux = aux->prox;
        }
    }
    printf("\n\n\n");
}

int buscaLADAE0(LADAE0 **inicio,int elemento){
	int i=0;
	LADAE0 *aux;
	aux = *inicio;
	if(aux == NULL){
		return -1;
	}
	else{
		while(aux != NULL){
			if((aux->elem).num == elemento){
				return i;
				aux = NULL;
			}
			aux = aux->prox;
			i++;
		}
		return -1;
	}
}

int insereLADAE0(LADAE0 **inicio, DATA novo ){
	
	LADAE0 *aux,*auxant,*novono;
	int i=1;
	
	novono = (LADAE0*) malloc(sizeof(LADAE0*));
	novono->elem = novo;
	novono->prox = NULL;
	
	aux = *inicio;
	auxant = *inicio;
	
	if(ehvaziaLADAE0(inicio)){
		*inicio = novono;
		return 1;
	}
	else{
		if((novono->elem).num <= (aux->elem).num){
			novono->prox = aux;
			*inicio = novono;
			return 1;
		}
		if(aux->prox == NULL){
			aux->prox = novono;
			return 1;
		}
		aux = aux->prox;
		while(i != 0){
			if((novono->elem).num <= (aux->elem).num){
				novono->prox = aux;
				auxant->prox = novono;
				i = 0;
				return 1;
			}
			if(aux->prox == NULL){
				aux->prox = novono;
				i = 0;
				return 1;
			}
			else{
				aux = aux->prox;
				auxant = aux;
			}
		}
	}
	return 0;
}
int retiraLADAE0(LADAE0**inicio, int elemento){
	LADAE0 *aux,*aux2;
	aux = *inicio;
	aux2 = *inicio;
	if(aux == NULL){
		return 0;
	}
	if((aux->elem).num == elemento){
		*inicio = aux->prox;
		free(aux);
		return 1;
	}
	else{
		aux = aux->prox;
		while(aux != NULL){
			if((aux->elem).num == elemento){
				aux2 = aux->prox;
				free(aux);
				aux = NULL;
				return 1;
			}
				aux = aux->prox;
				aux2 = aux2->prox;
		}
	}
	return 0;
}
	
void liberaLADAE0(LADAE0 **inicio)
{
		LADAE0 *aux,*liberar;
		aux = *inicio;    
    
		while(aux!=NULL)
		{
			liberar = aux;
			aux=aux->prox;
			free(liberar);
		}
		free(inicio);
		inicio = NULL;
	
}
