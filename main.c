#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenacao.h"

// Função para gerar um vetor aleatório
int *gerarVetorAleatorio(int n) {
    int *A = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        A[i] = rand() % 10000000;
    return A;
}

// Gera vetor crescente
int *gerarVetorCrescente(int n) {
    int *A = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        A[i] = i;
    return A;
}

// Gera vetor decrescente
int *gerarVetorDecrescente(int n) {
    int *A = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        A[i] = n - i;
    return A;
}

// Função para medir o tempo de execução de um algoritmo
double medirTempo(void (*algoritmo)(int *, int), int *A, int n) {
    int *copia = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        copia[i] = A[i];

    clock_t inicio = clock();
    algoritmo(copia, n);
    clock_t fim = clock();

    free(copia);
    return (double)(fim - inicio) / CLOCKS_PER_SEC;
}

int main() {
    srand(time(NULL));

    int numTestes = 4;
    int tamanhos[] = {5000, 15000, 30000, 40000};

    FILE *arquivo = fopen("resultados.csv", "w");
    if (!arquivo) {
        printf("Erro ao criar o arquivo resultados.csv\n");
        return 1;
    }

    fprintf(arquivo, "Tipo,Tamanho,InsertionSort,MergeSort,QuickSort\n");

    printf("DESEMPENHO - INSERTION x MERGE x QUICK\n");

    // Testa com vetores aleatórios, crescentes e decrescentes
    const char *tipos[] = {"Aleatorio", "Crescente", "Decrescente"};

    for (int t = 0; t < 3; t++) {
        printf("\n----- Tipo: %s -----\n", tipos[t]);

        for (int i = 0; i < numTestes; i++) {
             int n = tamanhos[i];

            int *vetor;

            // Gera vetor de acordo com o tipo
            if (t == 0)
                vetor = gerarVetorAleatorio(n);
            else if (t == 1)
                vetor = gerarVetorCrescente(n);
            else
                vetor = gerarVetorDecrescente(n);

            // Mede tempos
            double tempoInsertion = medirTempo(insertion, vetor, n);
            double tempoMerge = medirTempo(mergesort2, vetor, n);
            double tempoQuick = medirTempo(quicksort, vetor, n);

            // Grava no CSV
            fprintf(arquivo, "%s,%d,%.8f,%.8f,%.8f\n",
                    tipos[t], n, tempoInsertion, tempoMerge, tempoQuick);

            // Exibe no console
            printf("Tamanho: %7d | Insertion: %.4fs | Merge: %.4fs | Quick: %.4fs\n",
                   n, tempoInsertion, tempoMerge, tempoQuick);

            free(vetor);
        }
    }

    fclose(arquivo);

    printf("\n=======================================\n");
    printf("Arquivo 'resultados.csv' gerado com sucesso!\n");
    printf("=======================================\n");

    return 0;
}
