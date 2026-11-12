#ifndef FILA_H
#define FILA_H
#define CAPACIDADE 20
#define TAM_NOME 60
typedef struct { char nome[TAM_NOME]; } Usuario;
typedef struct { Usuario usuarios[CAPACIDADE]; int inicio, fim, quantidade; } Fila;
void inicializar_fila(Fila *fila);
int fila_vazia(const Fila *fila);
int fila_cheia(const Fila *fila);
int enfileirar(Fila *fila, const char *nome);
int desenfileirar(Fila *fila, Usuario *usuario);
int mostrar_fila(const Fila *fila, int posicao, Usuario *usuario);
#endif
