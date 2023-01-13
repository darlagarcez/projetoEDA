#include <stdio.h>
#include <stdlib.h>
#include "funcoesextras.h"

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