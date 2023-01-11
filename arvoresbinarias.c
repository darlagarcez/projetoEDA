#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvoresbinarias.h"

arvore_produtos *criar_arvore();
arvore_produtos *busca(arvore_produtos *raiz, int matricula);
arvore_produtos *venda(arvore_produtos *no, int quantidade);
void cadastrar(arvore_produtos *raiz, int matricula, int tipo, float preco, int estoque);
void excluir(arvore_produtos *raiz, int matricula);
arvore_produtos *alteracao(arvore_produtos *no, int opcao, float valor);

arvore_produtos *criar_arvore()
{
    arvore_produtos* raiz = (arvore_produtos*) malloc(sizeof(arvore_produtos));

    if (raiz != NULL)
        *raiz = NULL;
    
    return raiz;
}

arvore_produtos *busca(arvore_produtos *raiz, int matricula)
{
    if (raiz == NULL)
        return raiz;
    else if (*raiz != NULL)
    {
        struct produto *atual = *raiz;

        while (atual != NULL)
        {
            if (atual->matricula == matricula)
                return atual;
            else if (atual->matricula > matricula)
                atual = atual->esq;
            else 
                atual = atual->dir;
        }
        if (atual == NULL)
        {
            return NULL;
        }
    }
}

arvore_produtos *venda(arvore_produtos *no, int quantidade)
{
    no_aux->estoque = no_aux->estoque - quantidade;
}

void cadastrar(arvore_produtos *raiz, int matricula, int tipo, float preco, int estoque)
{
    struct produto* novo;

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
        novo->estoque = estoque
        novo->esq = NULL;
        novo->dir = NULL;
        *raiz = novo;
    
        puts("PRODUTO CADASTRADO COM SUCESSO!\n");
    }
}

void excluir(arvore_produtos *raiz, int matricula)
{
    
        struct produto *atual = *raiz;
        struct produto *anterior = NULL;
        struct produto *no_aux;

        while (atual != NULL)
        {
            if (atual->matricula > matricula)
            {
                anterior = atual;
                atual = atual->esq;
            }
            else if (atual->matricula < matricula)
            {
                anterior = atual;
                atual = atual->dir;
            }
            else
            {
                if (atual->esq == NULL && atual->dir == NULL)
                {
                    atual = NULL;
                    free(atual);
                }
                else if (atual->esq != NULL && atual->dir == NULL)
                {
                    anterior->esq = atual->esq;
                    free(atual);
                }
                else if (atual->esq == NULL && atual->dir != NULL)
                {
                    anterior->esq = atual->dir;
                    free(atual);
                }
                else
                {
                    no_aux = atual;

                    while (no_aux->dir != NULL)
                        no_aux = no_aux->dir;

                    if (no_aux->esq != NULL)
                    {
                        no_aux->dir = no_aux->esq;

                        if (anterior->esq == atual)
                        {
                            anterior->esq = no_aux;
                        }
                        else if (anterior->dir == atual)
                        {
                            anterior->dir = no_aux;
                        }
                    }

                    free(atual);
                }
            }
        }
    
}

arvore_produtos *alteracao(arvore_produtos *no, int opcao, float valor)
{
    if (opcao == 1)
        no_aux->tipo = (int)valor;
    else if (opcao == 2)
        no_aux->preco = valor;
    else if (opcao == 3)
        no_aux->estoque = (int)valor;
}