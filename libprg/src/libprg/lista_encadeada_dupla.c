#include "libprg/libprg.h"
#include <stdio.h>
#include <stdlib.h>

struct no_duplo {
    struct no_duplo *anterior;
    int valor;
    struct no_duplo *proximo;
};

no_duplo_t* criar_no_duplo(int valor) {
    no_duplo_t *novo = malloc(sizeof(no_duplo_t));
    if (novo == NULL) {
        fprintf(stderr, "Erro ao alocar memória.\n");
        return NULL;
    }
    novo->valor = valor;
    novo->anterior = NULL;
    novo->proximo = NULL;
    return novo;
}

void adicionar_no_duplo(no_duplo_t **inicio, int valor) {
    no_duplo_t *novo = criar_no_duplo(valor);
    if (novo == NULL) return;
    if (*inicio != NULL) {
        novo->proximo = *inicio;
        (*inicio)->anterior = novo;
    }
    *inicio = novo;
}

no_duplo_t* buscar_no_duplo(no_duplo_t *inicio, int valor) {
    no_duplo_t *atual = inicio;
    while (atual != NULL) {
        if (atual->valor == valor)
            return atual;
        atual = atual->proximo;
    }
    return NULL;
}

int remover_no_duplo(no_duplo_t **inicio, int valor) {
    if (*inicio == NULL) return 0;
    no_duplo_t *atual = *inicio;
    while (atual != NULL) {
        if (atual->valor == valor) {
            if (atual->anterior == NULL) {
                *inicio = atual->proximo;
                if (*inicio)
                    (*inicio)->anterior = NULL;
            } else {
                atual->anterior->proximo = atual->proximo;
                if (atual->proximo)
                    atual->proximo->anterior = atual->anterior;
            }
            free(atual);
            return 1;
        }
        atual = atual->proximo;
    }
    return 0;
}

void imprimir_lista_dupla(no_duplo_t *inicio) {
    if (inicio == NULL) {
        printf("Lista vazia.\n");
        return;
    }
    no_duplo_t *atual = inicio;
    no_duplo_t *ultimo = NULL;
    printf("Ordem direta: ");
    while (atual != NULL) {
        printf("%d ", atual->valor);
        ultimo = atual;
        atual = atual->proximo;
    }
    printf("\nOrdem reversa: ");
    while (ultimo != NULL) {
        printf("%d ", ultimo->valor);
        ultimo = ultimo->anterior;
    }
    printf("\n");
}

void destruir_lista_dupla(no_duplo_t **inicio) {
    no_duplo_t *atual = *inicio;
    while (atual != NULL) {
        no_duplo_t *prox = atual->proximo;
        free(atual);
        atual = prox;
    }
    *inicio = NULL;
}