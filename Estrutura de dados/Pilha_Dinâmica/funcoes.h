#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

struct tipoitem {
  int valor;
  /* outros componentes */
};

typedef struct celula_str {
  TipoItem Item;
  struct celula_str* Prox;
} Celula;

struct tipopilha {
   Celula* Fundo; 
   Celula* Topo;
   int Tamanho;
};

TipoPilha* InicializaPilha(){
  TipoPilha* Pilha = (TipoPilha*) malloc(sizeof(TipoPilha));
  
  Pilha->Topo = (Celula*) malloc(sizeof(Celula));
  Pilha->Fundo = Pilha->Topo;
  Pilha->Topo->Prox=NULL;
  Pilha->Tamanho = 0;
  
  return Pilha;
}

int Vazia (TipoPilha* Pilha) {
  return (Pilha->Topo == Pilha->Fundo);
}

void Empilha (TipoPilha* Pilha) {
 
  int valor; 
   
  printf("Digite um valor: ");
  scanf("%d", &valor); 

  TipoItem* item = (TipoItem*) malloc(sizeof(TipoItem));
  item->valor = valor; 
    
  Celula* Aux = (Celula*) malloc(sizeof(Celula));
  Pilha->Topo->Item = *item;
  Aux->Prox   = Pilha->Topo;
  Pilha->Topo = Aux;
  Pilha->Tamanho++;
}

void Desempilha (TipoPilha* Pilha) {

  Celula* q;
  
  if (Vazia (Pilha))
    printf ("Erro: pilha esta vazia\n");
  else {
    q = Pilha->Topo; 
    Pilha->Topo = q->Prox;
    
    TipoItem* item = (TipoItem*) malloc(sizeof(TipoItem));
    *item = q->Prox->Item;
    free(q); 
    Pilha->Tamanho--;
  }
}

int Tamanho (TipoPilha* Pilha) {
  return (Pilha->Tamanho);
}

void Imprime (TipoPilha* pilha)
{
  Celula* Aux;
  printf ("Pilha: ");
  
  Aux = pilha->Topo->Prox;
  while(Aux != NULL)
  {
    printf ("%d ", Aux->Item.valor);
    Aux = Aux->Prox; 
  }
}
