#ifndef ARVORESBINARIAS_H
#define ARVORESBINARIAS_H

struct produto
{
    int matricula;
    int tipo;
    float preco;
    int estoque;
    int vendas;
    struct produto* esq;
    struct produto* dir;
};

struct produto* criar_arvore();
struct produto* busca(struct produto* raiz, int matricula);
struct produto* venda(struct produto* no, int quantidade);
struct produto* cadastrar(struct produto* raiz, int matricula, int tipo, float preco, int estoque);
struct produto* excluir(struct produto* atual, , struct produto* anterior, int matricula);
struct produto* alteracao(struct produto* no, int opcao, float valor);
int quantidade_produtos(struct produto* raiz);
void em_ordem_tipo(struct produto* raiz, int tipo);
void em_ordem_vendas(struct produto* raiz);

#endif