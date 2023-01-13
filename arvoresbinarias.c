#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoesextras.h"
#include "arvoresbinarias.h"


Produtos* criar_arvore();
Produtos* busca(Produtos* raiz, int matricula);
Produtos* venda(Produtos* no, int quantidade);
void cadastrar(Produtos** raiz, int matricula, int tipo, float preco, int estoque, int op);
void excluir(Produtos** raiz, int matricula);
Produtos* menor_valor(Produtos* raiz);
Produtos* alteracao(Produtos* no, int opcao, float valor);
int quantidade_produtos(Produtos* raiz);
void em_ordem_tipo(Produtos* raiz, int tipo);
void em_ordem_vendas(Produtos* raiz);

// Funcao que cria uma arvore
Produtos* criar_arvore()
{
    Produtos* raiz = NULL;
    return raiz;
}

// Funcao que busca um no na arvore a partir da matricula
Produtos* busca(Produtos* raiz, int matricula)
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

Produtos* venda(Produtos* no, int quantidade)
{
    no->estoque = no->estoque - quantidade;
    no->vendas = no->vendas + quantidade;
}

// Funcao que cadastra um novo no na arvore
void cadastrar(Produtos** raiz, int matricula, int tipo, float preco, int estoque, int op)
{
    if (*raiz == NULL)
    {
        *raiz = (Produtos*) malloc(sizeof(Produtos));
        (*raiz)->matricula = matricula;
        (*raiz)->tipo = tipo;
        (*raiz)->preco = preco;
        (*raiz)->estoque = estoque;
        (*raiz)->vendas = 0;
        (*raiz)->esq = NULL;
        (*raiz)->dir = NULL;
        if (op == 1)
        {
            limpar_tela();
            gotoxy(10,2);
            puts("PRODUTO ALTERADO!");
            pausar_tela(5,4);
        }
    }
    else if (matricula < (*raiz)->matricula)
        cadastrar(&((*raiz)->esq), matricula, tipo, preco, estoque, op);
    else if (matricula > (*raiz)->matricula)
        cadastrar(&((*raiz)->dir), matricula, tipo, preco, estoque, op);
    else
    {
        limpar_tela();
        gotoxy(10,2);
        puts("MATRICULA JÁ CADASTRADA!");
        pausar_tela(5,4);
    }
}

// Funcao que exclui um no da arvore
void excluir(Produtos** raiz, int matricula)
{
    if (*raiz == NULL)
    {
        limpar_tela();
        gotoxy(10,2);
        puts("MATRICULA NAO ENCONTRADA!");
        pausar_tela(5,4);
    }
    else if (matricula < (*raiz)->matricula)
        excluir(&(*raiz)->esq, matricula);
    else if (matricula > (*raiz)->matricula)
        excluir(&(*raiz)->dir, matricula);
    else
    {
        Produtos* no_aux;

        if ((*raiz)->esq == NULL && (*raiz)->dir == NULL)
        {
            free(*raiz);
            *raiz = NULL;
        }
        else if ((*raiz)->esq == NULL)
        {
            no_aux = *raiz;
            *raiz = (*raiz)->dir;
            free(no_aux);
        }
        else if ((*raiz)->dir == NULL)
        {
            no_aux = *raiz;
            *raiz = (*raiz)->esq;
            free(no_aux);
        }
        else 
        {
            no_aux = menor_valor((*raiz)->dir);
            (*raiz)->matricula = no_aux->matricula;
            excluir(&(*raiz)->dir, no_aux->matricula);
        }

        limpar_tela();
        gotoxy(10,2);
        puts("PRODUTO EXCLUIDO!");
        pausar_tela(5,4);
    }
}

// Funcao que retorno o no mais a esquerda da arvore
Produtos* menor_valor(Produtos* raiz)
{
    Produtos* atual = raiz;

    while (atual->esq != NULL)
        atual = atual->esq;

    return atual;
}


// Funcao que altera um no da arvore
Produtos* alteracao(Produtos* no, int opcao, float valor)
{
    if (opcao == 1)
        no->tipo = (int)valor;
    else if (opcao == 2)
        no->preco = valor;
    else if (opcao == 3)
        no->estoque = (int)valor;
}

int quantidade_produtos(Produtos* raiz)
{
    if (raiz == NULL)
    {
        return 0;
    }
    else 
        return 1 + quantidade_produtos(raiz->esq) + quantidade_produtos(raiz->dir);
}

void em_ordem_tipo(Produtos* raiz, int tipo)
{
    if (raiz != NULL)
    {
        return em_ordem_tipo(raiz->esq, tipo);
        if (raiz->tipo == tipo)
            printf("     |\t\t%d\t\tR$ %.2f\t\t\t%d\t\t%d\t\t|\n", raiz->matricula, raiz->preco, raiz->estoque, raiz->vendas);
        em_ordem_tipo(raiz->dir, tipo);
    }
}

void em_ordem_vendas(Produtos* raiz)
{
    if (raiz != NULL)
    {
        em_ordem_vendas(raiz->esq);
        if (raiz->vendas != 0)
            printf("     |\t\t%d\t\t%d\t\tR$ %.2f\t\t\t%d\t\t%d\t\t|\n", raiz->matricula, raiz->tipo, raiz->preco, raiz->estoque, raiz->vendas);
        em_ordem_vendas(raiz->dir);
    }
}