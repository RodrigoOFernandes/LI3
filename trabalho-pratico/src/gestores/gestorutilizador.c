#include <glib.h>
#include "../include/gestores/gestorutilizador.h"

struct gestorutilizador{
    GHashTable* utilizadores;
};

GestorUtilizador* GestorUtilizadorInit() {
    GestorUtilizador* g = malloc(sizeof(GestorUtilizador));
    if (g) {
        g->utilizadores = g_hash_table_new_full(g_str_hash, g_str_equal, free_key, free_utilizador);
    }
    return g;
}

void GestorUtilizadorDestroy(GestorUtilizador* g) {
    if (g) {
        g_hash_table_destroy(g->utilizadores);
        free(g);
    }
}


GHashTable* getUtilizadores(GestorUtilizador* g)
{
    return g->utilizadores;
}

