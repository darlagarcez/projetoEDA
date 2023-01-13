#ifndef MENU_H
#define MENU_H

#include "arvoresbinarias.h"

struct usuarios
{
    int CPF;
    char senha[21];
};

typedef struct usuarios Usuarios;

void inicializacao(Usuarios usuarios[]);
int menu_login(Usuarios usuarios[]);
int menu_cadastro(Usuarios usuarios[]);
void menu_acoes(Produtos* raiz);
void menu_produtos(Produtos* raiz);
void menu_relatorio(Produtos* raiz);
void exibir_produto(Produtos* no);

#endif