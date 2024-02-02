#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#define MaxTam 1000

struct tipoitem {
  int valor;
  /* outros componentes */
};

struct tipopilha {
  TipoItem Item[MaxTam];
  int Topo;
};

TipoPilha* InicializaPilha(){
  TipoPilha* Pilha = (TipoPilha*) malloc(sizeof(TipoPilha));
  Pilha->Topo = 0;
  return Pilha;
}

int Vazia (TipoPilha* Pilha) {
  return (Pilha->Topo == 0);
}

void Empilha (TipoPilha* Pilha) {
 
  int valor; 
  
  printf("Digite um valor: ");
  scanf("%d", &valor); 

  if (Pilha->Topo == MaxTam)
    printf ("Erro: pilha esta cheia\n");
  else {

    TipoItem* item = (TipoItem*) malloc(sizeof(TipoItem));
    item->valor = valor; 

    Pilha->Item[Pilha->Topo] = *item;
    Pilha->Topo++;
  }
}

void Desempilha (TipoPilha* Pilha) {

  if (Vazia (Pilha))
    printf ("Erro: pilha esta vazia\n");
  else {
    //TipoItem* item = Pilha->Item[Pilha->Topo-1];
    TipoItem* item = (TipoItem*) malloc(sizeof(TipoItem));
    *item = Pilha->Item[Pilha->Topo-1];
    Pilha->Topo--;
  }
}

int Tamanho (TipoPilha* Pilha) {
  return (Pilha->Topo);
}

void Imprime (TipoPilha* pilha)
{
  int Aux;
  printf ("Pilha: ");
  
  for (Aux = (pilha->Topo-1); Aux >= 0; Aux--)
  {
    printf ("%d ", pilha->Item[Aux].valor);
  }
}
