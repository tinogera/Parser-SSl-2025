# TP 5 - Parser LN

Grupo 4

Autores:

| Usuario | Legajo | Apellido | Nombre |
|---------|--------|----------|--------|
| marcosegan  | 220.817-9 | Egan  | Marcos Ariel |
| aculeddu        | 220.808-8       | Culeddu         | Ana Clara       |
| Lucawieczorek1  | 211.507-4   | Wieczorek    | Luca       |
| Maximiliano-E-Gigli| 222.352-1| Gigli | Maximiliano |
| FedericoLopezLapaz| 222.465-3| Lopez Lapaz| Federico Gabriel |
| tinogera | 213.742-2-3| Gerardi | Santino |

## Objetivo

El objetivo de este trabajo es crear un Parser que permita pasar de declaraciones en el lenguaje C a "Lenguaje Natural"

## Especificación Léxica (Regex):

int      = "int"
char     = "char" 
void     = "void"
float    = "float"
double   = "double"

IDENTIFICADOR = [a-zA-Z_][a-zA-Z0-9_]*

NUMERO = [0-9]+

PARENTESIS_ABRE    = "("

PARENTESIS_CIERRA  = ")"

CORCHETE_ABRE      = "["

CORCHETE_CIERRA    = "]"

PUNTO_Y_COMA       = ";"

ASTERISCO          = "*"

EOF = fin de archivo

ERROR = cualquier secuencia no reconocida por las reglas anteriores

## Especificación Sintáctica (BNF):

```
UT:
    declaración
    | UT declaración
    ;

declaración:
    tipo declarador ';'
    ;
 
declarador:
    puntero declarador-directo
    | declarador-directo
    ;

declarador-directo:
    identificador
    | '(' declarador ')'
    | declarador '(' ')'
    | declarador '[' ']'
    | declarador '[' numero ']' 
    ;

puntero:
    '*'
    | puntero '*'
    ;

tipo:
    identificador
    | int
    | double
    | float
    | char
    | void
    ;

```
