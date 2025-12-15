#include "Scanner.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

static struct {
    const char *palabra;
    TipoDeToken tipo;
} palabras_reservadas[] = {
    { "int",     token_int },
    { "void",    token_void },
    { "char", token_char },
    { "double", token_double},
    { "float", token_float}
};

static const int cantidad_palabras =
    sizeof(palabras_reservadas) / sizeof(palabras_reservadas[0]); // (todavía no está tan prolijo)

static TipoDeToken verificar_palabra_reservada(const char *lexema) {
    for (int i = 0; i < cantidad_palabras; i++) {
        if (strcmp(lexema, palabras_reservadas[i].palabra) == 0)
            return palabras_reservadas[i].tipo;
    }
    return token_identificador;
}

bool GetNextToken(Token *salida) {

    int c;

    // Saltar espacios en blanco
    do {
        c = fgetc(stdin);

        if (c == EOF) {
        salida->tipo = token_EOF;
        strcpy(salida->lexema, "EOF");
        return false;
        }

    } while (isspace(c));


    // Identificadores o palabras reservadas
    if (isalpha(c) || c == '_') {
        int i = 0;
        salida->lexema[i++] = c;
        while ((c = fgetc(stdin)), (isalnum(c) || c == '_')) {
            salida->lexema[i++] = c;
        }
        ungetc(c, stdin);
        salida->lexema[i] = '\0';
        salida->tipo = verificar_palabra_reservada(salida->lexema);
        return true;
    }

    // Números
    if (isdigit(c)) {
        int i = 0;
        salida->lexema[i++] = c;
        while (isdigit(c = fgetc(stdin))) {
            salida->lexema[i++] = c;
        }
        ungetc(c, stdin);
        salida->lexema[i] = '\0';
        salida->tipo = token_numero;
        return true;
    }

    // Símbolos individuales
    salida->lexema[0] = c;
    salida->lexema[1] = '\0';

    switch (c) {
        case '(':
            salida->tipo = token_par_abre; break;
        case ')':
            salida->tipo = token_par_cierra; break;
        case '*':
            salida->tipo = token_asterisco; break;
        case ';':
            salida->tipo = token_punto_coma; break;

        case '[':
            salida->tipo = token_corchete_abre; break;
        case ']':
            salida->tipo = token_corchete_cierra; break;
        // case '.':
        //     salida->tipo = token_punto; break;
        default:
            salida->tipo = token_error; break;
    }

    return true;
}

// --------------------------------------------
// Convierte un tipo de token a texto
// --------------------------------------------
const char *token_a_cadena(TipoDeToken tipo) {
    switch (tipo) {
        case token_EOF: return "EOF";
        case token_error: return "Error";
        case token_identificador: return "Identificador";
        case token_numero: return "Número";
        case token_int: return "Palabra reservada: int";
        case token_void: return "Palabra reservada: void";
        case token_char: return "Palabra reservada: char";
        case token_double: return "Palabra reservada: double";
        case token_float: return "Palabra reservada: float";
        case token_par_abre: return "(";
        case token_par_cierra: return ")";
        case token_asterisco: return "*";
        case token_punto_coma: return ";";
        case token_corchete_abre: return "[";
        case token_corchete_cierra: return "]";
        default: return "Desconocido";
    }
}







