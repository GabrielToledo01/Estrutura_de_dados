#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

struct tipoitem {
  int valor;
  /* outros componentes */
};

typedef struct celula_str {
  TipoItem Item;
  struct celula_str* Prox;
} Celula;

struct tipofila {
  Celula* Inicio; 
  Celula* Fundo;
  int Tamanho; 
};

TipoFila* InicializaFila(){
  TipoFila* Fila = (TipoFila*) malloc(sizeof(TipoFila));
  
  Fila->Inicio = (Celula*) malloc(sizeof(Celula));
  Fila->Fundo = Fila->Inicio;
  Fila->Inicio->Prox=NULL;
  Fila->Tamanho = 0;

  return Fila;
}

int Vazia (TipoFila* Fila) {
  return (Fila->Inicio == NULL);
}

void Enfileirar (TipoFila* Fila) {
 
  int valor; 
  
  printf("Digite um valor: ");
  scanf("%d", &valor); 

  TipoItem* item = (TipoItem*) malloc(sizeof(TipoItem));
  item->valor = valor; 

  Fila->Fundo->Prox = (Celula*) malloc(sizeof(Celula));
  Fila->Fundo = Fila->Fundo->Prox; 
  Fila->Fundo->Item = *item; 
  Fila->Fundo->Prox = NULL; 
  Fila->Tamanho++;
}

void Desenfileirar (TipoFila* Fila) {

  Celula* q;

  if (Vazia (Fila))
    printf ("Erro: fila esta vazia\n");
  else {

    q = Fila->Inicio; 
    Fila->Inicio = q->Prox;

    TipoItem* item = (TipoItem*) malloc(sizeof(TipoItem));
    *item = q->Item;
    free(q);
    
    Fila->Tamanho--; 
  }
}

int Tamanho (TipoFila* Fila) {
  return (Fila->Tamanho);
}

void Imprime (TipoFila* Fila)
{
  Celula* Aux;
  printf ("Fila: ");
  
  Aux = Fila->Inicio->Prox;
  while(Aux != NULL)
  {
    printf ("%d ", Aux->Item.valor);
    Aux = Aux->Prox; 
  } 
}
