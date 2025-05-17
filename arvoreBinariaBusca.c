#include "arvoreBinariaBusca.h"
#include<stdio.h>
#include<stdlib.h>

void ArvoreBinariaBusca_inicializacao(ArvoreBinariaBusca *arvore)
{
    arvore->raiz = NULL;
}

No *criarNo(int elem)
{
    No *novoNo = (No*)malloc(1 * sizeof(No));

    if(novoNo == NULL)
    {
        printf("\nErro na alocacao de memoria!\n");
        return NULL;
    }

    novoNo->valor = elem;
    novoNo->esq = NULL;
    novoNo->dir = NULL;

    return novoNo;

}

No *inserirNoRec(No *raiz, int elem)
{
    if(raiz == NULL)
    {
        return criarNo(elem);

    }

    if(raiz->valor == elem)
    {
        return raiz;
    }

    if(elem < raiz->valor)
    {
        raiz->esq = inserirNoRec(raiz->esq, elem);

    }else{

        raiz->dir = inserirNoRec(raiz->dir, elem);

    }

    return raiz;

}

void inserirRec(ArvoreBinariaBusca *arvore, int elem)
{
    arvore->raiz = inserirNoRec(arvore->raiz, elem);
}

No *inserirNoIter(No *raiz, int elem)
{
    if(raiz == NULL)
    {
        return criarNo(elem);
    }

    No *atual = raiz;
    No *pai = NULL;

    while(atual != NULL)
    {
        pai = atual;

        if(elem < atual->valor)
        {
            atual = atual->esq;

        }else if(elem > atual->valor)
        {
            atual = atual->dir;

        }else{

            return raiz;
        }
    }

    if(elem < pai->valor)
    {
        pai->esq = criarNo(elem);

    }else{

        pai->dir = criarNo(elem);
    }

    return raiz;

}

void inserirIter(ArvoreBinariaBusca *arvore, int elem)
{
    arvore->raiz = inserirNoIter(arvore->raiz, elem);
}

void imprimirEmOrdem(No *raiz)
{
    if(raiz != NULL)
    {
        imprimirEmOrdem(raiz->esq);
        printf("%d ", raiz->valor);
        imprimirEmOrdem(raiz->dir);

    }
}

void imprimirPreOrdem(No *raiz)
{
    if(raiz != NULL)
    {
        printf("%d ", raiz->valor);
        imprimirPreOrdem(raiz->esq);
        imprimirPreOrdem(raiz->dir);
    }
}

void imprimirPosOrdem(No *raiz)
{
    if(raiz != NULL)
    {
        imprimirPosOrdem(raiz->esq);
        imprimirPosOrdem(raiz->dir);
        printf("%d ", raiz->valor);
    }
}

int calcularNivel(No *raiz, int elem, int nivel)
{
    No *atual = raiz;

    if(atual == NULL)
    {
        return -1;
    }

    if(atual->valor == elem)
    {
        return nivel;

    }else{

        if(elem < atual->valor)
        {
            return calcularNivel(atual->esq, elem, nivel+1);

        }else if(elem > atual->valor){

            return calcularNivel(atual->dir, elem, nivel+1);

        }
    }

}

No *buscarPai(No *raiz, int elem)
{
    No *atual = raiz;

    if(atual == NULL || (atual->esq == NULL && atual->dir == NULL))
    {
        return NULL;
    }

    if((atual->esq != NULL && atual->esq->valor == elem) || (atual->dir != NULL && atual->dir->valor == elem))
    {
        return atual;

    }else{

        if(elem < atual->valor)
        {
            return buscarPai(atual->esq, elem);

        }else{

            return buscarPai(atual->dir, elem);
        }

    }

}

No *buscarElemento(No *raiz, int elem)
{
    if(raiz == NULL)
    {
        return NULL;
    }

    if(raiz->valor == elem)
    {
        return raiz;
    }

    if(elem < raiz->valor)
    {
        return buscarElemento(raiz->esq, elem);

    }else{

        return buscarElemento(raiz->dir, elem);
    }
}
