typedef struct tipoitem TipoItem;
typedef struct tipofila TipoFila;

TipoFila* InicializaFila();

int Vazia (TipoFila* Fila);

void Enfileirar (TipoFila* Fila);

void Desenfileirar (TipoFila* Fila);

int Tamanho (TipoFila* Fila);

void Imprime (TipoFila* Fila);
