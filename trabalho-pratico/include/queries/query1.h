/**
 * @file query1.h
 * @author André Ribeiro
 * @author David Costa
 * @author Rodrigo Fernandes
 * @date 6 Jan 2024
 * @brief Declaração da função de consulta 1.
 * 
 * Este arquivo contém a declaração da função `query1`, responsável por realizar a primeira consulta no sistema.
 * Ele recebe informações sobre utilizadores e artistas a partir de tabelas de hash e manipula os dados de acordo com
 * o ID do utilizador fornecido, a string de buffer e um valor de flag.
 */

#ifndef QUERY1_H
#define QUERY1_H

#include <stdio.h>
#include <glib.h>
/**
 * @brief Função para realizar a consulta 1.
 * 
 * A função `query1` realiza uma consulta no sistema com base no ID do utilizador fornecido. Ela utiliza duas tabelas
 * de hash: uma contendo os utilizadores e outra contendo os artistas. Estas tabelas são usadas separadamente, visto que a query1 pode 
 * tratar de artistas e de utilizadores, com base no primeiro caracter da string ID. A função pode modificar o conteúdo do buffer com base no 
 * resultado da consulta e no valor da flag.
 * 
 * 
 * @param tabela_utilizadores Ponteiro para uma tabela de hash contendo os dados dos utilizadores, com o ID como chave.
 * @param tabela_artistas Ponteiro para uma tabela de hash contendo os dados dos artistas, com o ID como chave.
 * @param id ID do utilizador ou artista que será utilizado para filtrar os dados nas tabelas de hash.
 * @param buffer Buffer de string que pode ser modificado pela função para armazenar os resultados.
 * @param flag Valor inteiro usado para indicar o tipo de resultado da consulta. 
 *             
 */
void query1(GHashTable *tabela_utilizadores, GHashTable *tabela_artistas, char *id, char *buffer, int flag);


#endif