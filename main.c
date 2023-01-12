#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

int main()
{
    int retorno;
    Usuarios usuarios[50];
    int opcao;

    do
    {
        limpar_tela();
        gotoxy(10,2);
        puts("ESCOLHA UMA ACAO: ");
        gotoxy(5,4);
        puts("1 - Login");
        gotoxy(5,5);
        puts("2 - Cadastro");
        gotoxy(5,7);
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
            case 1:
                retorno = menu_login(usuarios);
    
                while (retorno == 1)
                {
                    limpar_tela();
                    gotoxy(5,2);
                    puts("USUARIO OU SENHA INVALIDOS!");
                    gotoxy(5,3);
                    puts("POR FAVOR, TENTE NOVAMENTE");
                    pausar_tela(5,5);
                    retorno = menu_login(usuarios);
                }
                break;
        
            case 2:
                retorno = menu_cadastro(usuarios);

                if (retorno == 1)
                {
                    limpar_tela();
                    gotoxy(5,2);
                    puts("USUARIO JA CADASTRADO!");
                    gotoxy(5,3);
                    puts("Favor, realizar login");
                    pausar_tela(5,5);
                }
        }
    } while (retorno != 0);

    inicializacao();

    return 0;
}