/*

Autor: Thales Costa
Disciplina: ED1
Professor: Irineu
Maio/2017

*/

#include "Lista Enc Circular.h"

Lista* inicializar(){
	
	return NULL;
}

Lista* insere_Inicio(Lista* L, int dado){		//Insere no inicio da lista o elemento informado e retorna o ponteiro criado.
	
	Lista* novo = (Lista*)malloc(sizeof(Lista));
	novo->info = dado;

	if(L == NULL){
		novo->prox = novo;
		
		return  novo;
	}else{
		novo->prox = L->prox;
		L->prox = novo;
		
		return L;
	}
}

Lista* insere_Fim(Lista* L, int dado){		//Insere no fim da lista o elemento informado.
	
	Lista* novo = (Lista*)malloc(sizeof(Lista));
	novo->info = dado;

	if(L == NULL){
		novo->prox = novo;
		
		return  novo;
	}else{
		novo->prox = L->prox;
		L->prox = novo;
	
		return novo;
	}
	
}

Lista* retira_Inicio(Lista* L, int* elemento){		//Retira o primeiro elemento da lista.
	
	if(L == NULL){
		
		return NULL;
	}else if(L == L->prox){
		*elemento = L->info;
		free(L);
			
		return NULL;
	}else{
		*elemento = L->info;
		Lista* P;
		P = L->prox;
		L->prox = P->prox;
		free(P);
		
		return L;
	}
	
}

Lista* retira_Fim(Lista* L, int* elemento){		//Retira o primeiro elemento da lista.
	
	if(L == NULL){
		
		return NULL;
	}else if(L == L->prox){
		*elemento = L->info;
		free(L);
			
		return NULL;
	}else{
		*elemento = L->info;
		Lista* P;
		
		for(P = L->prox; P->prox != L; P = P->prox);
		
		P->prox = L->prox;
		free(P);
		
		return P;
	}
	
}

void mostra_Tudo(Lista* L){		//Mostra os elementos da lista de forma recursiva.
	
	printf("\nLista:\n");
	
	if(L == L->prox){
		printf("%d\t", L->info);
	
	}else{
		Lista* P = (Lista*)malloc(sizeof(Lista));
		
		for(P = L->prox; P != L; P = P->prox){
			printf("%d\t", P->info);
		}
		printf("%d\t", P->info);
	
	}
	printf("\n\n");
}

int mostra_Inicio(Lista* L){		//Retorna o primeiro elemento da lista.
	
	return L->prox->info;
}

int mostra_Fim(Lista* L){		//Retorna o último elemento da lista.
	
	return L->info;
}

void libera(Lista* L){		//Libera, com auxilio da função libera_aux, a memória alocada, caso tenha alguma.

	if(L != NULL){
		Lista* P = (Lista*)malloc(sizeof(Lista));
	
		P = L->prox;
		L->prox = NULL;
	
		libera_aux(P);
	}
	
}

void libera_aux(Lista* L){		//Libera, de forma recursiva, a memória alocada, caso tenha alguma.
	
	if(L != NULL){
		libera_aux(L->prox);
		free(L);
	}
	
}



