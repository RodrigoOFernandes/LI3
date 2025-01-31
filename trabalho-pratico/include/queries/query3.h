/**
 * @file query3.h
 * @author André Ribeiro
 * @author David Costa
 * @author Rodrigo Fernandes
 * @date 6 Jan 2024
 * @brief Declaração da função de consulta 3.
 * 
 * Este arquivo contém a declaração da função `query3`, responsável por realizar a consulta 3 no sistema.
 * A função consulta a matriz de gêneros e calcula o total de gostos por gênero em um intervalo de idades, 
 * retornando os resultados em um formato específico de string.
 */
#ifndef QUERY3_H
#define QUERY3_H

#include "../tipos/generosmatrix.h"
/**
 * @brief Função para realizar a consulta 3.
 * 
 * A função `query3` calcula o total de gostos por gênero musical em um intervalo de idades, 
 * baseado nos dados da matriz de gêneros  por idade fornecida. A consulta é realizada para idades entre 
 * `min_age` e `max_age` (inclusive) e os resultados são armazenados no buffer.
 * A função também ordena os gêneros por número de gostos de forma descendente e, em caso de empate, 
 * ordena alfabeticamente por nome de gênero. O formato de saída é determinado pelo valor de `flag`.
 *
 * @param gm Ponteiro para a estrutura `GenerosMatrix`, que contém os dados dos gostos de gênero por faixa etária.
 * @param min_age Idade mínima do intervalo para consulta.
 * @param max_age Idade máxima do intervalo para consulta.
 * @param buffer Buffer de string onde os resultados da consulta serão armazenados.
 * @param flag Determina o formato da saída: 
 *             - `0` para saída no formato "nome do gênero;total de gostos", 
 *             - `1` para saída no formato "nome do gênero=total de gostos".
 * @return Nenhum valor de retorno. O resultado é armazenado no `buffer`.
 */
void query3(GenerosMatrix* gm, int min_age, int max_age, char *buffer, int flag);

#endif 
