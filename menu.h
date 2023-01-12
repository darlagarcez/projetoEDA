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
void menu_produtos(struct produto* raiz);
void menu_relatorio(struct produto* raiz);
void exibir_produto(struct produto* no);

#endif