/**
 * @file data_aux.h
 * @author André Ribeiro
 * @author David Costa
 * @author Rodrigo Fernandes
 * @date 6 Jan 2024
 * @brief Ficheiro que contém funções auxiliares para manipulação de datas.
 * 
 * Este ficheiro contém declarações de funções que auxiliam na manipulação e 
 * processamento de datas, incluindo cálculo de idades e extração de informações 
 * sobre semanas do ano.
 */

#ifndef DATA_AUX_H
#define DATA_AUX_H

/**
 * @brief Calcula a idade com base na data de nascimento.
 * 
 * A função recebe uma data de nascimento e calcula a idade atual da pessoa,
 * considerando a data de referência 2024/09/09.
 * 
 * @param data_nascimento String contendo a data de nascimento no formato "AAAA/MM/DD".
 * @return Idade calculada em anos.
 */
int calcular_idade(char *data_nascimento);

/**
 * @brief Obtém a representação de uma data no formato "ano-semana".
 * 
 * A função recebe uma data e retorna uma string que representa o ano e a 
 * semana correspondente no formato "AAAA-SS", onde SS é o número da semana
 * no ano (1-52).
 * 
 * @param data String contendo a data a ser processada.
 * @return String alocada dinamicamente contendo a representação "ano-semana" ou NULL em caso de erro.
 */
char *get_ano_semana(char *data);

#endif