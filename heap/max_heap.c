#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void maxHeapFy(int *A, int m, int i) {
    int maior;
    int e = 2*i+1;
    int d = 2*i+2;
    if((e < m) && (A[e] > A[i])){
        maior = e;
    } else {
        maior = i;
    }
    if (d<=m && (A[d] > A[maior])) {
        maior = d;
    }
    if (maior != i) {
        int aux = A[i];
        A[i] = A[maior];
        A[maior] = aux;
        maxHeapFy(A, m, maior);
    }
}

void buildMaxHeap(int *A, int n) {
    for(int i=n/2; i >=0; i--) {
        maxHeapFy(A, n, i);
    }
}

void heapSort2(int *A, int n) {
    int m = n-1;
    buildMaxHeap(A, n);
    for(int i = n; i>=1; i--){
        int aux = A[0];
        A[0] = A[i];
        A[i] = aux;
        m--;
        maxHeapFy(A, m, 0);
    }
}

int * getVetorDecrescente (int n) {
    int *a = malloc(sizeof(int)*n);
    for(int i=0; i<n; i++) {
        a[i] = n-i;
    }
    return a;
}

int main() {
    int repeticoes = 15;
    int begin = 100000;
    int end = 10000000;
    int step = 10000;
    double tempo;
    for (int i = begin; i<=end; i+=step) {
        int *a = getVetorDecrescente(i);
        for(int j = 0; j<repeticoes; j++){
            clock_t start = clock();
            heapSort2(a, i);
            clock_t end = clock();
            tempo = (double)(end-start)/CLOCKS_PER_SEC;
            printf("%d\t%d\t%.10f\n", (j+1, i, tempo));
        }
        free(a);
    }
    return 0;
}