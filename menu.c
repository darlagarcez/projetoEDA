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

    cadastrar_tipo(&lista, 32);
    cadastrar_tipo(&lista, 29);
    cadastrar_tipo(&lista, 26);
    cadastrar_tipo(&lista, 24);

    do
    {
        limpar_tela();
        puts(" ESCOLHA UMA ACAO:\n");
        puts(" 1 - Login");
        puts(" 2 - Cadastro\n");
        printf(" Opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
            case 1:
                retorno = menu_login(usuarios);
    
                while (retorno == 1)
                {
                    limpar_tela();
                    puts(" USUARIO OU SENHA INVALIDOS!");
                    pausar_tela(1);
                    retorno = menu_login(usuarios);
                }
                if (retorno == 0)
                {
                    limpar_tela();
                    puts(" LOGIN REALIZADO COM SUCESSO!");
                    pausar_tela(1);
                    menu_acoes(raiz,lista);
                }
                break;
        
            case 2:
                retorno = menu_cadastro(usuarios);

                if (retorno == 1)
                {
                    limpar_tela();
                    puts(" USUARIO JA CADASTRADO!");
                    puts(" Favor, realizar login");
                    pausar_tela(1);
                }
                else
                {
                    limpar_tela();
                    puts(" USUARIO CADASTRADO COM SUCESSO!");
                    pausar_tela(1);
                    menu_acoes(raiz, lista);
                }
                break;

            default:
                limpar_tela();
                puts(" OPCAO INVALIDA!");
                pausar_tela(1);
                break;
        }
    } while (retorno != 0);
}

int menu_login(Usuarios usuarios[])
{
    int usuario;
    char senha[21];
    int usuario_encontrado = 1;

    limpar_tela();
    puts(" LOGIN\n");
    puts(" USUARIO: ");
    puts(" SENHA: ");
    gotoxy(11,3);
    scanf("%d", &usuario);
    getchar();
    gotoxy(9,4);
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
    char senha[21];
    int usuario_encontrado = 1;

    limpar_tela();
    puts(" CADASTRO\n");
    puts(" USUARIO: ");
    puts(" SENHA: ");
    gotoxy(11,3);
    scanf("%d", &usuario);
    getchar();
    gotoxy(9,4);
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

    limpar_tela();
    puts(" ESCOLHA UMA ACAO:\n");
    puts(" 1 - Acessar produtos");
    puts(" 2 - Acessar relatorios");
    puts(" 3 - Sair\n");
    printf(" Opcao: ");
    scanf("%d", &opcao);

    switch (opcao)
    {
        case 1:
            menu_produtos(raiz, lista);
            menu_acoes(raiz, lista);
            break;

        case 2:
            menu_relatorio(raiz, lista);
            menu_acoes(raiz, lista);
            break;

        case 3:
            limpar_tela();
            puts(" PROGRAMA FINALIZADO!\n");
            exit(1);
            break;

        default:
            limpar_tela();
            puts(" OPCAO INVALIDA!");
            pausar_tela(1);
            menu_acoes(raiz, lista);
            break;
    }
}


void menu_produtos(Produtos* raiz, Tipo_produto* lista)
{
    int opcao1 = 0, opcao2 = 0, opcao3 = 0;
    int matricula;
    int tipo;
    float preco;
    float valor;
    int estoque;
    Produtos* no_aux;

    limpar_tela();
    puts(" O QUE DESEJA REALIZAR EM PRODUTOS:\n");
    puts(" 1 - Buscar");
    puts(" 2 - Vender");
    puts(" 3 - Cadastrar");
    puts(" 4 - Excluir");
    puts(" 5 - Alterar");
    puts(" 6 - Voltar\n");
    printf(" Opcao: ");
    scanf("%d", &opcao1);

    switch (opcao1)
    {
    case 1:
        limpar_tela();
        printf(" DIGITE A MATRICULA DO PRODUTO: ");
        scanf("%d", &matricula);
        no_aux = busca(raiz, matricula, 2);

        if (no_aux == NULL)
        {
            limpar_tela();
            puts(" PRODUTO NAO ENCONTRADO!");
            pausar_tela(1);
        }
        menu_produtos(raiz, lista);
        
        break;
    
    case 2:
        limpar_tela();
        printf(" DIGITE OS DADOS DA VENDA DO PRODUTO:\n");
        printf(" Matricula: ");
        printf(" Quantidade: ");
        gotoxy(12,3);
        scanf("%d", &matricula);
        gotoxy(13,4);
        scanf("%d", &estoque);
        no_aux = busca(raiz, matricula, 1);

        if (no_aux == NULL)
        {
            limpar_tela();
            puts(" PRODUTO NAO ENCONTRADO!");
            pausar_tela(1);
        }
        else if (no_aux->estoque < estoque)
        {
            limpar_tela();
            puts(" ESTOQUE INSUFICIENTE!");
            pausar_tela(1);
        }
        else
        {
            no_aux = venda(no_aux, estoque);
            limpar_tela();
            puts(" PRODUTO VENDIDO!");
            pausar_tela(1);
        }

        menu_produtos(raiz, lista);
        break;

    case 3:
        limpar_tela();
        printf(" DIGITE OS DADOS DO PRODUTO:\n\n");
        puts(" Matricula: ");
        puts(" Tipo: ");
        puts(" Preco: ");
        puts(" Estoque: ");
        gotoxy(12,3);
        scanf("%d", &matricula);
        gotoxy(7,4);
        scanf("%d", &tipo);
        gotoxy(8,5);
        scanf("%f", &preco);
        gotoxy(10,6);
        scanf("%d", &estoque);

        if (preco <= 0)
        {
            limpar_tela();
            puts(" PRECO INVALIDO!");
            pausar_tela(1);
        }
        else if (estoque <= 0)
        {
            limpar_tela();
            puts(" ESTOQUE INVALIDO!");
            pausar_tela(1);
        }
        else
        {
            Tipo_produto* auxiliar = busca_tipo(lista, tipo);

            if (auxiliar == NULL)
            {
                limpar_tela();
                printf(" O TIPO %d NAO ESTÁ CADASTRADO!\n\n", tipo);
                puts(" Deseja cadastrar um novo tipo?\n");
                puts(" 1 - Sim");
                puts(" 2 - Nao\n");
                printf("Opcao: ");
                scanf("%d", &opcao3);

                if (opcao3 == 1)
                {
                    cadastrar_tipo(&lista, tipo);
                    cadastrar(&raiz, matricula, tipo, preco, estoque, 1);
                }
                else if (opcao3 != 2)
                {
                    limpar_tela();
                    gotoxy(55,2);
                    puts("OPCAO INVALIDA!");
                    pausar_tela(1);
                }
            }
            else
                cadastrar(&raiz, matricula, tipo, preco, estoque, 1);
        }

        menu_produtos(raiz, lista);
        break;

    case 4:
        limpar_tela();
        printf(" DIGITE A MATRICULA DO PRODUTO: ");
        scanf("%d", &matricula);

        excluir(&raiz, matricula);

        menu_produtos(raiz, lista);
        break;

    case 5:
        limpar_tela();
        printf(" DIGITE A MATRICULA DO PRODUTO: ");
        scanf("%d", &matricula);
        no_aux = busca(raiz, matricula, 1);

        if (no_aux == NULL)
        {
            limpar_tela();
            puts(" PRODUTO NAO ENCONTRADO!");
            pausar_tela(1);
        }
        else
        {
            limpar_tela();
            puts(" QUAL ALTERACAO DESEJA FAZER NO PRODUTO?\n");
            puts(" 1 - Tipo do produto");
            puts(" 2 - Preco");
            puts(" 3 - Estoque\n");
            printf(" Opcao: ");
            scanf("%d", &opcao2);

            switch (opcao2)
            {
                case 1:
                    limpar_tela();
                    printf(" QUAL O NOVO TIPO DO PRODUTO? ");
                    scanf("%f", &valor);

                    Tipo_produto* auxiliar = busca_tipo(lista, (int)valor);

                    if (auxiliar == NULL)
                    {
                        do
                        {
                            limpar_tela();
                            printf(" O TIPO %d NAO ESTÁ CADASTRADO!\n\n", (int)valor);
                            puts(" Deseja cadastrar um novo tipo?");
                            puts(" 1 - Sim");
                            puts(" 2 - Nao\n");
                            printf(" Opcao: ");
                            scanf("%d", &opcao3);

                            if (opcao3 == 1)
                            {
                                cadastrar_tipo(&lista, (int)valor);
                                no_aux = alteracao(no_aux, 1, valor);
                            }
                            else if (opcao3 != 2)
                            {
                                limpar_tela();
                                puts(" OPCAO INVALIDA!");
                                pausar_tela(1);
                            }
                        } while (opcao3 == 1 || opcao3 == 2);
                    }
                    else
                        no_aux = alteracao(no_aux, 1, valor);
                    break;

                case 2:
                    limpar_tela();
                    printf(" QUAL O NOVO PRECO DO PRODUTO? ");
                    scanf("%f", &valor);

                    if (valor <= 0)
                    {
                        limpar_tela();
                        puts(" PRECO INVALIDO!");
                        pausar_tela(1);
                    }
                    else
                        no_aux = alteracao(no_aux, 2, valor);
                    break;

                case 3:
                    limpar_tela();
                    printf(" QUAL O NOVA QUANTIDADE DO ESTOQUE DO PRODUTO? ");
                    scanf("%f", &valor);

                    if  (valor <= 0)
                    {
                        limpar_tela();
                        puts(" QUANTIDADE INVALIDA!");
                        pausar_tela(1);
                    }
                    else
                        no_aux = alteracao(no_aux, 3, valor);
                    break;

                default: 
                    limpar_tela();
                    puts(" OPCAO INVALIDA!");
                    pausar_tela(1);
                    break;
            }
        }

        menu_produtos(raiz, lista);
        break;

    case 6:
        menu_acoes(raiz, lista);
        break;

    default:
        limpar_tela();
        puts(" OPCAO INVALIDA!");
        pausar_tela(1);
        menu_produtos(raiz, lista);
        break;
    }
}

void menu_relatorio(Produtos* raiz, Tipo_produto* lista)
{
    int opcao = 0;
    Tipo_produto* auxiliar;

    limpar_tela();
    puts(" QUAL RELATORIO DESEJA VER:\n");
    puts(" 1 - Por tipo de produto");
    puts(" 2 - De vendas");
    puts(" 3 - Voltar\n"); 
    printf(" Opcao: ");
    scanf("%d", &opcao);

    switch (opcao)
    {
        case 1:
            limpar_tela();
            for (auxiliar = lista; auxiliar != NULL; auxiliar = auxiliar->proximo)
            {
                printf("      PRODUTOS DO TIPO %d\n\n", auxiliar->codigo);
                puts(" MATRICULA     PRECO     ESTOQUE");
                em_ordem_tipo(raiz, auxiliar->codigo);
                puts("");
            }
            getchar();
            printf("Pressione qualquer tecla para continuar...");
            getchar();

            menu_relatorio(raiz, lista);
            break;
    
        case 2:
            limpar_tela();
            printf("               RELATORIO DE VENDAS\n\n");
            puts(" MATRICULA     TIPO     PRECO     ESTOQUE     VENDAS");
            em_ordem_vendas(raiz);
            puts("");
            getchar();
            printf(" Pressione qualquer tecla para continuar...");
            getchar();

            menu_relatorio(raiz, lista);
            break;

        case 3:
            menu_acoes(raiz, lista);
            break;

        default:
            limpar_tela();
            puts(" OPCAO INVALIDA!");
            pausar_tela(1);
        
            menu_relatorio(raiz, lista);
            break;
    }
}
