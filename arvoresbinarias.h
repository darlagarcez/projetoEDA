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

typedef struct produto Produtos;

struct tipo_produto {
    int codigo;
    struct tipo_produto* proximo;
};

typedef struct tipo_produto Tipo_produto;

Produtos* criar_arvore();
Tipo_produto* criar_lista();
Tipo_produto* cadastrar_tipo(TipoProduto* lista, int codigo);
Produtos* busca(Produtos* raiz, int matricula);
Produtos* venda(Produtos* no, int quantidade);
void cadastrar(Produtos** raiz, int matricula, int tipo, float preco, int estoque, int op);
void excluir(Produtos** raiz, int matricula);
Produtos* menor_valor(Produtos* raiz);
Produtos* alteracao(Produtos* no, int opcao, float valor);
int quantidade_produtos(Produtos* raiz);
void em_ordem_tipo(Produtos* raiz, int tipo);
void em_ordem_vendas(Produtos* raiz);

#endif