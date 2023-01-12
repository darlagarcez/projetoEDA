#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvoresbinarias.h"

struct produto* criar_arvore();
struct produto* busca(struct produto* raiz, int matricula);
struct produto* venda(struct produto* no, int quantidade);
struct produto* cadastrar(struct produto* raiz, int matricula, int tipo, float preco, int estoque);
struct produto* excluir(struct produto* raiz, , struct produto* anterior, int matricula);
struct produto* alteracao(struct produto* no, int opcao, float valor);
int quantidade_produtos(struct produto* raiz);
void em_ordem_tipo(struct produto* raiz, int tipo);
void em_ordem_vendas(struct produto* raiz);

// Funcao que cria uma arvore
struct produto* criar_arvore()
{
    struct produto* raiz = (struct produto*) malloc(sizeof(struct produto));
    struct produto* raiz = NULL;
    return raiz;
}

// Funcao que busca um no na arvore a partir da matricula
struct produto* busca(struct produto* raiz, int matricula)
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
    no->vendas = no->vendas + quantidade;
}

// Funcao que cadastra um novo no na arvore
struct produto* cadastrar(struct produto* raiz, int matricula, int tipo, float preco, int estoque)
{
    struct produto* novo = busca(raiz, matricula);

    if (novo == NULL)
    {
        novo = (struct produto*) malloc(sizeof(struct produto));
        novo->matricula = matricula;
        novo->tipo = tipo;
        novo->preco = preco;
        novo->estoque = estoque;
        novo->vendas = 0;
        novo->esq = NULL;
        novo->dir = NULL;

        return novo;
    }
    else
        return NULL;
}

// Funcao que exclui um no da arvore
struct produto* excluir(struct produto* atual, struct produto* anterior, int matricula)
{
    struct produto* no_aux1;
    struct produto* no_aux2;

    if (atual == NULL) 
        return NULL;
    
    if (atual->matricula > matricula)
        atual->esq = excluir(atual->esq, atual, matricula);
    else if (atual->matricula < matricula)
        atual->esq = excluir(atual->esq, atual, matricula);
    else
    {
        if (atual->esq == NULL && atual->dir == NULL)
        {
            free(atual);
            return NULL;
        }
        else if (atual->esq != NULL && atual->dir == NULL)
        {
            if (anterior->esq == atual)
            {
                anterior->esq = atual->esq;
                free(atual);
                return (anterior->esq);
            }
            else if (anterior->dir == atual)
            {
                anterior->dir = atual->esq;
                free(atual);
                return (anterior->dir);
            }
        }
        else if (atual->esq == NULL && atual->dir != NULL)
        {
            if (anterior->esq == atual)
            {
                anterior->esq = atual->dir;
                free(atual);
                return (anterior->esq);
            }
            else if (anterior->dir == atual)
            {
                anterior->dir = atual->dir;
                free(atual);
                return (anterior->dir);
            }
        }
        else
        {
            no_aux1 = atual;

            while (no_aux1->dir != NULL)
                no_aux1 = no_aux->dir;

            if (no_aux1->esq != NULL)
            {
                no_aux2 = no_aux1->esq;
                no_aux2->esq = atual->esq;
                no_aux1->dir = atual->dir;
            }
            else
            {
                no_aux1->dir = atual->dir;
                no_aux1->esq = atual->esq;
            }

            if (anterior->esq == atual)
                anterior->esq = no_aux1;
            else if (anterior->dir == atual)
                anterior->dir = no_aux1;
            
            free(atual);
            return no_aux1;
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

int quantidade_produtos(struct produto* raiz)
{
    if (raiz == NULL)
    {
        return 0;
    }
    else 
        return 1 + quantidade_produtos(raiz->esq) + quantidade_produtos(raiz->dir);
}

void em_ordem_tipo(struct produto* raiz, int tipo)
{
    if (raiz != NULL)
    {
        return em_ordem_tipo(raiz->esquerdo, codigo_tipo_produto);
        if (raiz->tipo == tipo)
            printf("     |\t\t%d\t\tR$ %.2f\t\t\t%d\t\t%d\t\t|\n", raiz->matricula, raiz->preco, raiz->estoque, raiz->vendas);
        em_ordem_tipo(raiz->direito, codigo_tipo_produto);
    }
}

void em_ordem_vendas(struct produto* raiz)
{
    if (raiz != NULL)
    {
        em_ordem_vendas(raiz->esquerdo);
        if (raiz->vendas != 0)
            printf("     |\t\t%d\t\t%d\t\tR$ %.2f\t\t\t%d\t\t%d\t\t|\n", raiz->matricula, raiz->tipo, raiz->preco, raiz->estoque, raiz->vendas);
        em_ordem_vendas(raiz->direito);
    }
}