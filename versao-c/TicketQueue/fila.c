#include "fila.h"
#include <string.h>
void inicializar_fila(Fila *fila) { fila->inicio = fila->fim = fila->quantidade = 0; }
int fila_vazia(const Fila *fila) { return fila->quantidade == 0; }
int fila_cheia(const Fila *fila) { return fila->quantidade == CAPACIDADE; }
int enfileirar(Fila *fila, const char *nome) {
 if (fila_cheia(fila) || !nome || !nome[0]) return 0;
 strncpy(fila->usuarios[fila->fim].nome, nome, TAM_NOME-1);
 fila->usuarios[fila->fim].nome[TAM_NOME-1] = '\0';
 fila->fim = (fila->fim+1)%CAPACIDADE;
 fila->quantidade++;
 return 1;
}
int desenfileirar(Fila *fila, Usuario *usuario) {
 if (fila_vazia(fila) || !usuario) return 0;
 *usuario = fila->usuarios[fila->inicio];
 fila->inicio = (fila->inicio+1)%CAPACIDADE;
 fila->quantidade--;
 return 1;
}
int mostrar_fila(const Fila *fila, int posicao, Usuario *usuario) {
 if (posicao<0 || posicao>=fila->quantidade || !usuario) return 0;
 *usuario = fila->usuarios[(fila->inicio+posicao)%CAPACIDADE];
 return 1;
}