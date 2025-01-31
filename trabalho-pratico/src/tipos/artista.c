#include <stdlib.h>
#include <stdio.h>
#include <glib.h>
#include <string.h>
#include "../include/tipos/artista.h"

struct artista{
    char *id;
    char *nome;
    char *description;
    float recipe_per_stream;
    char **id_constituent;
    char *country;
    char *type;
    int tempo_total;
    int n_album_individual;
    GHashTable *reps_semana_ano;
    float total_recipe;
};

Artista* cria_artista(){
    Artista *novoartista = (Artista*)malloc(sizeof(Artista));
    if(novoartista == NULL)
    {
        return NULL;
    }

    novoartista->id = NULL;
    novoartista->nome = NULL;
    novoartista->description = NULL;
    novoartista->recipe_per_stream = 0;
    novoartista->id_constituent = NULL;
    novoartista->country = NULL;
    novoartista->type = NULL;
    novoartista->tempo_total = 0;
    novoartista->reps_semana_ano = g_hash_table_new_full(g_str_hash, g_str_equal, g_free, g_free);
    novoartista->n_album_individual = 0;
    novoartista->total_recipe = 0;

    return novoartista;
}

Artista* clone_artista(Artista* original) {
    if (original == NULL) {
        return NULL;
    }

    Artista* clone = cria_artista();
    if (clone == NULL) {
        return NULL; // Falha na alocação de memória
    }

    // Usar os getters para obter os valores do original
    char* id = get_artista_id(original);
    char* nome = get_artista_nome(original);
    char* description = get_artista_description(original);
    char* country = get_artista_country(original);
    char* type = get_artista_type(original);
    char** id_constituent = get_artista_id_constituent(original);

    // Definir os valores no clone usando os setters
    set_artista_id(clone, id);
    set_artista_nome(clone, nome);
    set_artista_description(clone, description);
    set_artista_country(clone, country);
    set_artista_type(clone, type);
    set_artista_recipe_per_stream(clone, original->recipe_per_stream);
    set_artista_tempo(clone, original->tempo_total);
    set_n_album(clone, original->n_album_individual);
    set_total_recipe(clone, original->total_recipe);

    if (id_constituent != NULL) {
        set_artista_id_constituent(clone, id_constituent);
        // Liberar o array de cópias retornado pelo getter
        for (int i = 0; id_constituent[i] != NULL; i++) {
            free(id_constituent[i]);
        }
        free(id_constituent);
    }

    // Liberar as cópias obtidas pelos getters
    free(id);
    free(nome);
    free(description);
    free(country);
    free(type);

    return clone;
}

void freeArtista(Artista * a)
{
    if(a -> id != NULL) free(a->id);
    if(a->nome != NULL) free(a->nome);
    if(a->description != NULL) free(a->description); 
    if(a->id_constituent != NULL)
    {
        for(int i = 0; a->id_constituent[i] != NULL; i++)
        {
            free(a->id_constituent[i]);
        }
        free(a->id_constituent);
    }
    if(a->country != NULL) free(a->country);
    if(a->type != NULL) free(a->type);
    g_hash_table_destroy(a->reps_semana_ano);

    free(a);
}

float get_total_recipe(Artista *a)
{
    return a->total_recipe;
}

void set_total_recipe(Artista *a, float n)
{
    a->total_recipe = n; 
}

int get_n_album(Artista *a)
{
    return a->n_album_individual;
}

void set_n_album(Artista *a, int n)
{
    a->n_album_individual = n;
}



/// Getters
char* get_artista_id(Artista* artista) {
    return strdup(artista->id); // Retorna uma cópia do ID
}

char* get_artista_nome(Artista* artista) {
if (artista->nome != NULL) {
    return strdup(artista->nome);
}
return NULL;}

char* get_artista_description(Artista* artista) {
    return strdup(artista->description); // Retorna uma cópia da descrição
}

float get_artista_recipe_per_stream(Artista* artista) {
    return artista->recipe_per_stream; // Retorna uma cópia da receita por stream
}

int get_artista_tempo(Artista* artista)
{
    return artista->tempo_total;
}

char** get_artista_id_constituent(Artista* artista) {
    if (!artista || !artista->id_constituent) {
        printf("Artista ou id_constituent é NULL\n");
        return NULL; // Verifica se o ponteiro é nulo
    }

    // Contar o número de strings no array id_constituent
    int count = 0;
    while (artista->id_constituent[count] != NULL) {
        //printf("Elemento id_constituent[%d]: %s\n", count, artista->id_constituent[count]);
        count++;
    }

    if (count == 0) {
        //printf("Nenhum constituinte encontrado.\n");
        return NULL;
    }

    // Usar calloc para alocar e inicializar a memória
    char** copy = calloc(count + 1, sizeof(char*));
    if (!copy) {
        //printf("Falha na alocação de memória.\n");
        return NULL; // Verifica se a alocação falhou
    }

    // Copiar cada string individualmente
    for (int i = 0; i < count; i++) {
        copy[i] = strdup(artista->id_constituent[i]);
        if (!copy[i]) {
            // Se a duplicação falhar, liberar o que já foi alocado
            //printf("Falha ao duplicar a string id_constituent[%d]: %s\n", i, artista->id_constituent[i]);
            while (i > 0) {
                free(copy[--i]);
            }
            free(copy);
            return NULL;
        }
    }
    // Terminador NULL já inserido pelo calloc
    return copy;
}


char* get_artista_country(Artista* artista) {
if (artista->country != NULL) {
    return strdup(artista->country);
}
return NULL;}

char* get_artista_type(Artista* artista) {
if (artista->type != NULL) {
    return strdup(artista->type);
}
return NULL;}

// Setters
void set_artista_id(Artista* artista, char* id) {
    if(id != NULL) artista->id = strdup(id); // Duplica a nova string
}

void set_artista_tempo(Artista* a, int tempo)
{
    a->tempo_total = tempo;
}

void set_artista_nome(Artista* artista, char* nome) {
    if(nome != NULL) artista->nome = strdup(nome); // Duplica a nova string
}

void set_artista_description(Artista* artista, char* description) {
    if(description != NULL) artista->description = strdup(description); // Duplica a nova string
}

void set_artista_recipe_per_stream(Artista* artista, float recipe) {
    artista->recipe_per_stream = recipe; // Duplica a nova string
}

void set_artista_id_constituent(Artista* artista, char** id_constituent) {
    if (artista->id_constituent != NULL) {
    for (int i = 0; artista->id_constituent[i] != NULL; i++) {
        free(artista->id_constituent[i]);
    }
    free(artista->id_constituent);
    }

    if(id_constituent != NULL)
    {
        int count = 0;
        // Contar quantos elementos existem em id_constituent
        while(id_constituent[count] != NULL) count++;

        // Alocar memória para count + 1 ponteiros (para incluir o NULL terminador)
        artista->id_constituent = malloc((count + 1) * sizeof(char*));
        if (artista->id_constituent == NULL) {
            // Garantir que a alocação de memória ocorreu corretamente
            perror("Erro ao alocar memória para id_constituent");
            exit(EXIT_FAILURE);
        }

        // Copiar cada string de id_constituent para o struct artista
        for(int i = 0; i < count; i++)
        {
            artista->id_constituent[i] = strdup(id_constituent[i]);
            if (artista->id_constituent[i] == NULL) {
                // Garantir que strdup foi bem sucedido
                perror("Erro ao duplicar string");
                exit(EXIT_FAILURE);
            }
        }

        // Definir o último elemento como NULL
        artista->id_constituent[count] = NULL;
    }
}


void set_artista_country(Artista* artista, char* country) {
    if(country != NULL) artista->country = strdup(country); // Duplica a nova string
}

void set_artista_type(Artista* artista, char* type) {
    if(type != NULL) artista->type = strdup(type); // Duplica a nova string
}


void set_artista(Artista* artista,  char* id,  char* nome,  char* description, 
                 float recipe_per_stream, char** id_constituent, 
                  char* country,  char* type) {
    set_artista_id(artista, id);
    set_artista_nome(artista, nome);
    set_artista_description(artista, description);
    set_artista_recipe_per_stream(artista, recipe_per_stream);
    set_artista_id_constituent(artista, id_constituent);
    set_artista_country(artista, country);
    set_artista_type(artista, type);
    artista->tempo_total = 0;
    artista->n_album_individual = 0;
    artista->total_recipe = 0;

}

void free_idartista(gpointer id)
{
    free(id);
}

void free_artista(gpointer art)
{
    Artista *a = (Artista*)art;
    free(a->id);
    free(a->nome);
    free(a->description);
    if(a->id_constituent)
    {
        for(int i = 0; a->id_constituent[i] != NULL; i++)
        {
            free(a->id_constituent[i]);
        }
        free(a->id_constituent);
    }
    free(a->country);
    free(a->type);
    g_hash_table_destroy(a->reps_semana_ano);
    free(a);
}

GHashTable* get_reps_por_semana(Artista* a)
{
    return a->reps_semana_ano;
}

void insert_artista(GHashTable* tabela, Artista* a){
    Artista *clone = clone_artista(a);
    g_hash_table_insert(tabela,get_artista_id(a), clone);
    freeArtista(a);
}

void insert_counter(Artista *a, char* ano_semana)
{
    GHashTable *table = get_reps_por_semana(a);
    int *contador = (int *)g_hash_table_lookup(table, ano_semana);
    if (contador != NULL) {
        (*contador)++;
    } else {
        contador = g_new(int, 1);
        *contador = 1;
        g_hash_table_insert(table, ano_semana, contador);
    }
}