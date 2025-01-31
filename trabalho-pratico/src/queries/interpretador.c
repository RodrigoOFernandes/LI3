#include <stdio.h>
#include <time.h>
#include "../include/queries/interpretador.h"
#include "../include/utils/string_aux.h"
#include "../include/queries/query1.h"
#include "../include/queries/query2.h"
#include "../include/queries/query3.h"

void processar_comandos(Gestor *g, FILE *inputs, int flag) {
    char input[500]; // Buffer de leitura
    int counter = 1;
    
    // Arrays dinâmicos para guardar os tempos
    double *tempo_query1 = NULL;
    double *tempo_query2 = NULL;
    double *tempo_query3 = NULL;
    int count_q1 = 0, count_q2 = 0, count_q3 = 0;
    int size_q1 = 10, size_q2 = 10, size_q3 = 10;  // Tamanho inicial

    if (flag == 1) {
        // Alocação inicial dos arrays
        tempo_query1 = malloc(size_q1 * sizeof(double));
        tempo_query2 = malloc(size_q2 * sizeof(double));
        tempo_query3 = malloc(size_q3 * sizeof(double));
        
        if (!tempo_query1 || !tempo_query2 || !tempo_query3) {
            free(tempo_query1);
            free(tempo_query2);
            free(tempo_query3);
            fprintf(stderr, "Erro na alocação de memória\n");
            return;
        }
    }

    while (fgets(input, sizeof(input), inputs)) {
        struct timespec start, end;
        double elapsed_time;

        char *linha = strtok(input, "\n");
        if (!linha) continue;

        int flag_special = 0;
        if (linha[1] == 'S') {
            flag_special = 1;
            memmove(linha + 1, linha + 2, strlen(linha) - 1);
        }

        char nome_arquivo[50];
        snprintf(nome_arquivo, sizeof(nome_arquivo), "resultados/command%d_output.txt", counter);

        char output[2500] = "";

        if (flag == 1) {
            clock_gettime(CLOCK_REALTIME, &start);
            
            switch (linha[0]) {
                case '1': {
                    char *id = strtok(linha + (flag_special ? 1 : 2), " ");
                    if (id) query1(getUtilizadores(getGestorUtilizador(g)), getArtistas(getGestorArtista(g)), id, output, flag_special);
                    
                    clock_gettime(CLOCK_REALTIME, &end);
                    elapsed_time = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
                    
                    // Redimensionar array se necessário
                    if (count_q1 >= size_q1) {
                        size_q1 *= 2;
                        double *temp = realloc(tempo_query1, size_q1 * sizeof(double));
                        if (!temp) {
                            fprintf(stderr, "Erro no realloc\n");
                            break;
                        }
                        tempo_query1 = temp;
                    }
                    tempo_query1[count_q1++] = elapsed_time;
                    break;
                }
                case '2': {
                    char *n_str = strtok(linha + (flag_special ? 1 : 2), " ");
                    int numero = n_str ? atoi(n_str) : 0;
                    char *country = strtok(NULL, "\"");
                    if (country) removeaspas(country);
                    
                    query2(getArtistas(getGestorArtista(g)), numero, country, output, flag_special);
                    
                    clock_gettime(CLOCK_REALTIME, &end);
                    elapsed_time = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
                    
                    if (count_q2 >= size_q2) {
                        size_q2 *= 2;
                        double *temp = realloc(tempo_query2, size_q2 * sizeof(double));
                        if (!temp) {
                            fprintf(stderr, "Erro no realloc\n");
                            break;
                        }
                        tempo_query2 = temp;
                    }
                    tempo_query2[count_q2++] = elapsed_time;
                    break;
                }
                case '3': {
                    char *idade_minima_str = strtok(linha + (flag_special ? 1 : 2), " ");
                    char *idade_maxima_str = strtok(NULL, " ");
                    int idade_minima = idade_minima_str ? atoi(idade_minima_str) : 0;
                    int idade_maxima = idade_maxima_str ? atoi(idade_maxima_str) : 0;
                    
                    query3(getGenerosMatrix(g), idade_minima, idade_maxima, output, flag_special);
                    
                    clock_gettime(CLOCK_REALTIME, &end);
                    elapsed_time = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
                    
                    if (count_q3 >= size_q3) {
                        size_q3 *= 2;
                        double *temp = realloc(tempo_query3, size_q3 * sizeof(double));
                        if (!temp) {
                            fprintf(stderr, "Erro no realloc\n");
                            break;
                        }
                        tempo_query3 = temp;
                    }
                    tempo_query3[count_q3++] = elapsed_time;
                    break;
                }
            }
        } else {
            // O mesmo código original para flag != 1
            switch (linha[0]) {
                case '1': {
                    char *id = strtok(linha + (flag_special ? 1 : 2), " ");
                    if (id) query1(getUtilizadores(getGestorUtilizador(g)), getArtistas(getGestorArtista(g)), id, output, flag_special);
                    break;
                }
                case '2': {
                    char *n_str = strtok(linha + (flag_special ? 1 : 2), " ");
                    int numero = n_str ? atoi(n_str) : 0;
                    char *country = strtok(NULL, "\"");
                    if (country) removeaspas(country);
                    query2(getArtistas(getGestorArtista(g)), numero, country, output, flag_special);
                    break;
                }
                case '3': {
                    char *idade_minima_str = strtok(linha + (flag_special ? 1 : 2), " ");
                    char *idade_maxima_str = strtok(NULL, " ");
                    int idade_minima = idade_minima_str ? atoi(idade_minima_str) : 0;
                    int idade_maxima = idade_maxima_str ? atoi(idade_maxima_str) : 0;
                    query3(getGenerosMatrix(g), idade_minima, idade_maxima, output, flag_special);
                    break;
                }
            }
        }

        FILE *arquivo_saida = fopen(nome_arquivo, "w");
        if (!arquivo_saida) {
            perror("Erro ao abrir o arquivo de saída");
            if (flag == 1) {
                free(tempo_query1);
                free(tempo_query2);
                free(tempo_query3);
            }
            return;
        }
        fprintf(arquivo_saida, "%s", output);
        fclose(arquivo_saida);
        counter++;
    }

    if (flag == 1) {
        // Cálculo das médias
        double media_query1 = 0, media_query2 = 0, media_query3 = 0;
        
        if (count_q1 > 0) {
            double somatorio1 = 0;
            for (int i = 0; i < count_q1; i++) {
                somatorio1 += tempo_query1[i];
            }
            media_query1 = somatorio1 / count_q1;
        }

        if (count_q2 > 0) {
            double somatorio2 = 0;
            for (int i = 0; i < count_q2; i++) {
                somatorio2 += tempo_query2[i];
            }
            media_query2 = somatorio2 / count_q2;
        }

        if (count_q3 > 0) {
            double somatorio3 = 0;
            for (int i = 0; i < count_q3; i++) {
                somatorio3 += tempo_query3[i];
            }
            media_query3 = somatorio3 / count_q3;
        }

        printf("\n");
        printf("Tempo de execução:\n");
        printf("    Q1: %f s (média de %d queries)\n", media_query1, count_q1);
        printf("    Q2: %f s (média de %d queries)\n", media_query2, count_q2);
        printf("    Q3: %f s (média de %d queries)\n", media_query3, count_q3);
        printf("\n");

        // Liberação da memória
        free(tempo_query1);
        free(tempo_query2);
        free(tempo_query3);
    }
}