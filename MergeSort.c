#include <stdio.h>
#include <stdlib.h>

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int array[], int inicio, int meio, int tamanho)
{
    int i, j, k;
    int n1 = meio - inicio + 1;
    int n2 = tamanho - meio;

    // Create temp arrays
    int L[n1], R[n2];

    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = array[inicio + i];
    for (j = 0; j < n2; j++)
        R[j] = array[meio + 1 + j];

    // Merge the temp arrays back into arr[l..r
    i = 0;
    j = 0;
    k = inicio;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        }
        else {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[],
    // if there are any
    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[],
    // if there are any
    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }
}

// l = inicio, r = tamanho



void mergeSort(int array[], int inicio, int tamanho)
{
    if (inicio < tamanho) {
        int meio = inicio + (tamanho - inicio) / 2;

        // Sort first and second halves
        mergeSort(array, inicio, meio);
        mergeSort(array, meio + 1, tamanho);

        merge(array, inicio, meio, tamanho);
    }
}


void MergeSort(int array[], int tamanho){
    mergeSort(array, 0, tamanho);
}
