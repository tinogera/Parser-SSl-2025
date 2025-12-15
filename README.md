# Traductor de Declaraciones C a Lenguaje Natural (dcl)

## Descripción

Este proyecto implementa un **traductor de declaraciones del lenguaje C a Lenguaje Natural (LN)**, basado en el programa clásico **dcl** presentado en *The C Programming Language* de Kernighan & Ritchie (sección 5.12).

El sistema analiza declaraciones de C utilizando un **scanner y un parser implementados manualmente**, sin herramientas automáticas y genera una traducción textual que explica el significado de la declaración.

El trabajo corresponde al **Caso de Estudio 28: Análisis Léxico y Sintáctico**, cumpliendo con las restricciones establecidas por la cátedra.

---

## Objetivos

- Diseñar el léxico y la sintaxis del lenguaje fuente.
- Implementar un **analizador léxico (Scanner)** manual.
- Implementar un **analizador sintáctico descendente recursivo (Parser)**.
- Traducir declaraciones complejas de C a Lenguaje Natural.
- Manejar errores léxicos y sintácticos.
- Usar flujos estándar (`stdin`) para permitir redirección de entrada.
- Aplicar modularización y separación clara de responsabilidades.

---

## Estructura del Proyecto

- Scanner.h // Interfaz del analizador léxico
- Scanner.c // Implementación del scanner
- Parser.h // Interfaz del analizador sintáctico
- Parser.c // Implementación del parser
- scanner_main.c // Programa de prueba del scanner
- parser_main.c // Programa principal del parser
- Makefile // Script de compilación

## Cada archivo cumple una función específica (leer README.md del /src):
- **Scanner**: análisis léxico y generación de tokens.
- **Parser**: análisis sintáctico y traducción a LN.
- **Main**: punto de entrada del programa.


## Equipo de Trabajo
- Egan, Marcos Ariel
- Gigli, Maximiliano Ezequiel
- Gerardi, Santino
- Lopez Lapaz, Federico Gabriel 
- Culeddu, Ana Clara
