#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funcoesextras.h"
#include "menu.h"
#include "arvoresbinarias.h"

void inicializacao(Usuarios usuarios[]);
int menu_login(Usuarios usuarios[]);
int menu_cadastro(Usuarios usuarios[]);
void menu_acoes(Produtos* raiz, Tipo_produto* lista);
void menu_produtos(Produtos* raiz, Tipo_produto* lista);
void menu_relatorio(Produtos* raiz, Tipo_produto* lista);
void exibir_produto(Produtos* no);

void inicializacao(Usuarios usuarios[])
{
    Produtos* raiz = criar_arvore();
    Tipo_produto* lista = criar_lista();
    int retorno;
    int opcao = 0;

    for (int i = 0; i < 50; i++)
    {
        usuarios[0].matricula = 0;
        strcpy(usuarios[0].senha, "0");
    }

    // usuario 1
    usuarios[0].matricula = 1001;
    strcpy(usuarios[0].senha, "admin");
    // usuario 2
    usuarios[1].matricula = 1201;
    strcpy(usuarios[1].senha, "usuario1");
    // usuario 3
    usuarios[2].matricula = 1202;
    strcpy(usuarios[2].senha, "usuario2");

    // cadastro de produtos
    cadastrar(&raiz, 633, 32, 4.39, 43, 0);
    cadastrar(&raiz, 264, 29, 36.00, 56, 0);
    cadastrar(&raiz, 811, 24, 4.39, 79, 0);
    cadastrar(&raiz, 147, 32, 7.29, 53, 0);
    cadastrar(&raiz, 258, 29, 56.00, 75, 0);
    cadastrar(&raiz, 369, 29, 20.00, 96, 0);
    cadastrar(&raiz, 159, 32, 6.99, 71, 0);
    cadastrar(&raiz, 357, 24, 7.29, 48, 0);
    cadastrar(&raiz, 951, 26, 8.69, 47, 0);
    cadastrar(&raiz, 753, 29, 46.49, 90, 0);

    lista = cadastrar_tipo(lista, 32);
    lista = cadastrar_tipo(lista, 29);
    lista = cadastrar_tipo(lista, 26);
    lista = cadastrar_tipo(lista, 24);

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

        if (opcao != 1 && opcao != 2)
        {
            limpar_tela();
            gotoxy(5,2);
            puts("OPCAO INVALIDA!");
            pausar_tela(1);
        }
        else if (opcao == 1)
        {
            retorno = menu_login(usuarios);

            while (retorno == 1)
            {
                limpar_tela();
                gotoxy(5,2);
                puts("USUARIO OU SENHA INVALIDOS!");
                gotoxy(5,3);
                puts("POR FAVOR, TENTE NOVAMENTE");
                pausar_tela(1);
                retorno = menu_login(usuarios);
            }
            if (retorno == 0)
            {
                limpar_tela();
                gotoxy(5,2);
                puts("LOGIN REALIZADO COM SUCESSO!");
                pausar_tela(1);
                menu_acoes(raiz, lista);
                opcao = 1;
            }
        }
        else if (opcao == 2)
        {
            retorno = menu_cadastro(usuarios);

            if (retorno == 1)
            {
                limpar_tela();
                gotoxy(5,2);
                puts("CADASTRO REALIZADO COM SUCESSO!");
                pausar_tela(1);
                opcao = 1;
            }
            else if (retorno == 0)
            {
                limpar_tela();
                gotoxy(5,2);
                puts("CADASTRO CANCELADO!");
                pausar_tela(1);
                opcao = 1;
            }
        }
        /*
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
                    pausar_tela(1);
                    retorno = menu_login(usuarios);
                }
                if (retorno == 0)
                {
                    limpar_tela();
                    gotoxy(5,2);
                    puts("LOGIN REALIZADO COM SUCESSO!");
                    pausar_tela(1);
                    menu_acoes(raiz, lista);
                    opcao = 1;
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
                    pausar_tela(1);
                }
                else
                {
                    limpar_tela();
                    gotoxy(5,2);
                    puts("USUARIO CADASTRADO COM SUCESSO!");
                    pausar_tela(1);
                    menu_acoes(raiz, lista);
                    opcao = 2;
                }
                break;

            default:
                limpar_tela();
                gotoxy(10,2);
                puts("OPCAO INVALIDA!");
                pausar_tela(1);
                break;

        }*/
    } while (retorno != 0);
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


void menu_acoes(Produtos* raiz, Tipo_produto* lista)
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
        gotoxy(5,7);
        printf("Opcao: %d", opcao);
        gotoxy(5,9);
        printf("Opcao: ");

        fflush(stdin);
        scanf("%d", &opcao);
        

        if (opcao == 1)
            menu_produtos(raiz, lista);
        else if (opcao == 2)
            menu_relatorio(raiz, lista);
        else if (opcao == 3)
        {
            limpar_tela();
            gotoxy(10,2);
            puts("PROGRAMA FINALIZADO!\n");
        }
        else
        {
            limpar_tela();
            gotoxy(10,2);
            puts("OPCAO INVALIDA!");
            pausar_tela(1);
        }
        /*switch (opcao)
        {
            case 1:
                menu_produtos(raiz, lista);
                break;

            case 2:
                menu_relatorio(raiz, lista);
                break;

            case 3:
                limpar_tela();
                gotoxy(10,2);
                puts("PROGRAMA FINALIZADO!\n");
                break;

            default:
                limpar_tela();
                gotoxy(10,2);
                puts("OPCAO INVALIDA!");
                pausar_tela(1);
                break;
        }*/
    } while (opcao != 3);
}


void menu_produtos(Produtos* raiz, Tipo_produto* lista)
{
    int opcao1 = 0;
    int matricula;
    int tipo;
    float preco;
    float valor;
    int estoque;
    Produtos* no_aux;

    do
    {
        int opcao2 = 0, opcao3 = 0;
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
        scanf("%d", &opcao1);
        getchar();
        switch (opcao1)
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
                pausar_tela(1);
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
            scanf("%d", &estoque);
            no_aux = busca(raiz, matricula);

            if (no_aux == NULL)
            {
                limpar_tela();
                gotoxy(10,2);
                puts("PRODUTO NAO ENCONTRADO!");
                pausar_tela(1);
            }
            else
            {
                no_aux = venda(no_aux, estoque);
                limpar_tela();
                gotoxy(10,2);
                puts("PRODUTO VENDIDO!");
                pausar_tela(1);
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

            Tipo_produto* auxiliar = busca_tipo(lista, tipo);
            if (auxiliar == NULL)
            {
                limpar_tela();
                gotoxy(10,2);
                printf("O TIPO %d NAO ESTÁ CADASTRADO!", tipo);
                gotoxy(5,4);
                printf("Deseja cadastrar um novo tipo?");
                gotoxy(5,6);
                printf("1 - Sim");
                gotoxy(28,6);
                printf("2 - Nao");
                gotoxy(5,7);
                printf("Opcao: ");
                scanf("%d", &opcao3);

                if (opcao3 == 1)
                {
                    lista = cadastrar_tipo(lista,tipo);
                    cadastrar(&raiz, matricula, tipo, preco, estoque, 1);
                }
                else if (opcao3 != 2)
                {
                    limpar_tela();
                    gotoxy(10,2);
                    puts("OPCAO INVALIDA!");
                    pausar_tela(1);
                }
            }
            else
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
                pausar_tela(1);
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
                scanf("%d", &opcao2);
                switch (opcao2)
                {
                    case 1:
                        limpar_tela();
                        gotoxy(10,2);
                        printf("QUAL O NOVO TIPO DO PRODUTO? ");
                        scanf("%f", &valor);
                        Tipo_produto* auxiliar = busca_tipo(lista, (int)valor);
                        if (auxiliar == NULL)
                        {
                            do
                            {
                                limpar_tela();
                                gotoxy(10,2);
                                printf("O TIPO %d NAO ESTÁ CADASTRADO!", (int)valor);
                                gotoxy(5,4);
                                printf("Deseja cadastrar um novo tipo?");
                                gotoxy(5,5);
                                printf("1 - Sim");
                                gotoxy(28,5);
                                printf("2 - Nao");
                                gotoxy(5,7);
                                printf("Opcao: ");
                                scanf("%d", &opcao3);

                                if (opcao3 == 1)
                                {
                                    lista = cadastrar_tipo(lista, (int)valor);
                                    no_aux = alteracao(no_aux, 1, valor);
                                }
                                else if (opcao3 != 2)
                                {
                                    limpar_tela();
                                    gotoxy(10,2);
                                    puts("OPCAO INVALIDA!");
                                    pausar_tela(1);
                                }
                            } while (opcao3 == 1 || opcao3 == 2);
                        }
                        else
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
                        pausar_tela(1);
                        break;
                }
            }
            break;

        case 6:
            menu_acoes(raiz, lista);
            break;

        default:
            limpar_tela();
            gotoxy(10,2);
            puts("OPCAO INVALIDA!");
            pausar_tela(1);
            break;
        }
    } while (opcao1 != 6);
}

void menu_relatorio(Produtos* raiz, Tipo_produto* lista)
{
    int opcao = 0;
    Tipo_produto* auxiliar;

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
                for (auxiliar = lista; auxiliar != NULL; auxiliar = auxiliar->proximo)
                {
                    printf("\nPRODUTOS DO TIPO %d", auxiliar->codigo);
                    puts("\nMATRICULA\t\tPRECO\t\tESTOQUE\t\tVENDAS\t\t");
                    em_ordem_tipo(raiz, auxiliar->codigo);
                    puts("");
                }
                getchar();
                printf("\nPressione qualquer tecla para continuar...");
                getchar();
                break;
        
            case 2:
                limpar_tela();
                puts("\nPRODUTOS QUE JA FORAM VENDIDOS");
                puts("MATRICULA\t\tTIPO\t\tPRECO\t\tESTOQUE\t\tVENDAS\t\t");
                em_ordem_vendas(raiz);
                getchar();
                printf("\nPressione qualquer tecla para continuar...");
                getchar();
                break;

            case 3:
                menu_acoes(raiz, lista);
                break;

            default:
                limpar_tela();
                gotoxy(10,2);
                puts("OPCAO INVALIDA!");
                pausar_tela(1);
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
    printf("Matricula--------------%d", no->matricula);
    gotoxy(5,5);
    printf("Preco:-----------------%.2f", no->preco);
    gotoxy(5,6);
    printf("Estoque:---------------%d", no->estoque);
    gotoxy(5,7);
    printf("Vendas:----------------%d", no->vendas);
    pausar_tela(3);
}