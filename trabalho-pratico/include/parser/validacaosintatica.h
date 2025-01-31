/**
* @file validacaosintatica.h
* @author André Ribeiro
* @author David Costa
* @author Rodrigo Fernandes
* @date 6 Jan 2024
* @brief Declaração das funções de validação sintática dos campos.
* 
* Este ficheiro contém a declaração das funções responsáveis pela validação
* sintática dos diversos campos das entidades do sistema, garantindo que
* os dados estão no formato correto antes de serem processados.
*/

#ifndef VALIDACAO_SINTATICA_H
#define VALIDACAO_SINTATICA_H

/**
* @brief Valida o formato de uma data.
* 
* @details Verifica se uma string de data está no formato correto AAAA/MM/DD e se:
* 1. O formato tem exatamente 10 caracteres
* 2. A data usa '/' como separador
* 3. O mês está entre 1 e 12
* 4. O dia está entre 1 e 31
* 5. A data não é posterior à data atual (2024/09/09)
* 
* @param data String contendo a data a validar
* @return 1 se a data é válida, 0 caso contrário
*/
int eData(char *data);

/**
* @brief Valida o formato de uma duração.
* 
* @details Verifica se uma string de duração está no formato correto HH:MM:SS e se:
* 1. O formato tem exatamente 8 caracteres
* 2. Usa ':' como separador
* 3. As horas estão entre 0 e 99
* 4. Os minutos e segundos estão entre 0 e 59
* 
* @param duracao String contendo a duração a validar
* @return 1 se a duração é válida, 0 caso contrário
*/
int eDuracao(char *duracao);

/**
* @brief Valida um nome de utilizador.
* 
* @details Verifica se um nome de utilizador contém apenas:
* 1. Dígitos (0-9)
* 2. Letras minúsculas (a-z)
* 
* @param user String contendo o nome de utilizador
* @return 1 se o nome é válido, 0 caso contrário
*/
int is_valid_username(const char *user);

/**
* @brief Valida a parte esquerda de um domínio de email.
* 
* @details Verifica se o lstring (parte antes do último ponto) do domínio:
* 1. Tem pelo menos 1 caractere
* 2. Contém apenas letras minúsculas
* 
* @param lstring String contendo a parte esquerda do domínio
* @return 1 se o lstring é válido, 0 caso contrário
*/
int is_valid_lstring(const char *lstring);

/**
* @brief Valida a parte direita de um domínio de email.
* 
* @details Verifica se o rstring (parte após o último ponto) do domínio:
* 1. Tem 2 ou 3 caracteres
* 2. Contém apenas letras minúsculas
* 
* @param rstring String contendo a parte direita do domínio
* @return 1 se o rstring é válido, 0 caso contrário
*/
int is_valid_rstring(const char *rstring);

/**
* @brief Valida um endereço de email.
* 
* @details Verifica se um email está no formato correto:
* 1. Tem uma parte de utilizador válida
* 2. Usa '@' como separador
* 3. Tem um domínio válido com lstring e rstring corretos
* 
* @param email String contendo o email a validar
* @return 1 se o email é válido, 0 caso contrário
*/
int eEmail(char *email);

/**
* @brief Valida uma plataforma.
* 
* @details Verifica se a plataforma é uma das permitidas:
* - "mobile" ou "desktop" (case insensitive)
* 
* @param plataforma String contendo a plataforma a validar
* @return 1 se a plataforma é válida, 0 caso contrário
*/
int ePlataforma(char* plataforma);

/**
* @brief Valida o tipo de artista.
* 
* @details Verifica se o tipo é um dos permitidos:
* - "individual" ou "group" (case insensitive)
* 
* @param tipo String contendo o tipo a validar
* @return 1 se o tipo é válido, 0 caso contrário
*/
int eType(char* tipo);

/**
* @brief Valida o tipo de subscrição.
* 
* @details Verifica se a subscrição é uma das permitidas:
* - "normal" ou "premium"
* 
* @param tipo String contendo o tipo de subscrição a validar
* @return 1 se a subscrição é válida, 0 caso contrário
*/
int eSubscricao(char *tipo);

#endif