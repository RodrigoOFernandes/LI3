#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include "../include/utils/comparator.h"
#include "../include/utils/files_handler.h"

void verificar_resultados(const char *pasta_resultados, const char *pasta_esperados) {
    DIR *dir;
    struct dirent *entry;
    int total_files = 0;
    int *corretos = NULL;
    int *totais = NULL;
    int num_queries = 0;

    // First count how many files we have
    dir = opendir(pasta_resultados);
    if (dir == NULL) {
        printf("Erro ao abrir a pasta de resultados\n");
        return;
    }

    // Count total files and determine number of queries
    while ((entry = readdir(dir)) != NULL) {
        if (strstr(entry->d_name, "command") && strstr(entry->d_name, "_output.txt")) {
            total_files++;
            // Extract query number and update max query if needed
            int current_query;
            sscanf(entry->d_name, "command%d", &current_query);
            if (current_query > num_queries) {
                num_queries = current_query;
            }
        }
    }
    closedir(dir);

    if (total_files == 0) {
        printf("Nenhum ficheiro de resultado encontrado\n");
        return;
    }

    // Allocate arrays for statistics
    int num_categories = (num_queries + 24) / 25; // Round up division
    corretos = calloc(num_categories, sizeof(int));
    totais = calloc(num_categories, sizeof(int));
    
    if (!corretos || !totais) {
        printf("Erro de alocação de memória\n");
        free(corretos);
        free(totais);
        return;
    }

    // Initialize totals
    for (int i = 0; i < num_categories; i++) {
        totais[i] = (i < num_categories - 1) ? 25 : 
                    (num_queries - (num_categories - 1) * 25);
    }

    // Compare files
    for (int n = 1; n <= num_queries; n++) {
        char ficheiro_resultado[256], ficheiro_esperado[256];
        sprintf(ficheiro_resultado, "%s/command%d_output.txt", pasta_resultados, n);
        sprintf(ficheiro_esperado, "%s/command%d_output.txt", pasta_esperados, n);

        int linha_diferente;
        int resultado = comparar_ficheiros(ficheiro_resultado, ficheiro_esperado, &linha_diferente);

        if (resultado == 1) {
            // Files are equal
            int categoria = (n - 1) / 25;
            corretos[categoria]++;
        }
        else if (resultado == 0) {
            // Discrepancy found
            printf("Discrepância na query %d: linha %d de \"%s\"\n", n, linha_diferente, ficheiro_resultado);
        }
    }

    // Print results
    printf("\n");
    for (int i = 0; i < num_categories; i++) {
        printf("Q%d: %d de %d testes ok!\n", i + 1, corretos[i], totais[i]);
    }

    // Clean up
    free(corretos);
    free(totais);
}