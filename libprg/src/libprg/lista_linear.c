#include <stdio.h>
#include <stdlib.h>
#include "libprg/libprg.h"

struct lista_linear {
    int *dados;
    int tamanho;
    int capacidade;
    bool ordenada;
};

lista_linear_t* criar_lista_linear(int capacidade, bool ordenada) {
    lista_linear_t* lista = malloc(sizeof(lista_linear_t));
    if (!lista) return NULL;
    lista->dados = malloc(capacidade * sizeof(int));
    if (!lista->dados) {
        free(lista);
        return NULL;
    }
    lista->tamanho = 0;
    lista->capacidade = capacidade;
    lista->ordenada = ordenada;
    return lista;
}

bool lista_cheia(lista_linear_t* lista) {
    return lista->tamanho == lista->capacidade;
}

bool lista_vazia(lista_linear_t* lista) {
    return lista->tamanho == 0;
}

int inserir_lista(lista_linear_t* lista, int valor) {
    if (lista_cheia(lista)) return 0;
    if (!lista->ordenada) {
        lista->dados[lista->tamanho++] = valor;
    } else {
        int i = lista->tamanho - 1;
        while (i >= 0 && lista->dados[i] > valor) {
            lista->dados[i + 1] = lista->dados[i];
            i--;
        }
        lista->dados[i + 1] = valor;
        lista->tamanho++;
    }
    return 1;
}

int buscar_lista(lista_linear_t* lista, int valor) {
    for (int i = 0; i < lista->tamanho; i++)
        if (lista->dados[i] == valor) return i;
    return -1;
}

int remover_lista(lista_linear_t* lista, int valor) {
    int pos = buscar_lista(lista, valor);
    if (pos == -1) return 0;
    for (int i = pos; i < lista->tamanho - 1; i++)
        lista->dados[i] = lista->dados[i + 1];
    lista->tamanho--;
    return 1;
}

int primeiro_lista(lista_linear_t* lista, int* valor) {
    if (lista_vazia(lista)) return 0;
    *valor = lista->dados[0];
    return 1;
}

void exibir_lista(lista_linear_t* lista) {
    for (int i = 0; i < lista->tamanho; i++)
        printf("%d ", lista->dados[i]);
    printf("\n");
}

void destruir_lista(lista_linear_t* lista) {
    free(lista->dados);
    free(lista);
}