#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#define MaxTam 1000

struct tipoitem {
  int valor;
  /* outros componentes */
};

struct tipofila {
  TipoItem Item[MaxTam];
  int Inicio;
  int Fundo; 
};

TipoFila* InicializaFila(){
  TipoFila* Fila = (TipoFila*) malloc(sizeof(TipoFila));
  Fila->Inicio = 0;
  Fila->Fundo  = 0;
  return Fila;
}

int Vazia (TipoFila* Fila) {
  return (Fila->Fundo == 0);
}

void Enfileirar (TipoFila* Fila) {
 
  int valor; 
  
  printf("Digite um valor: ");
  scanf("%d", &valor); 

  if (Fila->Fundo == MaxTam)
    printf ("Erro: fila esta cheia\n");
  else {

    TipoItem* item = (TipoItem*) malloc(sizeof(TipoItem));
    item->valor = valor; 

    Fila->Item[Fila->Fundo] = *item;
    Fila->Fundo++;
  }
}

void Desenfileirar (TipoFila* Fila) {

  if (Vazia (Fila))
    printf ("Erro: fila esta vazia\n");
  else {

    TipoItem* item = (TipoItem*) malloc(sizeof(TipoItem));
    *item = Fila->Item[Fila->Inicio];
    Fila->Inicio++; 

    if(Fila->Inicio == MaxTam)
       Fila->Inicio = 0; 

    Fila->Fundo--;
  }
}

int Tamanho (TipoFila* Fila) {
  return (Fila->Fundo);
}

void Imprime (TipoFila* Fila)
{
  int Aux;
  printf ("Fila: ");
  
  for (Aux=0; Aux < Fila->Fundo; Aux++)
  {
    printf ("%d ", Fila->Item[Aux].valor);
  }
}
