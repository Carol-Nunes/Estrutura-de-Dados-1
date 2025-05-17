#include "arvoreBinariaBusca.c"
#include<stdio.h>

int main()
{

    ArvoreBinariaBusca arvore;
    ArvoreBinariaBusca_inicializacao(&arvore);

    /*
    inserirRec(&arvore, 10);
    inserirRec(&arvore, 8);
    inserirRec(&arvore, 7);
    inserirRec(&arvore, 15);
    inserirRec(&arvore, 16);
    inserirRec(&arvore, 14);

    */

    inserirIter(&arvore, 10);
    inserirIter(&arvore, 8);
    inserirIter(&arvore, 7);
    inserirIter(&arvore, 15);
    inserirIter(&arvore, 16);
    inserirIter(&arvore, 14);

    printf("\nImpressao em Ordem:\n");
    imprimirEmOrdem(arvore.raiz);
    printf("\nImpresssao em Pre-Ordem:\n");
    imprimirPreOrdem(arvore.raiz);
    printf("\nImpressao em Pos-Ordem:\n");
    imprimirPosOrdem(arvore.raiz);

    printf("\nNivel: %d\n", calcularNivel(arvore.raiz, 8, 0));


    int valor = 1;
    No *pai = buscarPai(arvore.raiz, valor);

    if(pai == NULL)
    {
        printf("\nPai do %d nao encontrado(raiz ou inexistente)\n", valor);

    }else{

        printf("\nPai do %d: %d\n", valor, pai->valor);

    }

    No *encontrado = buscarElemento(arvore.raiz, valor);

    if(encontrado == NULL)
    {
        printf("\nNo %d nao encontrado!\n", valor);

    }else{

        printf("\n%d\n", encontrado->valor);

    }

    return 0;
}
