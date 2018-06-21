#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define ARRAY_SIZE 1000

int buscaSequencial (int valor, int tamanhoVetor, int *v) {
    for (int i = 0; i < tamanhoVetor-1; ++i) {
        if(*(v + i) == valor) {
            return i;
        }
    }
    return -1;
}

int buscaBinaria (int valor, int tamanhoVetor, int *v) {
    int esq, meio, dir;
    esq = 0;
    dir = tamanhoVetor - 1;
    while (esq <= dir) {
        meio = (esq + dir)/2;
        if (*(v + meio) == valor) {
            return meio;
        }
        if (*(v + meio) < valor) {
            esq = meio + 1;
        } else {
            dir = meio - 1;
        }
    }
    return -1;
}

int * gerarArrayOrdenado() {
    static int vetor[ARRAY_SIZE];
    int base = 0;
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        base += rand() % 100;
        vetor[i] = base;
    }
    return vetor;
}

void embaralhar(int *v) {
    for (int i = ARRAY_SIZE - 2; i > 0; i--) {
        int j = rand() % (i + 1);
        int tmp = v[j];
        v[j] = v[i];
        v[i] = tmp;
    }
}

void imprimirArray(int *arr, int size) {
    int i;
    for (i=0; i < 5; i++) {
        printf( "vetor[%d] = %d\n", i, arr[i]);
    }
    for (i=size-5; i < size; i++) {
        printf( "vetor[%d] = %d\n", i, arr[i]);
    }
}

/* Troca 2 numeros nos sorts */
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

/* SELECTION SORT */

void selectionSort(int *arr, int n)
{
    int i, j, min_idx;

    for (i = 0; i < n-1; i++)
    {
        // Acha o menor elemento e testa sempre
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        // Swap!!
        swap(&arr[min_idx], &arr[i]);
    }
}
/* GNOME (OU STUPID) SORT */
void gnomeSort(int *arr, int n)
{
    int index = 0;

    while (index < n) {
        if (index == 0)
            index++;
        if (arr[index] >= arr[index - 1])
            index++;
        else {
            swap(&arr[index], &arr[index - 1]);
            index--;
        }
    }
}

/* QUICK SORT */

int particao (int *arr, int indiceInicial, int indiceFinal)
{
    int pivot = arr[indiceFinal];    // pivot
    int i = (indiceInicial - 1);  // Indice do menor elemento

    for (int j = indiceInicial; j <= indiceFinal- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[indiceFinal]);
    return (i + 1);
}

void quickSort(int *arr, int indiceInicial, int indiceFinal)
{
    if (indiceInicial < indiceFinal)
    {
        int pi = particao(arr, indiceInicial, indiceFinal);

        quickSort(arr, indiceInicial, pi - 1);
        quickSort(arr, pi + 1, indiceFinal);
    }
}

/* SHELLSORT */

void shellSort(int *arr, int n)
{
    for (int espaco = n/2; espaco > 0; espaco /= 2)
    {
        for (int i = espaco; i < n; i += 1)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= espaco && arr[j - espaco] > temp; j -= espaco) {
                arr[j] = arr[j - espaco];
            }
            arr[j] = temp;
        }
    }
}

/* MERGE SORT */

void merge(int arr[], int esq, int pontoMedio, int dir)
{
    int i, j, k;
    int n1 = pontoMedio - esq + 1;
    int n2 =  dir - pontoMedio;

    /* create temp arrays */
    int ESQ[n1], DIR[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        ESQ[i] = arr[esq + i];
    for (j = 0; j < n2; j++)
        DIR[j] = arr[pontoMedio + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = esq; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (ESQ[i] <= DIR[j])
        {
            arr[k] = ESQ[i];
            i++;
        }
        else
        {
            arr[k] = DIR[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = ESQ[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = DIR[j];
        j++;
        k++;
    }
}

void mergeSort(int *arr, int esq, int dir)
{
    if (esq < dir)
    {
        int pontoMedio = esq+(dir-esq)/2;

        // Ordena cada uma das metades
        mergeSort(arr, esq, pontoMedio);
        mergeSort(arr, pontoMedio+1, dir);

        merge(arr, esq, pontoMedio, dir);
    }
}

int main() {
    int *pVetor, posBusca;

    pVetor = gerarArrayOrdenado();
    embaralhar(pVetor);
    imprimirArray(pVetor, ARRAY_SIZE);
//    selectionSort(pVetor, ARRAY_SIZE);
//    gnomeSort(pVetor, ARRAY_SIZE);
//    quickSort(pVetor, 0, ARRAY_SIZE-1);
//    shellSort(pVetor, ARRAY_SIZE);
    mergeSort(pVetor, 0, ARRAY_SIZE-1);
    imprimirArray(pVetor, ARRAY_SIZE);

//    posBusca = buscaSequencial(47132, ARRAY_SIZE, pVetor);
//    posBusca = buscaBinaria(47132, ARRAY_SIZE, pVetor);


//    printf("%d", posBusca);
    return 0;
}