typedef int Posicao;
typedef struct tipoitem TipoItem;
typedef struct celula_str Celula;
typedef struct tipolista TipoLista;


TipoLista* InicializaLista();

int Vazia (TipoLista* Lista);

void Insere (TipoLista* Lista);

int tamanho (TipoLista* Lista); 

void Retira (Posicao p, TipoLista* Lista);

void Imprime (TipoLista* Lista);