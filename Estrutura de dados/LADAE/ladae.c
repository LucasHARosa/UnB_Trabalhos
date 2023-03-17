#include"ladae.h"

LADAE** criaLADAE()
{
	
    LADAE **novo;
    novo = (LADAE **) malloc(sizeof(LADAE **));
	*novo = NULL;
    return novo;
    
}

int ehVaziaLADAE(LADAE **inicio)
{
    if(*inicio == NULL){
        return 1;
	}
    return 0;
}

int insereInicioLADAE(LADAE **inicio, Data novo)
{
    LADAE *novono;
    
    novono = (LADAE *) malloc(sizeof(LADAE*));
    
    if(novono == NULL)
        return 0;
    
    novono->prox = NULL;
    novono->elem = novo;
    
    if(ehVaziaLADAE(inicio))
    {
        *inicio = novono;
    }
    else
    {
        novono->prox = *inicio;
        *inicio = novono;
    }
    return 1;
}

void imprimeLADAE(LADAE **inicio)
{
    LADAE *aux;
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
            printf("%d => ",(aux->elem).info);
            aux = aux->prox;
        }
    }
    printf("\n\n\n");
}

void liberaLADAE(LADAE **inicio)
{
	if(inicio != NULL){
		LADAE *aux,*liberar;
		aux = *inicio;    
    
		while(aux!=NULL)
		{
			liberar = aux;
			aux=aux->prox;
			free(liberar);
			liberar = NULL;
		}
		
		free(inicio);
		inicio = NULL;
	}
}

int buscaLADAE(LADAE **inicio,int elemento){
	int i=0;
	LADAE *aux;
	aux = *inicio;
	if(aux == NULL){
		return -1;
	}
	else{
		while(aux != NULL){
			if((aux->elem).info == elemento){
				return i;
				aux = NULL;
			}
			aux = aux->prox;
			i++;
		}
		return -1;
	}
}

int insereFimLADAE(LADAE **inicio, Data novo){ 
	LADAE *novono;
    LADAE *aux;
    LADAE *auxant;
    
    novono = (LADAE *) malloc(sizeof(LADAE));
    
    if(novono == NULL){
        return 0;
	}
    novono->elem = novo;
    novono->prox = NULL;    
    aux = *inicio;
    if(ehVaziaLADAE(inicio))
    {
        *inicio = novono;
        return 1;
    }
    else{
		while(aux != NULL){
			auxant = aux; 
			aux = aux->prox;
		}  			
		auxant->prox = novono;
		return 1;
	}
}

int removeInicio(LADAE **inicio){
	
	if(ehVaziaLADAE(inicio)){
		return 0;
	}
	LADAE *aux;
	aux = *inicio;
	(*inicio) = (*inicio)->prox;
	free(aux);
	return 1;
}
int removeFim(LADAE **inicio){
	if(ehVaziaLADAE(inicio)){
		return 0;
	}
	LADAE *aux;
	LADAE *auxant;
	aux = *inicio;
	while(aux->prox != NULL){
		auxant = aux;
		aux = aux->prox;
    }
    free(aux);
    auxant->prox = NULL;
    return 1;
}  			
	
int existeLADAE(LADAE **inicio){
	if(inicio == NULL){
		return 1;
	}
	return 0;
}
			
	
	
	
	
	
	
	
	
	
	
	
	

