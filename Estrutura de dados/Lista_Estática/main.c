/******************************************************************************
 -> Lista estática; 
   - Operações: 
    - Inicializar; 
    - Verifica se a lista está vazia; 
    - Inserir elemento no final; 
    - Remover elemento no final; 
    - Imprimir elementos da lista. 
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "funcoes.h"

int main()
{
    TipoLista* lista; 
    int num_elem;
    int pos; 
    int i; 
    
    printf("**** Inicializando lista ****\n");
    lista = InicializaLista(); 
    
    printf("**** Imprimindo ponteiros ****\n");
    printf("Lista->Primeiro: %d | Lista->Ultimo: %d\n", lista->Primeiro, lista->Ultimo);
    printf("\n");
    
    printf("**** Inserindo elementos ****\n");
    printf("Digite o número de elementos que deseja inserir na lista: ");
    scanf("%d", &num_elem);
    
    for(i=0; i<num_elem; i++) 
    {
      Insere(lista); 
    }
    printf("\n");
    
    printf("**** Imprimindo elementos ****\n");
    Imprime(lista);
    printf("\n");
    
    printf("**** Removendo elementos ****\n");
    printf("Digite o número de elementos que deseja inserir na lista: ");
    scanf("%d", &num_elem);
    for(i=0; i<num_elem; i++) 
    {
      printf("Digite a posição do nó que deseja retirar da lista: "); 
      scanf("%d", &pos);
      Retira(pos, lista); 
      printf("\n");
    
      printf("**** Imprimindo elementos ****\n");
      Imprime(lista);    
    }
    
    return 0;
}