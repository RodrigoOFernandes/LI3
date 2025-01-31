/**
 * @file gestorartista.h
 * @author André Ribeiro
 * @author David Costa
 * @author Rodrigo Fernandes
 * @date 6 Jan 2024
 * @brief Ficheiro que contém a definição do gestor de artistas.
 * 
 * Este ficheiro define a estrutura e funções para gerir a coleção de artistas
 * do sistema. O gestor utiliza uma tabela hash para armazenar e aceder
 * eficientemente aos artistas.
 */

#ifndef GESTORARTISTA_H
#define GESTORARTISTA_H

#include <glib.h>
#include "../tipos/artista.h"

/**
 * @struct gestorartista
 * @brief Estrutura que gere a coleção de artistas.
 * @details Encapsula uma tabela hash para armazenamento e gestão eficiente
 * dos artistas do sistema. A tabela hash utiliza os IDs dos artistas como chaves.
 */
typedef struct gestorartista GestorArtista;

/**
 * @brief Inicializa um novo gestor de artistas.
 * 
 * Aloca e inicializa uma nova estrutura GestorArtista, incluindo a sua
 * tabela hash interna para armazenamento dos artistas.
 * 
 * @return Ponteiro para o novo gestor de artistas inicializado ou NULL em caso de erro.
 */
GestorArtista* GestorArtistaInit();

/**
 * @brief Liberta toda a memória associada ao gestor de artistas.
 * 
 * Liberta a memória da tabela hash e de todos os artistas nela contidos,
 * bem como a própria estrutura do gestor.
 * 
 * @param g Ponteiro para o gestor a ser libertado.
 */
void GestorArtistaDestroy(GestorArtista* g);

/**
 * @brief Obtém a tabela hash de artistas.
 * 
 * @param g Ponteiro para o gestor de artistas.
 * @return Ponteiro para a tabela hash que contém os artistas.
 */
GHashTable* getArtistas(GestorArtista* g);

#endif