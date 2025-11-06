#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenacao.h"

void imprimirVetor(int *A, int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main() {
    srand(time(NULL)); // inicializa gerador aleatório

    // Gera um tamanho aleatório entre 5 e 10000
    int n = 5 + rand() % 9995;

    // Aloca vetor
    int *A = (int *)malloc(n * sizeof(int));

    // Preenche com valores aleatórios de 0 a 100000
    for (int i = 0; i < n; i++) {
        A[i] = rand() % 100000;
    }

    printf("Tamanho do vetor gerado: %d\n", n);
    printf("Vetor original:\n");
    imprimirVetor(A, n);

    // Marca o início do tempo
    clock_t inicio = clock();
    mergesort2(A, n);

    // Marca o fim do tempo
    clock_t fim = clock();

    // Calcula tempo total em segundos
    double tempoExecucao = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("\nVetor ordenado:\n");
    imprimirVetor(A, n);

    printf("\nTamanho do vetor: %d elementos\n", n);
    printf("Tempo de execucao: %.9f segundos\n", tempoExecucao);

    free(A);
    return 0;
}
