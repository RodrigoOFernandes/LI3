/**
 * @file gestorhistorico.h
 * @author André Ribeiro
 * @author David Costa
 * @author Rodrigo Fernandes
 * @date 6 Jan 2024
 * @brief Ficheiro que contém a definição do gestor de histórico.
 * 
 * Este ficheiro define a estrutura e funções para gerir o histórico de reproduções
 * do sistema. O gestor utiliza uma tabela hash para armazenar e aceder
 * eficientemente aos registos históricos.
 */

#ifndef GESTORHISTORICO_H
#define GESTORHISTORICO_H

#include <glib.h>
#include "../tipos/historico.h"

/**
 * @struct gestorhistorico
 * @brief Estrutura que gere a coleção de registos históricos.
 * @details Encapsula uma tabela hash para armazenamento e gestão eficiente
 * dos registos históricos do sistema. A tabela hash utiliza os IDs dos registos como chaves.
 */
typedef struct gestorhistorico GestorHistorico;

/**
 * @brief Inicializa um novo gestor de histórico.
 * 
 * Aloca e inicializa uma nova estrutura GestorHistorico, incluindo a sua
 * tabela hash interna para armazenamento dos registos.
 * 
 * @return Ponteiro para o novo gestor de histórico inicializado ou NULL em caso de erro.
 */
GestorHistorico* GestorHistoricoInit();

/**
 * @brief Liberta toda a memória associada ao gestor de histórico.
 * 
 * Liberta a memória da tabela hash e de todos os registos nela contidos,
 * bem como a própria estrutura do gestor.
 * 
 * @param g Ponteiro para o gestor a ser libertado.
 */
void GestorHistoricoDestroy(GestorHistorico* g);

/**
 * @brief Obtém a tabela hash de registos históricos.
 * 
 * @param g Ponteiro para o gestor de histórico.
 * @return Ponteiro para a tabela hash que contém os registos históricos.
 */
GHashTable* getHistorico(GestorHistorico* g);

/**
 * @brief Insere um registo no histórico.
 * 
 * @param g Ponteiro para o gestor de histórico.
 * @param h Ponteiro para o registo histórico a inserir.
 */
void insert_historico(GestorHistorico* g, Historico* h);

/**
 * @brief Liberta a memória associada a um ID de registo histórico.
 * 
 * @param id Ponteiro para o ID a ser libertado.
 */
void free_idhistorico(gpointer id);

/**
 * @brief Liberta a memória associada a um registo histórico.
 * 
 * @param h Ponteiro para o registo histórico a ser libertado.
 */
void free_historico_entry(gpointer h);

#endif