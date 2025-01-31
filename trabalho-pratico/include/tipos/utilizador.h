/**
 * @file utilizador.h
 * @author André Ribeiro
 * @author David Costa
 * @author Rodrigo Fernandes
 * @date 6 Jan 2024
 * @brief Declaração das funções e estrutura de um utilizador.
 * 
 * Este arquivo contém a declaração da estrutura `Utilizador` e das funções associadas a ela, 
 * incluindo a criação, manipulação, e libertação de memória de um utilizador, bem como a clonagem 
 * e inserção em uma tabela de hash.
 */
#ifndef UTILIZADOR_H
#define UTILIZADOR_H
/**
 * @struct utilizador
 * @brief Estrutura que representa um utilizador.
 * 
 * Contém informações sobre o utilizador, como nome de usuário, email, nome completo, data de nascimento, 
 * país, subscrição, e uma lista de músicas que o utilizador gostou.
 */
typedef struct utilizador Utilizador;
/**
 * @brief Cria um novo utilizador.
 * 
 * A função aloca memória para uma nova estrutura `Utilizador` e inicializa seus campos com valores nulos.
 * 
 * @return Ponteiro para a nova estrutura `Utilizador` ou NULL em caso de falha na alocação.
 */
Utilizador* criaruser();
/**
 * @brief Liberta a memória de um utilizador.
 * 
 * A função liberta a memória alocada para os campos da estrutura `Utilizador`, incluindo as strings e listas.
 * Após a libertação, a memória da própria estrutura `Utilizador` também é libertada.
 *
 * @param user Ponteiro para a estrutura `Utilizador` a ser libertada.
 */
void free_user(Utilizador *user);
/**
 * @brief Define o nome de usuário de um utilizador.
 * 
 * A função aloca memória para o nome de usuário e o armazena na estrutura `Utilizador`.
 * 
 * @param user Ponteiro para o utilizador.
 * @param nome Nome de utilizador a ser atribuído.
 */
void setusername(Utilizador *user,  char *nome);
/**
 * @brief Define o email de um utilizador.
 * 
 * A função aloca memória para o email e o armazena na estrutura `Utilizador`.
 * 
 * @param user Ponteiro para o utilizador.
 * @param email Email a ser atribuído.
 */
void setemail(Utilizador *user,  char *email);
/**
 * @brief Define o primeiro nome de um utilizador.
 * 
 * A função aloca memória para o primeiro nome e o armazena na estrutura `Utilizador`.
 * 
 * @param user Ponteiro para o utilizador.
 * @param primeiro Primeiro nome a ser atribuído.
 */
void setprimeiro(Utilizador *user,  char *primeiro);
/**
 * @brief Define o último nome de um utilizador.
 * 
 * A função aloca memória para o último nome e o armazena na estrutura `Utilizador`.
 * 
 * @param user Ponteiro para o utilizador.
 * @param ultimo Último nome a ser atribuído.
 */
void setultimo(Utilizador *user,  char *ultimo);
/**
 * @brief Define a data de nascimento de um utilizador.
 * 
 * A função aloca memória para a data de nascimento e a armazena na estrutura `Utilizador`.
 * 
 * @param user Ponteiro para o utilizador.
 * @param data Data de nascimento a ser atribuída.
 */
void setnascimento(Utilizador *user,  char *data);
/**
 * @brief Define o país de origem de um utilizador.
 * 
 * A função aloca memória para o país de origem e o armazena na estrutura `Utilizador`.
 * 
 * @param user Ponteiro para o utilizador.
 * @param pais País de origem a ser atribuído.
 */
void setcountry(Utilizador *user,  char *pais);
/**
 * @brief Define o tipo de subscrição de um utilizador.
 * 
 * A função aloca memória para o tipo de subscrição e o armazena na estrutura `Utilizador`.
 * 
 * @param user Ponteiro para o utilizador.
 * @param tipo Tipo de subscrição a ser atribuído.
 */
void setsubs(Utilizador *user,  char *tipo);
/**
 * @brief Define a lista de gostos de um utilizador.
 * 
 * A função aloca memória para a lista de gostos (músicas) e a armazena na estrutura `Utilizador`.
 * 
 * @param user Ponteiro para o utilizador.
 * @param lista Lista de gostos a ser atribuída.
 */
void setlista(Utilizador *user, char **lista);
/**
 * @brief Define todos os campos de um utilizador.
 * 
 * A função é um setter que define todos os campos da estrutura `Utilizador`, como username, email, nome, etc.
 * 
 * @param user Ponteiro para o utilizador.
 * @param username Nome de usuário do utilizador.
 * @param email Email do utilizador.
 * @param primeiro_nome Primeiro nome do utilizador.
 * @param ultimo_nome Último nome do utilizador.
 * @param birth_date Data de nascimento do utilizador.
 * @param country País de origem do utilizador.
 * @param subscricao Tipo de subscrição do utilizador.
 * @param lista_gostadas Lista de músicas gostados pelo utilizador.
 */
void usersetter(Utilizador *user,  char *username,  char *email,  char *primeiro_nome,  char *ultimo_nome,  char *birth_date,  char *country,  char *subscricao, char **lista_gostadas);
/**
 * @brief Retorna o nome de usuário de um utilizador.
 * 
 * A função retorna uma cópia do nome de usuário da estrutura `Utilizador`.
 * 
 * @param user Ponteiro para o utilizador.
 * @return Cópia do nome de usuário do utilizador ou NULL se não existir.
 */
char* get_utilizador_username(Utilizador *user);
/**
 * @brief Retorna o email de um utilizador.
 * 
 * A função retorna uma cópia do email da estrutura `Utilizador`.
 * 
 * @param user Ponteiro para o utilizador.
 * @return Cópia do email do utilizador ou NULL se não existir.
 */
char* get_utilizador_email(Utilizador *user);
/**
 * @brief Retorna o primeiro nome de um utilizador.
 * 
 * A função retorna uma cópia do primeiro nome da estrutura `Utilizador`.
 * 
 * @param user Ponteiro para o utilizador.
 * @return Cópia do primeiro nome do utilizador ou NULL se não existir.
 */
char* get_utilizador_primeiro_nome(Utilizador *user);
/**
 * @brief Retorna o último nome de um utilizador.
 * 
 * A função retorna uma cópia do último nome da estrutura `Utilizador`.
 * 
 * @param user Ponteiro para o utilizador.
 * @return Cópia do último nome do utilizador ou NULL se não existir.
 */
char* get_utilizador_ultimo_nome(Utilizador *user);
/**
 * @brief Retorna a data de nascimento de um utilizador.
 * 
 * A função retorna uma cópia da data de nascimento da estrutura `Utilizador`.
 * 
 * @param user Ponteiro para o utilizador.
 * @return Cópia da data de nascimento do utilizador ou NULL se não existir.
 */
char* get_utilizador_birth_date(Utilizador *user);
/**
 * @brief Retorna o país de origem de um utilizador.
 * 
 * A função retorna uma cópia do país de origem da estrutura `Utilizador`.
 * 
 * @param user Ponteiro para o utilizador.
 * @return Cópia do país de origem do utilizador ou NULL se não existir.
 */
char* get_utilizador_country(Utilizador *user);
/**
 * @brief Retorna o tipo de subscrição de um utilizador.
 * 
 * A função retorna uma cópia do tipo de subscrição da estrutura `Utilizador`.
 * 
 * @param user Ponteiro para o utilizador.
 * @return Cópia do tipo de subscrição do utilizador ou NULL se não existir.
 */
char* get_utilizador_subscricao(Utilizador *user);
/**
 * @brief Retorna a lista de gostos de um utilizador.
 * 
 * A função retorna uma cópia da lista de gostos (músicas) do utilizador.
 * 
 * @param user Ponteiro para o utilizador.
 * @return Cópia da lista de gostos do utilizador ou NULL se não existir.
 */
char** get_utilizador_lista_gostadas(Utilizador *user);
/**
 * @brief Clona um utilizador.
 * 
 * A função cria uma nova estrutura `Utilizador` e copia os dados de um utilizador original para o clone.
 * Utiliza os getters e setters definidos.
 * 
 * @param original Ponteiro para o utilizador a ser clonado.
 * @return Ponteiro para o clone do utilizador ou NULL se falhar a clonagem.
 */
Utilizador* clone_utilizador(Utilizador *original);
/**
 * @brief Liberta a memória de um utilizador.
 * 
 * A função liberta a memória de todos os campos e da estrutura `Utilizador` em si.
 * 
 * @param u Ponteiro para o utilizador a ser libertado.
 */
void free_utilizador(gpointer u);
/**
 * @brief Liberta a chave de um utilizador.
 * 
 * A função liberta a memória associada ao nome de usuário de um utilizador.
 * 
 * @param username Ponteiro para o nome de usuário a ser libertado.
 */
void free_key(gpointer username);
/**
 * @brief Insere um utilizador em uma tabela de hash.
 * 
 * A função clona o utilizador e o insere na tabela de hash, utilizando o nome de usuário como chave.
 * 
 * @param tabela Tabela de hash onde o utilizador será inserido.
 * @param user Ponteiro para o utilizador a ser inserido.
 */
void insert_utilizador(GHashTable* tabela, Utilizador* user);

#endif
