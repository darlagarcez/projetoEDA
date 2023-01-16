#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoesextras.h"
#include "arvoresbinarias.h"

Produtos* criar_arvore();
Tipo_produto* criar_lista();
void cadastrar_tipo(Tipo_produto** lista, int codigo);
Tipo_produto* busca_tipo(Tipo_produto* lista, int codigo);
Produtos* busca(Produtos* raiz, int matricula, int op);
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

Tipo_produto* criar_lista()
{
    return NULL;
}

void cadastrar_tipo(Tipo_produto** lista, int codigo)
{
    Tipo_produto* novo = (Tipo_produto*) malloc(sizeof(Tipo_produto));
    novo->codigo = codigo;
    novo->proximo = *lista;
    *lista = novo;
}

Tipo_produto* busca_tipo(Tipo_produto* lista, int codigo)
{
    Tipo_produto* auxiliar;
    int tipo_encontrado = 1;

    for (auxiliar = lista; auxiliar != NULL; auxiliar = auxiliar->proximo)
    {
        if (auxiliar->codigo == codigo)
        {
            tipo_encontrado = 0;
            return auxiliar;
        }
    }
    if (tipo_encontrado == 1)
    {
        return NULL;
    }
}

// Funcao que busca um no na arvore a partir da matricula
Produtos* busca(Produtos* raiz, int matricula, int op)
{
    if (raiz == NULL)
        return NULL;
    else if (raiz->matricula == matricula)
    {
        if (op == 1)
            return raiz;
        else
        {
            limpar_tela();
            printf(" PRODUTO TIPO %d\n\n", raiz->tipo);
            printf(" Matricula--------------%d\n", raiz->matricula);
            printf(" Preco------------------R$ %.2f\n", raiz->preco);
            printf(" Estoque----------------%d\n", raiz->estoque);
            printf(" Vendas-----------------%d\n\n", raiz->vendas);
            getchar();
            printf("Pressione qualquer tecla para continuar...");
            getchar();
            return raiz;
        }
    }
    else if (raiz->matricula > matricula)
        return busca(raiz->esq, matricula, op);
    else
        return busca(raiz->dir, matricula, op);
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
            puts(" PRODUTO CADASTRADO!");
            pausar_tela(1);
        }
    }
    else if (matricula < (*raiz)->matricula)
        cadastrar(&((*raiz)->esq), matricula, tipo, preco, estoque, op);
    else if (matricula > (*raiz)->matricula)
        cadastrar(&((*raiz)->dir), matricula, tipo, preco, estoque, op);
    else
    {
        limpar_tela();
        puts(" MATRICULA JÁ CADASTRADA!");
        pausar_tela(1);
    }
}

// Funcao que exclui um no da arvore
void excluir(Produtos** raiz, int matricula)
{
    if (*raiz == NULL)
    {
        limpar_tela();
        puts(" MATRICULA NAO ENCONTRADA!");
        pausar_tela(1);
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
        puts(" PRODUTO EXCLUIDO!");
        pausar_tela(1);
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
    {
        no->tipo = (int)valor;
        limpar_tela();
        puts(" TIPO DO PRODUTO ALTERADO!");
        pausar_tela(1);
    }
    else if (opcao == 2)
    {
        no->preco = valor;
        limpar_tela();
        puts(" PRECO DO PRODUTO ALTERADO!");
        pausar_tela(1);
    }
    else if (opcao == 3)
    {
        no->estoque = (int)valor;
        limpar_tela();
        puts(" ESTOQUE DO PRODUTO ALTERADO!");
        pausar_tela(1);
    }
}

int quantidade_produtos(Produtos* raiz)
{
    if (raiz == NULL)
        return 0;
    else 
        return 1 + quantidade_produtos(raiz->esq) + quantidade_produtos(raiz->dir);
}

void em_ordem_tipo(Produtos* raiz, int tipo)
{
    if (raiz == NULL)
        printf(" A arvore esta vazia, nao ha produtos para serem exibidos.\n");
    else
    {
        if (raiz->esq != NULL)
            em_ordem_tipo(raiz->esq, tipo);
        
        if (raiz->tipo == tipo)
        {
            printf(" %d", raiz->matricula);
            printf("%14.2f", raiz->preco);
            printf("%10d", raiz->estoque);
            puts("");
        }

        if (raiz->dir != NULL)
            em_ordem_tipo(raiz->dir, tipo);
    }
}

void em_ordem_vendas(Produtos* raiz)
{
    if (raiz == NULL)
        printf(" A arvore esta vazia, nao ha produtos para serem exibidos.\n");
    else
    {
        if (raiz->esq != NULL)
            em_ordem_vendas(raiz->esq);

        printf(" %d", raiz->matricula);
        printf("%13d", raiz->tipo);
        printf("%8.2f", raiz->preco);
        printf("%10d", raiz->estoque);
        printf("%9d", raiz->vendas);
        puts("");

        if (raiz->dir != NULL)
            em_ordem_vendas(raiz->dir);
    }
}