#include "../include/gestores/gestor.h"

struct gestor{
    GestorMusica* musicas;
    GestorUtilizador* utilizadores;
    GestorArtista* artistas;
    GestorAlbum* albuns;
    GenerosMatrix *generos;
};

Gestor* GestorInit() {
    Gestor *g = malloc(sizeof(Gestor));
    
    g->musicas = GestorMusicaInit();
    g->utilizadores = GestorUtilizadorInit();
    g->artistas = GestorArtistaInit();
    g->albuns = GestorAlbumInit();
    g->generos = MatrixInit();
    
    return g;
}

GestorMusica* getGestorMusica(Gestor *g){
    return g->musicas;
}

GestorUtilizador* getGestorUtilizador(Gestor *g){
    return g->utilizadores;
}

GestorArtista* getGestorArtista(Gestor *g){
    return g->artistas;
}

GestorAlbum* getGestorAlbum (Gestor *g){
    return g->albuns;
}

GenerosMatrix* getGenerosMatrix(Gestor *g)
{
    return g->generos;
}

void GestorDestroy(Gestor* g) {
    if (g->musicas) {
        GestorMusicaDestroy(g->musicas);
    }
    if (g->utilizadores) {
        GestorUtilizadorDestroy(g->utilizadores);
    }
    if (g->artistas) {
        GestorArtistaDestroy(g->artistas);
    }
    if (g->albuns) {
        GestorAlbumDestroy(g->albuns);
    }
    if (g->generos) {
        MatrixDestroy(g->generos);
    }    
    free(g);
}