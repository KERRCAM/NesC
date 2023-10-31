#ifndef LEXER_H 
#define LEXER_H 
typedef struct LEXER_STRUCT 
{ 
    char c; 
    unsigned int i; 
    char* contents;
} lexer_T; 

lexer_T* initLexer(char* contents); 

void lexerAdvance(lexer_T* lexer); 

void lexerSkipWhitespace(lexer_T* lexer);

#endif