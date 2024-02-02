/******************************************************************************
 -> Lista dinâmica; 
   - Operações: 
    - Inicializar; 
    - Verifica se a lista está vazia;
    - Inserir elemento no final;  
    - Retorna o tamanho da lista, tirando célula cabeça;
    - Remover elemento em qualquer posição; 
    - Imprimir elementos da lista. 
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "funcoes.h"

typedef struct Container {
    int container_id;
    int ship_id;
    struct Container* next;
} Container;

typedef struct Ship {
    int ship_id;
    TipoLista* containers;
    struct Ship* next;
} Ship;

typedef struct Port {
    TipoLista* ships;
    TipoLista* containers;
} Port;

Port* InicializaPorto() {
    Port* porto = (Port*)malloc(sizeof(Port));
    porto->ships = InicializaLista();
    porto->containers = InicializaLista();
    return porto;
}

void AdicionaContainer(Port* porto, int container_id, int ship_id) {
    Container* container = (Container*)malloc(sizeof(Container));
    container->container_id = container_id;
    container->ship_id = ship_id;
    container->next = NULL;

    Insere(porto->containers, container);
}

void AdicionaNavio(Port* porto, int ship_id) {
    Ship* navio = (Ship*)malloc(sizeof(Ship));
    navio->ship_id = ship_id;
    navio->containers = InicializaLista();
    navio->next = NULL;

    Insere(porto->ships, navio);
}

void CarregaNavio(Port* porto, Ship* navio) {
    if (Vazia(porto->containers)) {
        printf("Nao ha containers disponiveis para carregar o navio %d\n", navio->ship_id);
        return;
    }

    // Carrega os containers disponíveis no navio
    while (!Vazia(porto->containers)) {
        Container* container = (Container*)Retira(1, porto->containers);
        Insere(navio->containers, container);
    }

    printf("Navio %d carregado com sucesso\n", navio->ship_id);
}

void EsvaziaNavio(Port* porto, Ship* navio) {
    if (Vazia(navio->containers)) {
        printf("O navio %d ja esta vazio\n", navio->ship_id);
        return;
    }

    // Esvazia os containers do navio
    while (!Vazia(navio->containers)) {
        Container* container = (Container*)Retira(1, navio->containers);
        free(container);
    }

    printf("Navio %d esvaziado com sucesso\n", navio->ship_id);
}

void ProcessaNavios(Port* porto) {
    TipoLista* navios = porto->ships;
    while (!Vazia(navios)) {
        Ship* navio = (Ship*)Retira(1, navios);
        if (Vazia(navio->containers)) {
            EsvaziaNavio(porto, navio);
        } else {
            CarregaNavio(porto, navio);
        }
        free(navio);
    }
}

void ImprimePorto(Port* porto) {
    TipoLista* navios = porto->ships;
    printf("Navios no porto:\n");
    while (!Vazia(navios)) {
        Ship* navio = (Ship*)Retira(1, navios);
        printf("Navio: %d\n", navio->