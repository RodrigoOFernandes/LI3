#include <stdlib.h>
#include <stdio.h>
#include "../include/utils/duracao_aux.h"

int duracaoparasegundos(char* duracao) {
    int hora = (duracao[0] - '0') * 10 + (duracao[1] - '0');
    int minutos = (duracao[3] - '0') * 10 + (duracao[4] - '0');
    int segundos = (duracao[6] - '0') * 10 + (duracao[7] - '0');

    return (hora * 3600 + minutos * 60 + segundos);
}

char *segundosparaduracao(int durac)
{
    int horas = durac / 3600;
    int minutos = (durac % 3600) / 60;
    int segundos = durac % 60;

    char *duracao = (char *)malloc(16 * sizeof(char));
    if (duracao == NULL)
    {
        return NULL;
    }

    snprintf(duracao, 16, "%02d:%02d:%02d", horas, minutos, segundos);
    return duracao;
}