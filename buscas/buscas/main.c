#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

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

int * gerarArrayEmSequencia() {
    static int vetor[1000];
    int base = 0;
    for (int i = 0; i < 1000; ++i) {
        base += rand() % 100;
        vetor[i] = base;
    }
    return vetor;
}

int main() {
    int *pVetor, posBusca;

    pVetor = gerarArrayEmSequencia();
    for (int i = 0; i < 1000; ++i) {
        printf( "vetor[%d] = %d\n", i, pVetor[i]);
    }
//    posBusca = buscaSequencial(47132, 1000, pVetor);
    posBusca = buscaBinaria(47132, 1000, pVetor);

    printf("%d", posBusca);
    return 0;
}