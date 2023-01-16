#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoesextras.h"

#ifdef __linux__
    #include <unistd.h>
#elif _WIN32
    #include <windows.h>
#elif _WIN64
    #include <windows.h>
#else

#endif

// DECLARACAO DE FUNCOES

void limpar_tela();
void gotoxy(int x,int y);
void pausar_tela(int segundos);

// FIM DAS DECLARACOES

// Funcao que limpa a tela
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

// Funcao que posiciona o cursor na tela
void gotoxy(int x,int y)
{
    #ifdef __linux__
        printf("%c[%d;%df",0x1B,y,x);
    #elif _WIN32 
        COORD coord;
        coord.X = x;
        coord.Y = y - 1;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    #elif _WIN64
        COORD coord;
        coord.X = x;
        coord.Y = y - 1;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    #else

    #endif
}

// Funcao que pausa a tela por um determinado tempo
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