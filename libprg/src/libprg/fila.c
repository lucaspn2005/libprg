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

fila_t* criar_fila(int capacidade) {
    fila_t* f = malloc(sizeof(fila_t));
    if (!f) return NULL;
    f->dados = malloc(capacidade * sizeof(int));
    if (!f->dados) {
        free(f);
        return NULL;
    }
    f->inicio = 0;
    f->fim = -1;
    f->tamanho = 0;
    f->capacidade = capacidade;
    return f;
}

int enfileirar(fila_t* f, int valor) {
    if (f->tamanho == f->capacidade) return 0;
    f->fim = (f->fim + 1) % f->capacidade;
    f->dados[f->fim] = valor;
    f->tamanho++;
    return 1;
}

int desenfileirar(fila_t* f, int *valor) {
    if (f->tamanho == 0) return 0;
    *valor = f->dados[f->inicio];
    f->inicio = (f->inicio + 1) % f->capacidade;
    f->tamanho--;
    return 1;
}

int frente_fila(fila_t* f, int *valor) {
    if (f->tamanho == 0) return 0;
    *valor = f->dados[f->inicio];
    return 1;
}

int tamanho_fila(fila_t* f) {
    return f->tamanho;
}

bool fila_vazia(fila_t* f) {
    return f->tamanho == 0;
}

bool fila_cheia(fila_t* f) {
    return f->tamanho == f->capacidade;
}

void imprimir_fila(fila_t* f) {
    int i, idx;
    for (i = 0; i < f->tamanho; i++) {
        idx = (f->inicio + i) % f->capacidade;
        printf("%d ", f->dados[idx]);
    }
    printf("\n");
}

void destruir_fila(fila_t* f) {
    free(f->dados);
    free(f);
}