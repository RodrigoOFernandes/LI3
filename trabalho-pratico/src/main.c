#include <stdio.h>
#include "../include/gestores/gestor.h"
#include "../include/queries/interpretador.h"
#include "../include/utils/files_handler.h"
#include "../include/parser/parser_handler.h"

#define MAX_GENEROS 10
#define MAX_IDADES 130

int main(int argc, char *argv[])
{
    int flag = 0;
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <data_path> <commands_file>\n", argv[0]);
        return 1;
    }

    char *caminho = argv[1];
    char *commands_file = argv[2];

    Gestor* g = GestorInit();

    FILE **error_files = open_ficheiros_erros();
    FILE **files = open_arquivos(caminho); 
    
    parser_handler(files, error_files, g);

    close_files(error_files,5);
    close_files(files, 5);

    FILE *inputs = fopen(commands_file, "r");

    // Process commands
    processar_comandos(g, inputs, flag);
    fclose(inputs);

    GestorDestroy(g);
    return 0;
}
