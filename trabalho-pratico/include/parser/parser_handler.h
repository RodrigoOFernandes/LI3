/**
 * @file parser_handler.h
 * @author André Ribeiro
 * @author David Costa
 * @author Rodrigo Fernandes
 * @date 6 Jan 2024
 * @brief Declaração das funções do gestor de parsing dos ficheiros.
 * 
 * Este ficheiro contém a declaração da função responsável por gerir o processo
 * de parsing dos diferentes ficheiros de dados do sistema, garantindo que são
 * processados na ordem correta e que os dados são devidamente validados e
 * armazenados nas estruturas apropriadas.
 */

#ifndef PARSER_HANDLER_H
#define PARSER_HANDLER_H

#include <stdio.h>
#include "../gestores/gestor.h"


/**
 * @brief Gere o processo de parsing dos ficheiros de dados.
 * 
 * @details Esta função é responsável por coordenar o parsing dos diferentes ficheiros
 * de dados do sistema. O processo inclui:
 * 1. Parsing dos ficheiros na ordem correta (artistas -> álbuns -> músicas -> utilizadores -> histórico)
 * 2. Validação dos dados durante o parsing
 * 3. Armazenamento dos dados válidos nas estruturas apropriadas
 * 4. Registo de erros encontrados nos ficheiros de erro correspondentes
 * 
 * @param files Array de ponteiros para os ficheiros de entrada a serem processados
 * @param error_files Array de ponteiros para os ficheiros onde serão registados os erros encontrados
 * @param g Ponteiro para a estrutura Gestor que armazenará os dados processados
 */
void parser_handler(FILE **files, FILE **error_files, Gestor *g);

#endif