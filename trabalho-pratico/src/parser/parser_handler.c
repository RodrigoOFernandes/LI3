#include "../include/parser/parser.h"
#include "../include/parser/parser_handler.h"


void parser_handler(FILE **files, FILE **error_files, Gestor *g)
{
    char *line = NULL;
    int ordem[] = {2, 4, 1, 0, 3}; // Ordem de processamento dos arquivos
    int num_arquivos = sizeof(ordem) / sizeof(ordem[0]);

    for (int i = 0; i < num_arquivos; i++) {
        int j = ordem[i];
        while ((line = readline(files[j], error_files[j], g, j)) != NULL) {
            free(line);
        }
    }
}