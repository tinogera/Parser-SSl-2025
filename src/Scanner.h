#ifndef SCANNER_H
#define SCANNER_H

#include <stdbool.h>
#include <stdio.h>

// Enum de tipos de tokens 
typedef enum {
    token_EOF,
    token_error,

    //identificadores y literales 
    token_identificador,
    token_numero,

    // palabras reservadas
    token_int,
    token_void,
    token_float,
    token_double,
    token_char,

    // símbolos y operadores 
    token_par_abre,      // (
    token_par_cierra,    // )
    token_asterisco,     // *
    token_punto_coma,    // ;
    token_corchete_abre, // [
    token_corchete_cierra,// ]

} TipoDeToken;

#define MAX_LEXEMA 128

typedef struct {
    TipoDeToken tipo;
    char lexema[MAX_LEXEMA];
} Token;

bool GetNextToken(Token *salida);
const char *token_a_cadena(TipoDeToken tipo);

#endif /* HEADER_SCANNER */
