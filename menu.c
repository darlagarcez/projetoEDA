#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifdef _WIN32
    #include <windows.h>
#else

#endif

void limpar_tela();
void gotoxy(int x,int y);
void pausar_tela(int x, int y);
int menu_login();
void menu_acoes();
void menu_produtos();
void menu_relatorio();

void limpar_tela()
{
    #ifdef __linux__
        system("clear");
    #elif _WIN32
        system("cls");
    #else

    #endif
}

void gotoxy(int x,int y)
{
    #ifdef __linux__
        printf("%c[%d;%df",0x1B,y,x);
    #elif _WIN32
        COORD coord;
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    #else

    #endif
}

void pausar_tela(int x, int y)
{
    #ifdef __linux__
        getchar();
        gotoxy(x,y);
        printf("Pressione qualquer tecla para continuar...");
        getchar();
    #elif _WIN32
        system("pause");
    #else

    #endif
}

int menu_login()
{
    char usuario[20];
    char senha[20];

    limpar_tela();
    gotoxy(10,2);
    puts("LOGIN");
    gotoxy(5,4);
    puts("USUARIO: ");
    gotoxy(5,5);
    puts("SENHA: ");
    gotoxy(14,4);
    scanf("%[^\n]s", usuario);
    getchar();
    gotoxy(13,5);
    scanf("%[^\n]s", senha);

    if (strcmp(usuario, "123") == 0 && strcmp(senha, "123") == 0)
        return 0;
    else
        return 1;
}

void menu_acoes()
{
    int opcao;

    limpar_tela();
    gotoxy(10,2);
    puts("O QUE DESEJA ACESSAR: ");
    gotoxy(5,4);
    puts("1 - Produtos");
    gotoxy(5,5);
    puts("2 - Relatorios");
    gotoxy(5,7);
    printf("Opcao: ");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
        menu_produtos();
        break;
    
    case 2:
        menu_relatorio();
        break;

    default:
        break;
    }
}

void menu_produtos()
{
    int opcao;

    limpar_tela();
    gotoxy(10,2);
    puts("O QUE DESEJA REALIZAR EM PRODUTOS: ");
    gotoxy(5,4);
    puts("1 - Buscar");
    gotoxy(5,5);
    puts("2 - Vender");
    gotoxy(5,6);
    puts("3 - Cadastrar");
    gotoxy(5,7);
    puts("4 - Excluir");
    gotoxy(5,8);
    puts("5 - Alterar");
    gotoxy(5,10);
    printf("Opcao: ");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
        
        break;
    
    case 2:
        
        break;

    case 3:
        
        break;

    case 4:
        
        break;

    case 5:
        
        break;

    default:
        break;
    }
}

void menu_relatorio()
{
    int opcao;

    limpar_tela();
    gotoxy(10,2);
    puts("QUAL RELATORIO DESEJA VER: ");
    gotoxy(5,4);
    puts("1 - Por tipo de produto");
    gotoxy(5,5);
    puts("2 - De vendas");
    gotoxy(5,7);
    printf("Opcao: ");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
        int codigo_produto;

        limpar_tela();
        gotoxy(5,2);
        printf("Digite o codigo do produto: ");
        scanf("%d", &codigo_produto);
        break;
    
    case 2:
        
        break;

    default:
        break;
    }
}