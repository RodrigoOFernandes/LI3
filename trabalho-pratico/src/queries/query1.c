#include <stdio.h>
#include <stdlib.h>
#include <glib.h>
#include "../include/tipos/artista.h"
#include "../include/tipos/utilizador.h"
#include "../include/utils/data_aux.h"
#include "../include/queries/query1.h"


void query1(GHashTable *tabela_utilizadores, GHashTable *tabela_artistas, char *id, char *buffer, int flag) {
    if(id[0] == 'U'){
    Utilizador *u = g_hash_table_lookup(tabela_utilizadores, id); 

        if (u != NULL) {
            char *email = get_utilizador_email(u);
            char *primeiro = get_utilizador_primeiro_nome(u);
            char *ultimo = get_utilizador_ultimo_nome(u);
            char *birth = get_utilizador_birth_date(u);
            char *pais = get_utilizador_country(u);

            if(flag == 0) sprintf(buffer, "%s;%s;%s;%d;%s\n",email,primeiro,ultimo, calcular_idade(birth), pais);
            else sprintf(buffer, "%s=%s=%s=%d=%s\n",email,primeiro,ultimo, calcular_idade(birth), pais);

            free(email);
            free(primeiro);
            free(ultimo);
            free(birth);
            free(pais);
        } else {
            sprintf(buffer, "\n");
        }  
    }
    else
    {

        Artista *a = g_hash_table_lookup(tabela_artistas, id);
        if(a != NULL)
        {
            char* nome = get_artista_nome(a);
            char* tipo = get_artista_type(a);
            char* pais = get_artista_country(a);
            int numero = get_n_album(a);
            float total = get_total_recipe(a);
        
            if(flag == 0) sprintf(buffer, "%s;%s;%s;%d;%.2f\n",nome,tipo,pais, numero, total);
            else sprintf(buffer, "%s=%s=%s=%d=%.2f\n",nome,tipo,pais, numero, total);

            free(nome);
            free(tipo);
            free(pais);
        }else{
            sprintf(buffer, "\n");
        }
}}