#include"abb.h"
/*Lucas Henrique Alves Rosa
 * 180042572
 * TAD ARVORE*/ 

int main()
{
    ABB **arv;
    Data aux;
    int criado = 0;
    int opp;
    int aux1,resultado;
    arv = criaInicializa_ABB();
    printf("O progama ja cria a Arvore\n");
    criado = 1;
    do{
        printf("\n============ MENU INTERATIVO DO LUQUITAS ===========\n\n\n");
        printf("   Escolha a opcao desejada\n\n");
        printf("(0) sair do progama\n");
        printf("(1) Cria e inicializa a Arvore\n");
        printf("(2) Percorre a Arvore\n");
        printf("(3) Insere elemento na Arvore\n");
        printf("(4) Busca elemento na Arvore\n");
        printf("(5) Libera todos os elementos da Arvore\n");
        printf("(6) Retirar um elemento da Arvore\n");
        scanf("%d",&opp);
        printf("\n");
        if(opp == 1){
            if(criado == 0){
                arv = criaInicializa_ABB();
                criado = 1;
                printf("O progama criou a Arvore\n");
            }
            else{
                printf("Arvore ja esta criada\n");
            }
        }
        if(opp == 2){
            if(criado == 1){
                printf("Digite qual maneira deseja caminhar (1)pre (2)in (3)pos:");
                scanf("%d",&aux1);
                printf("\n");
                caminhaProfund_ABB(arv,aux1);
                printf("\n");
            }
            else{
                printf("Arvore nao inicializada por favor digite 1\n");
            }
        }
        if(opp == 3){
            if(criado == 1){
                printf("Digite o valor que deseja adicionar na arvore:");
                scanf("%d",&aux.valor);
                printf("\n");
                resultado = insere_ABB(arv,aux);
                if(resultado == 1){
                    printf("inserido com sucesso\n");
                }
                else{
                    printf("Nao inserido\n");
                }
            }
            else{
                 printf("Arvore nao inicializada por favor digite 1\n");
            }

        }
        if(opp == 4){
            if(criado == 1){
                printf("Digite o valor a ser buscado:");
                scanf("%d",&aux.valor);
                printf("\n");
                resultado = procura_ABB(arv,aux);
                if(resultado == 1){
                    printf("Elemento encontrado\n");
                }
                else{
                    printf("Elemento nao encontrado\n");
                }
            }
             else{
                 printf("Arvore nao inicializada por favor digite 1\n");
            }
        }
        if(opp == 5){
            if(criado == 1){
                liberaProf_ABB(arv);
                criado = 0;
            }
            else{
                 printf("Arvore nao existe, aperte 1 e inicialize\n");
            }
        }
        if(opp == 6){
            if(criado == 1){
                printf("Digite o elemento a ser buscado:");
                scanf("%d",&aux.valor);
                printf("\n");
                remover(arv,aux);
                printf("cheguei aqui uhuu\n");
            }
            else{
                printf("Arvore nao inicializada por favor digite 1\n");
            }
        }
    }while(opp != 0);
    printf("\nEncerrando operacoes...\n");
    if(criado == 1){
        liberaProf_ABB(arv);
        criado = 0;
    }
    
    return 0;
}
