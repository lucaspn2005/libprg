#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H

#include <stdbool.h>

typedef struct pilha pilha_t;
pilha_t* criar_pilha(int capacidade);
int empilhar(pilha_t* p, int valor);
int desempilhar(pilha_t* p, int *valor);
int topo_pilha(pilha_t* p, int *valor);
int tamanho_pilha(pilha_t* p);
void imprimir_pilha(pilha_t* p);
void destruir_pilha(pilha_t* p);

typedef struct fila fila_t;
fila_t* criar_fila(int capacidade);
int enfileirar(fila_t* f, int valor);
int desenfileirar(fila_t* f, int *valor);
int frente_fila(fila_t* f, int *valor);
int tamanho_fila(fila_t* f);
bool fila_vazia(fila_t* f);
bool fila_cheia(fila_t* f);
void imprimir_fila(fila_t* f);
void destruir_fila(fila_t* f);

typedef struct lista_linear lista_linear_t;
lista_linear_t* criar_lista_linear(int capacidade, bool ordenada);
bool lista_cheia(lista_linear_t* lista);
bool lista_vazia(lista_linear_t* lista);
int inserir_lista(lista_linear_t* lista, int valor);
int buscar_lista(lista_linear_t* lista, int valor);
int remover_lista(lista_linear_t* lista, int valor);
int primeiro_lista(lista_linear_t* lista, int* valor);
void exibir_lista(lista_linear_t* lista);
void destruir_lista(lista_linear_t* lista);

typedef struct no no_t;
no_t* criar_le(int valor);
void adicionar_le(no_t** inicio, int valor);
no_t* buscar_lista_enc(no_t** inicio, int valor);
int remover_lista_enc(no_t** inicio, int valor);
void destruir_lista_enc(no_t** inicio);

#endif