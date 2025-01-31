/**
 * @file comparator.h
 * @author André Ribeiro
 * @author David Costa
 * @author Rodrigo Fernandes
 * @date 6 Jan 2024
 * @brief Ficheiro que contém a declaração da função de comparação de resultados.
 * 
 * Este ficheiro contém a declaração da função responsável por verificar e comparar
 * os resultados gerados pelo programa com os resultados esperados, permitindo
 * validar a correta implementação das queries.
 */

#ifndef COMPARATOR_H
#define COMPARATOR_H

/**
 * @brief Verifica e compara os resultados gerados com os resultados esperados.
 * 
 * A função lê os ficheiros de resultados gerados pelo programa e compara-os com
 * os ficheiros de resultados esperados, verificando se são idênticos. Para cada
 * tipo de query, calcula a percentagem de resultados corretos e identifica 
 * eventuais discrepâncias.
 * 
 * @param pasta_resultados Caminho para a pasta contendo os ficheiros de resultados gerados.
 * @param pasta_esperados Caminho para a pasta contendo os ficheiros de resultados esperados.
 */
void verificar_resultados(const char *pasta_resultados, const char *pasta_esperados);

#endif