#ifndef ARVOREBINARIA_H
#define ARVOREBINARIA_H

typedef struct _no{

    int valor;
    struct _no *esq;
    struct _no *dir;

}No;


typedef struct _arvoreBinariaBusca{

    No *raiz;

}ArvoreBinariaBusca;


void ArvoreBinariaBusca_inicializacao(ArvoreBinariaBusca *arvore);

No *criarNo(int elem);

No *inserirNoRec(No *raiz, int elem);
void inserirRec(ArvoreBinariaBusca *arvore, int elem);
No *inserirNoIter(No *raiz, int elem);
void inserirIter(ArvoreBinariaBusca *arvore, int elem);

void imprimirEmOrdem(No *raiz);
void imprimirPreOrdem(No *raiz);
void imprimirPosOrdem(No *raiz);

int calcularNivel(No *raiz, int elem, int nivel);

No *buscarPai(No *raiz, int elem);
No *buscarElemento(No *raiz, int elem);

#endif
