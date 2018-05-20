#include<stdio.h>
#include <stdlib.h>

typedef struct no
{
    int data;
    struct no *esq,*dir;
    int alt;
}no;

no *inserir(no *,int);
no *deletar(no *,int);
void preordem(no *);
void inordem(no *);
void posordem(no *);
int altura( no *);
no *rotacaodireita(no *);
no *rotacaoesquerda(no *);
no *rotacaodupladireita(no *);
no *rotacaoduplaesquerda(no *);
no *rotacaoesquerdadireita(no *);
no *rotacaodireitaesquerda(no *);
int balancoarvore(no *);

int main()
{
    no *root=NULL;
    int x,n,i,op;

    do
    {
        printf("\n1)Criar Arvore:");
        printf("\n2)Inserir Nodos:");
        printf("\n3)Deletar Nodo:");
        printf("\n4)Imprimir:");
        printf("\n5)Sair:");
        printf("\n\nDigite a sua opcao:");
        scanf("%d",&op);

        switch(op)
        {
            case 1: printf("\nDigite o numero de elementos:");
                scanf("%d",&n);
                printf("\nDigite o numero do nodo:");
                root=NULL;
                for(i=0;i<n;i++)
                {
                    scanf("%d",&x);
                    root=inserir(root,x);
                }
                break;

            case 2: printf("\nDigite o numero do nodo:");
                scanf("%d",&x);
                root=inserir(root,x);
                break;

            case 3: printf("\nDigite o numero do nodo:");
                scanf("%d",&x);
                root=deletar(root,x);
                break;

            case 4: printf("\nSequencia Pre-ordem:\n");
                preordem(root);
                printf("\n\nSequencia In-ordem:\n");
                inordem(root);
                printf("\n\nSequencia Pos-ordem:\n");
                posordem(root);
                printf("\n");
                break;
            default:
                return 0;
        }
    }while(op!=5);

    return 0;
}

no * inserir(no *T,int x)
{
    if(T==NULL)
    {
        T=(no*)malloc(sizeof(no));
        T->data=x;
        T->esq=NULL;
        T->dir=NULL;
    }
    else
    if(x > T->data)        // Insere na subarvore da direita
    {
        T->dir=inserir(T->dir,x);
        if(balancoarvore(T)==-2)
            if(x>T->dir->data)
                T=rotacaodupladireita(T);
            else
                T=rotacaodireitaesquerda(T);
    }
    else
    if(x<T->data)
    {
        T->esq=inserir(T->esq,x);
        if(balancoarvore(T)==2)
            if(x < T->esq->data)
                T=rotacaoduplaesquerda(T);
            else
                T=rotacaoesquerdadireita(T);
    }

    T->alt=altura(T);

    return(T);
}

no * deletar(no *T,int x)
{
    no *p;

    if(T==NULL)
    {
        return NULL;
    }
    else
    if(x > T->data)        // insere na subarvore da direita
    {
        T->dir=deletar(T->dir,x);
        if(balancoarvore(T)==2)
            if(balancoarvore(T->esq)>=0)
                T=rotacaoduplaesquerda(T);
            else
                T=rotacaoesquerdadireita(T);
    }
    else
    if(x<T->data)
    {
        T->esq=deletar(T->esq,x);
        if(balancoarvore(T)==-2)    //Rebalanceia
            if(balancoarvore(T->dir)<=0)
                T=rotacaodupladireita(T);
            else
                T=rotacaodireitaesquerda(T);
    }
    else
    {
        //numero a ser deletado é encontrado
        if(T->dir!=NULL)
        {    //Deleta o sucessor do in-ordem
            p=T->dir;

            while(p->esq!= NULL)
                p=p->esq;

            T->data=p->data;
            T->dir=deletar(T->dir,p->data);

            if(balancoarvore(T)==2)//rebalanceia
                if(balancoarvore(T->esq)>=0)
                    T=rotacaoduplaesquerda(T);
                else
                    T=rotacaoesquerdadireita(T);\
                }
        else
            return(T->esq);
    }
    T->alt=altura(T);
    return(T);
}

int altura(no *T)
{
    int lh,rh;
    if(T==NULL)
        return(0);

    if(T->esq==NULL)
        lh=0;
    else
        lh=1+T->esq->alt;

    if(T->dir==NULL)
        rh=0;
    else
        rh=1+T->dir->alt;

    if(lh>rh)
        return(lh);

    return(rh);
}

no * rotacaodireita(no *x)
{
    no *y;
    y=x->esq;
    x->esq=y->dir;
    y->dir=x;
    x->alt=altura(x);
    y->alt=altura(y);
    return(y);
}

no * rotacaoesquerda(no *x)
{
    no *y;
    y=x->dir;
    x->dir=y->esq;
    y->esq=x;
    x->alt=altura(x);
    y->alt=altura(y);

    return(y);
}

no * rotacaodupladireita(no *T)
{
    T=rotacaoesquerda(T);
    return(T);
}

no * rotacaoduplaesquerda(no *T)
{
    T=rotacaodireita(T);
    return(T);
}

no * rotacaoesquerdadireita(no *T)
{
    T->esq=rotacaoesquerda(T->esq);
    T=rotacaodireita(T);

    return(T);
}

no * rotacaodireitaesquerda(no *T)
{
    T->dir=rotacaodireita(T->dir);
    T=rotacaoesquerda(T);
    return(T);
}

int balancoarvore(no *T)
{
    int lh,rh;
    if(T==NULL)
        return(0);

    if(T->esq==NULL)
        lh=0;
    else
        lh=1+T->esq->alt;

    if(T->dir==NULL)
        rh=0;
    else
        rh=1+T->dir->alt;

    return(lh-rh);
}

void preordem(no *T)
{
    if(T!=NULL)
    {
        printf("%d(Balanco=%d)",T->data,balancoarvore(T));
        preordem(T->esq);
        preordem(T->dir);
    }
}

void inordem(no *T)
{
    if(T!=NULL)
    {
        inordem(T->esq);
        printf("%d(Balanco=%d)",T->data,balancoarvore(T));
        inordem(T->dir);
    }
}

void posordem(no *T)
{
    if(T!=NULL)
    {
        posordem(T->esq);
        posordem(T->dir);
        printf("%d(Balanco=%d)",T->data,balancoarvore(T));
    }
}