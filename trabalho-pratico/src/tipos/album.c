#include "../include/utils/string_aux.h"
#include "../include/tipos/album.h"

struct album{
    char *id;
    char *title;
    char **artists_id;
    int year;
    char **producers;
};

Album* criar_album(){
    Album *novoalbum = (Album*)malloc(sizeof(Album));
    if(novoalbum == NULL){
        return NULL;
    }

    novoalbum->id = NULL;
    novoalbum->title = NULL;
    novoalbum->artists_id = NULL;
    novoalbum->year = 0;
    novoalbum->producers = NULL;

    return novoalbum;
}

Album* clone_album(Album* original) {
    if (original == NULL) {
        return NULL;
    }

    Album* novoalbum = criar_album();
    if (novoalbum == NULL) {
        return NULL;
    }

    // Copiar o id
    char *id = getAlbum_id(original);
    char *title = get_album_title(original);
    char **artists_id = get_album_artists_id(original);
    int year = get_album_year(original);
    char **producers = get_album_producers(original);

    setAlbum_id(novoalbum, id);
    set_album_title(novoalbum, title);
    set_album_artists_id(novoalbum,artists_id);
    set_album_year(novoalbum, year);
    set_album_producers(novoalbum, producers);

    free(id);
    free(title);
    free_lista(artists_id);
    free_lista(producers);

    return novoalbum;
}


void insert_album(GHashTable* albums, Album*a)
{   Album *clone = clone_album(a);
    g_hash_table_insert(albums,strdup(a->id),clone);
    free_album(a);
}

char* getAlbum_id(Album *album){
    return strdup(album->id);
}

char* get_album_title(Album *album){
    if(album->title != NULL){
        return strdup(album->title);
    }
    return NULL;
}

int get_album_year(Album *album){
        return album->year;
}

char** get_album_artists_id(Album *album) {
    if (album->artists_id == NULL) {
        return NULL;
    }

    // Conta o número de elementos no array
    int count = 0;
    while (album->artists_id[count] != NULL) {
        count++;
    }

    // Aloca memória para o novo array
    char **copy = malloc((count + 1) * sizeof(char *));
    if(!copy){
        return NULL;
    }

    for (int i = 0; i < count; i++) {
        copy[i] = strdup(album->artists_id[i]);
    
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
    copy[count] = NULL;   

    return copy;
}

// Retorna uma cópia completa do array de producers
char **get_album_producers(Album *album) {
    if (album->producers == NULL) {
        return NULL;
    }

    // Conta o número de elementos no array
    int count = 0;
    while (album->producers[count] != NULL) {
        count++;
    }

    // Aloca memória para o novo array
    char **copy = malloc((count + 1) * sizeof(char *));
    if (!copy) {
        //printf("Falha na alocação de memória.\n");
        return NULL; // Verifica se a alocação falhou
    }

    for (int i = 0; i < count; i++) {
        copy[i] = strdup(album->producers[i]);
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
    copy[count] = NULL; // Marca o final do array

    return copy;
}

//setters
void setAlbum_id(Album* album, char* id){
    if(id != NULL)
    {
        free(album->id);
    }
    album->id = strdup(id); 
}

void set_album_title(Album* album, char* title){
    if(title != NULL) free(album->title);
    album->title = strdup(title);
}

void set_album_year(Album* album, int year){
    album->year = year;
}

void set_album_artists_id(Album* album, char** artists_id){
    if (album->artists_id != NULL) {
        for(int i=0; album->artists_id[i] != NULL; i++){
            free(album->artists_id[i]);
        }
        free(album->artists_id);
    }

    if(artists_id != NULL){
        int count = 0;
        while (artists_id[count] != NULL) count++;

        album->artists_id = malloc((count + 1) * sizeof(char*));
        if(album->artists_id == NULL){
            perror("Erro ao alocar memória para artists_id");
            exit(EXIT_FAILURE);
        }

        for(int i=0; i<count; i++){
            album->artists_id[i] = strdup(artists_id[i]);
            if(album->artists_id[i] == NULL){
                perror("Erro ao duplicar string para artists_id");
                exit(EXIT_FAILURE);
            }
        }

        album->artists_id[count] = NULL;
    }
}

void set_album_producers(Album* album, char** producers){
    if (album->producers != NULL) {
        for(int i=0; album->producers[i] != NULL; i++){
            free(album->producers[i]);
        }
        free(album->producers);
    }

    if(producers != NULL){

        int count = 0;
        while (producers[count] != NULL) count++;

        album->producers = malloc((count + 1) * sizeof(char*));

        if(album->producers == NULL){
            perror("Erro ao alocar memória para producers");
            exit(EXIT_FAILURE);
        }

        for(int i=0; i<count; i++){
            album->producers[i] = strdup(producers[i]);
            if(album->producers[i] == NULL){
                perror("Erro ao duplicar string para producers");
                exit(EXIT_FAILURE);
            }
        }
        album->producers[count] = NULL;
    }

}

void set_album(Album* album, char* id, char* title, char** artists_id, int year, char** producers){
    setAlbum_id(album, id);
    set_album_title(album, title);
    set_album_artists_id(album, artists_id);
    set_album_year(album, year);
    set_album_producers(album, producers);

}

void free_id_album(gpointer id){
    free(id);
}

void free_album(gpointer album){
    Album *a =(Album*)album;

    free(a->id);
    free(a->title);
    if(a->artists_id){
        for(int i=0; a->artists_id[i] != NULL; i++){
            free(a->artists_id[i]);
        }
        free(a->artists_id);
    }

    if(a->producers){
        for(int i=0; a->producers[i] != NULL; i++){
            free(a->producers[i]);
        }
        free(a->producers);
    }


    free(a);

}