/*Tarefa LAEAS (Lista de alocação estática de acesso sequencial do tipo inteiro)
 * Aluno: Lucas Henrique Alves Rosa 
 * Mtr: 180042572
 * Data: 30/04/2018*/
 
 #include "laeas.h"
 
int main(){
	LAEAS *lista;
	LAEAS listinha;
	lista = &listinha;
	int opcao;
	int aux;
	int fechar=1;
	do{
		printf("\n\n\n");
		printf("============== MENU =============\n");
		printf("(0) para fechar\n");
		printf("(1) para criar lista\n");
		printf("(2) verificar se eh cheia\n");
		printf("(3) verificar se eh vazia\n");
		printf("(4) imprimir lista\n");
		printf("(5) inserir elemento inicio\n");
		printf("(6) inserir elemento final\n");
		printf("(7) remover elemento inicio\n");
		printf("(8) remover elemento final\n");
		printf("(9) limpar Laeas\n");
		scanf("%d",&opcao);
		switch (opcao){
			case 0:
			fechar = 0;
			break;
			
			case 1:
			criarLaeas (lista);
			break;
			
			case 2:
			aux = Laeasehcheia (lista);
			if(aux == 0){
				printf("LAEAS nao está cheia\n");
			}
			else{
				printf("LAEAS está cheia\n");
			}
			break;
			
			case 3:
			aux = Laeasehvazia (lista);
			if(aux == 0){
				printf("LAEAS nao está vazia\n");
			}
			else{
				printf("LAEAS está vazia\n");
			}
			break;
			
			case 4:
			imprimirLaeas (lista);
			break;
			
			case 5:
			inserirInicioLaeas (lista);
			break;
			
			case 6:
			insereFimLaeas (lista);
			break;
			
			case 7:
			removeInicioLaeas (lista);
			break;
			
			case 8:
			removeFimLaeas (lista);
			break;
			
			case 9:
			limparLaeas(lista);
			break;
		}
	}while(fechar == 1);
			
	
	return 0;
}
