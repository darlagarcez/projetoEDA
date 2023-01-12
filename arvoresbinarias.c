#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvoresbinarias.h"

/*arvore_produtos *criar_arvore();
arvore_produtos *busca(arvore_produtos *raiz, int matricula);
arvore_produtos *venda(arvore_produtos *no, int quantidade);
void cadastrar(arvore_produtos *raiz, int matricula, int tipo, float preco, int estoque);
void excluir(arvore_produtos *raiz, int matricula);
arvore_produtos *alteracao(arvore_produtos *no, int opcao, float valor);*/

struct produto *criar_arvore();
struct produto *busca(struct produto *raiz, int matricula);
struct produto *venda(struct produto *no, int quantidade);
void cadastrar(struct produto *raiz, int matricula, int tipo, float preco, int estoque);
void excluir(struct produto *raiz, int matricula);
struct produto *alteracao(struct produto *no, int opcao, float valor);


// Funcao que cria uma arvore
struct produto *criar_arvore()
{
    struct produto *raiz = (struct produto*) malloc(sizeof(struct produto));
    struct produto *raiz = NULL;
    return raiz;
}

// Funcao que busca um no na arvore a partir da matricula
struct produto *busca(struct produto* raiz, int matricula)
{
    if (raiz == NULL)
        return NULL;
    else if (raiz->matricula == matricula)
        return raiz;
    else if (raiz->matricula > matricula)
        return busca(raiz->esq, matricula);
    else
        return busca(raiz->dir, matricula);
}

struct produto* venda(struct produto* no, int quantidade)
{
    no->estoque = no->estoque - quantidade;
}

// Funcao que cadastra um novo no na arvore
void cadastrar(struct produto* raiz, int matricula, int tipo, float preco, int estoque)
{
    struct produto* novo;

    if (raiz != NULL)
    {
        if (raiz->matricula > matricula)
        {
            cadastrar(raiz->esq, matricula, tipo, preco, estoque);
        }
        else if (raiz->matricula < matricula)
        {
            cadastrar(raiz->dir, matricula, tipo, preco, estoque);
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
        novo->estoque = estoque;
        novo->esq = NULL;
        novo->dir = NULL;
        raiz = novo;
    
        puts("PRODUTO CADASTRADO COM SUCESSO!\n");
    }
}

// Funcao que exclui um no da arvore
void excluir(struct produto* raiz, int matricula)
{
    
        struct produto *atual = raiz;
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

struct produto* alteracao(struct produto* no, int opcao, float valor)
{
    if (opcao == 1)
        no->tipo = (int)valor;
    else if (opcao == 2)
        no->preco = valor;
    else if (opcao == 3)
        no->estoque = (int)valor;
}