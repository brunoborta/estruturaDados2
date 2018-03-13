#include <stdio.h>
#include <stdlib.h>

typedef struct NO* arvore_binaria;
typedef struct NO {
    int valor;
    struct NO *esquerda;
    struct NO *direita;
};

arvore_binaria* cria_arvore() {
    arvore_binaria* raiz = (arvore_binaria*) malloc(sizeof(arvore_binaria));
    if(raiz != NULL) {
        *raiz = NULL;
    }
    return raiz;
}

/**
 * Vai
 * @param no Um ponteiro para o no que deseja liberar
 */
void libera_no(struct NO* no) {
    if(no != NULL) {
        libera_no(no->esquerda);
        libera_no(no->direita);
        free(no);
    }
}

/**
 * Destroi toda a arvore binária
 * @param raiz Um ponteiro de ponteiro para o no raiz da arvore
 */
void destroi_arvore(arvore_binaria* raiz) {
    if(raiz != NULL) {
        libera_no(*raiz);
        free(raiz);
    }
}

int main() {
    arvore_binaria* raiz = cria_arvore();
    return 0;
}