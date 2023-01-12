#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "menu.h"
#include "arvoresbinarias.h"

#ifdef _WIN32
    #include <windows.h>
#else

#endif

void limpar_tela();
void gotoxy(int x,int y);
void pausar_tela(int x, int y);
void inicializacao();
int menu_login(Usuarios usuarios[]);
int menu_cadastro(Usuarios usuarios[]);
void menu_acoes(struct produto* raiz);
void menu_produtos(struct produto* raiz);
void menu_relatorio(struct produto* raiz);
void exibir_produto(struct produto* no);
void em_ordem_tipo(struct produto* raiz, int tipo);
void em_ordem_vendas(struct produto* raiz);

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

void inicializacao()
{
    struct produto* raiz = criar_arvore();
    menu_acoes(raiz);
}

int menu_login(Usuarios usuarios[])
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

    for (int i = 0; i < 50; i++)
    {
        if (strcmp(usuario, usuarios[i].matricula) == 0 && strcmp(senha, usuarios[i].senha) == 0)
        {
            return 0;
            exit(1);
        }
        else
        {
            return 1;
        }
    }
}

int menu_cadastro(Usuarios usuarios[])
{
    char usuario[20];
    char senha[20];

    limpar_tela();
    gotoxy(10,2);
    puts("CADASTRO");
    gotoxy(5,4);
    puts("USUARIO: ");
    gotoxy(5,5);
    puts("SENHA: ");
    gotoxy(14,4);
    scanf("%[^\n]s", usuario);
    getchar();
    gotoxy(13,5);
    scanf("%[^\n]s", senha);

    for (int i = 0; i < 50; i++)
    {
        if (usuario == usuarios[i].matricula)
        {
            return 1;
            exit(1);
        }
    }

    for (int i = 0; i < 50; i++)
    {
        if (usuarios[i].matricula == 0 && strcmp(usuarios[i].senha, "0") == 0)
        {
            usuarios[i].matricula == usuario;
            strcpy(usuarios[i].senha, senha);
            return 0;
            exit(1);
        }
    }
}


void menu_acoes(struct produto* raiz)
{
    int opcao;

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

    do
    {
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

void menu_produtos(struct produto* raiz)
{
    int opcao, op;
    int matricula;
    int tipo;
    float preco;
    float valor;
    int estoque;
    struct produto* no_aux;

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

    do
    {
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

            do
            {
                matricula = rand() % 100;
                no_aux = busca(raiz, matricula);
            } while (no_aux != NULL);

            gotoxy(10,2);
            printf("DIGITE OS DADOS DO PRODUTO: ");
            gotoxy(5,4);
            printf("Tipo: ");
            gotoxy(5,5);
            printf("Preco: ");
            gotoxy(5,6);
            printf("Estoque: ");
            gotoxy(11,4);
            scanf("%d", &tipo);
            gotoxy(7,5);
            scanf("%.2f", &preco);
            gotoxy(14,6);
            scanf("%d", &estoque);
            no_aux = cadastrar(raiz, matricula, tipo, preco, estoque);

            if (no_aux == NULL)
            {
                limpar_tela();
                gotoxy(10,2);
                puts("ERRO AO CADASTRAR PRODUTO!");
                gotoxy(10,3);
                puts("Tente novamente:");
                pausar_tela(5,5);
            }
            else
            {
                no_aux = venda(no_aux, estoque);
                limpar_tela();
                gotoxy(10,2);
                puts("PRODUTO CADASTRADO!");
                pausar_tela(5,4);
            }
            break;

        case 4:
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
                no_aux = excluir(raiz, NULL, matricula);
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
    } while (opcao != 6)
}

void menu_relatorio(struct produto* raiz)
{
    int opcao;
    int codigo_tipo_produto;

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

    do
    {
        switch (opcao)
        {
            case 1:
                limpar_tela();
                gotoxy(5,2);
                printf("Digite o codigo do tipo do produto: ");
                scanf("%d", &codigo_tipo_produto);
                limpar_tela();
                gotoxy(5,4);
                puts("-----------------------------------------------------------------");
                gotoxy(5,5);
                printf("|                      PRODUTOS DO TIPO %d                      |", codigo_tipo_produto);
                gotoxy(5,7);
                puts("-----------------------------------------------------------------");
                gotoxy(5,9);
                printf("|       MATRICULA       PRECO       ESTOQUE       VENDAS        |", codigo_tipo_produto);
                em_ordem_tipo(raiz, codigo_tipo_produto);
                puts("-----------------------------------------------------------------");
                pausar_tela(5,2);
                break;
        
            case 2:
                limpar_tela();
                gotoxy(5,2);
                printf("Digite o codigo do tipo do produto: ");
                scanf("%d", &codigo_tipo_produto);
                limpar_tela();
                gotoxy(5,4);
                puts("-----------------------------------------------------------------------------");
                gotoxy(5,5);
                printf("|                       PRODUTOS QUE JA FORAM VENDIDOS                      |", codigo_tipo_produto);
                gotoxy(5,7);
                puts("-----------------------------------------------------------------------------");
                gotoxy(5,9);
                printf("|       MATRICULA       TIPO        PRECO       ESTOQUE       VENDAS        |", codigo_tipo_produto);
                em_ordem_vendas(raiz);
                puts("-----------------------------------------------------------------------------");
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

void exibir_produto(struct produto* no)
{
    limpar_tela();
    gotoxy(10,2);
    printf("PRODUTO TIPO %d", no->tipo);
    gotoxy(5,4);
    printf("Matricula: %d", no->matricula);
    gotoxy(5,5);
    printf("Preco: %f", no->preco);
    gotoxy(5,7);
    printf("Estoque: %d", no->estoque);
    pausar_tela(5,9);
}