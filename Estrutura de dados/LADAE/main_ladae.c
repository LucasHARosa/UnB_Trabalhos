/* Tarefa LADAE
 * Aluno: Lucas Henrique Alves Rosa
 * Mtr: 180042572   */


#include"ladae.h"
#define SUCESSO 1
#define FALHA 0

int main()
{
    LADAE **lista;
    Data aux;
    int r;
    
    int elem,op=-1;
    printf("O progama ja se inicia criando uma LADAE\n");
    lista = criaLADAE();
    do
    {          
        printf("\n\t\tMenu interativo\n\n");
        printf("(1) Criar e Inicializar LADAE\n");
        printf("(2) Inserir elemento no inicio\n");
        printf("(3) Inserir elemento no final\n");
        printf("(4) Remover elemento no inicio\n");
        printf("(5) Remover elemento no final\n");
        printf("(6) Buscar um elemento na LADAE\n");
        printf("(7) Zerar LADAE\n");
        printf("(0) SAIR\n");
        printf("Digite sua opcao: ");
        scanf("%d",&op);
        
        if(op == 1)
        {
			if(existeLADAE(lista)== 0){
				lista = criaLADAE();
				printf("Endereço do primeiro no da lista: %p\n",*lista);
				printf("Endereço da lista: %p\n",lista);
				printf("Lista LADAE inicializada com sucesso\n");
			}
			
        }
        if(op == 2)
        {
            printf("Digite um elemento: ");
            scanf("%d",&aux.info);
            
            if(insereInicioLADAE(lista,aux) == SUCESSO)
            {
                printf("Elemento inserido %d com sucesso\n",aux.info);
            }
            
            imprimeLADAE(lista);
            printf("\n\n");
        }
        if(op == 6){
			printf("Digite o elemento que voce quer buscar :");
			scanf("%d",&elem);
			r=buscaLADAE(lista,elem);
			if(r== -1){
				printf("Elemento nao esta na lista\n");
			}
			else{
				printf("esse eh o indice do elemento : %d",r);
			}
		}
		if(op==3){
			printf("Digite um elemento: ");
            scanf("%d",&aux.info);
            
            if(insereFimLADAE(lista,aux) == SUCESSO)
            {
                printf("Elemento inserido %d com sucesso\n",aux.info);
            }
            
            imprimeLADAE(lista);
            printf("\n\n");
        }
        if(op==4){
			if(removeInicio(lista) == SUCESSO)
            {
                printf("Elemento removido com sucesso\n");
            }
            printf("\n\n\t\t\tImprime lista\n");
            imprimeLADAE(lista);
            printf("\n\n");
        }
        if(op==5){
			if(removeFim(lista) == SUCESSO)
            {
                printf("Elemento removido com sucesso\n");
            }
            printf("\n\n\t\t\tImprime lista\n");
            imprimeLADAE(lista);
            printf("\n\n");
        }
		if(op==7){
			liberaLADAE(lista);
		}	
        
    }while(op != 0);
    
    printf("Encerrando as operações...\n");
    
    liberaLADAE(lista);
    
    return 0;
}
