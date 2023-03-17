/* Lucas Henrique Alves Rosa (180042572)
  * Diciplina : APC
  * Trabalho : Trabalho 3, Mercado */


#include <stdio.h>
#include <stdlib.h>
	

int main(){
	/*Registro que lê todos os produtos*/
	struct produto{
	       char codigo [14];
	       char nome [18];
	       double preco;
	       char medida [8];
    }nProdutos[100];
    
    /*variaveis entrada*/
    char codbarras[14]; 
    char nomeOperador[25];
    double quantidadef;
	int quantidadei;
	
	FILE *pBin;
	FILE *pNota;
	
	double total;
	double valorTotal;
	int valorValido = 0;
	
	/*variaveis auxiliares*/
	int aux2,aux3,aux1 = 0;
	int aux5 = 1;
	int aux4 = 1000;
	int i=0;
	int j=0;
	
	/*Teste se o arquivo .bin pode ser aberto*/
	pBin = fopen("market_database.bin","rb");
	if(pBin == NULL){
		printf("O arquivo não pode ser aberto\n");
		return 0;
	}	
	/*Criando um arquivo nota fiscal tipo .txt*/
	pNota = fopen("nota_fiscal.txt","w");
	if(pNota == NULL){
		printf("O arquivo da nota fiscal não pode ser criado\n");
		return 0;
	}	
	
	/*Copiando os códigos para os registros*/
	while(aux1 <= 100){
		 fread(&nProdutos[aux1],sizeof(struct produto),1,pBin);	
		 ++aux1;
	}
	printf("\33[H\33[2J");
	printf("Bem Vindo...\n");
	printf("Informe o nome do operador de caixa:");
	scanf("%s",nomeOperador);
	/*escreve no arquivo um cabeçalho*/
	fprintf(pNota,"          MERCADOS APC\n");
	fprintf(pNota,"          Caixa: %s\n\n\n",nomeOperador);
	fprintf(pNota,"Id        Codigo produto  Nome produto\n");
    fprintf(pNota,"          Qtd  Tipo       Valor unit.      Valor total\n");
    fprintf(pNota,"========================================================\n");
    getchar();
    do{
        do{
		    printf("\nDigite o codigo do produto...\n");
	        printf("Se nao houver mais produtos digite '0' e aperte ENTER\n");
	        for(i = 0; i < 14;i++){
		         codbarras[i] = getchar();
		         if(codbarras[i] == '\n'){
					 break;
				 } 
	        }
	        /*condição para fechar o progama, em que o valor de 'zero'
	         *é definido para uma variável, e essa condição sai de todos
	         *os laços*/ 
	        if(codbarras[0] == '0' && codbarras[1] == '\n'){
		        printf("Compras realizadas com sucesso\n");
		        i = 0;
		        break;
	        }
	        /*se a quantidade de caracteres for diferente da estabelecida
	         *pede outro vez o codigo*/
	        else if(i != 13){
				  printf("\33[H\33[2J");
		          printf("Voce digitou um codigo invalido, por favor digite outra vez\n\n");
		          i = 0;
	        }
	       /* checagem para descobrir onde está o valor do código nas estruturas*/
			for(aux2 = 0; aux2 < 100;aux2++){
		         aux3 = 0;
		         for(j=0;j<13;j++){
			          if(nProdutos[aux2].codigo[j] == codbarras[j]){
				          aux3++;
			          }
			          if(aux3 > 11){
				          aux4 = aux2;
			          }
		         }
	         }
	         /* essa variavel tem um valor pré-estabelecido diferente dos possiveis.
	          * obs: podia ser qualquer outro valor diferente do intervalo*/
	         if(aux4 == 1000){ 
				 printf("\33[H\33[2J");
			     printf("Voce digitou um codigo invalido, tente de novo\n\n");
			   	 i = 0;
			 }				
	     }while(i == 0);
	       if(i!=0){
			 /*escreve no arquivo as informações do produto*/
	         fprintf(pNota,"%.3d       %s   %s\n",aux5,nProdutos[aux4].codigo,nProdutos[aux4].nome);
	         ++aux5;
		   }
	     /*laço de repetição para as quantidades dos produtos*/
	     do{
			 valorTotal = 0;
		     valorValido = 0;
		     if(i==0){
			    break;
		     }
		     
		      /* verifica se o produto é em unidade e faz as devidas checagens*/
		     if(nProdutos[aux4].medida[0] == 'u'){
				 do{
					 printf("Digite a quantidade de %s em UNIDADES:",nProdutos[aux4].nome);
					 valorValido = scanf("%d",&quantidadei);
					 if(valorValido == 1){
					     if(quantidadei < 1){
						     valorValido = 0;
					     }
					 }
					 if(valorValido == 0){
						 printf("Valor incorreto, tente novamente:\n");
					 }
				 }while(valorValido == 0);
				  /*variavel para o valor total de cada produto*/
				 valorTotal = quantidadei* nProdutos[aux4].preco;
				 /*escreve no arquivo as informações do produto*/
				 fprintf(pNota,"          %d.000 un x      R$ %.2lf         R$ %.2lf\n",quantidadei,nProdutos[aux4].preco,valorTotal);
			 }
			 
			 /* verifica se o produto é em kg e faz as devidas checagens*/
			 if(nProdutos[aux4].medida[0] == 'k'){
				  do{
                     printf("Digite a quantidade de %s em Kg:",nProdutos[aux4].nome);	
                     valorValido = scanf("%lf",&quantidadef);
					 if(valorValido == 1){
					     if(quantidadef < 0){
						     valorValido = 0;
					     }
					 }
					 if(valorValido == 0){
						 printf("Valor incorreto, tente novamente:\n");
					 }
				 }while(valorValido == 0);
				  /*variavel para o valor total de cada produto*/
				 valorTotal = quantidadef * nProdutos[aux4].preco;
				 /*escreve no arquivo as informações do pruduto*/
				 fprintf(pNota,"          %.3lf kg x     R$ %.2lf         R$ %.2lf\n",quantidadef,nProdutos[aux4].preco,valorTotal);
			 }
			 
			  /* verifica se o produto é em litros e faz as devidas checagens*/
			 if(nProdutos[aux4].medida[0] == 'l'){
				  do{
                     printf("Digite a quantidade de %s em LITROS:",nProdutos[aux4].nome);
					 valorValido = scanf("%lf",&quantidadef);
					 if(valorValido == 1){
					     if(quantidadef < 0){
						     valorValido = 0;
					     }
					 }
					 if(valorValido == 0){
						 printf("Valor incorreto, tente novamente:\n");
					 }
				 }while(valorValido == 0);
				 /*variavel para o valor total de cada produto*/
				 valorTotal = quantidadef * nProdutos[aux4].preco;
				 /*escreve no arquivo as informações do produto*/
				 fprintf(pNota,"          %.3lf L  x      R$ %.2lf        n R$ %.2lf\n",quantidadef,nProdutos[aux4].preco,valorTotal);
			 }  
			 getchar();
			 
		 }while(valorValido == 0);
		 /*variavel que soma todos os valores totais de cada produto*/
		 total += valorTotal;
		 if(i == 0){
			 break;
		 }
		 printf("Compra efetuada!\nProximo produto...\n");
    /* novamente um valor aleatório somente para o ciclo não fechar*/
	}while(aux4 != 102);
		
     /*escreve no arquivo as informações finais*/
    fprintf(pNota,"========================================================\n");
	fprintf(pNota,"       TOTAL    R$  %.2lf",total);		    
	
	/*fecha os dois aequivos abertos*/
	fclose(pBin);
	fclose(pNota);
	
	return 0;
}
