#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "libprg/libprg.h"

struct pilha {
    int *dados;
    int topo;
    int capacidade;
};

pilha_t* criar_pilha(int capacidade) {
    pilha_t *p = malloc(sizeof(pilha_t));
    if (!p) return NULL;
    p->dados = malloc(capacidade * sizeof(int));
    if (!p->dados) {
        free(p);
        return NULL;
    }
    p->topo = -1;
    p->capacidade = capacidade;
    return p;
}

bool pilha_vazia(pilha_t *p) {
    return p->topo == -1;
}

bool pilha_cheia(pilha_t *p) {
    return p->topo == p->capacidade - 1;
}

int empilhar(pilha_t *p, int valor) {
    if (pilha_cheia(p)) return 0;
    p->dados[++p->topo] = valor;
    return 1;
}

int desempilhar(pilha_t *p, int *valor) {
    if (pilha_vazia(p)) return 0;
    *valor = p->dados[p->topo--];
    return 1;
}

int topo_pilha(pilha_t *p, int *valor) {
    if (pilha_vazia(p)) return 0;
    *valor = p->dados[p->topo];
    return 1;
}

int tamanho_pilha(pilha_t *p) {
    return p->topo + 1;
}

void imprimir_pilha(pilha_t *p) {
    if (pilha_vazia(p)) {
        printf("Pilha vazia.\n");
        return;
    }
    for (int i = p->topo; i >= 0; i--)
        printf("%d ", p->dados[i]);
    printf("\n");
}

void destruir_pilha(pilha_t *p) {
    if (!p) return;
    free(p->dados);
    free(p);

}