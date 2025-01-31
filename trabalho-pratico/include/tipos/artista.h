/**
 * @file 
 * @author André Ribeiro
 * @author David Costa
 * @author Rodrigo Fernandes
 * @date 6 Jan 2024
 * @brief Ficheiro em que esta definido a estrutura de arrista e todas as funções de criação, getters e setters do mesmo.
 *
 * 
*/
#ifndef ARTISTA_H
#define ARTISTA_H

#include<glib.h>

/**
 * @struct artista
 * @brief Estrutura que representa um artista.
 * @details Contém informações detalhadas sobre um artista.
 * 
 * @var artista::id
 * @var artista::nome
 * @var artista::description
 * @var artista::recipe_per_stream
 * @var artista::id_constituent
 * @var artista::country
 * @var artista::type
 * @var artista::tempo_total
 * @var artista::n_ambul_individual
 * @var artista::reps_semana_ano
 * @var artista::total_recipe
*/
typedef struct artista Artista;

/**
 * @brief Cria um novo artista.
 * 
 * @details Aloca memória para um novo objeto do tipo Artista e inicializa todos 
 * os seus campos com valores neutros (NULL ou 0 para inteiros). No caso da variavel 
 * reps_semana_ano cria uma hashtable.
 * 
 * @return Ponteiro para um novo artista, ou NULL se a alocação de memória falhar.
*/
Artista* cria_artista();
/**
 * @brief Cria uma cópia de um artista.
 * 
 * @details Copia todos os campos de um artista original para um novo objeto do
 * tipo Artista, garantindo que os dados sejam independentes. Usa o auxilio de setters
 * posteriormente definidos.
 * 
 * @param original Ponteiro para o artista original.
 * @return Ponteiro para o novo artista clonado, ou NULL se a alocação de memória falhar.
 */
Artista* clone_artista(Artista* original);
/**
 * @brief Liberta a memória associada a um artista.
 * 
 * @details Liberta toda a memória alocada para os campos do artista e o próprio objeto.
 * 
 * @param a Ponteiro para o artista a ser libertado.
 */
void freeArtista(Artista * a);
/**
 * @brief Obtém o ID do artista.
 * 
 * @details Retorna uma cópia do ID do artista armazenado.
 * 
 * @param artista Ponteiro para o artista.
 * @return String contendo o ID do artista. 
 */
char* get_artista_id(Artista* artista);
/**
 * @brief Obtém o nome do artista.
 * 
 * @details Retorna uma cópia do nome do artista armazenado.
 * 
 * @param artista Ponteiro para o artista.
 * @return String contendo o nome do artista.
*/
char* get_artista_nome(Artista* artista);
/**
 * @brief Obtém a descrição de um artista.
 * 
 * @details Retorna uma cópia da descrição do artista armazenada.
 * 
 * @param artista Ponteiro para o artista.
 * @return String contendo a descrição do artista.
*/
char* get_artista_description(Artista* artista);
/**
 * @brief Obtém a receita por stream do artista.
 * 
 * @details Retorna o valor do campo recipe_per_stream da estrutura artista.
 * 
 * @param artista Ponteiro para artista.
 * @return Valor do campo recipe_per_stream.
*/
float get_artista_recipe_per_stream(Artista* artista);
/**
 * @brief Obtém os IDs dos constituintes do artista.
 * 
 * @details Retorna uma cópia do array de strings contendo os IDs dos constituintes
 * associados ao artista. Aplicável apenas para artistas coletivos.
 * 
 * @param artista Ponteiro para o artista.
 * @return Ponteiro para um array de strings contendo os IDs dos constituintes.
 *         Retorna NULL se não houver constituintes ou em caso de falha na alocação.
 */
char** get_artista_id_constituent(Artista* artista);
/**
 * @brief Obtém o país do artista
 * 
 * @details Retorna uma cópia do país do artista armazenado.
 * 
 * @param artista Ponteiro para o artista.
 * @return String contendo o país do artista.
*/
char* get_artista_country(Artista* artista);
/**
 * @brief Obtém o tipo do artista (individual ou coletivo).
 * 
 * @details Retorna uma cópia do tipo do artista armazenado.
 * 
 * @param artista Ponteiro para o artista.
 * @return String contendo o tipo do artista.
*/
char* get_artista_type(Artista* artista);
/**
 * @brief Obtém a soma da duração das músicas de um artista.
 * 
 * @details Retorna o valor do campo tempo da estrutura artista.
 * 
 * @param artista Ponteiro para o artista.
 * @return Valor do campo tempo.
*/
int get_artista_tempo(Artista* artista);
/**
 * @brief Obtém o número de albuns do artista.
 * 
 * @details Retrona o número de albuns de que um artista faz parte.
 * 
 * @param artista Ponteiro para o artista.
 * @return Número de albuns.
*/
int get_n_album(Artista *a);
/**
 * @brief Obtém a receita total acumulada pelo artista.
 * 
 * @param a Ponteiro para o artista.
 * @return Receita total acumulada (float).
 */
float get_total_recipe(Artista *a);
/**
 * @brief Obtém a tabela hash de reproduções por semana e ano de um artista.
 * 
 * @details Esta função retorna um ponteiro para a tabela hash associada ao campo
 * `reps_semana_ano` de um artista. A tabela hash armazena os dados de reproduções
 * organizados por semana e ano.
 * 
 * @param a Ponteiro para a estrutura do tipo `Artista`.
 * 
 * @return Ponteiro para a tabela hash de reproduções por semana e ano.
 *         Retorna NULL se o ponteiro do artista for inválido.
 */
GHashTable* get_reps_por_semana(Artista* a);
/**
 * @brief Define o ID do artista.
 * 
 * @details Define o ID do artista, libertando qualquer valor anterior armazenado.
 * 
 * @param artista Ponteiro para o artista.
 * @param id String representando o novo ID do artista.
 */
void set_artista_id(Artista* artista, char* id);
void set_total_recipe(Artista *a, float n);
void set_n_album(Artista *a, int n);
void set_artista_nome(Artista* artista, char* nome);
void set_artista_description(Artista* artista, char* description);
void set_artista_recipe_per_stream(Artista* artista, float recipe);
/**
 * @brief Define os IDs dos constituintes do artista.
 * 
 * @details Define os IDs dos constituintes associados ao artista, libertando qualquer valor
 * anterior armazenado.
 * 
 * @param artista Ponteiro para o artista.
 * @param id_constituent Array de strings contendo os novos IDs dos constituintes.
 */
void set_artista_id_constituent(Artista* artista, char** id_constituent);
/**
 * @brief Define o país de um artista.
 * 
 * @details Atualiza o campo 'country' de um artista fornecido.
 * 
 * @param artista Ponteiro para o artista.
 * @param country String que representa o novo país do artista.
*/
void set_artista_country(Artista* artista, char* country);
/**
 * @brief Define o tipo de um artista.
 * 
 * @details Atualiza o campo 'type' de um artista fornecido.
 * 
 * @param artista Ponteiro para o artista.
 * @param country String que representa o novo tipo do artista.
*/
void set_artista_type(Artista* artista, char* type);
/**
 * @brief Define o tempo total para um artista.
 *
 * @details Esta função define o valor do campo `tempo_total` de uma estrutura
 * do tipo `Artista` para o valor especificado em `tempo`.
 *
 * @param a Ponteiro para a estrutura do tipo `Artista` que terá o tempo ajustado.
 * @param tempo Valor inteiro que será atribuído ao campo `tempo_total`.
 */
void set_artista_tempo(Artista* a, int t);
/**
 * @brief Define todos os parametros de um artista.
 * 
 * @details Com a ajuda das funções definidas anteriormente, altera os valores de
 * artista com os fornecidos.
 * 
 * @param artista Ponteiro para um artista.
 * @param id String que representa o ID do artista.
 * @param nome String que representa o nome do artista.
 * @param description String que representa a descrição do artista.
 * @param recipe_per_stream Receita por stream do artista.
 * @param id_constituent Array de strings dos constituintes em cado de ser um grupo.
 * @param  country String que representa o país do artista.
 * @param type String que representa o tipo do artista.
*/
void set_artista(Artista* artista, char* id, char* nome, char* description, 
                 float recipe_per_stream, char** id_constituent, 
                 char* country, char* type);
/**
 * @brief Liberta a memória associada ao ID de um artista.
 * 
 * @param id Ponteiro para o ID a ser libertado.
 */
void free_idartista(gpointer id);
/**
 * @brief Libetra um artista armazenado em uma tabela hash.
 * 
 * @param art Ponteiro para o artista a ser libertado.
 */
void free_artista(gpointer art);
/**
 * @brief Insere um artista em uma tabela hash.
 * 
 * @details Cria uma cópia do artista fornecido e o insere na tabela hash. O artista
 * original é libertado após a inserção.
 * 
 * @param tabela Tabela hash onde o artista será inserido.
 * @param a Ponteiro para o artista a ser inserido.
 */
void insert_artista(GHashTable* tabela, Artista* a);
/**
 * @brief Atualiza o contador de reproduções por semana e ano.
 * 
 * @details Incrementa o contador de reproduções associado a uma determinada semana e ano.
 * 
 * @param a Ponteiro para o artista.
 * @param ano_semana String representando o ano e a semana (formato "YYYY-WW").
 */
void insert_counter(Artista *a, char* ano_semana);

#endif