#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoesextras.h"

#ifdef __linux__
    #include <unistd.h>
#elif _WIN32
    #include <Windows.h>
#elif _WIN64
    #include <Windows.h>
#else

#endif

void limpar_tela();
void gotoxy(int x,int y);
void pausar_tela(int segundos);
void centraliza(char string[]);

void limpar_tela()
{
    #ifdef __linux__
        system("clear");
    #elif _WIN32 
        system("cls");
    #elif _WIN64
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
    #elif _WIN64
        COORD coord;
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    #else

    #endif
}

void pausar_tela(int segundos)
{
    #ifdef __linux__
        sleep(segundos);
    #elif _WIN32 
        sleep(segundos);
    #elif _WIN64
        sleep(segundos);
    #else

    #endif
}

void centraliza(char string[])
{
    int tam = strlen(string);
    int x = (135 - tam) / 2;
    gotoxy(x, 10);
    printf("%s", string);
}