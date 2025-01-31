#include <glib.h>
#include "../include/tipos/musica.h"
#include "../include/gestores/gestormusica.h"

struct gestormusica{
    GHashTable *musicas;
};

GestorMusica* GestorMusicaInit() {
    GestorMusica* g = malloc(sizeof(GestorMusica));
    if (g) {
        g->musicas = g_hash_table_new_full(g_str_hash, g_str_equal, free_idmusica, free_musica);
    }
    return g;       

    
}


void GestorMusicaDestroy(GestorMusica* g) {
    if (!g) return;
    if (g->musicas) {
        g_hash_table_destroy(g->musicas);
    }
    free(g);
}

GHashTable* getMusicas(GestorMusica* g)
{
    return g->musicas;
}
