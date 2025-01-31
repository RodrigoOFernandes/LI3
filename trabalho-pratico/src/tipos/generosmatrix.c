#include <stdlib.h>
#include <string.h>
#include "../include/tipos/generosmatrix.h"

struct generosmatrix{
    int matrix[MAX_GENEROS][MAX_IDADES];
};

int (*getMatrix(GenerosMatrix *g))[MAX_IDADES] {
    return g->matrix;
}

GenerosMatrix *MatrixInit() {
    GenerosMatrix *matrix = malloc(sizeof(GenerosMatrix));
    if (matrix == NULL) {
        return NULL; 
    }
    memset(matrix->matrix, 0, sizeof(matrix->matrix));
    return matrix;
}

void MatrixDestroy(GenerosMatrix *matrix) {
    if (matrix != NULL) {
        free(matrix);
    }
}

void addGeneroLike(char* genero, int idade, GenerosMatrix* gm)
{
    int (*matrixData)[MAX_IDADES] = getMatrix(gm);

    if(strcmp(genero, "Hip Hop") == 0) matrixData[0][idade]++;
    else if(strcmp(genero, "Blues") == 0) matrixData[1][idade]++;
    else if(strcmp(genero, "Rock") == 0) matrixData[2][idade]++;
    else if(strcmp(genero, "Pop") == 0) matrixData[3][idade]++;
    else if(strcmp(genero, "Jazz") == 0) matrixData[4][idade]++;
    else if(strcmp(genero, "Classical") == 0) matrixData[5][idade]++;
    else if(strcmp(genero, "Reggae") == 0) matrixData[6][idade]++;
    else if(strcmp(genero, "Electronic") == 0) matrixData[7][idade]++;
    else if(strcmp(genero, "Metal") == 0) matrixData[8][idade]++;
    else if(strcmp(genero, "Country") == 0) matrixData[9][idade]++;
}