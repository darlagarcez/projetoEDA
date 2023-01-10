#ifndef ARVORESBINARIAS_H
#define ARVORESBINARIAS_H

struct produto
{
    int matricula;
    int tipo;
    float preco;
    struct produto *esq;
    struct produto *dir;
};

typedef struct produto arvore_produtos;

arvore_produtos *criar_arvore();
void inserir(arvore_produtos **raiz, int matricula, int tipo, float preco);

#endif