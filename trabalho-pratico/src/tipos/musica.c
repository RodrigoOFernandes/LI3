#include <stdlib.h>
#include <glib.h>
#include <string.h>
#include "../include/tipos/musica.h"

struct musica{
    char *id;
    char *nome_musica;
    char **id_artistas;
    char *duracao;
    char *genero;
    int ano;
    char *letra;
    char *album_id;
};

Musica* criarMusica(){
    Musica *nova_musica = (Musica*)malloc(sizeof(Musica));
    if(nova_musica == NULL)
    {
        return NULL;
    }
    nova_musica->id = NULL;
    nova_musica->nome_musica = NULL;
    nova_musica->id_artistas = NULL;
    nova_musica->duracao = NULL;
    nova_musica->genero = NULL;
    nova_musica->ano = 0;
    nova_musica->album_id = NULL;
    nova_musica->letra = NULL;

    return nova_musica;
}

char* get_album_id(Musica* musica)
{
    if(musica->album_id != NULL)
    {
        return strdup(musica->album_id);
    }
    return NULL;
}

void set_album_id(Musica* musica, char* album)
{
    if(musica->album_id != NULL)
    {
        free(musica->album_id);
    }
    musica->album_id = album ? strdup(album) : NULL;
}

char* get_id(Musica* musica)
{
    if (musica->id != NULL) {
        return strdup(musica->id);
    }
    return NULL;
}


char* get_nome_musica(Musica *musica)
{
    if(musica->nome_musica != NULL)
    {
        return strdup(musica->nome_musica);
    }
    return NULL;
}

Musica* clone_musica(Musica* original) {
    if (original == NULL) {
        return NULL;
    }

    // Criar uma nova instância de Musica
    Musica* clone = criarMusica();
    if (clone == NULL) {
        return NULL; // Falha na alocação de memória
    }

    // Obter os valores do original usando os getters
    char* id = get_id(original);
    char* nome_musica = get_nome_musica(original);
    char** id_artistas = get_id_artistas(original);
    char* duracao = get_duracao(original);
    char* genero = get_genero(original);
    int ano = get_ano(original);
    char* letra = get_letra(original);
    char* album_id = get_album_id(original);

    // Definir os valores no clone usando os setters
    set_id(clone, id);
    set_nome_musica(clone, nome_musica);
    set_id_artistas(clone, id_artistas);
    set_duracao(clone, duracao);
    set_genero(clone, genero);
    set_ano(clone, ano);
    set_letra(clone, letra);
    set_album_id(clone, album_id);

    // Liberar as cópias retornadas pelos getters
    free(id);
    free(nome_musica);
    if (id_artistas != NULL) {
        for (int i = 0; id_artistas[i] != NULL; i++) {
            free(id_artistas[i]);
        }
        free(id_artistas);
    }
    free(duracao);
    free(genero);
    free(letra);
    free(album_id);

    return clone;
}


char** get_id_artistas(Musica *musica) {
    if (musica == NULL || musica->id_artistas == NULL) {
        return NULL; // Verifica se a música é nula ou se não há artistas
    }

    // Contar o número de artistas
    int count = 0;
    while (musica->id_artistas[count] != NULL) {
        count++;
    }

    // Alocar memória para o array de cópias
    char **artistas_copia = malloc((count + 1) * sizeof(char*));
    if (artistas_copia == NULL) {
        return NULL; // Verifica se a alocação falhou
    }

    // Copiar cada artista, verificando se a duplicação foi bem-sucedida
    for (int i = 0; i < count; i++) {
        artistas_copia[i] = strdup(musica->id_artistas[i]);
        if (artistas_copia[i] == NULL) {
            // Se a duplicação falhar, liberar a memória já alocada
            for (int j = 0; j < i; j++) {
                free(artistas_copia[j]);
            }
            free(artistas_copia);
            return NULL; // Retorna NULL em caso de falha
        }
    }

    artistas_copia[count] = NULL; // Terminador NULL

    return artistas_copia; // Retorna o array de cópias
}
char *get_duracao(Musica *musica) {
    return musica->duracao ? strdup(musica->duracao) : NULL;
}

char *get_genero(Musica *musica) {
    return musica->genero ? strdup(musica->genero) : NULL;
}

int get_ano(Musica *musica) {
    return musica->ano;
}

char *get_letra(Musica *musica) {
    return musica->letra ? strdup(musica->letra) : NULL;
}

void set_id(Musica *musica, char *id) {
    if (musica->id != NULL) {
        free(musica->id);  // Liberar o ID antigo
    }
    musica->id = id ? strdup(id) : NULL;
}

void set_nome_musica(Musica *musica, char *nome_musica) {
    if (musica->nome_musica != NULL) {
        free(musica->nome_musica);
    }
    musica->nome_musica = nome_musica ? strdup(nome_musica) : NULL;
}


void set_id_artistas(Musica *musica, char **id_artistas) {
    if (musica->id_artistas != NULL) {
    for (int i = 0; musica->id_artistas[i] != NULL; i++) {
        free(musica->id_artistas[i]);
    }
    free(musica->id_artistas);
    }
    if (id_artistas != NULL) {
        // Contar quantos artistas existem
        int count = 0;
        while (id_artistas[count] != NULL) count++;

        // Alocar memória para o novo array
        musica->id_artistas = malloc((count + 1) * sizeof(char*));
        for (int i = 0; i < count; i++) {
            musica->id_artistas[i] = strdup(id_artistas[i]); // Copia cada ID
        }
        musica->id_artistas[count] = NULL; // Termina o array com NULL
    } else {
        musica->id_artistas = NULL; // Se o array passado for NULL, define como NULL
    }
}


void set_duracao(Musica *musica, char *duracao) {
    if (musica->duracao != NULL) {
        free(musica->duracao);
    }
    musica->duracao = duracao ? strdup(duracao) : NULL;
}

void set_genero(Musica *musica, char *genero) {
    if (musica->genero != NULL) {
        free(musica->genero);
    }
    musica->genero = genero ? strdup(genero) : NULL;
}

void set_letra(Musica *musica, char *letra) {
    if (musica->letra != NULL) {
        free(musica->letra);
    }
    musica->letra = letra ? strdup(letra) : NULL;
}

void set_ano(Musica * musica, int ano)
{
    musica->ano = ano;
}
void freeMusica(Musica *musica) {
    if (musica == NULL) return;

    if (musica->id) free(musica->id);
    if (musica->nome_musica) free(musica->nome_musica);
    if (musica->id_artistas) {
        for (int i = 0; musica->id_artistas[i] != NULL; i++) {
            free(musica->id_artistas[i]);
        }
        free(musica->id_artistas);
    }
    if (musica->duracao) free(musica->duracao);
    if (musica->genero) free(musica->genero);
    if (musica->letra) free(musica->letra);
    if (musica->album_id) free(musica->album_id);

    free(musica);
}


void musicasetter(Musica* m, char *id, char *nome, char **idartistas,  char *album,char *duracao, char *genero, int ano, char *letra)
{
    set_id(m, id);
    set_nome_musica(m, nome);
    set_id_artistas(m,idartistas);
    set_duracao(m,duracao);
    set_genero(m,genero);
    set_ano(m,ano);
    set_letra(m,letra);
    set_album_id(m,album);
}

void free_idmusica(gpointer id){
    free(id);
}

void free_musica(gpointer mu){
    freeMusica((Musica*)mu);
}

void insert_musica(GHashTable* tabela, Musica* musica)
{
    Musica* clone = clone_musica(musica);
    g_hash_table_insert(tabela,strdup(musica->id), clone);
    freeMusica(musica);
}
