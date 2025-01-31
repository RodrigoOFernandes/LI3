#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include "../include/utils/garray_aux.h"
#include "../include/utils/duracao_aux.h"
#include "../include/tipos/artistaresultado.h"
#include "../include/tipos/artista.h"


void query2(GHashTable *tabela_artistas, int N, char *pais, char *buffer, int flag)
{
    if (N == 0)
    {
        sprintf(buffer, "\n");
        return;
    }

    GArray *artistas_array = g_array_new(FALSE, FALSE, sizeof(ArtistaResultado *));
    GHashTableIter iter_a;
    gpointer chave_a, valor_a;

    g_hash_table_iter_init(&iter_a, tabela_artistas);
    while (g_hash_table_iter_next(&iter_a, &chave_a, &valor_a))
    {
        Artista *a = (Artista *)valor_a;
        ArtistaResultado *ar = criar_AR();

        char *pais_a = get_artista_country(a);
        int tempo = get_artista_tempo(a);

        if ((pais == NULL && tempo > 0) || (pais != NULL && strcmp(pais_a, pais) == 0))
        {
            char *id = get_artista_id(a);
            char *nome = get_artista_nome(a);
            char *tipo = get_artista_type(a);

            set_artistaresultado_id(ar, id);
            set_artistaresultado_nome(ar, nome);
            set_artistaresultado_tipo(ar, tipo);
            set_artistaresultado_pais(ar, pais_a);
            char *duracao = segundosparaduracao(tempo);
            set_artistaresultado_duracao_total(ar, duracao);
            set_artistaresultado_d(ar, tempo);

            inserir_com_limite_optimizado(artistas_array, ar, N);

            free(id);
            free(nome);
            free(tipo);
            free(duracao);
        }
        else
        {
            free_artistaresultado(ar);
        }

        free(pais_a);
    }

    for (int i = 0; i < N && i < (int)artistas_array->len; i++)
    {
        ArtistaResultado *artista = g_array_index(artistas_array, ArtistaResultado *, i);
        char temp[200];

        char *nome = get_artistaresultado_nome(artista);
        char *tipo = get_artistaresultado_tipo(artista);
        char *duracao = get_artistaresultado_duracao_total(artista);
        char *pais = get_artistaresultado_pais(artista);

        if(flag == 0){
            snprintf(temp, sizeof(temp), "%s;%s;%s;%s\n", nome, tipo, duracao, pais);
            strcat(buffer, temp);
        }
        else{
            snprintf(temp, sizeof(temp), "%s=%s=%s=%s\n", nome, tipo, duracao, pais);
            strcat(buffer, temp);
        }

        free(nome);
        free(tipo);
        free(duracao);
        free(pais);

        free_artistaresultado(artista);
    }

    g_array_free(artistas_array, TRUE);
}
