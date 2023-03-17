#include "fila.h"
	
	
	
	
	
int main(){
	FILA **fila;
	int op,criado,resultado;
	DATA aux;
	
	
	
	printf("A fila ja é criada inicialmente\n\n");
	fila = criarFILA();
	criado = 1;
	
	do
    {          
        printf("\n\t\tMenu interativo\n\n");
        printf("(1) Criar e Inicializar FILA\n");
        printf("(2) Inserir elemento na FILA\n");
        printf("(3) desenfilera\n");
        printf("(4) Zerar fila\n");
        printf("(0) SAIR\n");
        printf("Digite sua opcao: ");
        scanf("%d",&op);
        
        if(op == 1){
			if(criado == 0){
				fila = criarFILA();
				printf("FILA criada com SUCESSO\n\n\n");
				criado = 1;
			}
			else{
				printf("FILA ja criada\n\n\n");
			}
		}
		if(op == 2){
			if(criado == 1){
				printf("Digite um elemento: ");
				scanf("%d",&aux.num);
				resultado = emFILera(fila, aux);
				if(resultado == 1){
					imprimeFILA(fila);
				}
				else{
					printf("Nao foi possivel adicionar o elemento\n\n");
				}
			}
			else{
				printf("A fila nao existe, crie apertando 1\n\n");
			}
		}
		if(op == 3){
			if(criado == 1){	
				resultado = desemFILera(fila);
				if(resultado == 1){
					imprimeFILA(fila);
				}
				else{
					printf("A fila está vazia\n\n\n");
				}
			}
			else{
				printf("A fila nao existe, crie apertando 1\n\n");
			}
		}
		if(op== 4){
			if(criado == 1){
				liberaFILA(fila);
				criado = 0;
			}
		}
		
		
	}while(op != 0);
	if(criado == 1){
		liberaFILA(fila);
		criado = 0;
	}
	printf("encerrando operaçoes...\n");
	return 0;
}	
	
	
	
	
	
	
	
	
