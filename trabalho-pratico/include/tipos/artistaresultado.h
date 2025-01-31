/**
 * @file 
 * @author André Ribeiro
 * @author David Costa
 * @author Rodrigo Fernandes
 * @date 6 Jan 2024
 * @brief Ficheiro em que esta definido a estrutura de artistasresultado e todas as funções de criação, getters e setters do mesmo
 *
 * 
*/
#ifndef ARTISTARESULTADO_H
#define ARTISTARESULTADO_H
/**
 * @struct artistasresultado
 * @brief Estrutura que representa os artistasresultado.
 * @details Contém informações detalhadas a função auxiliar que ajuda a resolver a query2.
 * 
 * @var artistaresultado::id
 * ID único do artista.
 * 
 * @var artistaresultado::nome
 * Nome de artista.
 * 
 * @var artistaresultado::tipo
 * Tipo de artista.
 * 
 * @var artistaresultado::pais
 * País do artista
 * 
 * @var artistaresultado::duracao_total
 * Soma da duracao de todas as músicas de um artistas em formato hh:mm:ss
 * 
 * @var artistaresultado::d
 * duracao_total mas em segundos.
 * 
 */

typedef struct artistaresultado ArtistaResultado;
/**
 * @brief Cria uma nova estrutura ArtistaResultado.
 * @details Inicializa os campos da estrutura com valores nulos ou padrão.
 * 
 * @return Ponteiro para a nova estrutura ou NULL em caso de erro.
 */
ArtistaResultado* criar_AR();
/**
* @brief Obtém o ID de artistaresultado.

* @details Retorna uma cópia do valor do campo id da estrutura.
*
* @param a Ponteiro para artistaresultado.
* @return ID de artistaresultado.
*/
char* get_artistaresultado_id(const ArtistaResultado* a);
/**
 * @brief Obtém o nome de artistaresultado.
 * 
 * @details Retorna uma cópia do valor do campo nome da estrutura.
 * 
 * @param a Ponteiro para artistaresultado.
 * @return Nome de artistaresultado.
*/
char* get_artistaresultado_nome(ArtistaResultado* a);
/**
 * @brief Obtém o tipo de artistaresultado.
 * 
 * @details Retorna uma cópia do valor do campo tipo da estrutura.
 * 
 * @param a Ponteiro para artistaresultado.
 * @return String com o nome de artistaresultado.
*/
char* get_artistaresultado_tipo(ArtistaResultado* a);
/**
 * @brief Obtém o país de artistaresultado.
 * 
 * @details Retorna uma cópia do valor do campo país da estrutura.
 * 
 * @param a Ponteiro para artistaresultado.
 * @return String com o país de artistaresultado.
*/
char* get_artistaresultado_pais(ArtistaResultado* a);
/**
 * @brief Obtém o nome de artistaresultado.
 * 
 * @details Retorna uma cópia do valor do campo nome da estrutura.
 * 
 * @param a Ponteiro para artistaresultado.
 * @return String com durção total das músicas de um artista.
*/
char* get_artistaresultado_duracao_total(ArtistaResultado* a);
/**
 * @brief Obtém o a durção das músicas de artistaresultado.
 * 
 * @details Retorna valor da duração das músicas da estrutura mas num valor inteiro.
 * 
 * @param a Ponteiro para artistaresultado.
 * @return Valor de duração.
*/
int get_artistaresultado_d(const ArtistaResultado* a);
/**
 * @brief Define o ID de um artistaresultado.
 * 
 * @details Atualiza o campo 'ID' de um artistaresultado com o fornecido.Este valor é igual ao da estrutura do artista.
 * 
 * @param album Ponteiro para um artistaresultado.
 * @param id String que representa o ID do artistaresultado.
 */ 
void set_artistaresultado_id(ArtistaResultado* a, char *id);
/**
 * @brief Define o nome de um artistaresultado.
 * 
 * @details Atualiza o campo 'nome' de um artistaresultado com o fornecido.Este valor é igual ao da estrutura do artista.
 * 
 * @param album Ponteiro para um artistaresultado.
 * @param nome String que representa o nome do artistaresultado.
 */ 
void set_artistaresultado_nome(ArtistaResultado* a, char *nome);
/**
 * @brief Define o tipo de um artistaresultado.
 * 
 * @details Atualiza o campo 'tipo' de um artistaresultado com o fornecido.Este valor é igual ao da estrutura do artista.
 * 
 * @param album Ponteiro para um artistaresultado.
 * @param tipo String que representa o tipo do artistaresultado.
 */ 
void set_artistaresultado_tipo(ArtistaResultado* a, char *tipo);
/**
 * @brief Define o pais de um artistaresultado.
 * 
 * @details Atualiza o campo 'pais' de um artistaresultado com o fornecido.Este valor é igual ao da estrutura do artista.
 * 
 * @param album Ponteiro para um artistaresultado.
 * @param pais String que representa o pais do artistaresultado.
 */ 
void set_artistaresultado_pais(ArtistaResultado* a, char *pais);
/**
 * @brief Define a duração total de um artistaresultado.
 * 
 * @details Atualiza o campo 'duracao_total' de um artistaresultado com o fornecido.
 * 
 * @param album Ponteiro para um artistaresultado.
 * @param d String que representa o a durcao total das musicas do artistaresultado.
 */ 
void set_artistaresultado_duracao_total(ArtistaResultado* a, char* d);
/**
 * @brief Define o a duração total em inteiro das de um artistaresultado.
 * 
 * @details Atualiza o campo 'd' de um artistaresultado com o fornecido.Este valor é igual obtém-se através da duracao_total da mesma estrutura.
 * 
 * @param album Ponteiro para um artistaresultado.
 * @param id Inteiro que representa a duração total em segundos de todas as musicas do artistaresultado.
 */ 
void set_artistaresultado_d(ArtistaResultado* a, int d);
/**
 * @brief Liberta a memória alocada para o ArtistaResultado.
 * 
 * @details Liberta a memória de todos os campos e da estrutura principal.
 * 
 * @param a Ponteiro para o ArtistaResultado a ser libertado.
 */
void free_artistaresultado(ArtistaResultado* a);

#endif