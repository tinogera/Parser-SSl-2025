#include "Parser.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void dcl();
void dirdcl();
void declaracion();

Token token_actual;
char token_name[MAX_LEXEMA];

// Nombre del tipo de datos
char datatype[MAX_LEXEMA];

#define OUT_SIZE 1000

//Buffer pedazos de frase
char out[OUT_SIZE];

void unidad_de_traduccion() {
    
    GetNextToken(&token_actual);
    
    while (token_actual.tipo != token_EOF) {
        declaracion();
        GetNextToken(&token_actual);
    }

}

bool es_keyword() {
    return token_actual.tipo >= token_int && token_actual.tipo <= token_char;
}
bool es_especificador_de_tipo() {
    return token_actual.tipo == token_identificador || es_keyword();
}


// declaracion: Compureba que sea una declaración
void declaracion(void){
    out[0] = '\0';
    if (es_especificador_de_tipo())
    {
        strncpy(datatype, token_actual.lexema, MAX_LEXEMA);

        GetNextToken(&token_actual);
        dcl();
        
        
        if (token_actual.tipo != token_punto_coma){
            printf("error: falta punto y coma\n");
            return;
        }
    }
    else
        printf("error: tipo de dato esperado\n");

    printf("%s %s\n", out, datatype);
}


int punteros() {
    int asteriscos = 0;
    while(token_actual.tipo == token_asterisco) {
        GetNextToken(&token_actual);
        asteriscos++;
    }
    return asteriscos;
}

// dcl: Comprueba que sea un declarador
void dcl() {
    int asteriscos = punteros();
    dirdcl();

    while(asteriscos-- > 0) {
        strcat(out, " puntero a");
    }
}


 // dirdcl: Comprueba que sea un declaradorDirecto
void dirdcl() {
    
    if (token_actual.tipo == token_par_abre) { // Caso de: (dcl)
        
        GetNextToken(&token_actual);
        dcl();

        if (token_actual.tipo != token_par_cierra)
            printf("error: falta ')'\n");

    }
    else if (token_actual.tipo == token_identificador) { // Caso de: identificador
        printf("%s: ", token_actual.lexema);
    }
    {
        /*
        Casos de:
        | declarador '(' ')'
        | declarador '[' ']'
        | declarador '[' numero ']' 
        */
        GetNextToken(&token_actual);

        if (token_actual.tipo == token_par_abre) {
            if (GetNextToken(&token_actual) && token_actual.tipo == token_par_cierra) {
                strcat(out, " función que devuelve");
            }
            else {
                printf("error: esperaba ')'\n");
            }
            GetNextToken(&token_actual);
        }
        else while (token_actual.tipo == token_corchete_abre) {
            GetNextToken(&token_actual);
        
            strcat(out, " array [");

            if (token_actual.tipo == token_numero) { //Caso de que se especifique el tamaño del array
                strcat(out, token_actual.lexema);
                GetNextToken(&token_actual);
            }
            strcat(out, "] de");

            if (token_actual.tipo != token_corchete_cierra) {
                printf("error: esperaba ']'\n");
            }
            GetNextToken(&token_actual);
        }
    }
    return;
}
