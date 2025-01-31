/**
 * @file garray_aux.h
 * @author André Ribeiro
 * @author David Costa
 * @author Rodrigo Fernandes
 * @date 6 Jan 2024
 * @brief Ficheiro que contém funções auxiliares para manipulação de arrays do GLib.
 * 
 * Este ficheiro contém declarações de funções que auxiliam na manipulação de GArrays,
 * especialmente para ordenação e gestão de resultados de artistas.
 */

#ifndef GARRAY_AUX_H
#define GARRAY_AUX_H

#include <glib.h>
#include "../tipos/artistaresultado.h"

/**
 * @brief Função de comparação para ordenação de artistas.
 * 
 * Compara dois artistas com base na sua duração total e, em caso de empate,
 * pelo seu ID. É utilizada para ordenar arrays de artistas em ordem decrescente
 * de duração.
 * 
 * @param a Ponteiro para o primeiro artista a comparar.
 * @param b Ponteiro para o segundo artista a comparar.
 * @return Valor negativo se a > b, positivo se b > a, ou 0 se iguais.
 */
gint compara_artista_resultado(const void *a, const void *b);

/**
 * @brief Ordena um GArray de artistas.
 * 
 * Ordena um array de artistas utilizando a função de comparação
 * compara_artista_resultado.
 * 
 * @param a Ponteiro para o GArray a ser ordenado.
 */
void ordenaGarray(GArray *a);

/**
 * @brief Insere um artista num array mantendo um limite de tamanho.
 * 
 * Insere um artista num array mantendo apenas os N melhores resultados.
 * Se o array já estiver cheio, o novo artista só é inserido se for
 * melhor que o pior artista atual.
 * 
 * @param array Ponteiro para o GArray onde inserir.
 * @param ar Ponteiro para o ArtistaResultado a inserir.
 * @param N Número máximo de elementos no array.
 */
void inserir_com_limite_optimizado(GArray *array, ArtistaResultado *ar, int N);

#endif