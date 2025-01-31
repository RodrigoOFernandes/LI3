/**
 * @file string_aux.h
 * @author André Ribeiro
 * @author David Costa
 * @author Rodrigo Fernandes
 * @date 6 Jan 2024
 * @brief Declaração das funções auxiliares para manipulação de strings.
 * 
 * Este ficheiro contém a declaração de funções utilitárias para manipulação
 * de strings, incluindo remoção de caracteres especiais, manipulação de arrays
 * de strings e operações de concatenação.
 */

#ifndef STRING_AUX_H
#define STRING_AUX_H

/**
 * @brief Remove aspas de uma string.
 * 
 * @details Remove todas as aspas (") de uma string, movendo os caracteres
 * restantes para preencher os espaços vazios. A string é modificada in-place.
 * 
 * @param linha String a ser processada
 */
void removeaspas(char *linha);

/**
 * @brief Remove o caractere de nova linha de uma string.
 * 
 * @details Procura e substitui o primeiro caractere de nova linha (\n)
 * encontrado na string por um terminador nulo (\0).
 * 
 * @param str String a ser processada
 */
void remove_newline(char *str);

/**
 * @brief Processa um array de strings removendo caracteres desnecessários.
 * 
 * @details Cria uma nova cópia do array de strings, removendo caracteres
 * específicos (como colchetes e aspas) de cada elemento. Usado principalmente
 * para processar arrays de IDs.
 * 
 * @param array Array de strings original
 * @return Novo array de strings processado ou NULL em caso de erro
 */
char **elimina_desnecessarios(char **array);

/**
 * @brief Processa um array de strings de artistas removendo caracteres desnecessários.
 * 
 * @details Similar a elimina_desnecessarios(), mas com tratamento específico
 * para arrays de IDs de artistas.
 * 
 * @param array Array de strings original
 * @return Novo array de strings processado ou NULL em caso de erro
 */
char **elimina_desnecessarios_a(char **array);

/**
 * @brief Liberta a memória de um array de strings.
 * 
 * @details Liberta a memória alocada para cada string no array e depois
 * liberta o próprio array.
 * 
 * @param lista Array de strings a ser libertado
 */
void free_lista(char **lista);

/**
 * @brief Concatena um caminho base com um nome de ficheiro.
 * 
 * @details Cria uma nova string que combina um caminho base com um nome de
 * ficheiro, garantindo a formatação correta do caminho.
 * 
 * @param path Caminho base
 * @param ficheiro Nome do ficheiro
 * @return Nova string contendo o caminho completo ou NULL em caso de erro
 */
char* juntar(char *path, char *ficheiro);

#endif