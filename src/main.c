#include <stdio.h> 
#include "include/lexer.h"
#include "include/parser.h"

int main(int argc, char* argv[]) 
{ 
    lexer_T* lexer = initLexer( 
        "var name = \"test print\";" 
        "print(name);"

    ); 

    parser_T* parser = initParser(lexer); 
    AST_T* root = parserParse(parser); 

    printf("%d\n", root->type);
    printf("%d\n", root->compund_size);

    return 0; 
} 

/*
commands list
make 
make clean 
./NesC.out
*/