/**
 * @file gestormusica.h
 * @author André Ribeiro
 * @author David Costa
 * @author Rodrigo Fernandes
 * @date 6 Jan 2024
 * @brief Ficheiro que contém a definição do gestor de músicas.
 * 
 * Este ficheiro define a estrutura e funções para gerir a coleção de músicas
 * do sistema. O gestor utiliza uma tabela hash para armazenar e aceder
 * eficientemente às músicas.
 */

#ifndef GESTORMUSICA_H
#define GESTORMUSICA_H

#include <glib.h>

/**
 * @struct gestormusica
 * @brief Estrutura que gere a coleção de músicas.
 * @details Encapsula uma tabela hash para armazenamento e gestão eficiente
 * das músicas do sistema. A tabela hash utiliza os IDs das músicas como chaves.
 */
typedef struct gestormusica GestorMusica;

/**
 * @brief Inicializa um novo gestor de músicas.
 * 
 * Aloca e inicializa uma nova estrutura GestorMusica, incluindo a sua
 * tabela hash interna para armazenamento das músicas.
 * 
 * @return Ponteiro para o novo gestor de músicas inicializado ou NULL em caso de erro.
 */
GestorMusica* GestorMusicaInit();

/**
 * @brief Liberta toda a memória associada ao gestor de músicas.
 * 
 * Liberta a memória da tabela hash e de todas as músicas nela contidas,
 * bem como a própria estrutura do gestor.
 * 
 * @param g Ponteiro para o gestor a ser libertado.
 */
void GestorMusicaDestroy(GestorMusica* g);

/**
 * @brief Obtém a tabela hash de músicas.
 * 
 * @param g Ponteiro para o gestor de músicas.
 * @return Ponteiro para a tabela hash que contém as músicas.
 */
GHashTable* getMusicas(GestorMusica* g);

#endif