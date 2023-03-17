#include "laeas.h"



void criarLaeas (LAEAS* lista){
	lista->fim = -1;
	printf("Lista inicializada\n");
}
int Laeasehcheia (LAEAS* lista){
	if(lista->fim == MAX-1){
		return 1;
	}
	else{
		return 0;
	}
}
int Laeasehvazia (LAEAS* lista){
	if(lista->fim == -1){
		return 1;
	}
	else{
		return 0;
	}
}
void imprimirLaeas (LAEAS* lista){
	int i;
	if(Laeasehvazia(lista) == 0){
		for(i=0;i<=(lista->fim);i++){
			printf("%d ",lista->elem[i]);
		}
	}
}
void inserirInicioLaeas (LAEAS* lista){
	int i;
	int elemento;
	if(Laeasehcheia(lista) == 1){
		printf("ERRO lista cheia\n");
	}
	if(Laeasehvazia (lista) == 1){
		printf("Digite o elemento: \n");
		scanf("%d",&elemento);
		lista->elem[0] = elemento;
		lista->fim++;
	}
	else{
		for(i=(lista->fim)+1;i>=0;i--){
			lista->elem[i]=lista->elem[i-1];
		}
		printf("Digite o elemento: \n");
		scanf("%d",&elemento);
		lista->elem[0] = elemento;
		lista->fim++;
	}
}
void insereFimLaeas (LAEAS* lista){
	int elemento;
	if(Laeasehcheia(lista) == 1){
		printf("ERRO lista cheia\n");
	}
	else{
		lista->fim++;
		printf("Digite o elemento: \n");
		scanf("%d",&elemento);
		lista->elem[lista->fim] = elemento;
	}
}
void removeInicioLaeas (LAEAS* lista){
	int i;
	if(Laeasehvazia(lista) == 1){
		printf("ERRO lista vazia \n");
	}
	else{
		for(i=0;i<lista->fim;i++){
			lista->elem[i] = lista->elem[i+1];
		}
		lista->fim--;
	}
}
void removeFimLaeas (LAEAS* lista){
	if(Laeasehvazia(lista) == 1){
		printf("ERRO lista vazia\n");
	}
	else{
		lista->elem[lista->fim] = 0;
		lista->fim--;
	}
}
void limparLaeas(LAEAS* lista){
	int i;
	for(i=0;i<=lista->fim;i++){
		lista->elem[i] = 0;
	}
	lista->fim = -1;
}
	
		
	
	
	
	
	
	
		
