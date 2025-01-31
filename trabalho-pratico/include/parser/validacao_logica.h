/**
 * @file validacao_logica.h
 * @author André Ribeiro
 * @author David Costa
 * @author Rodrigo Fernandes
 * @date 6 Jan 2024
 * @brief Declaração das funções de validação lógica das entidades.
 * 
 * Este ficheiro contém a declaração das funções responsáveis pela validação
 * lógica das diferentes entidades do sistema, garantindo a consistência e
 * integridade dos dados entre as várias estruturas.
 */

#ifndef VALIDACAO_LOGICA_H
#define VALIDACAO_LOGICA_H

#include <glib.h>
#include <stdio.h>
#include "../tipos/artista.h"
#include "../tipos/musica.h"
#include "../gestores/gestor.h"
#include "../tipos/utilizador.h"

/**
 * @brief Valida logicamente um utilizador.
 * 
 * @details Verifica se todas as músicas na lista de músicas gostadas do utilizador
 * existem na base de dados. Durante a validação:
 * 1. Verifica a existência de cada música referenciada
 * 2. Atualiza a matriz de géneros se o utilizador for válido
 * 3. Limpa referências inválidas
 * 
 * @param g Ponteiro para o gestor que contém todas as estruturas de dados
 * @param u Ponteiro para o utilizador a ser validado
 * @return 1 se o utilizador é válido, 0 caso contrário
 */
int validar_utilizador(Gestor *g, Utilizador *u);

/**
 * @brief Valida logicamente uma música.
 * 
 * @details Verifica se:
 * 1. O álbum referenciado existe
 * 2. Todos os artistas referenciados existem
 * 3. Atualiza o tempo total de reprodução dos artistas se a música for válida
 * 
 * @param a Tabela hash contendo os artistas
 * @param albums Tabela hash contendo os álbuns
 * @param m Ponteiro para a música a ser validada
 * @return 1 se a música é válida, 0 caso contrário
 */
int validar_musica(GHashTable *a, GHashTable *albums, Musica *m);

/**
 * @brief Valida logicamente um artista.
 * 
 * @details Verifica a consistência dos dados do artista:
 * 1. Se for um artista individual, não deve ter constituintes
 * 2. Valida que os IDs dos constituintes estão no formato correto
 * 
 * @param a Ponteiro para o artista a ser validado
 * @return 1 se o artista é válido, 0 caso contrário
 */
int validar_artista(Artista *a);

#endif