# TP 5 - Parser LN

Grupo 4

Autores:

| Usuario |Apellido | Nombre |
|--------|--------|-------|
| marcosegan  |Marcos Ariel |
| aculeddu        |  Culeddu         | Ana Clara       |
| Lucawieczorek1  |  Wieczorek    | Luca       |
| Maximiliano-E-Gigli| Gigli | Maximiliano |
| FedericoLopezLapaz|  Lopez Lapaz| Federico Gabriel |
| tinogera | Gerardi | Santino |

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
