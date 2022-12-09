#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
//#include "arvoresbinarias.h"

int main()
{
    int retorno;

    retorno = menu_login();
  
    while (retorno == 1)
    {
        limpar_tela();
        gotoxy(5,2);
        puts("USUARIO OU SENHA INVALIDOS!");
        gotoxy(5,3);
        puts("POR FAVOR, TENTE NOVAMENTE");
        pausar_tela(5,5);
        retorno = menu_login();
    }

    menu_acoes();

    return 0;
}