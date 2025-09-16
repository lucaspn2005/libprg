#include<stdio.h>
#include<stdlib.h>

#include "libprg/libprg.h"
typedef struct pilha {
    int* elementos;
    int topo;
    int capacidade;
} pilha_t;

pilha_t* criar_pilha(int capacidade) {
    pilha_t* p = malloc(sizeof(pilha_t));
    if (p == NULL) return NULL;

    p->elementos = malloc(capacidade * sizeof(int));
    if (p->elementos == NULL) {
        free(p);
        return NULL;
    }

    p->topo = -1;
    p->capacidade = capacidade;

    return p;
}

int empilhar(pilha_t* p, int valor) {
    if (p->topo >= p->capacidade - 1)
        return 0; // pilha cheia

    p->elementos[++(p->topo)] = valor;
    return 1;
}

int desempilhar(pilha_t* p, int* valor) {
    if (p->topo < 0)
        return 0; // pilha vazia

    *valor = p->elementos[(p->topo)--];
    return 1;
}

int topo_pilha(pilha_t* p, int* valor) {
    if (p->topo < 0)
        return 0;

    *valor = p->elementos[p->topo];
    return 1;
}

int tamanho_pilha(pilha_t* p) {
    return p->topo + 1;
}

void imprimir_pilha(pilha_t* p) {
    if (p->topo < 0) {
        printf("Pilha vazia.\n");
        return;
    }

    printf("Pilha (base -> topo): ");
    for (int i = 0; i <= p->topo; i++) {
        printf("%d ", p->elementos[i]);
    }
    printf("\n");
}

void destruir_pilha(pilha_t* p) {
    if (p) {
        free(p->elementos);
        free(p);
    }
}