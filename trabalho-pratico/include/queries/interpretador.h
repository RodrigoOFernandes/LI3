/**
 * @file interpretador.h
 * @author André Ribeiro
 * @author David Costa
 * @author Rodrigo Fernandes
 * @date 6 Jan 2024
 * @brief Declaração das funções do interpretador de comandos.
 * 
 * Este ficheiro contém a declaração da função responsável por processar e interpretar
 * os comandos (queries) fornecidos ao sistema, executando as operações correspondentes
 * e gerando os resultados apropriados.
 */

#ifndef INTERPRETADOR_H
#define INTERPRETADOR_H

#include "../gestores/gestor.h"


/**
 * @brief Processa e executa os comandos fornecidos.
 * 
 * @details Esta função é responsável por ler e interpretar os comandos a partir de um ficheiro
 * de entrada, executar as queries correspondentes e gerar os resultados. O processamento
 * pode ser realizado em diferentes modos, determinados pela flag.
 * Para cada comando, a função:
 * 1. Lê e interpreta o comando
 * 2. Identifica a query correspondente
 * 3. Executa a query com os parâmetros fornecidos
 * 4. Gera o output no formato apropriado
 * 5. Se a flag estiver ativa, recolhe métricas de desempenho
 * 
 * @param g Ponteiro para a estrutura Gestor que contém todas as estruturas de dados do sistema
 * @param inputs Ponteiro para o ficheiro que contém os comandos a serem processados
 * @param flag Inteiro que determina o modo de execução:
 *            - 0: modo normal
 *            - 1: modo de teste (recolhe métricas de desempenho)
 */
void processar_comandos(Gestor *g, FILE *inputs, int flag);

#endif