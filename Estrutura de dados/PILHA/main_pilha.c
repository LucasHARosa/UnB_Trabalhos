#include "pilha.h"
	 
	
	

int main(){
	PILHA **pilha;
	int op,criado,resultado;
	DATA aux;
	
	
	
	printf("A pilha ja é criada inicialmente\n");
	pilha = criarPILHA();
	criado = 1;
	do
    {          
        printf("\n\t\tMenu interativo\n\n");
        printf("(1) Criar e Inicializar PILHA\n");
        printf("(2) Inserir elemento na PILHA\n");
        printf("(3) desimpilha\n");
        printf("(4) Zerar LADAE\n");
        printf("(0) SAIR\n");
        printf("Digite sua opcao: ");
        scanf("%d",&op);
        
        if(op == 1){
			if(criado == 0){
				pilha = criarPILHA();
				printf("PIlha criada\n");
				criado = 1;
			}
			else{
				printf("Pilha ja criada\n");
			}
		}
		if(op == 2){
			if(criado == 1){
				printf("Digite um elemento: ");
				scanf("%d",&aux.num);
				resultado = emPILHA(pilha, aux);
				if(resultado == 1){
					imprimePILHA(pilha);
				}
				else{
					printf("Nâo foi possivel colocar elemento na pilha\n\n");
				}
			}
			else{
				printf("Pilha não inicializada, por favor aperte 1\n\n");
			}
		}
		if(op == 3){
			if(criado == 1){
				resultado = desemPILHA(pilha);
				if(resultado == 1){
					imprimePILHA(pilha);
				}
				else{
					printf("Nâo tem elemento a ser tirado\n\n");
				}
			}
			else{
				printf("Pilha não inicializada, por favor aperte 1\n\n");
			}
		}
		if(op== 4){
			if(criado == 1){
				liberaPILHA(pilha);
				criado = 0;
			}
			else{
				printf("PILHA não existe mais");
			}
		}	
	}while(op != 0);
	if(criado == 1){
		liberaPILHA(pilha);
		criado =0;
	}
	printf("encerrando operaçoes..\n");
	return 0;
}
		
				
				
				
				
				
				
				
				
				
				
            
