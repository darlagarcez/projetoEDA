#ifndef MENU_H
#define MENU_H

#include "arvoresbinarias.h"

struct usuarios
{
    int matricula;
    char senha[21];
};

typedef struct usuarios Usuarios;

void inicializacao(Usuarios usuarios[]);
int menu_login(Usuarios usuarios[]);
int menu_cadastro(Usuarios usuarios[]);
void menu_acoes(Produtos* raiz, Tipo_produto* lista);
void menu_produtos(Produtos* raiz, Tipo_produto* lista);
void menu_relatorio(Produtos* raiz, Tipo_produto* lista);

#endif