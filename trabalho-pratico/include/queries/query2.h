/**
 * @file query2.h
 * @author André Ribeiro
 * @author David Costa
 * @author Rodrigo Fernandes
 * @date 6 Jan 2024
 * @brief Declaração da função de consulta 2.
 * 
 * Este arquivo contém a declaração da função `query2`, responsável por realizar uma consulta no sistema,
 * com base nos artistas e nas informações sobre o país, além de filtrar por um número inteiro N.
 */
#ifndef QUERY2_H
#define QUERY2_H

#include <glib.h>
#include <stdio.h>

/**
 * @brief Função para realizar a consulta 2.
 * 
 * A função `query2` realiza uma consulta no sistema utilizando a tabela de artistas e filtra os resultados de acordo com
 * o país fornecido, se este o for fornecido, e um número `N`. Ela também modifica o conteúdo do buffer para armazenar os resultados 
 * ajusta a forma deste resultados consoante o valor da flag.
 * 
 * @param tabela_artistas Ponteiro para uma tabela de hash contendo os dados dos artistas, com o ID do artista como chave.
 * @param N Número inteiro utilizado para limitar o número de informação de artistas qie serão colocadas no buffer.
 * @param pais País pelo qual os artistas devem ser filtrados.
 * @param buffer Buffer de string que será modificado para armazenar resultados ou mensagens.
 * @param flag Valor inteiro que indica o tipo de resultado da consulta.
 */
void query2(GHashTable *tabela_artistas, int N,char *pais,char *buffer, int flag);

#endif