/**
 * @file gestoralbum.h
 * @author André Ribeiro
 * @author David Costa
 * @author Rodrigo Fernandes
 * @date 6 Jan 2024
 * @brief Ficheiro que contém a definição do gestor de álbuns.
 * 
 * Este ficheiro define a estrutura e funções para gerir a coleção de álbuns
 * do sistema. O gestor utiliza uma tabela hash para armazenar e aceder
 * eficientemente aos álbuns.
 */

#ifndef GESTORALBUM_H
#define GESTORALBUM_H

#include <glib.h>

/**
 * @struct gestoralbum
 * @brief Estrutura que gere a coleção de álbuns.
 * @details Encapsula uma tabela hash para armazenamento e gestão eficiente
 * dos álbuns do sistema. A tabela hash utiliza os IDs dos álbuns como chaves.
 */
typedef struct gestoralbum GestorAlbum;

/**
 * @brief Inicializa um novo gestor de álbuns.
 * 
 * Aloca e inicializa uma nova estrutura GestorAlbum, incluindo a sua
 * tabela hash interna para armazenamento dos álbuns.
 * 
 * @return Ponteiro para o novo gestor de álbuns inicializado ou NULL em caso de erro.
 */
GestorAlbum *GestorAlbumInit();

/**
 * @brief Liberta toda a memória associada ao gestor de álbuns.
 * 
 * Liberta a memória da tabela hash e de todos os álbuns nela contidos,
 * bem como a própria estrutura do gestor.
 * 
 * @param gestor Ponteiro para o gestor a ser libertado.
 */
void GestorAlbumDestroy(GestorAlbum* gestor);

/**
 * @brief Obtém a tabela hash de álbuns.
 * 
 * @param gestor Ponteiro para o gestor de álbuns.
 * @return Ponteiro para a tabela hash que contém os álbuns.
 */
GHashTable* getAlbuns(GestorAlbum* gestor);

#endif