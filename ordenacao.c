#include <stdio.h>
#include <stdlib.h>

// ordenação por inserção
void insertion(int *A, int n){
    for (int i = 1; i < n; i++){
        int novoItem = A[i]; // item a ser isetido na posição correta
        int posicao = i-1;
        while(posicao >= 0 && (novoItem < A[posicao])) {
            A[posicao+1] = A[posicao];
            posicao--;
        }
        
        A[posicao+1] = novoItem;
        posicao++;
    }
}


// merge sort
void merge(int *A, int inicio, int meio, int fim) {
    int n1 = meio - inicio;
    int n2 = fim - meio;

    int *parte1 = (int *)malloc(n1 * sizeof(int));
    int *parte2 = (int *)malloc(n2 * sizeof(int));

    // divide o vetor A em duas partes copiando os valores de cada uma das metades para os novos vetores
    for (int i = 0; i < n1; i++)
        parte1[i] = A[inicio + i];
    for (int j = 0; j < n2; j++)
        parte2[j] = A[meio + j];

    int i = inicio;
    int j = meio;
    int posicao = inicio;

    // compara os valores de cada uma das partes e atribui ordenado no vetor A
    while (i < n1 && j < n2) {
        if (parte1[i] <= parte2[j])
            A[posicao++] = parte1[i++];
        else
            A[posicao++] = parte2[j++];
    }

    // caso tenha sobrado itens em alguma das partes continua a atribuição no vetor A
    while (i < n1)
        A[posicao++] = parte1[i++];
    while (j < n2)
        A[posicao++] = parte2[j++];

    free(parte1);
    free(parte2);
}

void mergesort(int *A, int inicio, int fim) {
    if (fim - inicio <= 1)
        return;

    int meio = (inicio + fim) / 2;

    mergesort(A, inicio, meio);
    mergesort(A, meio, fim);
    merge(A, inicio, meio, fim);
}

void mergesort2(int *A, int n) {
    mergesort(A, 0, n);
}

// quicksort
void quicksort(int *A, int n);