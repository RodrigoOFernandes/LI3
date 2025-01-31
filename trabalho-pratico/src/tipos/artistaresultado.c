#include "../include/tipos/artistaresultado.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct artistaresultado{
    char* id;
    char* nome;
    char* tipo;
    char* pais;
    char* duracao_total;
    int d;
};

ArtistaResultado* criar_AR()
{
    ArtistaResultado* a = (ArtistaResultado*)malloc(sizeof(ArtistaResultado));
    if(a == NULL)
    {
        return NULL;
    }
    a->id = NULL;
    a->nome = NULL;
    a->tipo = NULL;
    a->pais = NULL;
    a->duracao_total = NULL;
    a->d = 0;

    return a;
}

char* get_artistaresultado_id(const ArtistaResultado* a){
    return strdup(a->id);
}
char* get_artistaresultado_nome(ArtistaResultado* a){
    if (a->nome != NULL) {
        return strdup(a->nome);
    }
    return NULL;    
}
char* get_artistaresultado_tipo(ArtistaResultado* a){
    if (a->tipo != NULL) {
    return strdup(a->tipo);
    }
return NULL;
}
char* get_artistaresultado_pais(ArtistaResultado* a){
    if (a->pais != NULL) {
        return strdup(a->pais);
        }
        return NULL;
}
char* get_artistaresultado_duracao_total(ArtistaResultado* a){
    if (a->duracao_total != NULL) {
        return strdup(a->duracao_total);
}
return NULL;
}
int get_artistaresultado_d(const ArtistaResultado* a) {
    return a->d; // Retorna o inteiro diretamente
}

void set_artistaresultado_id(ArtistaResultado* a, char *id)
{
    a->id = strdup(id);
}

void set_artistaresultado_nome(ArtistaResultado* a, char *nome)
{
    a->nome = strdup(nome);
}

void set_artistaresultado_tipo(ArtistaResultado* a, char *tipo)
{
    a->tipo = strdup(tipo);
}

void set_artistaresultado_pais(ArtistaResultado* a, char *pais)
{
    a->pais = strdup(pais);
}

void set_artistaresultado_duracao_total(ArtistaResultado* a, char* d)
{
    a->duracao_total = strdup(d);
}

void set_artistaresultado_d(ArtistaResultado* a, int d)
{
    a->d = d;
}

void free_artistaresultado(ArtistaResultado* a)
{
    free(a->id);
    free(a->nome);
    free(a->tipo);
    free(a->pais);
    free(a->duracao_total);
    free(a);
}