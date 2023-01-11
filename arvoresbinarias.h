#ifndef ARVORESBINARIAS_H
#define ARVORESBINARIAS_H

struct produto
{
    int matricula;
    int tipo;
    float preco;
    int estoque;
    struct produto *esq;
    struct produto *dir;
};

typedef struct produto arvore_produtos;

arvore_produtos *criar_arvore();
arvore_produtos *busca(arvore_produtos* raiz, int matricula);
arvore_produtos *venda(arvore_produtos *no, int quantidade);
void cadastrar(arvore_produtos *raiz, int matricula, int tipo, float preco, int estoque);
void excluir(arvore_produtos *raiz, int matricula);
arvore_produtos *alteracao(arvore_produtos *no, int opcao, float valor);

#endif