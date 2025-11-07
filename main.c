#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenacao.h"

// Função para gerar um vetor aleatório
int *gerarVetor(int n) {
    int *A = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) A[i] = rand() % 1000000;
    return A;
}

// Função para medir o tempo de execução de um algoritmo
double medirTempo(void (*algoritmo)(int *, int), int *A, int n) {
    int *copia = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) copia[i] = A[i];

    clock_t inicio = clock();
    algoritmo(copia, n);
    clock_t fim = clock();

    free(copia);
    return (double)(fim - inicio) / CLOCKS_PER_SEC;
}

int main() {
    srand(time(NULL));
    int numTestes = 12;

    FILE *arquivo = fopen("resultados.csv", "w");
    if (!arquivo) {
        printf("Erro ao criar o arquivo resultados.csv\n");
        return 1;
    }

    fprintf(arquivo, "Tamanho,QuickSort,MergeSort,InsertionSort\n");

    printf("=======================================\n");
    printf("BENCHMARK - QUICKSORT x MERGESORT x INSERTION\n");
    printf("=======================================\n");

    for (int i = 0; i < numTestes; i++) {
        int tamanho = 10000 + rand() % 100000;
        int *vetor = gerarVetor(tamanho);

        double tempoQuick = medirTempo(quicksort, vetor, tamanho);
        double tempoMerge = medirTempo(mergesort2, vetor, tamanho);
        double tempoInsertion = medirTempo(insertion, vetor, tamanho);

        fprintf(arquivo, "%d,%.8f,%.8f,%.8f\n", tamanho, tempoQuick, tempoMerge, tempoInsertion);

        printf("Tamanho: %10d | Insertion: %.6fs | Merge: %.6fs | Quick: %.6fs\n",
               tamanho, tempoInsertion, tempoMerge, tempoQuick);

        free(vetor);
    }

    fclose(arquivo);

    printf("=======================================\n");
    printf("Arquivo 'resultados.csv' gerado com sucesso!\n");
    printf("=======================================\n");

    return 0;
}
