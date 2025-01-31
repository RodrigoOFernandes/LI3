/**
 * @file menu.h
 * @author André Ribeiro
 * @author David Costa
 * @author Rodrigo Fernandes
 * @date 6 Jan 2024
 * @brief Declaração das funções de interface do menu interativo.
 * 
 * Este ficheiro contém a declaração da função responsável por gerir o menu interativo
 * do programa, permitindo ao utilizador executar queries de forma interativa através
 * da linha de comandos.
 */

#ifndef MENU_H
#define MENU_H

/**
 * @brief Inicia e gere o menu interativo do programa.
 * 
 * @details Esta função implementa a interface interativa do programa, permitindo ao
 * utilizador:
 * - Especificar o caminho para o dataset a ser carregado
 * - Escolher entre diferentes queries disponíveis
 * - Introduzir parâmetros para as queries
 * - Visualizar os resultados das queries
 * 
 * A função gere todo o ciclo de vida do menu interativo, incluindo:
 * 1. Carregamento inicial do dataset
 * 2. Apresentação das opções disponíveis
 * 3. Validação das entradas do utilizador
 * 4. Execução das queries selecionadas
 * 5. Apresentação dos resultados
 * 
 * @param gestor Ponteiro para a estrutura Gestor que contém todas as estruturas 
 *               de dados do sistema
 */
void menu_interativo(Gestor *gestor);

#endif