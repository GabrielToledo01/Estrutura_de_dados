typedef int Posicao;
typedef struct tipoitem TipoItem;
typedef struct tipolista TipoLista;

TipoLista* InicializaLista();

void FLVazia (TipoLista* Lista);

int Vazia (TipoLista* Lista);

void Insere (TipoLista* Lista);

void Retira (Posicao p, TipoLista* Lista);

void Imprime (TipoLista* Lista);