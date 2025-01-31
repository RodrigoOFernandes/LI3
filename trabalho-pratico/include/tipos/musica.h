/**
 * @file musica.h
 * @author André Ribeiro
 * @author David Costa
 * @author Rodrigo Fernandes
 * @date 6 Jan 2024
 * @brief Declaração das funções e estrutura de uma música.
 * 
 * Este ficheiro contém a declaração da estrutura `Musica` e das funções associadas a ela,
 * incluindo funções de criação, manipulação e libertação de memória de uma música.
 */

#ifndef MUSICA_H
#define MUSICA_H

#include <glib.h>

/**
 * @struct musica
 * @brief Estrutura que representa uma música.
 * 
 * Contém informações sobre uma música, incluindo identificador, título, artistas,
 * álbum, duração, género, ano e letra.
 */
typedef struct musica Musica;

/**
 * @brief Cria uma nova música.
 * 
 * @details Aloca memória para uma nova estrutura `Musica` e inicializa todos os seus
 * campos com valores nulos.
 * 
 * @return Ponteiro para a nova estrutura `Musica` ou NULL em caso de falha na alocação.
 */
Musica* criarMusica();

/**
 * @brief Liberta a memória de uma música.
 * 
 * @details Liberta toda a memória alocada para os campos da estrutura `Musica`.
 * 
 * @param musica Ponteiro para a música a ser libertada.
 */
void freeMusica(Musica *musica);

/**
 * @brief Obtém o género da música.
 * 
 * @details Retorna uma cópia do género musical armazenado.
 * 
 * @param musica Ponteiro para a música.
 * @return String contendo o género musical.
 */
char* get_genero(Musica *musica);

/**
 * @brief Obtém a duração da música.
 * 
 * @details Retorna uma cópia da duração da música no formato hh:mm:ss.
 * 
 * @param musica Ponteiro para a música.
 * @return String contendo a duração.
 */
char* get_duracao(Musica *musica);

/**
 * @brief Obtém os IDs dos artistas da música.
 * 
 * @details Retorna uma cópia do array de IDs dos artistas associados à música.
 * 
 * @param musica Ponteiro para a música.
 * @return Array de strings contendo os IDs dos artistas.
 */
char** get_id_artistas(Musica *musica);

/**
 * @brief Define o ID da música.
 * 
 * @details Atualiza o ID da música, libertando o valor anterior se existir.
 * 
 * @param musica Ponteiro para a música.
 * @param id Novo ID a ser definido.
 */
void set_id(Musica *musica, char *id);

/**
 * @brief Define o título da música.
 * 
 * @details Atualiza o título da música, libertando o valor anterior se existir.
 * 
 * @param musica Ponteiro para a música.
 * @param nome_musica Novo título a ser definido.
 */
void set_nome_musica(Musica *musica, char *nome_musica);

/**
 * @brief Define os IDs dos artistas da música.
 * 
 * @details Atualiza o array de IDs dos artistas, libertando os valores anteriores se existirem.
 * 
 * @param musica Ponteiro para a música.
 * @param id_artistas Novo array de IDs dos artistas.
 */
void set_id_artistas(Musica *musica, char **id_artistas);

/**
 * @brief Define a duração da música.
 * 
 * @details Atualiza a duração da música, libertando o valor anterior se existir.
 * 
 * @param musica Ponteiro para a música.
 * @param duracao Nova duração no formato hh:mm:ss.
 */
void set_duracao(Musica *musica, char* duracao);

/**
 * @brief Obtém o ID do álbum da música.
 * 
 * @details Retorna uma cópia do ID do álbum associado à música.
 * 
 * @param musica Ponteiro para a música.
 * @return String contendo o ID do álbum.
 */
char* get_album_id(Musica* musica);

/**
 * @brief Define o ID do álbum da música.
 * 
 * @details Atualiza o ID do álbum, libertando o valor anterior se existir.
 * 
 * @param musica Ponteiro para a música.
 * @param album Novo ID do álbum.
 */
void set_album_id(Musica* musica, char* album);

/**
 * @brief Obtém a letra da música.
 * 
 * @details Retorna uma cópia da letra da música.
 * 
 * @param musica Ponteiro para a música.
 * @return String contendo a letra da música.
 */
char *get_letra(Musica *musica);

/**
 * @brief Obtém o ano da música.
 * 
 * @details Retorna o ano de lançamento da música.
 * 
 * @param musica Ponteiro para a música.
 * @return Inteiro representando o ano.
 */
int get_ano(Musica *musica);

/**
 * @brief Define o género da música.
 * 
 * @details Atualiza o género musical, libertando o valor anterior se existir.
 * 
 * @param musica Ponteiro para a música.
 * @param genero Novo género musical.
 */
void set_genero(Musica *musica, char *genero);

/**
 * @brief Define o ano da música.
 * 
 * @details Atualiza o ano de lançamento da música.
 * 
 * @param musica Ponteiro para a música.
 * @param ano Novo ano de lançamento.
 */
void set_ano(Musica *musica, int ano);

/**
 * @brief Define a letra da música.
 * 
 * @details Atualiza a letra da música, libertando o valor anterior se existir.
 * 
 * @param musica Ponteiro para a música.
 * @param letra Nova letra da música.
 */
void set_letra(Musica *musica, char *letra);

/**
 * @brief Cria uma cópia de uma música.
 * 
 * @details Cria uma nova música com os mesmos valores da música original.
 * 
 * @param original Ponteiro para a música a ser clonada.
 * @return Ponteiro para a nova música clonada ou NULL em caso de falha.
 */
Musica* clone_musica(Musica* original);

/**
 * @brief Define todos os atributos de uma música.
 * 
 * @details Atualiza todos os campos da música com os valores fornecidos.
 * 
 * @param m Ponteiro para a música.
 * @param id ID da música.
 * @param nome Título da música.
 * @param idartistas Array de IDs dos artistas.
 * @param album ID do álbum.
 * @param duracao Duração da música.
 * @param genero Género musical.
 * @param ano Ano de lançamento.
 * @param letra Letra da música.
 */
void musicasetter(Musica* m, char *id, char *nome, char **idartistas, char *album, char *duracao, char *genero, int ano, char *letra);

/**
 * @brief Liberta a chave de uma música na tabela hash.
 * 
 * @param key Ponteiro para a chave a ser libertada.
 */
void free_idmusica(gpointer key);

/**
 * @brief Liberta uma música armazenada na tabela hash.
 * 
 * @param m Ponteiro para a música a ser libertada.
 */
void free_musica(gpointer m);

/**
 * @brief Insere uma música na tabela hash.
 * 
 * @details Cria uma cópia da música e a insere na tabela hash, usando o ID como chave.
 * 
 * @param tabela Tabela hash onde a música será inserida.
 * @param musica Ponteiro para a música a ser inserida.
 */
void insert_musica(GHashTable* tabela, Musica* musica);

#endif