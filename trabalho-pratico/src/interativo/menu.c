#include <stdio.h>
#include <string.h>
#include "../include/utils/string_aux.h"
#include "../include/queries/query1.h"
#include "../include/queries/query2.h"
#include "../include/queries/query3.h"
#include "../include/utils/files_handler.h"
#include "../include/parser/parser_handler.h"

void menu_interativo(Gestor *gestor)
{
    char caminho_dataset[500];
    printf("Bem-vindo ao programa interativo!\n");
    printf("Por favor, insira o caminho para o dataset: ");
    if (!fgets(caminho_dataset, sizeof(caminho_dataset), stdin))
    {
        fprintf(stderr, "Erro ao ler o caminho do dataset.\n");
        return;
    }
    caminho_dataset[strcspn(caminho_dataset, "\n")] = '\0'; // Remove o newline

    // Inicializa os dados
    FILE **files = open_arquivos(caminho_dataset);
    if (files == NULL)
    {
        fprintf(stderr, "Erro ao carregar o dataset do caminho: %s\n", caminho_dataset);
        return;
    }
    printf("Dataset carregado com sucesso.\n");
    
    FILE **error_files = open_ficheiros_erros();

    parser_handler(files, error_files, gestor);

    printf("Parsing realizado com sucesso.\n");

    while (1)
    {
        int opcao;
        printf("\n--- Menu Interativo ---\n");
        printf("1. Executar Query 1\n");
        printf("2. Executar Query 2\n");
        printf("3. Executar Query 3\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");

        if (scanf("%d", &opcao) != 1)
        {
            fprintf(stderr, "Entrada inválida. Por favor, insira um número.\n");
            while (getchar() != '\n'); // Limpa o buffer
            continue;
        }

        switch (opcao)
        {
        case 1:
        {
            char id[100];
            printf("Insira o ID do utilizador: ");
            if (scanf("%99s", id) != 1)
            {
                fprintf(stderr, "Erro ao ler o ID do utilizador. Tente novamente.\n");
                while (getchar() != '\n');
                continue;
            }
            char output[2500] = "";
            query1(getUtilizadores(getGestorUtilizador(gestor)), getArtistas(getGestorArtista(gestor)), id, output, 0);
            printf("Resultado da Query 1:\n%s\n", output);
            break;
        }
        case 2:
        {
            int numero;
            char country[100];
            printf("Insira o número: ");
            if (scanf("%d", &numero) != 1)
            {
                fprintf(stderr, "Erro ao ler o número. Tente novamente.\n");
                while (getchar() != '\n');
                continue;
            }
            printf("Insira o país (entre aspas): ");
            if (scanf(" \"%99[^\"]\"", country) != 1)
            {
                fprintf(stderr, "Erro ao ler o país. Tente novamente.\n");
                while (getchar() != '\n');
                continue;
            }
            removeaspas(country);
            char output[2500] = "";
            query2(getArtistas(getGestorArtista(gestor)), numero, country, output, 0);
            printf("Resultado da Query 2:\n%s\n", output);
            break;
        }
        case 3:
        {
            int idade_minima, idade_maxima;
            printf("Insira a idade mínima: ");
            if (scanf("%d", &idade_minima) != 1)
            {
                fprintf(stderr, "Erro ao ler a idade mínima. Tente novamente.\n");
                while (getchar() != '\n');
                continue;
            }
            printf("Insira a idade máxima: ");
            if (scanf("%d", &idade_maxima) != 1)
            {
                fprintf(stderr, "Erro ao ler a idade máxima. Tente novamente.\n");
                while (getchar() != '\n');
                continue;
            }
            char output[2500] = "";
            query3(getGenerosMatrix(gestor), idade_minima, idade_maxima, output, 0);
            printf("Resultado da Query 3:\n%s\n", output);
            break;
        }
        case 0:
            close_files(error_files, 5);
            close_files(files, 5);
            printf("Saindo do programa...\n");
            return;
        default:
            fprintf(stderr, "Opção inválida. Tente novamente.\n");
            break;
        }
    }
}