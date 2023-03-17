#include<stdio.h>
#include<stdlib.h>
/*Lucas Henrique Alves Rosa
 * 180042572
 * TAD ARVORE*/ 
struct dados {
    int valor;
};

typedef struct dados Data;

/* estrutura de um nodo da arvore */
struct node
{
    Data info;         /* campo de dados */
    struct node *esq;  /* referencia para o nodo filho esquerdo*/
    struct node *dir;  /* referencia para o nodo filho direito */
    struct node *pai;  /* referencia para o nodo papai */
};

typedef struct node ABB;

ABB** criaInicializa_ABB();

int existe_ABB(ABB **arv);

int ehVazia_ABB(ABB **arv);

void visita_Node(ABB *nodo);

void caminhaInOrdem_ABB(ABB *nodo);

void caminhaPosOrdem_ABB(ABB *nodo);

void caminhaPreOrdem_ABB(ABB *nodo);

void caminhaProfund_ABB(ABB **arv, int opcao);

int insereCaminha_ABB(ABB *nodo, Data novo);

int insere_ABB(ABB **arv, Data novo);

int procura_ABB (ABB **arv, Data elemento);

int procuraAfundo_ABB (ABB *nodo, Data elemento);

void libera_ABB (ABB *nodo);

void liberaProf_ABB (ABB **arv);

ABB* procuraEnd_ABB (ABB **arv, Data elemento);

ABB* procuraEndAfundo_ABB (ABB *nodo, Data elemento);

ABB* cade(ABB* wanted);

void remover(ABB** arv, Data elemento);
