#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include "../include/tipos/album.h"
#include "../include/utils/string_aux.h"
#include "../include/gestores/gestorartista.h"
#include "../include/parser/validacao_logica.h"
#include "../include/gestores/gestormusica.h"
#include "../include/parser/validacaosintatica.h"
#include "../include/gestores/gestorutilizador.h"
#include "../include/parser/parser.h"


char *readline(FILE *file, FILE *error, Gestor* g, int tal)
{
    int capacity = 1800;                          // Define a larger initial capacity
    char *line = malloc(capacity * sizeof(char)); // Memory allocation for the line

    if (line == NULL)
    {
        return NULL;
    }

    // Use fgets to read the entire line from the file at once
    if (fgets(line, capacity, file) == NULL)
    {
        free(line);
        return NULL;
    }

    // Duplicate the line for processing (keep the original `strdup` pointer)
    char *validator = strdup(line);
    if (validator == NULL)
    {
        free(line);
        return NULL;
    }

    removeaspas(validator); // Function to remove quotes

    char *token;
    char *temp_validator = validator; // Use a copy of the pointer for processing
    int invalido = 0;

    if (tal == 0)
    {
        int i = 0;
        char *campo1 = NULL;
        char *campo2 = NULL;
        char *campo3 = NULL;
        char *campo4 = NULL;
        char *campo5 = NULL;
        char *campo6 = NULL;
        char *campo7 = NULL;
        char **campo8 = NULL;

        // Use strsep to split the CSV fields
        while ((token = strsep(&temp_validator, ";")) != NULL)
        {
            i++;
            if (i == 1)
                campo1 = token;
            if (i == 2)
            {
                char *dup = strdup(token);
                if (!eEmail(dup))
                {
                    fprintf(error, "%s", line);
                    invalido = 1;
                    free(dup);
                    break;
                }
                else
                {
                    campo2 = token;
                }
                free(dup);
            }
            if (i == 3)
                campo3 = token;
            if (i == 4)
                campo4 = token;
            if (i == 5)
            {
                char *dup = strdup(token);
                if (!eData(dup))
                {
                    fprintf(error, "%s", line);
                    invalido = 1;
                    free(dup);
                    break;
                }
                else
                {
                    campo5 = token;
                }
                free(dup);
            }
            if (i == 6)
                campo6 = token;
            if (i == 7)
            {
                if (!eSubscricao(token))
                {
                    fprintf(error, "%s", line);
                    invalido = 1;
                    break;
                }
                else
                {
                    campo7 = token;
                }
            }
            if (i == 8)
            {
                int num_gostadas = 0;
                char *sub_token;
                char *temp_token = NULL;
                char *original_token = NULL;
                if (token[0] != '[' || token[strlen(token) - 2] != ']')
                {
                    fprintf(error, "%s", line);
                    invalido = 1;
                    break;
                }

                original_token = strdup(token);
                temp_token = original_token;

                while ((sub_token = strsep(&temp_token, ",")) != NULL)
                {
                    num_gostadas++;
                }
                free(original_token);

                campo8 = malloc((num_gostadas + 1) * sizeof(char *));
                original_token = strdup(token);
                temp_token = original_token;

                int j = 0;
                while ((sub_token = strsep(&temp_token, ",")) != NULL)
                {
                    campo8[j++] = strdup(sub_token);
                }
                campo8[j] = NULL;
                free(original_token);
            }
        }

        if (!invalido)
        {
            Utilizador *novo = criaruser();
            if (novo != NULL)
            {
                usersetter(novo, campo1, campo2, campo3, campo4, campo5, campo6, campo7, campo8);
                if (validar_utilizador(g, novo) == 1)
                {
                    insert_utilizador(getUtilizadores(getGestorUtilizador(g)), novo);
                }
                else
                {
                    fprintf(error, "%s", line);
                    free_user(novo);
                }
            }
            else
            {
                invalido = 1;
            }
        }
        if (campo8) free_lista(campo8);
        
    }

    if (tal == 1)
    {
        int i = 0;
        char *campo1 = NULL;
        char *campo2 = NULL;
        char **campo3 = NULL;
        char *campo4 = NULL;
        char *campo5 = NULL;
        char *campo6 = NULL;
        int campo7 = 0;
        char *campo8 = NULL;

        while ((token = strsep(&temp_validator, ";")) != NULL)
        {
            i++;
            if (i == 1)
                campo1 = token;
            if (i == 2)
                campo2 = token;
            if (i == 3)
            {
                int num_ids = 0;
                char *sub_token;
                char *original_token = NULL;
                char *temp_token = NULL;

                original_token = strdup(token);
                temp_token = original_token;
                if (token[0] != '[' || token[strlen(token) - 1] != ']')
                {
                    fprintf(error, "%s", line);
                    invalido = 1;
                    free(original_token);
                    break;
                }

                while ((sub_token = strsep(&temp_token, ",")) != NULL)
                {
                    num_ids++;
                }
                free(original_token);

                campo3 = malloc((num_ids + 1) * sizeof(char *));
                original_token = strdup(token);
                temp_token = original_token;

                int j = 0;
                while ((sub_token = strsep(&temp_token, ",")) != NULL)
                {
                    campo3[j++] = strdup(sub_token);
                }
                campo3[j] = NULL;
                free(original_token);
            }
            if(i == 4)
            {
                if (token[0] == '[' || token[strlen(token) - 1] == ']')
                {
                    fprintf(error,"%s", line);
                    invalido = 1;
                    break;
                }
                campo4 = token;
            } 
            if (i == 5)
            {
                char *dup = strdup(token);
                if (!eDuracao(dup))
                {
                    fprintf(error, "%s", line);
                    invalido = 1;
                    free(dup);
                    break;
                }
                else
                    campo5 = token;
                free(dup);
            }
            if (i == 6)
                campo6 = token;
            if (i == 7)
                campo7 = atoi(token);
            if (i == 8)
            {
                campo8 = token;
                remove_newline(campo8);
            }
        }

        if (!invalido)
        {
            Musica *nova = criarMusica();
            if (nova != NULL)
            {
                musicasetter(nova, campo1, campo2, campo3,campo4, campo5, campo6, campo7, campo8);
                if (validar_musica(getArtistas(getGestorArtista(g)), getAlbuns(getGestorAlbum(g)),nova) == 1)
                {
                    insert_musica(getMusicas(getGestorMusica(g)), nova);
                }
                else
                {
                    fprintf(error, "%s", line);
                    freeMusica(nova);
                }
            }
            else
            {
                invalido = 1;
            }
        }

        if (campo3) free_lista(campo3);
    }

    if (tal == 2)
    {
        int i = 0;
        char *campo1 = NULL;
        char *campo2 = NULL;
        char *campo3 = NULL;
        float campo4 = 0;
        char **campo5 = NULL;
        char *campo6 = NULL;
        char *campo7 = NULL;

        while ((token = strsep(&temp_validator, ";")) != NULL)
        {
            i++;
            if (i == 1)
                campo1 = token;
            if (i == 2)
                campo2 = token;
            if (i == 3)
                campo3 = token;
            if (i == 4)
            {
                campo4 = atof(token);
            }
            if (i == 5)
            {
                int num_ids = 0;
                char *sub_token;
                char *original_token = NULL;
                char *temp_token = NULL;
                original_token = strdup(token);
                temp_token = original_token;

                while ((sub_token = strsep(&temp_token, ",")) != NULL)
                {
                    num_ids++;
                }
                free(original_token);

                campo5 = malloc((num_ids + 1) * sizeof(char *));
                original_token = strdup(token);
                temp_token = original_token;

                int j = 0;
                while ((sub_token = strsep(&temp_token, ",")) != NULL)
                {
                    campo5[j++] = strdup(sub_token);
                }
                campo5[j] = NULL;
                free(original_token);
            }
            if (i == 6)
                campo6 = token;
            if (i == 7)
            {
                remove_newline(token);
                if(!eType(token))
                {
                    fprintf(error, "%s", line);
                    invalido = 1;
                    break;
                }
                campo7 = token;
                
            }
        }

        if (!invalido)
        {
            Artista *novo = cria_artista();
            if (novo != NULL)
            {
                set_artista(novo, campo1, campo2, campo3, campo4, campo5, campo6, campo7);
                if (validar_artista(novo) == 1)
                {
                    insert_artista(getArtistas(getGestorArtista(g)), novo);
                }
                else
                {
                    freeArtista(novo);
                    fprintf(error, "%s", line);
                }
            }
            else
            {
                invalido = 1;
            }
        }

        if (campo5) free_lista(campo5);
    }
    if(tal == 3)
    {
        int i = 0;

        char* campo1 = NULL;
        char* campo2 = NULL;
        char* campo3 = NULL;
        char* campo4 = NULL;
        char* campo5 = NULL;
        char* campo6 = NULL;
        char* campo7 = NULL;

        while((token = strsep(&temp_validator, ";")) != NULL)
        {
            i++;
            if(i == 1) campo1 = token;
            if(i == 2) campo2 = token;
            if(i == 3) campo3 = token;
            if(i == 4) {
                char* data_e_hora = strdup(token);
                char* data = strtok(data_e_hora, " ");
                char* duracao = strtok(NULL, " ");   
             
                char* aux = strdup(data);
                if(!eData(aux))
                {
                    fprintf(error, "%s", line);
                    invalido = 1;
                    free(data_e_hora);
                    free(aux);
                    break;
                }
                else campo4 = data;
                char* aux_hora = strdup(duracao);
                if (!eDuracao(aux_hora))
                {
                    fprintf(error, "%s", line);
                    invalido = 1;
                    free(data_e_hora);
                    free(aux_hora);
                    break;
                }
                else campo5 = duracao;

                free(data_e_hora);
                free(aux);
                free(aux_hora);
            }
            if(i == 5) 
            {
                char *dup = strdup(token);
                if (!eDuracao(dup))
                {
                    fprintf(error, "%s", line);
                    invalido = 1;
                    free(dup);
                    break;
                }
                else campo6 = token;
                free(dup);
            }
            if(i == 6)
            {
                char *dup = strdup(token);
                remove_newline(dup);
                if(!ePlataforma(dup))
                {
                    fprintf(error, "%s", line);
                    invalido = 1;
                    free(dup);
                    break;
                }
                else campo7 = token;
                free(dup);
            }
        }
        if(!invalido){            
            Musica *m = (Musica *)g_hash_table_lookup(getMusicas(getGestorMusica(g)),campo3);
            char **dup = get_id_artistas(m);

                for(int i = 0; dup[i] != NULL; i++)
                {
                    Artista *a = g_hash_table_lookup(getArtistas(getGestorArtista(g)),dup[i]);
                
                    if(a != NULL){
                    char *tipo = get_artista_type(a);
                    if(strcmp(tipo, "group") == 0)
                    {
                        float recipe = get_artista_recipe_per_stream(a);
                        set_total_recipe(a, recipe + get_total_recipe(a));
                        char **aux_ids = get_artista_id_constituent(a);
                        char **lista_aux = elimina_desnecessarios_a(aux_ids);
                        int tamanho = 0;
                        for(int j = 0; lista_aux[j] != NULL; j++)
                        {
                            tamanho++;
                        }
                        for(int j = 0; lista_aux[j] != NULL; j++)
                        {
                            Artista *artista = (Artista*)g_hash_table_lookup(getArtistas(getGestorArtista(g)),lista_aux[j]);
                            if(artista != NULL){
                                set_total_recipe(artista, recipe/tamanho + get_total_recipe(artista));
                            }
                            free(lista_aux[j]);
                        }
                        free(lista_aux);
                        free_lista(aux_ids);
                    }
                    else
                    {
                        set_total_recipe(a, get_total_recipe(a) +get_artista_recipe_per_stream(a));
                    }
                    free(tipo);
                    }
                }

                free_lista(dup);
            }
        }

        if(tal == 4)
        {
            int i = 0;
            char* campo1 = NULL;
            char* campo2 = NULL;
            char** campo3 = NULL;
            int campo4 = 0;
            char** campo5 = NULL;
 
            while((token = strsep(&temp_validator, ";")) != NULL)
            {
                i++;
                if(i == 1) campo1 = token;
                if(i == 2) campo2 = token;
                if(i == 3)
                {
                    int num_ids = 0;
                    char *sub_token;
                    char *original_token = NULL;
                    char *temp_token = NULL;

                    original_token = strdup(token);
                    temp_token = original_token;
                    while ((sub_token = strsep(&temp_token, ",")) != NULL)
                    {
                        num_ids++;
                    }
                    free(original_token);

                    campo3 = malloc((num_ids + 1) * sizeof(char *));
                    original_token = strdup(token);
                    temp_token = original_token;

                    int j = 0;
                    while ((sub_token = strsep(&temp_token, ",")) != NULL)
                    {
                        campo3[j++] = strdup(sub_token);
                    }
                    campo3[j] = NULL;
                    free(original_token);
                }
                if(i == 4) campo4 = atoi(token);
                if(i == 5)
                {
                    int num_ids = 0;
                    char *sub_token;
                    char *original_token = NULL;
                    char *temp_token = NULL;

                    original_token = strdup(token);
                    temp_token = original_token;
                    while ((sub_token = strsep(&temp_token, ",")) != NULL)
                    {
                        num_ids++;
                    }
                    free(original_token);

                    campo5 = malloc((num_ids + 1) * sizeof(char *));
                    original_token = strdup(token);
                    temp_token = original_token;

                    int j = 0;
                    while ((sub_token = strsep(&temp_token, ",")) != NULL)
                    {
                        campo5[j++] = strdup(sub_token);
                    }
                    campo5[j] = NULL;
                    free(original_token);
                }
            }    
            if(!invalido)
            {
                Album *a = criar_album();
                if(a != NULL)
                {
                    set_album(a,campo1,campo2,campo3,campo4,campo5);
                    char ** dup = get_album_artists_id(a);
                    char ** aux = elimina_desnecessarios(dup);
                    for(int i = 0; aux[i] != NULL; i++)
                    {
                        Artista *artista = (Artista*)g_hash_table_lookup(getArtistas(getGestorArtista(g)), aux[i]);
                        if(artista != NULL){
                            set_n_album(artista, get_n_album(artista)+1);
                        }
                    }
                    free_lista(dup);
                    free_lista(aux);

                    insert_album(getAlbuns(getGestorAlbum(g)), a);
                }
            }
            if(campo5) free_lista(campo5);
            if(campo3) free_lista(campo3);
        }
    free(validator);
    return line;
}

