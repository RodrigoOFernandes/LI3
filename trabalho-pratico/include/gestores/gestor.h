/**
 * @file gestor.h
 * @author André Ribeiro
 * @author David Costa
 * @author Rodrigo Fernandes
 * @date 6 Jan 2024
 * @brief Ficheiro que contém a definição do gestor principal do sistema.
 * 
 * Este ficheiro define a estrutura principal do gestor que centraliza o acesso
 * a todos os gestores específicos (músicas, utilizadores, artistas, álbuns)
 * e à matriz de géneros musicais.
 */

#ifndef GESTOR_H
#define GESTOR_H

#include "gestorartista.h"
#include "gestormusica.h"
#include "gestorutilizador.h"
#include "gestoralbum.h"
#include "../include/tipos/generosmatrix.h"

/**
 * @struct gestor
 * @brief Estrutura principal que agrega todos os gestores do sistema.
 * @details Contém ponteiros para todos os gestores específicos e para a matriz de géneros,
 * centralizando o acesso a todas as funcionalidades do sistema.
 */
typedef struct gestor Gestor;

/**
 * @brief Inicializa um novo gestor.
 * 
 * Aloca e inicializa uma nova estrutura Gestor, incluindo todos os seus
 * subgestores (músicas, utilizadores, artistas, álbuns) e a matriz de géneros.
 * 
 * @return Ponteiro para o novo gestor inicializado.
 */
Gestor* GestorInit();

/**
 * @brief Liberta toda a memória associada ao gestor.
 * 
 * Liberta a memória de todos os subgestores e da própria estrutura do gestor.
 * 
 * @param g Ponteiro para o gestor a ser libertado.
 */
void GestorDestroy(Gestor* g);

/**
 * @brief Obtém o gestor de músicas.
 * 
 * @param g Ponteiro para o gestor principal.
 * @return Ponteiro para o gestor de músicas.
 */
GestorMusica* getGestorMusica(Gestor *g);

/**
 * @brief Obtém o gestor de utilizadores.
 * 
 * @param g Ponteiro para o gestor principal.
 * @return Ponteiro para o gestor de utilizadores.
 */
GestorUtilizador* getGestorUtilizador(Gestor *g);

/**
 * @brief Obtém o gestor de artistas.
 * 
 * @param g Ponteiro para o gestor principal.
 * @return Ponteiro para o gestor de artistas.
 */
GestorArtista* getGestorArtista(Gestor *g);

/**
 * @brief Obtém o gestor de álbuns.
 * 
 * @param g Ponteiro para o gestor principal.
 * @return Ponteiro para o gestor de álbuns.
 */
GestorAlbum* getGestorAlbum(Gestor *g);

/**
 * @brief Obtém a matriz de géneros.
 * 
 * @param g Ponteiro para o gestor principal.
 * @return Ponteiro para a matriz de géneros.
 */
GenerosMatrix* getGenerosMatrix(Gestor *g);

#endif