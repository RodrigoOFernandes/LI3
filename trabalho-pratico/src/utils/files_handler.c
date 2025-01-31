#include <stdlib.h>
#include <string.h>
#include "../include/utils/string_aux.h"
#include "../include/utils/files_handler.h"

int comparar_ficheiros(const char *ficheiro1, const char *ficheiro2, int *linha_diferente)
{
    FILE *f1 = fopen(ficheiro1, "r");
    FILE *f2 = fopen(ficheiro2, "r");

    if (!f1 || !f2)
    {
        fprintf(stderr, "Erro ao abrir ficheiro: %s ou %s\n", ficheiro1, ficheiro2);
        if (f1)
            fclose(f1);
        if (f2)
            fclose(f2);
        return -1;
    }

    char linha1[MAX_LINE_LENGTH], linha2[MAX_LINE_LENGTH];
    int linha = 1;

    while (ler_linha(f1, linha1) && ler_linha(f2, linha2))
    {
        if (strcmp(linha1, linha2) != 0)
        {
            *linha_diferente = linha;
            fclose(f1);
            fclose(f2);
            return 0; // Discrepância encontrada
        }
        linha++;
    }

    if (ler_linha(f1, linha1) || ler_linha(f2, linha2))
    {
        *linha_diferente = linha;
        fclose(f1);
        fclose(f2);
        return 0; // Discrepância encontrada devido a diferença de tamanho
    }

    fclose(f1);
    fclose(f2);
    return 1; // Ficheiros são iguais
}

FILE** open_ficheiros_erros() {
    const char* paths[] = {
        "resultados/users_errors.csv",
        "resultados/musics_errors.csv",
        "resultados/artists_errors.csv",
        "resultados/history_errors.csv",
        "resultados/albums_errors.csv",
    };

    // Número de arquivos
    int num_files = sizeof(paths) / sizeof(paths[0]);

    // Aloca memória para o array de FILE*
    FILE** data_files = (FILE**) malloc(num_files * sizeof(FILE*));
    if (!data_files) {
        fprintf(stderr, "Error: Falha na alocação de memória para FILE**\n");
        return NULL;
    }

    // Abre cada arquivo e atribui ao array
    for (int i = 0; i < num_files; i++) {
        data_files[i] = fopen(paths[i], "w+");
        if (!data_files[i]) {
            fprintf(stderr, "Error: Falha ao abrir o arquivo %s\n", paths[i]);

            // Fecha arquivos abertos até o momento e libera memória
            for (int j = 0; j < i; j++) {
                fclose(data_files[j]);
            }
            free(data_files);
            return NULL;
        }
    }

    return data_files;
}

FILE** open_arquivos(char* caminho_base) {
    char* arquivos[] = {
        "/users.csv",
        "/musics.csv",
        "/artists.csv",
        "/history.csv",
        "/albums.csv"
    };
    
    // Número de arquivos
    int num_arquivos = sizeof(arquivos) / sizeof(arquivos[0]);
    
    // Aloca memória para os ponteiros FILE
    FILE** arquivos_abertos = (FILE**) malloc(num_arquivos * sizeof(FILE*));
    if (!arquivos_abertos) {
        fprintf(stderr, "Erro ao alocar memória para os arquivos\n");
        return NULL;
    }
    
    // Abre cada arquivo e armazena o ponteiro em arquivos_abertos
    for (int i = 0; i < num_arquivos; i++) {
        char* caminho_completo = juntar(caminho_base, arquivos[i]);
        if (!caminho_completo) {
            fprintf(stderr, "Erro ao criar o caminho completo para %s\n", arquivos[i]);
            // Libera memória e retorna NULL em caso de erro
            for (int j = 0; j < i; j++) {
                fclose(arquivos_abertos[j]);
            }
            free(arquivos_abertos);
            return NULL;
        }
        
        arquivos_abertos[i] = fopen(caminho_completo, "r");
        free(caminho_completo); // Libera a memória após o uso do caminho
        if (!arquivos_abertos[i]) {
            fprintf(stderr, "Erro ao abrir o arquivo %s\n", arquivos[i]);
            // Fecha arquivos abertos até o momento e libera memória
            for (int j = 0; j < i; j++) {
                fclose(arquivos_abertos[j]);
            }
            free(arquivos_abertos);
            return NULL;
        }
    }
    
    return arquivos_abertos;
}

void close_files(FILE **files, int count) {
    for (int i = 0; i < count; i++) {
        if (files[i]) {
            fclose(files[i]);
        }
    }
    free(files);
}

// Função para ler uma linha de um ficheiro
int ler_linha(FILE *file, char *linha)
{
    return fgets(linha, MAX_LINE_LENGTH, file) != NULL;
}