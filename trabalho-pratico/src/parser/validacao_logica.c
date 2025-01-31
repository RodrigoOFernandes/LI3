#include <stdio.h>
#include <stdlib.h>
#include <glib.h>
#include "../include/utils/string_aux.h"
#include "../include/utils/duracao_aux.h"
#include "../include/utils/data_aux.h"
#include "../include/parser/validacao_logica.h"
#include "../include/tipos/artista.h"
#include "../include/tipos/musica.h"
#include "../include/tipos/utilizador.h"

int validar_utilizador(Gestor *g, Utilizador *u) 
{
    char** gostadas = get_utilizador_lista_gostadas(u);
    char** lista = elimina_desnecessarios(gostadas);  

    GHashTable* tabela_musicas = getMusicas(getGestorMusica(g));
        
    int tamanho = 0;
    while (lista[tamanho] != NULL) {
        if (!g_hash_table_contains(tabela_musicas, lista[tamanho])) {
            free_lista(gostadas);
            free_lista(lista);
            return 0;
        }
        tamanho++;
    }

    setlista(u, lista);

    free_lista(gostadas);


    for(int i = 0; lista[i] != NULL; i++)
    {
        char *genero = get_genero(g_hash_table_lookup(tabela_musicas,lista[i]));
        char *birth = get_utilizador_birth_date(u);
        addGeneroLike(genero, calcular_idade(birth), getGenerosMatrix(g));
        free(genero);
        free(birth);
        free(lista[i]);
    }
    free(lista);


    return 1;
}


int validar_musica(GHashTable *tabela_artistas, GHashTable *tabela_album, Musica * m) {
    char **artistas = get_id_artistas(m);
    char *album = get_album_id(m);
    char **constituintes = elimina_desnecessarios(artistas);
    int tamanho = 0;

    if(g_hash_table_lookup(tabela_album,album) == NULL){
        free_lista(artistas);
        free_lista(constituintes);

        free(album);

        return 0;
    }
         

        while(constituintes[tamanho] != NULL)
        {
            if(!g_hash_table_contains(tabela_artistas,constituintes[tamanho]))
            {
                free_lista(artistas);
                free_lista(constituintes);
                free(album);
                return 0;
            }
            else
            {
                Artista *a = (Artista *)g_hash_table_lookup(tabela_artistas, constituintes[tamanho]);
                int tempo = get_artista_tempo(a);
                char *duracao = get_duracao(m);
                tempo += duracaoparasegundos(duracao);
                set_artista_tempo(a, tempo);
                free(duracao);
            }
            tamanho++;
        }
    set_id_artistas(m, constituintes);    

    free_lista(artistas);
    free_lista(constituintes);
    free(album);
    
    return 1;
}

int validar_artista(Artista *a) {
    char **constituintes = get_artista_id_constituent(a);
    char *tipo = get_artista_type(a);

    if (constituintes != NULL && constituintes[0] != NULL) {
        int tamanho = 0; // Initialize tamanho to 0
        int i = 0;

        while (constituintes[i] != NULL) {
            if (constituintes[i][2] == 'A') {
                tamanho++; // Increment tamanho only when the condition is met
            }
            i++; // Move to the next element
        }
     
        if (g_strcmp0(tipo, "individual") == 0 && tamanho > 0) 
        {
            free(tipo);
            free_lista(constituintes);
            return 0;
        }      
    }

    set_artista_id_constituent(a,constituintes);
    free(tipo);
    free_lista(constituintes);

    return 1;
}
    
 