#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct list {
	int fim;
	int elem[MAX];
};
typedef struct list LAEAS;

void criarLaeas (LAEAS *lista);
int Laeasehcheia (LAEAS *lista);
int Laeasehvazia (LAEAS *lista);
void imprimirLaeas (LAEAS *lista);
void inserirInicioLaeas (LAEAS *lista);
void insereFimLaeas (LAEAS *lista);
void removeInicioLaeas (LAEAS *lista);
void removeFimLaeas (LAEAS *lista);
void limparLaeas(LAEAS *lista);
		
		
		
		
		
		
		
		
		
			 
