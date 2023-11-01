#include <stdio.h> 
#include "include/lexer.h"

int main(int argc, char* argv[]) 
{ 
    lexer_T* lexer = initLexer( 
        "var name = \"test print\";" 
        "print(name);"

    ); 

    token_T* token = (void*)0; 

    while ((token = lexerGetNextToken(lexer)) != (void*)0) 
    { 
        printf("TOKEN(%d, %s)\n", token->type, token->value);
    }

    return 0; 
} 