#include <stdlib.h>
#include <glib.h>
#include <stdio.h>
#include <string.h>
#include "../include/utils/string_aux.h"
#include "../include/tipos/utilizador.h"

struct utilizador{
    char *username;
    char *email;
    char *primeiro_nome;
    char *ultimo_nome;
    char *birth_date;
    char *country;
    char *subscricao;
    char **lista_gostadas;
};

Utilizador* criaruser()
{
    Utilizador *novouser = (Utilizador*)malloc(sizeof(Utilizador));
    if(novouser == NULL)
    {
        return NULL;
    }

    novouser->username = NULL;
    novouser->email = NULL;
    novouser->primeiro_nome = NULL;
    novouser->ultimo_nome = NULL;
    novouser->birth_date = NULL;
    novouser->country = NULL;
    novouser->subscricao = NULL;
    novouser->lista_gostadas = NULL;

    return novouser;
}

void free_user(Utilizador *user) {
    free(user->username);
    free(user->email);
    free(user->primeiro_nome);
    free(user->ultimo_nome);
    free(user->birth_date);
    free(user->country);
    free(user->subscricao);
    if (user->lista_gostadas != NULL) {
        for (int i = 0; user->lista_gostadas[i] != NULL; i++) {
            free(user->lista_gostadas[i]);
        }
        free(user->lista_gostadas);
    }
    free(user);  // Free the user struct itself
}

Utilizador* clone_utilizador(Utilizador *original) {
    if (original == NULL) {
        return NULL; // Verifica se o original é nulo
    }

    // Criar um novo utilizador
    Utilizador *clone = criaruser();
    if (clone == NULL) {
        return NULL; // Verifica se a alocação falhou
    }

    char *username = get_utilizador_username(original);
    char *email = get_utilizador_email(original);
    char *primeiro = get_utilizador_primeiro_nome(original);
    char *ultimo = get_utilizador_ultimo_nome(original);
    char *data = get_utilizador_birth_date(original);
    char *country = get_utilizador_country(original);
    char *sub = get_utilizador_subscricao(original);
    char **lista = get_utilizador_lista_gostadas(original);

    setusername(clone, username);
    setemail(clone, email);
    setprimeiro(clone, primeiro);
    setultimo(clone, ultimo);
    setnascimento(clone, data);
    setcountry(clone, country);
    setsubs(clone, sub);
    setlista(clone, lista);

    free(username);
    free(email);
    free(primeiro);
    free(ultimo);
    free(country);
    free(data);
    free(sub);
    free_lista(lista);

    return clone;
}


void setusername(Utilizador *user,  char *nome)
{
    if(nome != NULL) user->username = strdup(nome);
}

void setemail(Utilizador *user,  char *email)
{
    if(email != NULL) user->email = strdup(email);
}

void setprimeiro(Utilizador *user,  char *primeiro)
{
    if(primeiro != NULL) user->primeiro_nome = strdup(primeiro);
}

void setultimo(Utilizador *user,  char *ultimo)
{
    if(ultimo != NULL) user->ultimo_nome = strdup(ultimo);
}

void setnascimento(Utilizador *user,  char *data)
{
    if(data != NULL) user->birth_date = strdup(data);
}

void setcountry(Utilizador *user,  char *pais)
{
    if(pais != NULL) user->country = strdup(pais);
}

void setsubs(Utilizador *user,  char *tipo)
{
    if(tipo != NULL) user->subscricao = strdup(tipo);
}

void setlista(Utilizador *user, char **lista)
{
    if (user->lista_gostadas != NULL) {
    for (int i = 0; user->lista_gostadas[i] != NULL; i++) {
        free(user->lista_gostadas[i]);
    }
    free(user->lista_gostadas);
    }

    if(lista != NULL)
    {
        int count = 0;
        while(lista[count] != NULL) count ++;

        user->lista_gostadas = malloc((count + 1) * sizeof(char*));
        for(int i = 0; i < count; i++)
        {
            user->lista_gostadas[i] = strdup(lista[i]);
        }
        user->lista_gostadas[count] = NULL;
    } else {
        user->lista_gostadas = NULL;
    }

}

void usersetter(Utilizador *user,  char *username,  char *email,  char *primeiro_nome,  char *ultimo_nome,  char *birth_date,  char *country,  char *subscricao, char **lista_gostadas)
{
    setusername(user, username);
    setemail(user, email);
    setprimeiro(user, primeiro_nome);
    setultimo(user, ultimo_nome);
    setnascimento(user, birth_date);
    setcountry(user, country);
    setsubs(user, subscricao);
    setlista(user, lista_gostadas);
}


char* get_utilizador_username(Utilizador *user){
    if(user->username != NULL)
    {
        return strdup(user->username);
    }
    return NULL;
}

char* get_utilizador_email(Utilizador *user){
    if(user->email != NULL)
    {
        return strdup(user->email);
    }
    return NULL;
}

char* get_utilizador_primeiro_nome(Utilizador *user){
    if(user->primeiro_nome != NULL)
    {
        return strdup(user->primeiro_nome);
    }
    return NULL;
}

char* get_utilizador_ultimo_nome(Utilizador *user){
    if(user->ultimo_nome != NULL)
    {
        return strdup(user->ultimo_nome);
    }
    return NULL;
}

char* get_utilizador_birth_date(Utilizador *user){
    if(user->birth_date != NULL)
    {
        return strdup(user->birth_date);
    }
    return NULL;
}

char* get_utilizador_country(Utilizador *user){
    if(user->country != NULL)
    {
        return strdup(user->country);
    }
    return NULL;
}

char* get_utilizador_subscricao(Utilizador *user){
    if(user->subscricao != NULL)
    {
        return strdup(user->subscricao);
    }
    return NULL;
}

char** get_utilizador_lista_gostadas(Utilizador *user){

    if(user->lista_gostadas != NULL)
    {
        int count = 0;
        while(user->lista_gostadas[count] != NULL) count++;

        char **copia= malloc((count + 1) * sizeof(char*));
        for (int i = 0; i < count; i++) {
            copia[i] = strdup(user->lista_gostadas[i]);
        }
        copia[count] = NULL;

        return copia;
    }
    return NULL;
}

void free_utilizador(gpointer u) {
    Utilizador* user = (Utilizador*)u;
    free(user->username);
    free(user->email);
    free(user->primeiro_nome);
    free(user->ultimo_nome);
    free(user->birth_date);
    free(user->country);
    free(user->subscricao);
    if (user->lista_gostadas) {
        for (int i = 0; user->lista_gostadas[i] != NULL; i++) {
            free(user->lista_gostadas[i]);
        }
        free(user->lista_gostadas);
    }
    free(user);
}

void free_key(gpointer username){
    free(username);
}

void insert_utilizador(GHashTable* tabela, Utilizador* user)
{
    Utilizador* clone = clone_utilizador(user);
    g_hash_table_insert(tabela,strdup(user->username), clone);
    free_user(user);
}