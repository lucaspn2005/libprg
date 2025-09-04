#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H

typedef struct pilha {
    int* elementos;
    int topo;
    int capacidade;
} pilha_t;
pilha_t* criar_pilha(int capacidade);
int empilhar(pilha_t* p, int valor);
int desempilhar(pilha_t* p, int* valor);
int topo_pilha(pilha_t* p, int* valor);
int tamanho_pilha(pilha_t* p);
void imprimir_pilha(pilha_t* p);
void destruir_pilha(pilha_t* p);

#endif
