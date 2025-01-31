/**
 * @file historico.h
 * @author André Ribeiro
 * @author David Costa
 * @author Rodrigo Fernandes
 * @date 6 Jan 2024
 * @brief Declaração das funções e estrutura do histórico de reproduções.
 * 
 * Este arquivo contém a declaração da estrutura `Historico` e das funções associadas a ela,
 * incluindo criação, manipulação e libertação de memória das entradas do histórico de reproduções.
 */

#ifndef HISTORICO_H
#define HISTORICO_H

/**
 * @struct historico
 * @brief Estrutura que representa uma entrada no histórico de reproduções.
 * 
 * Contém informações sobre uma reprodução específica, incluindo identificadores,
 * momento da reprodução, duração e plataforma utilizada.
 */
typedef struct historico Historico;

/**
 * @brief Cria uma nova entrada no histórico.
 * 
 * @details Aloca memória para uma nova estrutura `Historico` e inicializa seus campos com valores nulos.
 * 
 * @return Ponteiro para a nova estrutura `Historico` ou NULL em caso de falha na alocação.
 */
Historico* criar_historico();

/**
 * @brief Liberta a memória de uma entrada do histórico.
 * 
 * @details Liberta toda a memória alocada para os campos da estrutura `Historico`.
 * 
 * @param h Ponteiro para a entrada do histórico a ser libertada.
 */
void free_historico(Historico* h);

/**
 * @brief Cria uma cópia de uma entrada do histórico.
 * 
 * @details Cria uma nova entrada do histórico com os mesmos valores da entrada original.
 * 
 * @param original Ponteiro para a entrada do histórico a ser clonada.
 * @return Ponteiro para a nova entrada clonada ou NULL em caso de falha.
 */
Historico* clone_historico(Historico* original);

/**
 * @brief Obtém o ID da entrada do histórico.
 * 
 * @details Retorna uma cópia do ID da entrada do histórico.
 * 
 * @param h Ponteiro para a entrada do histórico.
 * @return String contendo o ID da entrada ou NULL se não existir.
 */
char* get_historico_id(const Historico* h);

/**
 * @brief Obtém o ID do utilizador associado à entrada.
 * 
 * @details Retorna uma cópia do ID do utilizador que realizou a reprodução.
 * 
 * @param h Ponteiro para a entrada do histórico.
 * @return String contendo o ID do utilizador ou NULL se não existir.
 */
char* get_historico_user_id(const Historico* h);

/**
 * @brief Obtém o ID da música reproduzida.
 * 
 * @details Retorna uma cópia do ID da música associada à reprodução.
 * 
 * @param h Ponteiro para a entrada do histórico.
 * @return String contendo o ID da música ou NULL se não existir.
 */
char* get_historico_music_id(const Historico* h);

/**
 * @brief Obtém o timestamp da reprodução.
 * 
 * @details Retorna uma cópia do timestamp que indica quando a reprodução ocorreu.
 * 
 * @param h Ponteiro para a entrada do histórico.
 * @return String contendo o timestamp ou NULL se não existir.
 */
char* get_historico_timestamp(const Historico* h);

/**
 * @brief Obtém a duração da reprodução.
 * 
 * @details Retorna uma cópia da duração da reprodução.
 * 
 * @param h Ponteiro para a entrada do histórico.
 * @return String contendo a duração ou NULL se não existir.
 */
char* get_historico_duration(const Historico* h);

/**
 * @brief Obtém a plataforma utilizada na reprodução.
 * 
 * @details Retorna uma cópia da plataforma onde a música foi reproduzida.
 * 
 * @param h Ponteiro para a entrada do histórico.
 * @return String contendo a plataforma ou NULL se não existir.
 */
char* get_historico_platform(const Historico* h);

/**
 * @brief Define o ID da entrada do histórico.
 * 
 * @details Atualiza o ID da entrada, libertando o valor anterior se existir.
 * 
 * @param h Ponteiro para a entrada do histórico.
 * @param id Novo ID a ser definido.
 */
void set_historico_id(Historico* h, char* id);

/**
 * @brief Define o ID do utilizador da entrada.
 * 
 * @details Atualiza o ID do utilizador, libertando o valor anterior se existir.
 * 
 * @param h Ponteiro para a entrada do histórico.
 * @param user_id Novo ID de utilizador a ser definido.
 */
void set_historico_user_id(Historico* h, char* user_id);

/**
 * @brief Define o ID da música da entrada.
 * 
 * @details Atualiza o ID da música, libertando o valor anterior se existir.
 * 
 * @param h Ponteiro para a entrada do histórico.
 * @param music_id Novo ID de música a ser definido.
 */
void set_historico_music_id(Historico* h, char* music_id);

/**
 * @brief Define o timestamp da entrada.
 * 
 * @details Atualiza o timestamp da reprodução, libertando o valor anterior se existir.
 * 
 * @param h Ponteiro para a entrada do histórico.
 * @param timestamp Novo timestamp a ser definido.
 */
void set_historico_timestamp(Historico* h, char* timestamp);

/**
 * @brief Define a duração da reprodução.
 * 
 * @details Atualiza a duração da reprodução, libertando o valor anterior se existir.
 * 
 * @param h Ponteiro para a entrada do histórico.
 * @param duration Nova duração a ser definida.
 */
void set_historico_duration(Historico* h, char* duration);

/**
 * @brief Define a plataforma da reprodução.
 * 
 * @details Atualiza a plataforma onde a música foi reproduzida, libertando o valor anterior se existir.
 * 
 * @param h Ponteiro para a entrada do histórico.
 * @param platform Nova plataforma a ser definida.
 */
void set_historico_platform(Historico* h, char* platform);

#endif