#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H

#include <stdbool.h>

/* ---------------------------
 *        PILHA
 * ---------------------------*/
typedef struct pilha pilha_t;

pilha_t* criar_pilha(int capacidade);
int empilhar(pilha_t* p, int valor);
int desempilhar(pilha_t* p, int *valor);
int topo_pilha(pilha_t* p, int *valor);
int tamanho_pilha(pilha_t* p);
bool pilha_vazia(pilha_t* p);
bool pilha_cheia(pilha_t* p);
void imprimir_pilha(pilha_t* p);
void destruir_pilha(pilha_t* p);


/* ---------------------------
 *         FILA
 * ---------------------------*/
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


/* ---------------------------
 *     LISTA LINEAR
 * ---------------------------*/
typedef struct lista_linear lista_linear_t;

lista_linear_t* criar_lista_linear(int capacidade, bool ordenada);
bool lista_vazia(lista_linear_t* lista);
bool lista_cheia(lista_linear_t* lista);
int inserir_lista(lista_linear_t* lista, int valor);
int inserir_na_posicao(lista_linear_t* lista, int valor, int posicao);
int inserir_ordenada(lista_linear_t* lista, int valor);
int buscar_lista(lista_linear_t* lista, int valor);
int remover_lista(lista_linear_t* lista, int valor);
int remover_da_posicao(lista_linear_t* lista, int posicao);
int primeiro_lista(lista_linear_t* lista, int *valor);
int busca_na_posicao(lista_linear_t* lista, int posicao, int *valor);
void exibir_lista(lista_linear_t* lista);
void destruir_lista(lista_linear_t* lista);


/* ---------------------------
 *  LISTA ENCADEADA SIMPLES
 * ---------------------------*/
typedef struct no no_t;

no_t* criar_no(int valor);
void adicionar_no(no_t** inicio, int valor);
no_t* buscar_no(no_t* inicio, int valor);
int remover_no(no_t** inicio, int valor);
void imprimir_lista_encadeada(no_t* inicio);
void destruir_lista_encadeada(no_t** inicio);


/* ---------------------------
 * LISTA ENCADEADA DUPLAMENTE
 * ---------------------------*/
typedef struct no_duplo no_duplo_t;

no_duplo_t* criar_no_duplo(int valor);
void adicionar_no_duplo(no_duplo_t** inicio, int valor);
no_duplo_t* buscar_no_duplo(no_duplo_t* inicio, int valor);
int remover_no_duplo(no_duplo_t** inicio, int valor);
void imprimir_lista_dupla(no_duplo_t* inicio);
void destruir_lista_dupla(no_duplo_t** inicio);

#endif /* LIBPRG_LIBPRG_H */