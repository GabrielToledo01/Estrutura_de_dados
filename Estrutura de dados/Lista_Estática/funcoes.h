#define InicioVetor 0
#define MaxTam 1000

struct tipoitem {
  int valor;
  /* outros componentes */
};

struct tipolista{
  TipoItem Item[MaxTam];
  Posicao Primeiro, Ultimo;
};

/* Inicializa uma lista */
TipoLista* InicializaLista(){
   TipoLista* lista = (TipoLista*) malloc(sizeof(TipoLista));
   lista->Primeiro  = InicioVetor;
   lista->Ultimo    = lista->Primeiro;
   return lista;
}

/*Verifica se a lista está vazia*/
int Vazia (TipoLista* Lista)
{
  return (Lista->Primeiro == Lista->Ultimo);
}

/* Insere x após o último elemento da lista */
void Insere (TipoLista *Lista)
{
  int valor; 
  
  printf("Digite um valor: ");
  scanf("%d", &valor); 
  
  if (Lista->Ultimo >= MaxTam)
    printf ("Lista está cheia\n");
  else
  { 
    TipoItem* item = (TipoItem*) malloc(sizeof(TipoItem));
    item->valor    = valor; 
    
    Lista->Item[Lista->Ultimo] = *item;
    Lista->Ultimo++;
  }
}

void Retira(Posicao p, TipoLista *Lista)
{
   int Aux;

   if (Vazia(Lista) || p >= Lista->Ultimo)
   {
      printf ("A posição não existe!\n");
   } 
   else 
   {
     TipoItem* item = (TipoItem*) malloc(sizeof(TipoItem));
     *item = Lista->Item[p]; 
     Lista->Ultimo--;
   
     for (Aux = p; Aux < Lista->Ultimo; Aux++)
        Lista->Item[Aux] = Lista->Item[Aux+1];
   }       
}

/*Imprime os itens da lista na ordem de ocorrência */
void Imprime(TipoLista* Lista)
{
   int Aux;
   printf ("Lista: ");

   for (Aux = Lista->Primeiro; Aux < Lista->Ultimo; Aux++)
   {
     printf ("%d ", Lista->Item[Aux].valor);
   }
   printf("\n");
}


