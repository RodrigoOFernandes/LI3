#include "../include/utils/garray_aux.h"

gint compara_artista_resultado(const void *a, const void *b)
{
    const ArtistaResultado *artistaA = *(ArtistaResultado **)a;
    const ArtistaResultado *artistaB = *(ArtistaResultado **)b;

    int dA = get_artistaresultado_d(artistaA);
    int dB = get_artistaresultado_d(artistaB);

    if (dA != dB)
    {
        return dB - dA;
    }

    char *idA = get_artistaresultado_id(artistaA);
    char *idB = get_artistaresultado_id(artistaB);

    int id_num_a = atoi(idA + strlen(idA) - 7);
    int id_num_b = atoi(idB + strlen(idB) - 7);

    free(idA);
    free(idB);

    return id_num_a - id_num_b;
}

void ordenaGarray(GArray *a)
{
    g_array_sort(a, compara_artista_resultado);
}

void inserir_com_limite_optimizado(GArray *array, ArtistaResultado *ar, int N)
{
    // Se o array estiver vazio ou menor que N, apenas adiciona
    if ((int)array->len < N)
    {
        g_array_append_val(array, ar);
        ordenaGarray(array);
        return;
    }

    // Obtém o último elemento do array
    ArtistaResultado *menor_ar = g_array_index(array, ArtistaResultado *, array->len - 1);
    if (menor_ar == NULL)
    {
        return;
    }

    int dAr = get_artistaresultado_d(ar);
    int dMenorAr = get_artistaresultado_d(menor_ar);

    if (dAr > dMenorAr)
    {
        // Libera o elemento mais fraco antes de substituí-lo
        free_artistaresultado(menor_ar);

        g_array_remove_index(array, array->len - 1);
        g_array_append_val(array, ar);
        ordenaGarray(array);
    }
    else
    {
        free_artistaresultado(ar);
    }
}
