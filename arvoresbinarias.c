#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvoresbinarias.h"

arvore_produtos *criar_arvore();
void inserir(arvore_produtos **raiz, int matricula, int tipo, float preco);

arvore_produtos *criar_arvore()
{
    return NULL;
}

void inserir(arvore_produtos **raiz, int matricula, int tipo, float preco)
{
    struct produto *novo;

    if (*raiz != NULL)
    {
        if ((*raiz)->matricula > matricula)
        {
            inserir((&(*raiz)->esq), matricula, tipo, preco);
        }
        else if ((*raiz)->matricula < matricula)
        {
            inserir((&(*raiz)->dir), matricula, tipo, preco);
        }
        else
        {
            puts("MATRICULA JA CADASTRADA!\n");
        }
    }
    else
    {
        novo = (struct produto* ) malloc(sizeof(struct produto));
        novo->matricula = matricula;
        novo->tipo = tipo;
        novo->preco = preco;
        novo->esq = NULL;
        novo->dir = NULL;
        *raiz = novo;
    
        puts("PRODUTO CADASTRADO COM SUCESSO!\n");
    }
}

void excluir(arvore_produtos **raiz, int matricula)
{
    struct produto *anterior;

    if (*raiz != NULL)
    {
        if ((*raiz)->matricula > matricula)
        {
            excluir((&(*raiz)->esq), matricula);
        }
        else if ((*raiz)->matricula < matricula)
        {
            excluir((&(*raiz)->dir), matricula);
        }
        else
        {
            puts("MATRICULA JA CADASTRADA!\n");
        }
    }
}
