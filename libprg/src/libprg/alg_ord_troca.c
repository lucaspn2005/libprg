#include "libprg/libprg.h"
#include <stdio.h>

/* ----------------------------------------------------------
 *                 BUBBLE SORT
 * ----------------------------------------------------------*/
void bubble_sort(int vetor[], int tamanho) {
    int trocou, aux;

    for (int i = 0; i < tamanho - 1; i++) {
        trocou = 0;
        for (int j = 0; j < tamanho - 1 - i; j++) {
            if (vetor[j] > vetor[j + 1]) {
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
                trocou = 1;
            }
        }
        if (!trocou) break; // Otimização
    }
}

/* ----------------------------------------------------------
 *                 INSERTION SORT
 * ----------------------------------------------------------*/
void insertion_sort(int vetor[], int tamanho) {
    for (int i = 1; i < tamanho; i++) {
        int chave = vetor[i];
        int j = i - 1;

        // Move elementos maiores que a chave
        while (j >= 0 && vetor[j] > chave) {
            vetor[j + 1] = vetor[j];
            j--;
        }

        vetor[j + 1] = chave;
    }
}

/* ----------------------------------------------------------
 *                 SELECTION SORT
 * ----------------------------------------------------------*/
void selection_sort(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        int menor = i;

        // Encontra o menor elemento à frente
        for (int j = i + 1; j < tamanho; j++) {
            if (vetor[j] < vetor[menor]) {
                menor = j;
            }
        }

        // Troca
        if (menor != i) {
            int aux = vetor[i];
            vetor[i] = vetor[menor];
            vetor[menor] = aux;
        }
    }
}
