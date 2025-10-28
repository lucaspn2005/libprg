#include "libprg/libprg.h"
#include <stdio.h>
#include <stdlib.h>

/* Estrutura do nó da lista encadeada simples */
struct no {
    int valor;
    struct no* proximo;
};

/* Cria um novo nó com o valor informado */
no_t* criar_no(int valor) {
    no_t* novo = malloc(sizeof(no_t));
    if (!novo) return NULL;

    novo->valor = valor;
    novo->proximo = NULL;
    return novo;
}

/* Adiciona um novo nó no início da lista */
void adicionar_no(no_t** inicio, int valor) {
    if (!inicio) return;

    no_t* novo = criar_no(valor);
    if (!novo) return;

    novo->proximo = *inicio;
    *inicio = novo;
}

/* Busca um nó pelo valor e retorna o ponteiro para ele */
no_t* buscar_no(no_t* inicio, int valor) {
    for (no_t* atual = inicio; atual != NULL; atual = atual->proximo) {
        if (atual->valor == valor)
            return atual;
    }
    return NULL;
}

/* Remove o primeiro nó com o valor especificado */
int remover_no(no_t** inicio, int valor) {
    if (!inicio || !*inicio) return 0;

    no_t* atual = *inicio;
    no_t* anterior = NULL;

    while (atual != NULL) {
        if (atual->valor == valor) {
            if (anterior == NULL) {
                // Removendo o primeiro nó
                *inicio = atual->proximo;
            } else {
                anterior->proximo = atual->proximo;
            }
            free(atual);
            return 1; // Removido com sucesso
        }
        anterior = atual;
        atual = atual->proximo;
    }
    return 0; // Valor não encontrado
}

/* Imprime todos os elementos da lista */
void imprimir_lista_encadeada(no_t* inicio) {
    printf("Lista: ");
    for (no_t* atual = inicio; atual != NULL; atual = atual->proximo) {
        printf("%d ", atual->valor);
    }
    printf("\n");
}

/* Libera toda a memória da lista */
void destruir_lista_encadeada(no_t** inicio) {
    if (!inicio) return;

    no_t* atual = *inicio;
    while (atual != NULL) {
        no_t* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    *inicio = NULL;
}