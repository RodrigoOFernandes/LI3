#include <stdio.h>
#include <glib.h>
#include "../include/utils/data_aux.h"

int calcular_idade(char *data_nascimento) {
    int ano, mes, dia;
    int anoAtual = 2024, mesAtual = 9, diaAtual = 9;

    // Extrai a data de nascimento (ano, mês e dia) da string
    sscanf(data_nascimento, "%d/%d/%d", &ano, &mes, &dia);
    
    // Calcula a idade
    int idade = anoAtual - ano;

    //Ajustando a idade se a pessoa ainda não tiver feito aniversário no ano atual
    if (mes > mesAtual || (mes == mesAtual && dia > diaAtual)) {
        idade--;
    }
    
    return idade;
}

char *get_ano_semana(char *data) {
    GDate *gdate = g_date_new();
    char *ano_semana = NULL;

    g_date_set_parse(gdate, data); // Tenta interpretar a string como uma data
    if (g_date_valid(gdate)) {     // Verifica se a data é válida
        guint year = g_date_get_year(gdate);
        guint week = g_date_get_iso8601_week_of_year(gdate);
        ano_semana = g_strdup_printf("%u-%02u", year, week); // Formata "ano-semana"
    }

    printf("%s", ano_semana);

    g_date_free(gdate); // Libera a memória alocada para o GDate
    return ano_semana;  // Retorna a string "ano-semana" ou NULL se inválida
}
