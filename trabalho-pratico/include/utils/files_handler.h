/**
 * @file files_handler.h
 * @author André Ribeiro
 * @author David Costa
 * @author Rodrigo Fernandes
 * @date 6 Jan 2024
 * @brief Ficheiro que contém funções para gestão e manipulação de ficheiros.
 * 
 * Este ficheiro contém declarações de funções que auxiliam na manipulação de ficheiros,
 * incluindo abertura, fecho, comparação e leitura de ficheiros CSV e de resultados.
 */

#ifndef FILES_HANDLER_H
#define FILES_HANDLER_H

#define MAX_LINE_LENGTH 1024
#include <stdio.h>

/**
 * @brief Abre os ficheiros para registo de erros.
 * 
 * Abre ficheiros na pasta "resultados" para registar as entradas inválidas
 * encontradas durante o processamento dos dados.
 * 
 * @return Array de ponteiros FILE* para os ficheiros de erro ou NULL em caso de erro.
 */
FILE **open_ficheiros_erros();

/**
 * @brief Abre os ficheiros de dados CSV.
 * 
 * Abre os ficheiros CSV (users.csv, musics.csv, etc.) a partir do caminho base fornecido.
 * 
 * @param caminho_base Caminho base onde se encontram os ficheiros CSV.
 * @return Array de ponteiros FILE* para os ficheiros CSV ou NULL em caso de erro.
 */
FILE **open_arquivos(char* caminho_base);

/**
 * @brief Fecha um conjunto de ficheiros.
 * 
 * Fecha todos os ficheiros abertos e liberta a memória alocada para o array de ponteiros.
 * 
 * @param files Array de ponteiros FILE* a serem fechados.
 * @param num_files Número de ficheiros no array.
 */
void close_files(FILE **files, int num_files);

/**
 * @brief Compara dois ficheiros linha a linha.
 * 
 * Compara o conteúdo de dois ficheiros e identifica a primeira linha onde existe uma diferença.
 * 
 * @param ficheiro1 Caminho para o primeiro ficheiro.
 * @param ficheiro2 Caminho para o segundo ficheiro.
 * @param linha_diferente Ponteiro para guardar o número da linha onde foi encontrada a primeira diferença.
 * @return 1 se os ficheiros são iguais, 0 se são diferentes, -1 em caso de erro.
 */
int comparar_ficheiros(const char *ficheiro1, const char *ficheiro2, int *linha_diferente);

/**
 * @brief Lê uma linha de um ficheiro.
 * 
 * Lê uma linha completa de um ficheiro, respeitando o tamanho máximo definido.
 * 
 * @param file Ponteiro para o ficheiro a ser lido.
 * @param linha Buffer onde será guardada a linha lida.
 * @return 1 se a leitura foi bem sucedida, 0 caso contrário.
 */
int ler_linha(FILE *file, char *linha);

#endif