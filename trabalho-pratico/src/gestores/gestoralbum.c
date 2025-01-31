#include "../include/gestores/gestoralbum.h"
#include "../include/tipos/album.h"

struct gestoralbum{
    GHashTable *albuns; // A hashtable está encapsulada aqui
};

GestorAlbum *GestorAlbumInit(){
    GestorAlbum* gestor = malloc(sizeof(GestorAlbum));
    if(gestor){
        gestor->albuns = g_hash_table_new_full(g_str_hash, g_str_equal, free_id_album, free_album);
    }
    return gestor;
}

void GestorAlbumDestroy(GestorAlbum* gestor){
    if(gestor){
        g_hash_table_destroy(gestor->albuns);
        free(gestor);
    }
}

GHashTable* getAlbuns(GestorAlbum* gestor){
    return gestor->albuns;
}

