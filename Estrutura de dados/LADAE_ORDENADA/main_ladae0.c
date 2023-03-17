/* Tarefa LADAE ORDENADA
 * Aluno: Lucas Henrique Alves Rosa
 * Mtr: 180042572   */


#include "ladae0.h"

int main(){
	LADAE0 **lista;
	DATA aux;
	int elem, op,criado,decisao;
	int indice = -1;
	
	printf("O progama ja cria a LADAE inicialmente\n");
	lista = criarLADAE0();
	criado = 1;
	do{
		printf("\n\t\tMenu interativo\n\n");
        printf("(1) Criar e Inicializar LADAEordenada\n");
        printf("(2) Inserir elemento\n");
        printf("(3) Buscar um elemento na LADAE\n");
        printf("(4) Zerar LADAE\n");
        printf("(5) remover um elemento\n");
        printf("(0) SAIR\n");
        printf("Digite sua opcao: ");
        scanf("%d",&op);

		if(op == 1){
			if(criado == 0){
				lista = criarLADAE0();
				criado = 1;
				printf("LADAE ordenada criada com sucesso\n");
			}
			else{
				printf("Lista ja criada\n");
			}
		}
		if(op == 2){
			printf("Digite o elemento: ");
			scanf("%d",&aux.num);
			
			if(insereLADAE0(lista,aux)){
				printf("elemento %d inserido", aux.num);
			}
			imprimeLADAE0(lista);
			printf("\n\n");
		}
		if(op == 3){
			printf("Digite o elemento que voce quer buscar :");
			scanf("%d",&elem);
			indice = buscaLADAE0(lista,elem);
			if(indice == -1){
				printf("Elemento nao esta na lista\n");
			}
			else{
				printf("esse eh o indice do elemento : %d\n\n",indice);
			}
		}
		if (op == 4){
			liberaLADAE0(lista);
			criado = 0;
		}
		if (op == 5){
			printf("Digite o elemento que voce quer tirar :");
			scanf("%d",&elem);
			decisao = retiraLADAE0(lista, elem);
			if(decisao == 1){
				imprimeLADAE0(lista);
				printf("\n\n");
			}
			else{
				printf("elemento n esta na LADAE\n ");
			}
		}
		
			
			
	}while(op != 0);
	printf("encerrando...\n");
	
	liberaLADAE0(lista);
	return 0;
}



