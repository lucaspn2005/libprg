#include <stdio.h>
#include <stdlib.h>
#include "libprg/libprg.h"

struct no {
    int valor;
    struct no* prox;
};

no_t* criar_le(int valor) {
    no_t* novo = malloc(sizeof(no_t));
    if (!novo) return NULL;
    novo->valor = valor;
    novo->prox = NULL;
    return novo;
}

void adicionar_le(no_t** inicio, int valor) {
    no_t* novo = criar_le(valor);
    if (!novo) return;
    novo->prox = *inicio;
    *inicio = novo;
}

no_t* buscar_lista_enc(no_t** inicio, int valor) {
    no_t* atual = *inicio;
    while (atual) {
        if (atual->valor == valor) return atual;
        atual = atual->prox;
    }
    return NULL;
}

int remover_lista_enc(no_t** inicio, int valor) {
    no_t* atual = *inicio;
    no_t* anterior = NULL;
    while (atual && atual->valor != valor) {
        anterior = atual;
        atual = atual->prox;
    }
    if (!atual) return 0;
    if (!anterior) *inicio = atual->prox;
    else anterior->prox = atual->prox;
    free(atual);
    return 1;
}

void destruir_lista_enc(no_t** inicio) {
    no_t* atual = *inicio;
    while (atual) {
        no_t* temp = atual;
        atual = atual->prox;
        free(temp);
    }
    *inicio = NULL;
}