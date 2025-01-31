#include <stdio.h>
#include <time.h>
#include <sys/resource.h>
#include "../include/utils/comparator.h"
#include "../include/gestores/gestor.h"
#include "../include/queries/interpretador.h"
#include "../include/utils/files_handler.h"
#include "../include/parser/parser_handler.h"


int main(int argc, char *argv[])
{
    struct timespec start, end;
    double elapsed;
    clock_gettime(CLOCK_REALTIME, &start);

    int flag = 1;
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <data_path> <commands_file>\n", argv[0]);
        return 1;
    }

    char *caminho = argv[1];
    char *commands_file = argv[2];
    char *expected_outputs = argv[3];

    Gestor* g = GestorInit();

    FILE **error_files = open_ficheiros_erros();
    FILE **files = open_arquivos(caminho); 
    
    parser_handler(files, error_files, g);

    close_files(error_files,5);
    close_files(files, 5);

    FILE *inputs = fopen(commands_file, "r");

    // Process commands
    processar_comandos(g, inputs, flag);
    verificar_resultados("resultados", expected_outputs);

    fclose(inputs);

    GestorDestroy(g);

    // End time do programa inteiro
    clock_gettime(CLOCK_REALTIME, &end);

    elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("\n");
    printf("Elapsed time: %.6f s\n", elapsed);

    struct rusage r_usage;
    getrusage(RUSAGE_SELF, &r_usage);
    printf("Memory usage : % ld KB\n", r_usage.ru_maxrss);

    return 0;
}


