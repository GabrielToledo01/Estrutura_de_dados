/******************************************************************************
 -> Pilha estática; 
   - Operações: 
    - Inicializar; 
    - Verifica se a pilha está vazia; 
    - Insere elemento no topo; 
    - Remove elemento no topo;
    - Retorna o tamanho da pilha; 
    - Imprime os elementos; 
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "funcoes.h"

int main()
{
   TipoPilha* pilha; 
    int num_elem;
    int i; 
    
    printf("**** Inicializando pilha ****\n");
    pilha = InicializaPilha(); 
    
    printf("**** Imprimindo topo ****\n");
    printf("Pilha->Topo: %d \n", pilha->Topo);
    printf("\n");
    
    printf("**** Inserindo elementos ****\n");
    printf("Digite o número de elementos que deseja inserir na pilha: ");
    scanf("%d", &num_elem);
    
    for(i=0; i<num_elem; i++) 
    {
      Empilha(pilha); 
    }
    printf("\n");
    
    printf("**** Imprimindo elementos ****\n");
    Imprime(pilha);
    printf("\n\n");
    
    printf("**** Removendo elementos ****\n");
    printf("Digite o número de elementos que deseja remover na pilha: ");
    scanf("%d", &num_elem);
    for(i=0; i<num_elem; i++) 
    {
      Desempilha(pilha); 
      printf("\n");
    
      printf("**** Imprimindo elementos ****\n");
      Imprime(pilha); 
      printf("\n");
    } 

    return 0;
}
