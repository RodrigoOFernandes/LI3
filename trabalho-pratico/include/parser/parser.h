/**
 * @file parser.h
 * @author André Ribeiro
 * @author David Costa
 * @author Rodrigo Fernandes
 * @date 6 Jan 2024
 * @brief Declaração das funções de parsing dos ficheiros.
 * 
 * Este ficheiro contém a declaração da função responsável pela leitura e 
 * processamento linha a linha dos ficheiros CSV, realizando a validação e
 * conversão dos dados para as estruturas do sistema.
 */

#ifndef PARSER_H
#define PARSER_H

#include <stdio.h>
#include "../gestores/gestor.h"


/**
 * @brief Lê e processa uma linha de um ficheiro CSV.
 * 
 * @details Esta função é responsável por:
 * 1. Ler uma linha do ficheiro de entrada
 * 2. Validar o formato e conteúdo da linha
 * 3. Processar e converter os dados para as estruturas apropriadas
 * 4. Registar erros encontrados no ficheiro de erro correspondente
 * 5. Atualizar as estruturas do gestor com os dados válidos
 * 
 * O parâmetro 'tal' determina o tipo de ficheiro a ser processado:
 * - 0: ficheiro de utilizadores
 * - 1: ficheiro de músicas
 * - 2: ficheiro de artistas
 * - 3: ficheiro de histórico
 * - 4: ficheiro de álbuns
 * 
 * @param file Ponteiro para o ficheiro de entrada a ser lido
 * @param error Ponteiro para o ficheiro onde serão registados os erros
 * @param g Ponteiro para a estrutura Gestor que armazenará os dados
 * @param tal Inteiro que indica o tipo de ficheiro a ser processado
 * 
 * @return Ponteiro para a linha lida ou NULL em caso de erro ou fim do ficheiro
 */
char *readline(FILE *file, FILE *error, Gestor *g, int tal);

#endif