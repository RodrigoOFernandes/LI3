/**
 * @file gestorutilizador.h
 * @author André Ribeiro
 * @author David Costa
 * @author Rodrigo Fernandes
 * @date 6 Jan 2024
 * @brief Ficheiro que contém a definição do gestor de utilizadores.
 * 
 * Este ficheiro define a estrutura e funções para gerir a coleção de utilizadores
 * do sistema. O gestor utiliza uma tabela hash para armazenar e aceder
 * eficientemente aos utilizadores.
 */

#ifndef GESTORUTILIZADOR_H
#define GESTORUTILIZADOR_H

#include <glib.h>
#include "../tipos/utilizador.h"

/**
 * @struct gestorutilizador
 * @brief Estrutura que gere a coleção de utilizadores.
 * @details Encapsula uma tabela hash para armazenamento e gestão eficiente
 * dos utilizadores do sistema. A tabela hash utiliza os usernames dos utilizadores como chaves.
 */
typedef struct gestorutilizador GestorUtilizador;

/**
 * @brief Liberta toda a memória associada ao gestor de utilizadores.
 * 
 * Liberta a memória da tabela hash e de todos os utilizadores nela contidos,
 * bem como a própria estrutura do gestor.
 * 
 * @param g Ponteiro para o gestor a ser libertado.
 */
void GestorUtilizadorDestroy(GestorUtilizador* g);

/**
 * @brief Inicializa um novo gestor de utilizadores.
 * 
 * Aloca e inicializa uma nova estrutura GestorUtilizador, incluindo a sua
 * tabela hash interna para armazenamento dos utilizadores.
 * 
 * @return Ponteiro para o novo gestor de utilizadores inicializado ou NULL em caso de erro.
 */
GestorUtilizador* GestorUtilizadorInit();

/**
 * @brief Obtém a tabela hash de utilizadores.
 * 
 * @param g Ponteiro para o gestor de utilizadores.
 * @return Ponteiro para a tabela hash que contém os utilizadores.
 */
GHashTable* getUtilizadores(GestorUtilizador* g);

#endif