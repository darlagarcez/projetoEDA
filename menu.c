#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funcoesextras.h"
#include "menu.h"
#include "arvoresbinarias.h"

#ifdef _WIN32
    #include <windows.h>
#else

#endif

void inicializacao(Usuarios usuarios[]);
int menu_login(Usuarios usuarios[]);
int menu_cadastro(Usuarios usuarios[]);
void menu_acoes(Produtos* raiz);
void menu_produtos(Produtos* raiz);
void menu_relatorio(Produtos* raiz);
void exibir_produto(Produtos* no);

void inicializacao(Usuarios usuarios[])
{
    Produtos* raiz = criar_arvore();
    int retorno;
    int opcao;

    for (int i = 0; i < 50; i++)
    {
        usuarios[0].matricula = 0;
        strcpy(usuarios[0].senha, "0");
    }

    // usuario 1
    usuarios[0].matricula = 123;
    strcpy(usuarios[0].senha, "123");
    // usuario 2
    usuarios[1].matricula = 456;
    strcpy(usuarios[1].senha, "456");
    // usuario 3
    usuarios[2].matricula = 789;
    strcpy(usuarios[2].senha, "789");

    // cadastro de produtos
    cadastrar(&raiz, 123, 1, 10.00, 10, 0);
    cadastrar(&raiz, 456, 2, 20.00, 20, 0);
    cadastrar(&raiz, 789, 3, 30.00, 30, 0);
    cadastrar(&raiz, 147, 1, 40.00, 40, 0);
    cadastrar(&raiz, 258, 2, 50.00, 50, 0);
    cadastrar(&raiz, 369, 3, 60.00, 60, 0);
    cadastrar(&raiz, 159, 1, 70.00, 70, 0);
    cadastrar(&raiz, 357, 2, 80.00, 80, 0);
    cadastrar(&raiz, 951, 3, 90.00, 90, 0);
    cadastrar(&raiz, 753, 1, 100.00, 100, 0);

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

    menu_acoes(raiz);
}

int menu_login(Usuarios usuarios[])
{
    int usuario;
    char senha[21];
    int usuario_encontrado = 1;

    limpar_tela();
    gotoxy(10,2);
    puts("LOGIN");
    gotoxy(5,4);
    puts("USUARIO: ");
    gotoxy(5,5);
    puts("SENHA: ");
    gotoxy(14,4);
    scanf("%d", &usuario);
    getchar();
    gotoxy(13,5);
    scanf("%[^\n]s", senha);

    for (int i = 0; i < 50; i++)
    {
        if (usuarios[i].matricula == usuario && strcmp(senha, usuarios[i].senha) == 0)
            usuario_encontrado = 0;
    }

    if (usuario_encontrado == 0)
        return 0;
    else
        return 1;
}

int menu_cadastro(Usuarios usuarios[])
{
    int usuario;
    char senha[20];
    int usuario_encontrado = 1;

    limpar_tela();
    gotoxy(10,2);
    puts("CADASTRO");
    gotoxy(5,4);
    puts("USUARIO: ");
    gotoxy(5,5);
    puts("SENHA: ");
    gotoxy(14,4);
    scanf("%d", &usuario);
    getchar();
    gotoxy(13,5);
    scanf("%[^\n]s", senha);

    for (int i = 0; i < 50; i++)
    {
        if (usuarios[i].matricula == usuario)
            usuario_encontrado = 0;
    }

    if (usuario_encontrado == 0)
        return 1;
    else
    {
        for (int i = 0; i < 50; i++)
        {
            if (usuarios[i].matricula == 0 && strcmp(usuarios[i].senha, "0") == 0)
            {
                usuarios[i].matricula = usuario;
                strcpy(usuarios[i].senha, senha);
                return 0;
            }
        }
    }
}


void menu_acoes(Produtos* raiz)
{
    int opcao;

    do
    {
        limpar_tela();
        gotoxy(10,2);
        puts("ESCOLHA UMA AÇÃO: ");
        gotoxy(5,4);
        puts("1 - Acessar produtos");
        gotoxy(5,5);
        puts("2 - Acessar relatorios");
        gotoxy(5,6);
        puts("3 - Sair");
        gotoxy(5,8);
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            menu_produtos(raiz);
            break;
        
        case 2:
            menu_relatorio(raiz);
            break;

        case 3:
            limpar_tela();
            gotoxy(10,2);
            puts("PROGRAMA FINALIZADO!");
            break;

        default:
            limpar_tela();
            gotoxy(10,2);
            puts("OPCAO INVALIDA!");
            gotoxy(10,3);
            puts("Digite novamente:");
            pausar_tela(5,5);
            break;
        }
    } while (opcao != 3);
}

void menu_produtos(Produtos* raiz)
{
    int opcao, op;
    int matricula;
    int tipo;
    float preco;
    float valor;
    int estoque;
    Produtos* no_aux;

    do
    {
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
        gotoxy(5,9);
        puts("6 - Voltar");
        gotoxy(5,11);
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            limpar_tela();
            gotoxy(10,2);
            printf("DIGITE A MATRICULA DO PRODUTO: ");
            scanf("%d", &matricula);
            no_aux = busca(raiz, matricula);

            if (no_aux == NULL)
            {
                limpar_tela();
                gotoxy(10,2);
                puts("PRODUTO NAO ENCONTRADO!");
                gotoxy(10,3);
                puts("Tente novamente:");
                pausar_tela(5,5);
            }
            else
                exibir_produto(no_aux);
            break;
        
        case 2:
            limpar_tela();
            gotoxy(10,2);
            printf("DIGITE OS DADOS DA VENDA DO PRODUTO: ");
            gotoxy(5,4);
            printf("Matricula: ");
            gotoxy(5,5);
            printf("Quantidade: ");
            gotoxy(15,4);
            scanf("%d", &matricula);
            gotoxy(17,5);
            scanf("%.2f", &estoque);
            no_aux = busca(raiz, matricula);

            if (no_aux == NULL)
            {
                limpar_tela();
                gotoxy(10,2);
                puts("PRODUTO NAO ENCONTRADO!");
                gotoxy(10,3);
                puts("Tente novamente:");
                pausar_tela(5,5);
            }
            else
            {
                no_aux = venda(no_aux, estoque);
                limpar_tela();
                gotoxy(10,2);
                puts("PRODUTO VENDIDO!");
                pausar_tela(5,4);
            }
            break;

        case 3:
            limpar_tela();
            gotoxy(10,2);
            printf("DIGITE OS DADOS DO PRODUTO: ");
            gotoxy(5,4);
            printf("Matricula: ");
            gotoxy(5,5);
            printf("Tipo: ");
            gotoxy(5,6);
            printf("Preco: ");
            gotoxy(5,7);
            printf("Estoque: ");
            gotoxy(16,4);
            scanf("%d", &matricula);
            gotoxy(11,5);
            scanf("%d", &tipo);
            gotoxy(12,6);
            scanf("%f", &preco);
            gotoxy(14,7);
            scanf("%d", &estoque);

            cadastrar(&raiz, matricula, tipo, preco, estoque, 1);
            break;

        case 4:
            limpar_tela();
            gotoxy(10,2);
            printf("DIGITE A MATRICULA DO PRODUTO: ");
            scanf("%d", &matricula);

            excluir(&raiz, matricula);
            break;

        case 5:
            limpar_tela();
            gotoxy(10,2);
            printf("DIGITE A MATRICULA DO PRODUTO: ");
            scanf("%d", &matricula);
            no_aux = busca(raiz, matricula);

            if (no_aux == NULL)
            {
                limpar_tela();
                gotoxy(10,2);
                puts("PRODUTO NAO ENCONTRADO!");
                gotoxy(10,3);
                puts("Tente novamente:");
                pausar_tela(5,5);
            }
            else
            {
                limpar_tela();
                gotoxy(10,2);
                puts("QUAL ALTERACAO DESEJA FAZER NO PRODUTO?");
                gotoxy(5,4);
                puts("1 - Tipo do produto");
                gotoxy(5,5);
                puts("2 - Preco");
                gotoxy(5,6);
                puts("3 - Estoque");
                gotoxy(5,7);
                printf("Opcao: ");
                scanf("%d", &op);
                switch (op)
                {
                    case 1:
                        limpar_tela();
                        gotoxy(10,2);
                        printf("QUAL O NOVO TIPO DO PRODUTO? ");
                        scanf("%f", &valor);
                        no_aux = alteracao(no_aux, 1, valor);
                        break;

                    case 2:
                        limpar_tela();
                        gotoxy(10,2);
                        printf("QUAL O NOVO PRECO DO PRODUTO? ");
                        scanf("%f", &valor);
                        no_aux = alteracao(no_aux, 2, valor);
                        break;

                    case 3:
                        limpar_tela();
                        gotoxy(10,2);
                        printf("QUAL O NOVA QUANTIDADE DO ESTOQUE DO PRODUTO? ");
                        scanf("%f", &valor);
                        no_aux = alteracao(no_aux, 3, valor);
                        break;
                    default: 
                        limpar_tela();
                        gotoxy(10,2);
                        puts("OPCAO INVALIDA!");
                        gotoxy(10,3);
                        puts("Tente novamente:");
                        pausar_tela(5,5);
                        break;
                }
            }
            break;

        case 6:
            menu_acoes(raiz);
            break;

        default:
            limpar_tela();
            gotoxy(10,2);
            puts("OPCAO INVALIDA!");
            gotoxy(10,3);
            puts("Digite novamente:");
            pausar_tela(5,5);
            break;
        }
    } while (opcao != 6);
}

void menu_relatorio(Produtos* raiz)
{
    int opcao;
    int codigo_tipo_produto;

    do
    {
        limpar_tela();
        gotoxy(10,2);
        puts("QUAL RELATORIO DESEJA VER: ");
        gotoxy(5,4);
        puts("1 - Por tipo de produto");
        gotoxy(5,5);
        puts("2 - De vendas");
        gotoxy(5,6);
        puts("3 - Voltar");
        gotoxy(5,8);
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
            case 1:
                limpar_tela();
                gotoxy(5,2);
                printf("Digite o codigo do tipo do produto: ");
                scanf("%d", &codigo_tipo_produto);
                limpar_tela();
                pausar_tela(5,2);
                break;
        
            case 2:
                limpar_tela();
                pausar_tela(5,2);
                break;

            case 3:
                menu_acoes(raiz);
                break;

            default:
                limpar_tela();
                gotoxy(10,2);
                puts("OPCAO INVALIDA!");
                gotoxy(10,3);
                puts("Tente novamente:");
                pausar_tela(5,5);
                break;
        }
    } while (opcao != 3);
}

void exibir_produto(Produtos* no)
{
    limpar_tela();
    gotoxy(10,2);
    printf("PRODUTO TIPO %d", no->tipo);
    gotoxy(5,4);
    printf("Matricula: %d", no->matricula);
    gotoxy(5,5);
    printf("Preco: %.2f", no->preco);
    gotoxy(5,6);
    printf("Estoque: %d", no->estoque);
    gotoxy(5,7);
    printf("Vendas: %d", no->vendas);
    pausar_tela(5,9);
}