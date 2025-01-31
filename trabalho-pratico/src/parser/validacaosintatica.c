#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../include/parser/validacaosintatica.h"


int eData(char *data) {
    if (data == NULL){
        return 0;
    }

    if(strlen(data) != 10)
    {
        return 0;
    }

    if(data[4] != '/' || data[7] != '/') 
    {
        return 0;
    }
    // Make a copy of the input string to avoid modifying it
    char data_copy[11];
    strncpy(data_copy, data, 10);
    data_copy[10] = '\0';  // Ensure null termination

    char *ano = strtok(data_copy, "/");
    char *mes = strtok(NULL, "/");
    char *dia = strtok(NULL, "/");

    if (ano == NULL || mes == NULL || dia == NULL) {
        return 0;
    }

    int year = atoi(ano);
    int month = atoi(mes);
    int day = atoi(dia);

    if (year >= 2024 && month >= 9 && day > 9) {
        return 0;
    }

    if (year > 2024 || month < 1 || month > 12 || day < 1 || day > 31) {
        return 0;
    }
    
    return 1;
}

int eDuracao(char *duracao){
    if(strlen(duracao) != 8)
    {
        return 0;
    }

    if(duracao[2] != ':' || duracao[5] != ':')
    {
        return 0;
    }

    char *horas = strtok(duracao, ":");
    char *minutos = strtok(NULL, ":");
    char *segundos = strtok(NULL, ":");

    char *bufferh;
    char *bufferm;
    char *buffers;

    long int hour = strtol(horas, &bufferh, 10);
    long int min = strtol(minutos, &bufferm, 10);
    long int secs = strtol(segundos, &buffers, 10);

    if(*bufferh != '\0' || *bufferm != '\0' || *buffers != '\0')
    {
        return 0;
    }

    if(hour < 0 || hour > 99 || min < 0 || min > 59 || secs < 0 || secs > 59)
    {
        return 0;
    }

    return 1;

}


int is_valid_username(const char *user) {
    for (int i = 0; user[i] != '\0'; i++) {
        if (!isdigit(user[i]) && !islower(user[i])) {
            return 0; 
        }
    }
    return 1; 
}

int is_valid_lstring(const char *lstring) {
    if (strlen(lstring) < 1) {
        return 0;  
    }
    for (int i = 0; lstring[i] != '\0'; i++) {
        if (!islower(lstring[i])) {
            return 0;  
        }
    }
    return 1;  
}

int is_valid_rstring(const char *rstring) {
    int len = strlen(rstring);
    if (len != 2 && len != 3) {
        return 0;  
    }
    for (int i = 0; rstring[i] != '\0'; i++) {
        if (!islower(rstring[i])) {
            return 0;  
        }
    }
    return 1;  
}

int eEmail(char *email) {    
    char *user = strtok(email, "@");
    if (user == NULL || !is_valid_username(user)) {
        return 0;
    }

    char *domain = strtok(NULL, "@");
  
    if (domain == NULL) {
        return 0;
    }

    if(domain[0] == '.')
    {
        return 0;
    }
    char *lstring = strtok(domain, ".");
    char *rstring = strtok(NULL, ".");

    if (lstring == NULL || rstring == NULL || strtok(NULL, ".") != NULL) {
        return 0;
    }

    if (!is_valid_lstring(lstring)) {
        return 0;
    }
    if (!is_valid_rstring(rstring)) {
        return 0;
    }

    return 1;
}

int eSubscricao(char *tipo)
{
    if(strcmp(tipo,"normal") && strcmp(tipo,"premium"))
    {
        return 0;
    }

    return 1;
}

int ePlataforma(char* plataforma)
{
    char* plat = strdup(plataforma);
    if (plat == NULL) {
        return 0; 
    }

    for (int i = 0; plat[i] != '\0'; i++) {
        plat[i] = tolower(plat[i]);
    }

    // Compare strings
    if(strcmp(plat, "mobile") == 0 || strcmp(plat, "desktop") == 0)
    {
        free(plat);
        return 1;
    } 
    free(plat);
    return 0;
}

int eType(char* tipo)
{
    char* str = strdup(tipo);
    if (str == NULL) {
        return 0;
    }

    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }

    // Compare strings
    if(strcmp(str, "individual") == 0 || strcmp(str, "group") == 0){
        free(str);
        return 1;
    } 

    free(str); 
    return 0;
}