#include <stdio.h>
#include <stdlib.h>
#include "Scanner.h"

int main(void) {
    Token t;

    while (1) {
        bool ok = GetNextToken(&t);

        if (!ok || t.tipo == token_EOF) {
            printf("[EOF]\n");
            break;
        }

        printf("Token: %-20s  Lexema: '%s'\n",
               token_a_cadena(t.tipo),
               t.lexema);
    }

    return 0;
}
