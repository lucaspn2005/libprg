#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H
#include <stdbool.h>
// ----------PILHA-----------------
typedef struct pilha pilha_t;
pilha_t* criar_pilha(int capacidade);
int empilhar(pilha_t* p, int valor);
int desempilhar(pilha_t* p, int* valor);
int topo_pilha(pilha_t* p, int* valor);
int tamanho_pilha(pilha_t* p);
void imprimir_pilha(pilha_t* p);
void destruir_pilha(pilha_t* p);

// -------- FILA------------

typedef struct fila fila_t;

fila_t* criar_fila(int capacidade);
int enfileirar(fila_t* f, int valor);
int desenfileirar(fila_t* f, int* valor);
int frente_fila(fila_t* f, int* valor);
int tamanho_fila(fila_t* f);
void imprimir_fila(fila_t* f);
void destruir_fila(fila_t* f);


// -----------LISTA--------------
typedef struct  lista_linear lista_linear_t;
lista_linear_t* criar (int capacidade);
void inserir (lista_linear_t* lista, int valor);
bool lista_cheia(lista_linear_t* lista);
int buscar (lista_linear_t* lista, int valor);

#endif
