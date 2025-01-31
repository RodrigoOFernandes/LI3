#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/utils/string_aux.h"

void remove_newline(char *str)
{

    if (str == NULL)
    {
        return; 
    }

    size_t len = strlen(str); // Obtém o comprimento da string

    for (size_t i = 0; i < len; i++)
    {

        if (str[i] == '\n')
        {

            str[i] = '\0'; // Substitui o \n por terminador nulo

            break; // Sai do loop após encontrar o primeiro \n
        }
    }
}

void free_lista(char **lista)
{
    for(int i = 0; lista[i] != NULL; i++)
    {
        free(lista[i]);
    }
    free(lista);
}

void removeaspas(char *linha)
{
    char *pr = linha;
    char *pw = linha;
    while(*pr)
    {
        *pw = *pr++;
        pw += (*pw != '"');
    }
    *pw = '\0';
}

char **elimina_desnecessarios(char **array) {
    int i = 0;
    while (array[i] != NULL) {
        i++;
    }

    // Aloca espaço para o novo array de strings
    char **novo_array = malloc((i + 1) * sizeof(char *));
    if (novo_array == NULL) {
        perror("Erro de alocação de memória para novo array");
        exit(1);
    }

    int tamanho = 0;
    while (array[tamanho] != NULL) {
        int len = strlen(array[tamanho]);
        
        char *nova_str = malloc(len - 1); 
        if (nova_str == NULL) {
            perror("Erro de alocação de memória para string");
            // Libera as strings já alocadas em caso de erro
            for (int j = 0; j < tamanho; j++) {
                free(novo_array[j]);
            }
            free(novo_array);
            exit(1);
        }

        if (tamanho == 0 && i == 1) {  
            strncpy(nova_str, array[tamanho] + 2, len - 4);
            nova_str[len - 4] = '\0';
        } else if (tamanho == 0 && i > 1) {
            strncpy(nova_str, array[tamanho] + 2, len - 3);
            nova_str[len - 3] = '\0';
        } else if (array[tamanho + 1] == NULL && i < 3) {  
            strncpy(nova_str, array[tamanho] + 2, len - 4);
            nova_str[len - 4] = '\0';
        } else if (array[tamanho + 1] == NULL && i >= 3) {
            strncpy(nova_str, array[tamanho] + 2, len - 5);
            nova_str[len - 5] = '\0';
        } else {  
            strncpy(nova_str, array[tamanho] + 2, len - 3);
            nova_str[len - 3] = '\0';
        }
        
        novo_array[tamanho] = nova_str;
        tamanho++;
    }

    novo_array[tamanho] = NULL;  // Marca o fim do array
    return novo_array;
}

char **elimina_desnecessarios_a(char **array) {
    int i = 0;
    while (array[i] != NULL) {
        i++;
    }

    // Aloca espaço para o novo array de strings
    char **novo_array = malloc((i + 1) * sizeof(char *));
    if (novo_array == NULL) {
        perror("Erro de alocação de memória para novo array");
        exit(1);
    }

    int tamanho = 0;
    while (array[tamanho] != NULL) {
        int len = strlen(array[tamanho]);
        
        char *nova_str = malloc(len - 1); 
        if (nova_str == NULL) {
            perror("Erro de alocação de memória para string");
            // Libera as strings já alocadas em caso de erro
            for (int j = 0; j < tamanho; j++) {
                free(novo_array[j]);
            }
            free(novo_array);
            exit(1);
        }

        if (tamanho == 0 && i == 1) {  
            strncpy(nova_str, array[tamanho] + 2, len - 4);
            nova_str[len - 4] = '\0';
        } else if (tamanho == 0 && i > 1) {
            strncpy(nova_str, array[tamanho] + 2, len - 3);
            nova_str[len - 3] = '\0';
        } else if (array[tamanho + 1] == NULL && i < 3) {  
            strncpy(nova_str, array[tamanho] + 2, len - 4);
            nova_str[len - 4] = '\0';
        } else if (array[tamanho + 1] == NULL && i >= 3) {
            strncpy(nova_str, array[tamanho] + 2, len - 4);
            nova_str[len - 4] = '\0';
        } else {  
            strncpy(nova_str, array[tamanho] + 2, len - 3);
            nova_str[len - 3] = '\0';
        }
        
        novo_array[tamanho] = nova_str;
        tamanho++;
    }

    novo_array[tamanho] = NULL;  // Marca o fim do array
    return novo_array;
}

char* juntar(char *path, char *ficheiro) {
    // Verifica se path ou ficheiro são NULL
    if (path == NULL || ficheiro == NULL) {
        fprintf(stderr, "Error: path ou ficheiro é NULL\n");
        return NULL;
    }

    // Aloca memória para o caminho completo
    char* filepath = (char *) malloc(1000 * sizeof(char));
    if (filepath == NULL) {
        fprintf(stderr, "Error: Falha na alocação de memória\n");
        return NULL;
    }

    // Copia o path e concatena o ficheiro
    strcpy(filepath, path);
    strcat(filepath, ficheiro);

    return filepath;
}


