#include <glib.h>
#include "../include/tipos/artista.h"
#include "../include/gestores/gestorartista.h"

struct gestorartista{
    GHashTable *artistas;
};

GestorArtista* GestorArtistaInit() {
    GestorArtista* g = malloc(sizeof(GestorArtista));
    if (g) {
        g->artistas = g_hash_table_new_full(g_str_hash, g_str_equal, free_idartista, free_artista);
    }
    return g;
}

void GestorArtistaDestroy(GestorArtista* g) {
    if (g) {
        g_hash_table_destroy(g->artistas);
        free(g);
    }
}


GHashTable* getArtistas(GestorArtista* g)
{
    return g->artistas;
}

