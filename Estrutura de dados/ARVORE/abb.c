#include"abb.h"
/*Lucas Henrique Alves Rosa
 * 180042572
 * TAD ARVORE*/ 
ABB** criaInicializa_ABB()
{
    ABB **nova;
    /* cria o endereco para armazenar o nodo raiz */
    nova = (ABB **) malloc(sizeof(ABB *));
    if(nova != NULL)
    {
        /* Inicializa a ABB, coloca na condicao de vazia */
        *nova = NULL;
    }
    return nova;
}

int existe_ABB(ABB **arv)
{
    if(arv == NULL)
    {
        return 0;
    }
    return 1;
}
int existeNo (ABB *node){
    if(node == NULL)
        return 0;
    return 1;
}

int ehVazia_ABB(ABB **arv)
{
    if(existe_ABB(arv) == 0)
        return -1;  /* se a ABB nao existir ... */
    if(*arv == NULL)
        return 1; /* o endereco do nodo raiz nao existe */
    return 0; /* ok, existe um nodo raiz, arv nao eh vazia */
}
/* funcao que registra a visita a um nodo da ABB 
   funcao aqui esta bem simples... */
void visita_Node(ABB *nodo)
{
    printf("%d ",nodo->info.valor);
}

void caminhaInOrdem_ABB(ABB *nodo)
{
    /* verifico se o nodo existe*/
    if(nodo == NULL)
        return ;
    
    caminhaInOrdem_ABB(nodo->esq);
    visita_Node(nodo);
    caminhaInOrdem_ABB(nodo->dir);
}
void caminhaPreOrdem_ABB(ABB *nodo){
	if(nodo == NULL){
		return ;
	}
	visita_Node(nodo);
	caminhaPreOrdem_ABB(nodo->esq);
	caminhaPreOrdem_ABB(nodo->dir);
}

void caminhaPosOrdem_ABB(ABB *nodo){
	if(nodo == NULL){
		return ;
	}
	caminhaPosOrdem_ABB(nodo->esq);
	caminhaPosOrdem_ABB(nodo->dir);
	visita_Node(nodo);
}

void caminhaProfund_ABB(ABB **arv, int opcao)
{
    if(ehVazia_ABB(arv) == 0)
    {
        /* fazer os outros tipos de caminho em profundidade ... */
        /* caminha em profundidade na ABB - InOrdem*/
        if(opcao == 2){
            caminhaInOrdem_ABB(*arv);
        }
        if(opcao == 1){
			caminhaPreOrdem_ABB(*arv);
		}
		if(opcao == 3){
			caminhaPosOrdem_ABB(*arv);
		}
    }
}

/* caminha na arvore em profundidade, mas encontrando a posicao do novo nodo
 na ABB respeitando a propriedade de uma arvore binaria de busca*/
int insereCaminha_ABB(ABB *nodo, Data novo){
    ABB *novo_node;
    
    if(novo.valor < nodo->info.valor)
    {
        /* insercao do novo nodo ocorrera na sub-arvore esquerda em relacao ao nodo atual */
        
        /* se nao existe filho esquerdo em relacao ao nodo atual
         encontramos a posicao para inserir o novo nodo*/
        if(nodo->esq == NULL)
        {
            novo_node = (ABB *) malloc(sizeof(ABB));
            if(novo_node != NULL)
            {
                novo_node->info = novo;
                novo_node->pai = nodo;
                novo_node->esq = NULL;
                novo_node->dir = NULL;
                nodo->esq = novo_node;
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            /* caminha na sub-arvore esquerda da ABB ate
             encontrar o local correto para inserir novo nodo*/
            return insereCaminha_ABB(nodo->esq,novo);
        }
    }
    else
    {
        /* insercao do novo elem ocorrera na sub-arvore direita 
         do nodo atual*/
        if(novo.valor > nodo->info.valor)
        {
            if(nodo->dir == NULL)
            {
                novo_node = (ABB *) malloc(sizeof(ABB));
                if(novo_node != NULL)
                {
                    novo_node->info = novo;
                    novo_node->esq = NULL;
                    novo_node->dir = NULL;
                    novo_node->pai = nodo;
                    nodo->dir = novo_node;
                    return 1; /* sucesso na operacao */
                }
                else
                {
                    return 0;
                }
            }
            else
            {
                return insereCaminha_ABB(nodo->dir,novo);
            }
        }
    }
}

/* funcao que insere um novo elemento na ABB - adicao como um nodo folha*/
int insere_ABB(ABB **arv, Data novo){
    ABB *novo_node;
    
    /* se a arvore eh vazia, aloca novo no e atribui como novo
     noh raiz*/
    if(ehVazia_ABB(arv) == 1)
    {
        novo_node = (ABB *) malloc(sizeof(ABB));
        if(novo_node != NULL)
        {
            novo_node->info = novo;
            novo_node->pai = NULL;
            novo_node->esq = NULL;
            novo_node->dir = NULL;
            /* novo nodo alocado eh o nodo raiz da ABB */
            *arv = novo_node; 
            return 1;
        }
        else
        {
            /* Falhou a alocacao do no */
            return 0;
        } 
    }
    else
    {
        /* se jah existir um nodo raiz, deve-se caminhar na ABB ate
         encontrar a posicao de noh folha para insercao */
        return insereCaminha_ABB(*arv,novo);
    }
}
int procuraAfundo_ABB (ABB *nodo, Data elemento){
    int resultado = 0;
    if(existeNo(nodo) == 0){
        return resultado;
    }
    
    if(nodo->info.valor == elemento.valor){
        resultado = 1;
        return resultado;
    }
    if(nodo->info.valor < elemento.valor){
        resultado = procuraAfundo_ABB(nodo->dir,elemento);
        if(resultado != 0){
            return resultado;
        }
        
    }
    if(nodo->info.valor > elemento.valor){
        resultado = procuraAfundo_ABB(nodo->esq,elemento);
        if(resultado != 0){
            return resultado;
        }
    }
    
}
int procura_ABB (ABB **arv, Data info){
    ABB *nodo = *arv;
    if(procuraAfundo_ABB(nodo,info) != 0){
        return 1;
    }
    return 0;
}


void libera_ABB (ABB *nodo){
    if(existeNo(nodo) == 0){
        return ;
    }
    libera_ABB(nodo->esq);
    libera_ABB(nodo->dir);
    free(nodo);
}

void liberaProf_ABB (ABB **arv){
    if(ehVazia_ABB(arv) == -1){
        return ;
    }
    if(ehVazia_ABB(arv) == 1){
        free (arv);
        return ;
    }
    else{
        libera_ABB(*arv);
        free(arv);
    }
}
ABB* procuraEndAfundo_ABB (ABB *nodo, Data elemento){
    ABB* resultado;
    if(nodo == NULL){
        return NULL;
    }
    
    if(nodo->info.valor == elemento.valor){
        printf("%p\n",nodo);
        return nodo;
    }
    else if(nodo->info.valor < elemento.valor){
        resultado = procuraEndAfundo_ABB(nodo->dir,elemento);
        if(resultado != NULL){
            return resultado;
        }
        
    }
    else if(nodo->info.valor > elemento.valor){
        resultado = procuraEndAfundo_ABB(nodo->esq,elemento);
        if(resultado != NULL){
            return resultado;
        }
    }
    return NULL;
    
}
ABB* procuraEnd_ABB(ABB **arv, Data info){
    ABB* end = *arv;
    return procuraEndAfundo_ABB(end,info);
}

ABB* cade(ABB* wanted){
    ABB*pai = wanted->pai;
    if(wanted->esq == NULL && wanted->dir == NULL){
        if(pai->esq == wanted){
            pai->esq = NULL;
        }
        if(pai->dir == wanted){
            pai->dir = NULL;
        }
        return wanted;
    }
    else{
        if(wanted->esq != NULL && wanted->dir == NULL){
            if(pai->dir == wanted){
                pai->dir = wanted->esq;
                return wanted;
            }
            if(pai->esq == wanted){
                pai->esq = wanted->esq;
                return wanted;
            }
            else{
                return cade(wanted->dir);
            }
        }
    }
}	 

void remover (ABB** arv,Data elemento1){
    ABB* atual;
    ABB* pai;
    ABB* nodo;
    atual = procuraEnd_ABB(arv,elemento1);
    printf("%p\n",atual);
    printf("chegou aqui\n");
    printf("chegou aqui3\n");
    if(atual != NULL){
        if(atual->pai == NULL){
            pai = NULL;
        }
        else{
            pai = atual->pai;
        }
        if(atual->esq == NULL && atual->dir == NULL){
            if(pai == NULL){
                *arv = NULL;
                atual = NULL;
                free (atual);
                return ;
            }
            if(pai->esq == atual){
                pai->esq = NULL;
                atual = NULL;
                free(atual);
                return ;
            }
            if(pai->dir == atual){
                pai->dir = NULL;
                atual = NULL;
                free(atual);
                return ;
            }
        }
        else{
            if(atual->dir == NULL){  
                if(pai == NULL){
                    *arv = atual->esq;
                    atual = NULL;
                    free (atual);
                    return ;
                }
                if(pai->esq == atual){
                    pai->esq = atual->esq;
                    free(atual);
                    return ;
                }
                if(pai->dir == atual){
                    pai->dir = atual->esq;
                    free(atual);
                    return ;
                }  
            }
            if(atual->esq == NULL){
                if(pai == NULL){
                    *arv = atual->dir;
                    atual = NULL;
                    free (atual);
                    return ;
                }
                if(pai->esq == atual){
                    pai->esq = atual->dir;
                    free(atual);
                    return ;
                }
                if(pai->dir == atual){
                    pai->dir = atual->dir;
                    free(atual);
                    return ;
                }    
            }
            else{
                nodo = cade(atual->esq);
                if(pai == NULL){
                    *arv = nodo;
                    nodo->esq = atual->esq;
                    nodo->dir = atual->dir;
                    nodo->pai = atual->pai;
                    free (atual);
                    return ;
                }
                if(pai->esq == atual){
                    pai->esq = nodo;
                    nodo->esq = atual->esq;
                    nodo->dir = atual->dir;
                    nodo->pai = atual->pai;
                    free (atual);
                    return ;
                }
                if(pai->dir == atual){
                    pai->dir = nodo;
                    nodo->esq = atual->esq;
                    nodo->dir = atual->dir;
                    nodo->pai = atual->pai;
                    free (atual);
                    return ;
                }
            }
        }
    }
    else{
        printf("Elemento nao encontrado\n");
    }
    free(atual);
}		







