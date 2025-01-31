/**
 * @file duracao_aux.h
 * @author André Ribeiro
 * @author David Costa
 * @author Rodrigo Fernandes
 * @date 6 Jan 2024
 * @brief Ficheiro que contém funções auxiliares para manipulação de durações.
 * 
 * Este ficheiro contém declarações de funções que auxiliam na manipulação e 
 * conversão de durações entre diferentes formatos (string "HH:MM:SS" e segundos).
 */

#ifndef DURACAO_AUX_H
#define DURACAO_AUX_H

/**
 * @brief Converte uma duração do formato string para segundos.
 * 
 * A função recebe uma string no formato "HH:MM:SS" e converte-a para o número
 * total de segundos correspondente.
 * 
 * @param duracao String contendo a duração no formato "HH:MM:SS".
 * @return Número total de segundos correspondente à duração.
 */
int duracaoparasegundos(char* duracao);

/**
 * @brief Converte uma duração em segundos para o formato string.
 * 
 * A função recebe um número de segundos e converte-o para uma string no
 * formato "HH:MM:SS".
 * 
 * @param durac Número de segundos a converter.
 * @return String alocada dinamicamente contendo a duração no formato "HH:MM:SS" ou NULL em caso de erro.
 */
char *segundosparaduracao(int durac);

#endif