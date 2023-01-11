#ifndef MENU_H
#define MENU_H

struct usuarios
{
    int matricula;
    char senha[21];
};

typedef struct usuarios Usuarios;

void limpar_tela();
void gotoxy(int x,int y);
void pausar_tela(int x, int y);
int menu_login(Usuarios usuarios[]);
int menu_cadastro(Usuarios usuarios[]);
void menu_acoes();
void menu_produtos(arvore_produtos *raiz);
void menu_relatorio(arvore_produtos *raiz);
void exibir_produto(arvore_produtos *no);

#endif