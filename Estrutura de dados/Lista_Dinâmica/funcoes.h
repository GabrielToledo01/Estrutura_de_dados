struct tipoitem{
   int valor;
   /* outros componentes */
};

struct celula_str {
    TipoItem Item;
    Celula* Prox;
};

struct tipolista{
    Celula* Primeiro; 
    Celula* Ultimo;
};

TipoLista* InicializaLista()
{
  TipoLista* lista = (TipoLista*) malloc(sizeof(TipoLista));
   
  lista->Primeiro = (Celula*) malloc(sizeof(Celula));
  lista->Ultimo   = lista->Primeiro;
  lista->Primeiro->Prox = NULL;
   
   return lista;
}

int Vazia (TipoLista* Lista)
{
  return (Lista->Primeiro == Lista->Ultimo);
}

void Insere (TipoLista *Lista)
{
  int valor; 
  
  printf("Digite um valor: ");
  scanf("%d", &valor); 
  
  TipoItem* item = (TipoItem*) malloc(sizeof(TipoItem));
  item->valor    = valor; 
  
  Lista->Ultimo->Prox = (Celula*) malloc(sizeof(Celula));
  Lista->Ultimo       = Lista->Ultimo->Prox;   
  
  Lista->Ultimo->Item = *item;
  Lista->Ultimo->Prox = NULL;
}

int tamanho (TipoLista* Lista)
{
  Celula* aux;

  int cont = 0;

  for (aux=Lista->Primeiro->Prox; aux!=NULL; aux=aux->Prox)
      cont++; 

  return cont;
}

/* O item retirado é o seguinte apontado por p */
void Retira (Posicao p, TipoLista *Lista)
{
  Celula* q;  
  Celula* q2; 
  TipoItem* item;
   
  item = (TipoItem*) malloc(sizeof(TipoItem));
   
  int i;
   
  int t = tamanho (Lista);

  if (Vazia(Lista) || p>=t)
     printf ("Lista vazia ou posicao nao existe\n");
  else 
  {
     q = Lista->Primeiro;
     
     //encontra o elemento antes da posicao desejada
     for (i=0; i<p; i++)
        q = q->Prox;
        
     q2 = q->Prox;

     *item   = q2->Item;
     q->Prox = q2->Prox;

     if (q2->Prox == NULL) Lista->Ultimo = q;
     
     free (q2);
  }
}

void Imprime (TipoLista* Lista)
{
  Celula* aux;
  
  printf ("Lista: ");

  aux = Lista->Primeiro->Prox;
  
  while (aux != NULL)
  {
     printf ("%d ", aux->Item.valor);
     aux = aux->Prox;
  }
  printf("\n");
}


