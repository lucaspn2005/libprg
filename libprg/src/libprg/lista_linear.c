#include <stdlib.h>
#include <stdbool.h>
#include "libprg/libprg.h"

typedef struct lista_linear
{
    int* elementos;
    int tamanho;
    int capacidade;
}lista_linear_t;

lista_linear_t* criar (int capacidade)
{
    lista_linear_t* lista = malloc(sizeof(lista_linear_t));
    lista->elementos = malloc(sizeof(int) * capacidade);
    lista->tamanho=0;
    lista->capacidade = capacidade;

    return lista;

}
void inserir (lista_linear_t* lista, int valor)
{
    lista->elementos[lista->tamanho] = valor;
    lista->tamanho++;
}
bool lista_cheia(lista_linear_t* lista)
{
    return lista->tamanho==lista->capacidade;
}
int buscar (lista_linear_t* lista, int valor)
{
    for (int i = 0; i < lista->tamanho; ++i)
    {
        if (lista->elementos[i] == valor)
        {
            return i;
        }
    }
}
