.PHONY: all clean test_scanner test_parser

# Parámetros de compilación (gcc)
CFLAGS=-Wall -g

SRC_SCANNER=Scanner.c scanner_main.c
SRC_PARSER=Parser.c parser_main.c Scanner.c

all: scanner parser

scanner: $(SRC_SCANNER) Scanner.h
	gcc $(SRC_SCANNER) $(CFLAGS) -o $@

parser: $(SRC_PARSER) Parser.h
	gcc $(SRC_PARSER) $(CFLAGS) -o $@

test_scanner: scanner
	@./$< < pruebaScanner.txt

test_parser: parser
	@./$<

clean:
	rm scanner parser
