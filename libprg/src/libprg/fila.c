#include <stdio.h>
#include <stdlib.h>
#include "libprg/libprg.h"


// ---------- FILA -----------------
struct fila {
    int* elementos;
    int inicio;
    int fim;
    int tamanho;
    int capacidade;
};

fila_t* criar_fila(int capacidade) {
    fila_t* f = (fila_t*) malloc(sizeof(fila_t));
    if (!f) return NULL;

    f->elementos = (int*) malloc(capacidade * sizeof(int));
    if (!f->elementos) {
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
    if (!f || f->tamanho == f->capacidade) {
        return 0; // falha
    }
    f->fim = (f->fim + 1) % f->capacidade;
    f->elementos[f->fim] = valor;
    f->tamanho++;
    return 1; // sucesso
}

int desenfileirar(fila_t* f, int* valor) {
    if (!f || f->tamanho == 0) {
        return 0; // falha
    }
    *valor = f->elementos[f->inicio];
    f->inicio = (f->inicio + 1) % f->capacidade;
    f->tamanho--;
    return 1; // sucesso
}

int frente_fila(fila_t* f, int* valor) {
    if (!f || f->tamanho == 0) {
        return 0; // falha
    }
    *valor = f->elementos[f->inicio];
    return 1; // sucesso
}

int tamanho_fila(fila_t* f) {
    if (!f) return -1;
    return f->tamanho;
}

void imprimir_fila(fila_t* f) {
    if (!f) return;
    printf("Fila: ");
    for (int i = 0; i < f->tamanho; i++) {
        int idx = (f->inicio + i) % f->capacidade;
        printf("%d ", f->elementos[idx]);
    }
    printf("\n");
}

void destruir_fila(fila_t* f) {
    if (!f) return;
    free(f->elementos);
    free(f);
}