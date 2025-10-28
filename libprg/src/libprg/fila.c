#include <stdio.h>
#include <stdlib.h>
#include "libprg/libprg.h"

struct fila {
    int *dados;
    int inicio;
    int fim;
    int tamanho;
    int capacidade;
};

/* Cria uma nova fila com tamanho máximo especificado */
fila_t* criar_fila(int capacidade) {
    if (capacidade <= 0) return NULL;

    fila_t* f = malloc(sizeof(fila_t));
    if (!f) return NULL;

    f->dados = malloc(capacidade * sizeof(int));
    if (!f->dados) {
        free(f);
        return NULL;
    }

    f->inicio = 0;
    f->fim = 0;
    f->tamanho = 0;
    f->capacidade = capacidade;

    return f;
}

/* Insere um elemento no final da fila */
int enfileirar(fila_t* f, int valor) {
    if (!f || fila_cheia(f))
        return 0;

    f->dados[f->fim] = valor;
    f->fim = (f->fim + 1) % f->capacidade;
    f->tamanho++;
    return 1;
}

/* Remove o elemento do início da fila */
int desenfileirar(fila_t* f, int *valor) {
    if (!f || fila_vazia(f))
        return 0;

    *valor = f->dados[f->inicio];
    f->inicio = (f->inicio + 1) % f->capacidade;
    f->tamanho--;
    return 1;
}

/* Retorna o valor do início da fila sem removê-lo */
int frente_fila(fila_t* f, int *valor) {
    if (!f || fila_vazia(f))
        return 0;

    *valor = f->dados[f->inicio];
    return 1;
}

/* Retorna o número de elementos na fila */
int tamanho_fila(fila_t* f) {
    if (!f) return 0;
    return f->tamanho;
}

/* Verifica se a fila está vazia */
bool fila_vazia(fila_t* f) {
    return (f && f->tamanho == 0);
}

/* Verifica se a fila está cheia */
bool fila_cheia(fila_t* f) {
    return (f && f->tamanho == f->capacidade);
}

/* Exibe os elementos da fila na ordem atual */
void imprimir_fila(fila_t* f) {
    if (!f) return;

    printf("Fila: ");
    for (int i = 0; i < f->tamanho; i++) {
        int idx = (f->inicio + i) % f->capacidade;
        printf("%d ", f->dados[idx]);
    }
    printf("\n");
}

/* Libera toda a memória associada à fila */
void destruir_fila(fila_t* f) {
    if (!f) return;
    free(f->dados);
    free(f);
}