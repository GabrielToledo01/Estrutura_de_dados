/******************************************************************************
 -> Fila Estática; 
   - Operações: 
    - Inicializar; 
    - Verifica se a fila está vazia; 
    - Insere elemento no final; 
    - Remove elemento no início;
    - Retorna o tamanho da fila; 
    - Imprime os elementos; 
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include "funcoes.h"

int main()
{
    TipoFila* fila; 
    int num_elem;
    int i; 
    
    printf("**** Inicializando fila ****\n");
    fila = InicializaFila(); 
    
    printf("**** Inserindo elementos ****\n");
    printf("Digite o número de elementos que deseja inserir na fila: ");
    scanf("%d", &num_elem);
    
    for(i=0; i<num_elem; i++) 
    {
      Enfileirar(fila); 
    }
    printf("\n");
    
    printf("**** Imprimindo elementos ****\n");
    Imprime(fila);
    printf("\n\n");
    
    printf("**** Imprimindo tamanho ****\n");
    printf("fila->tamanho: %d\n", fila->Tamanho);
    printf("\n");

    printf("**** Removendo elementos ****\n");
    printf("Digite o número de elementos que deseja remover na pilha: ");
    scanf("%d", &num_elem);
    for(i=0; i<num_elem; i++) 
    {
      Desenfileirar(fila); 
      printf("\n");
    
      printf("**** Imprimindo elementos ****\n");
      Imprime(fila); 
      printf("\n\n");

      printf("**** Imprimindo tamanho ****\n");
      printf("fila->tamanho: %d \n", fila->Tamanho);
      printf("\n");
    } 

    return 0;
}
