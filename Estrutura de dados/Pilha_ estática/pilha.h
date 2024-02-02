typedef struct tipoitem TipoItem;
typedef struct tipopilha TipoPilha;

TipoPilha* InicializaPilha();

int Vazia (TipoPilha* Pilha);

void Empilha (TipoPilha* Pilha);

void Desempilha (TipoPilha* Pilha);

int Tamanho (TipoPilha* Pilha);

void Imprime (TipoPilha* pilha);