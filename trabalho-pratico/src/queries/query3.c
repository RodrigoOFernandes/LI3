#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/tipos/generosmatrix.h"

void query3(GenerosMatrix *gm, int min_age, int max_age, char *buffer, int flag) {

    char *generos[10] = {"Hip Hop", "Blues", "Rock", "Pop", "Jazz", "Classical", "Reggae", "Electronic", "Metal", "Country"};
    int total_gostos[10] = {0}; // Armazena os gostos totais por gênero
    int offset = 0;

    int (*matrixData)[MAX_IDADES] = getMatrix(gm);

    // Somar gostos diretamente da matriz para o intervalo de idades
    for (int genero = 0; genero < 10; genero++) {
        for (int idade = min_age; idade <= max_age; idade++) {
            total_gostos[genero] += matrixData[genero][idade];
        }
    }

    // Ordenar gêneros por número de gostos (descendente) e nome (alfabeticamente)
    for (int i = 0; i < 9; i++) {
        for (int j = i + 1; j < 10; j++) {
            if (total_gostos[i] < total_gostos[j] || 
                (total_gostos[i] == total_gostos[j] && strcmp(generos[i], generos[j]) > 0)) {
                // Trocar os valores de gostos totais
                int temp = total_gostos[i];
                total_gostos[i] = total_gostos[j];
                total_gostos[j] = temp;

                // Trocar os nomes dos gêneros
                char *temp_gen = generos[i];
                generos[i] = generos[j];
                generos[j] = temp_gen;
            }
        }
    }

    if(flag == 0){
        for (int i = 0; i < 10 && total_gostos[i] > 0; i++) {
            offset += snprintf(buffer + offset, 2000 - offset, "%s;%d\n", generos[i], total_gostos[i]);
        }
    }
    else{
        for (int i = 0; i < 10 && total_gostos[i] > 0; i++) {
            offset += snprintf(buffer + offset, 2000 - offset, "%s=%d\n", generos[i], total_gostos[i]);
        }
    }
    // Se nenhum gênero for encontrado no intervalo
    if (offset == 0) {
        snprintf(buffer, 2000, "\n");
    }
}

