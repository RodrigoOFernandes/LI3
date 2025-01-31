/**
 * @file generosmatrix.h
 * @author André Ribeiro
 * @author David Costa
 * @author Rodrigo Fernandes
 * @date 6 Jan 2024
 * @brief Ficheiro que contém definições e funções para manipulação da matriz de géneros musicais.
 *
 * Este ficheiro define uma estrutura de matriz para armazenar estatísticas de géneros musicais
 * por faixa etária, permitindo rastrear as preferências musicais dos utilizadores.
 */

#ifndef GENEROSMATRIX_H
#define GENEROSMATRIX_H

/**
 * @brief Número máximo de géneros musicais suportados.
 */
#define MAX_GENEROS 10

/**
 * @brief Número máximo de idades suportadas.
 */
#define MAX_IDADES 130

/**
 * @struct generosmatrix
 * @brief Estrutura que representa uma matriz de géneros musicais.
 * @details Armazena uma matriz que relaciona géneros musicais com idades de utilizadores.
 */
typedef struct generosmatrix GenerosMatrix;

/**
 * @brief Inicializa uma nova matriz de géneros.
 *
 * Aloca e inicializa uma nova estrutura GenerosMatrix, inicializando todos
 * os elementos da matriz com zero.
 *
 * @return Ponteiro para a nova matriz inicializada ou NULL em caso de erro.
 */
GenerosMatrix *MatrixInit();

/**
 * @brief Obtém a matriz interna da estrutura GenerosMatrix.
 *
 * @param g Ponteiro para a estrutura GenerosMatrix.
 * @return Ponteiro para a matriz bidimensional de inteiros.
 */
int (*getMatrix(GenerosMatrix *g))[MAX_IDADES];

/**
 * @brief Liberta a memória alocada para uma matriz de géneros.
 *
 * @param matrix Ponteiro para a estrutura GenerosMatrix a ser libertada.
 */
void MatrixDestroy(GenerosMatrix *matrix);

/**
 * @brief Incrementa o contador para um género e idade específicos.
 *
 * Atualiza a matriz incrementando o contador para a combinação específica
 * de género musical e idade.
 *
 * @param genero Nome do género musical.
 * @param idade Idade do utilizador.
 * @param gm Ponteiro para a estrutura GenerosMatrix.
 */
void addGeneroLike(char *genero, int idade, GenerosMatrix *gm);

#endif