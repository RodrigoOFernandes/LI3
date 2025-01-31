/**
 * @file 
 * @author André Ribeiro
 * @author David Costa
 * @author Rodrigo Fernandes
 * @date 6 Jan 2024
 * @brief Ficheiro em que esta definido a estrutura de album e todas as funções de criação, getters e setters do mesmo
 *
 * 
*/

#ifndef ALBUM_H
#define ALBUM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <glib.h>

/**
 * @struct album
 * @brief Estrutura que representa um álbum.
 * @details Contém informações detalhadas sobre um álbum, incluindo seu ID, título,
 * IDs dos artistas, ano de lançamento e produtores.
 * 
 * @var album::id
 * ID único do álbum.
 * 
 * @var album::title
 * Título do álbum.
 * 
 * @var album::artists_id
 * Array de strings contendo os IDs dos artistas associados ao álbum.
 * 
 * @var album::year
 * Ano de lançamento do álbum.
 * 
 * @var album::producers
 * Array de strings contendo os produtores do álbum.
 */

typedef struct album Album;
/**
 * @brief Cria um novo álbum.
 * 
 * @details Aloca memória para um novo objeto do tipo Album e inicializa todos os
 * seus campos com valores padrão (NULL ou 0 para inteiros como é o caso do ano).
 * 
 * @return Ponteiro para o novo álbum, ou NULL se a alocação de memória falhar.
 */
Album* criar_album();
/**
 * @brief Cria uma cópia de um álbum.
 * 
 * @details Copia todos os campos de um álbum original para um novo objeto do
 * tipo Album, garantindo que os dados sejam independentes.
 * 
 * @param original Ponteiro para o álbum original.
 * @return Ponteiro para o novo álbum clonado, ou NULL se a alocação de memória falhar.
 */
Album* clone_album(Album* original);
/**
 * @brief Insere um álbum em uma tabela hash.
 * 
 * @details Cria uma cópia do álbum fornecido e insere na tabela hash,
 * utilizando o ID do álbum como chave. O álbum original é libertado após a inserção.
 * 
 * @param albums Tabela hash onde o álbum será inserido.
 * @param a Ponteiro para o álbum a ser inserido.
 */
void insert_album(GHashTable* albums, Album* a);
/**
 * @brief Obtém o ID do álbum.
 * 
 * @details Retorna uma cópia da string que representa o ID do álbum.
 * 
 * @param album Ponteiro para o álbum.
 * @return Ponteiro para uma cópia da string do ID do álbum.
 */
char* getAlbum_id(Album *album);
/**
 * @brief Obtem o título do album.
 * 
 * @details Retorna uma cópia da string que representa o título do album.
 * 
 * @param album Ponteito para álbum.
 * @return Ponteiro para uma cópia da string do título do álbum. 
*/
char* get_album_title(Album *album);
/**
 * @brief Obtem o ano do album.
 * 
 * @details Retorna o valor do campo year da estrutura álbum.
 * 
 * @param album Ponteiro para álbum.
 * @return O ano de lançamento do álbum (em inteiro) 
*/
int get_album_year(Album *album);
/**
 * @brief Obtém os IDs dos artistas associados ao álbum.
 * 
 * @details Retorna uma cópia do array de strings que contém os IDs dos artistas associados.
 * 
 * @param album Ponteiro para o álbum.
 * @return Ponteiro para um array de strings contendo os IDs dos artistas. 
 *         Retorna NULL se o campo `artists_id` do álbum for NULL.
 */
char** get_album_artists_id(Album *album);
/**
 * @brief Obtém os produtores associados ao álbum.
 * 
 * @details Retorna uma cópia do array de strings que contém os produtores associados.
 * 
 * @param album Ponteiro para o álbum.
 * @return Ponteiro para um array de strings contendo os produtores. 
 *         Retorna NULL se o campo `producers` do álbum for NULL.
 */
char** get_album_producers(Album *album);
/**
 * @brief Define todos os parametros de um album.
 * 
 * @details Com a ajuda das funções definidas em seguida, altera os valores de
 * álbum com os fornecidos.
 * 
 * @param album Ponteiro para um album.
 * @param id String que representa o ID do álbum.
 * @param title String que representa o título do álbum.
 * @param artists_id Array de strings dos IDs dos artistas.
 * @param year Ano de lançamento do álbum.
 * @param producers Array de strings dos produtores.
*/
void set_album(Album* album, char* id, char* title, char** artists_id, int year, char** producers);
/**
 * @brief Define o ID de um álbum.
 * 
 * @details Atualiza o campo 'ID' de um álbum com o fornecido.
 * 
 * @param album Ponteiro para um álbum.
 * @param id String que representa o ID do álbum.
 */ 
void setAlbum_id(Album* album, char* id);
/**
 * @brief Define o título de um álbum.
 * 
 * @details Atualiza o campo 'title' de um álbum com o fornecido.
 * 
 * @param album Ponteiro para um álbum.
 * @param title String que representa o ID do álbum.
 */ 
void set_album_title(Album* album, char* title);
/**
 * @brief Define o ano de lançamento do álbum.
 * 
 * @details Atualiza o campo `year` de um álbum com o valor fornecido.
 * 
 * @param album Ponteiro para o álbum.
 * @param year Ano de lançamento do álbum (inteiro).
 */
void set_album_year(Album* album, int year);
/**
 * @brief Define os IDs dos artistas associados ao álbum.
 * 
 * @details Define os IDs dos artistas associados ao álbum, liberando qualquer valor
 * anterior armazenado.
 * 
 * @param album Ponteiro para o álbum.
 * @param artists_id Array de strings representando os novos IDs dos artistas.
 */
void set_album_artists_id(Album* album, char** artists_id);
/**
 * @brief Define os produtores do álbum.
 * 
 * @details Define os produtores associados ao álbum, liberando qualquer valor
 * anterior armazenado.
 * 
 * @param album Ponteiro para o álbum.
 * @param producers Array de strings representando os novos produtores.
 */
void set_album_producers(Album* album, char** producers);
/**
 * @brief Liberta a memória associada a um álbum.
 * 
 * @details Liberta toda a memória alocada para os campos do álbum e o próprio objeto.
 * 
 * @param album Ponteiro para o álbum a ser libertado.
 */
void free_album(gpointer album);
/**
 * @brief Liberta a memória associada ao ID de um álbum.
 * 
 * @details Liberta a memória alocada para a string que representa o ID do álbum.
 * 
 * @param id Ponteiro para o ID a ser libertado.
 */
void free_id_album(gpointer id);


#endif 
