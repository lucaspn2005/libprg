//
// Created by lu062231 on 26/11/2025.
//

#include <stdlib.h>
#include <stdbool.h>
#include "libprg/libprg.h"

/* ============================================
 *            ÁRVORE BINÁRIA NORMAL
 * ============================================*/

typedef struct no_arvore {
    int valor;
    struct no_arvore *esq;
    struct no_arvore *dir;
} no_arvore_t;

no_arvore_t* arv_criar_no(int valor) {
    no_arvore_t *n = malloc(sizeof(no_arvore_t));
    if (!n) return NULL;

    n->valor = valor;
    n->esq = NULL;
    n->dir = NULL;
    return n;
}

void arv_destruir(no_arvore_t *raiz) {
    if (raiz == NULL) return;

    arv_destruir(raiz->esq);
    arv_destruir(raiz->dir);
    free(raiz);
}

no_arvore_t* arv_inserir(no_arvore_t *raiz, int valor) {
    if (raiz == NULL)
        return arv_criar_no(valor);

    if (valor < raiz->valor)
        raiz->esq = arv_inserir(raiz->esq, valor);
    else if (valor > raiz->valor)
        raiz->dir = arv_inserir(raiz->dir, valor);

    return raiz;
}

bool arv_buscar(no_arvore_t *raiz, int valor) {
    if (!raiz) return false;

    if (valor == raiz->valor)
        return true;

    return (valor < raiz->valor) ?
        arv_buscar(raiz->esq, valor) :
        arv_buscar(raiz->dir, valor);
}

static no_arvore_t* maior_da_esquerda(no_arvore_t *r) {
    while (r && r->dir != NULL)
        r = r->dir;
    return r;
}

no_arvore_t* arv_remover(no_arvore_t *raiz, int valor) {
    if (!raiz) return NULL;

    if (valor < raiz->valor) {
        raiz->esq = arv_remover(raiz->esq, valor);
    }
    else if (valor > raiz->valor) {
        raiz->dir = arv_remover(raiz->dir, valor);
    }
    else {
        // caso 0 ou 1 filho
        if (!raiz->esq || !raiz->dir) {
            no_arvore_t *aux = raiz->esq ? raiz->esq : raiz->dir;
            free(raiz);
            return aux;
        }

        // caso 2 filhos → substitui pelo maior da esquerda
        no_arvore_t *aux = maior_da_esquerda(raiz->esq);
        raiz->valor = aux->valor;
        raiz->esq = arv_remover(raiz->esq, aux->valor);
    }

    return raiz;
}


/* ============================================
 *                  ÁRVORE AVL
 * ============================================*/

typedef struct no_avl {
    int valor;
    int altura;
    struct no_avl *esq;
    struct no_avl *dir;
} no_avl_t;

static int avl_altura(no_avl_t *n) {
    return n ? n->altura : 0;
}

static int avl_fb(no_avl_t *n) {
    return n ? avl_altura(n->esq) - avl_altura(n->dir) : 0;
}

static int avl_max(int a, int b) {
    return (a > b) ? a : b;
}

no_avl_t* avl_criar_no(int valor) {
    no_avl_t *n = malloc(sizeof(no_avl_t));
    if (!n) return NULL;

    n->valor = valor;
    n->altura = 1;
    n->esq = NULL;
    n->dir = NULL;
    return n;
}

static no_avl_t* avl_rot_dir(no_avl_t *y) {
    no_avl_t *x = y->esq;
    no_avl_t *t2 = x->dir;

    x->dir = y;
    y->esq = t2;

    y->altura = 1 + avl_max(avl_altura(y->esq), avl_altura(y->dir));
    x->altura = 1 + avl_max(avl_altura(x->esq), avl_altura(x->dir));

    return x;
}

static no_avl_t* avl_rot_esq(no_avl_t *x) {
    no_avl_t *y = x->dir;
    no_avl_t *t2 = y->esq;

    y->esq = x;
    x->dir = t2;

    x->altura = 1 + avl_max(avl_altura(x->esq), avl_altura(x->dir));
    y->altura = 1 + avl_max(avl_altura(y->esq), avl_altura(y->dir));

    return y;
}

static no_avl_t* avl_balancear(no_avl_t *n) {
    int fb = avl_fb(n);

    if (fb > 1) {
        if (avl_fb(n->esq) < 0)
            n->esq = avl_rot_esq(n->esq);
        return avl_rot_dir(n);
    }
    if (fb < -1) {
        if (avl_fb(n->dir) > 0)
            n->dir = avl_rot_dir(n->dir);
        return avl_rot_esq(n);
    }

    return n;
}

no_avl_t* avl_inserir(no_avl_t *raiz, int valor) {
    if (!raiz)
        return avl_criar_no(valor);

    if (valor < raiz->valor)
        raiz->esq = avl_inserir(raiz->esq, valor);
    else if (valor > raiz->valor)
        raiz->dir = avl_inserir(raiz->dir, valor);
    else
        return raiz; // valores duplicados não são inseridos

    raiz->altura = 1 + avl_max(avl_altura(raiz->esq), avl_altura(raiz->dir));

    return avl_balancear(raiz);
}

no_avl_t* avl_remover(no_avl_t *raiz, int valor) {
    if (!raiz) return NULL;

    if (valor < raiz->valor)
        raiz->esq = avl_remover(raiz->esq, valor);
    else if (valor > raiz->valor)
        raiz->dir = avl_remover(raiz->dir, valor);
    else {
        if (!raiz->esq || !raiz->dir) {
            no_avl_t *aux = raiz->esq ? raiz->esq : raiz->dir;
            free(raiz);
            return aux;
        }

        no_avl_t *aux = raiz->esq;
        while (aux->dir)
            aux = aux->dir;

        raiz->valor = aux->valor;
        raiz->esq = avl_remover(raiz->esq, aux->valor);
    }

    raiz->altura = 1 + avl_max(avl_altura(raiz->esq), avl_altura(raiz->dir));
    return avl_balancear(raiz);
}

void avl_destruir(no_avl_t *raiz) {
    if (!raiz) return;
    avl_destruir(raiz->esq);
    avl_destruir(raiz->dir);
    free(raiz);
}