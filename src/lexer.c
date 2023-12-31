#include "include/lexer.h"  
#include <stdlib.h> 
#include <string.h> 
#include <ctype.h>



lexer_T* initLexer(char* contents)
{ 
    lexer_T* lexer = calloc(1, sizeof(struct LEXER_STRUCT)); 
    lexer->contents = contents; 
    lexer->i = 0; 
    lexer->c = contents[lexer->i]; 

    return lexer;
}


void lexerAdvance(lexer_T* lexer)
{ 
    if (lexer->c != '\0' && lexer->i < strlen(lexer->contents)) 
    { 
        lexer->i += 1; 
        lexer->c = lexer->contents[lexer->i];
    }
}


void lexerSkipWhitespace(lexer_T* lexer)
{ 
    while (lexer->c == ' ' || lexer->c == 10) //10 is code for a new line which should also be skipped
    { 
        lexerAdvance(lexer);
    }
}


token_T* lexerCollectString(lexer_T* lexer) 
{ 
    lexerAdvance(lexer); // 

    char* value = calloc(1, sizeof(char)); 
    value[0] = '\0';

    while (lexer->c != '"') 
    {
        char* s = lexerGetCurrentCharAsString(lexer); 
        value = realloc(value, (strlen(value) + strlen(s) + 1) * sizeof(char)); 
        strcat(value, s); 

        lexerAdvance(lexer);
    } 
 
    lexerAdvance(lexer);

    return initToken(TOKEN_STRING, value);
}  


token_T* lexerCollectID(lexer_T* lexer)
{

    char* value = calloc(1, sizeof(char)); 
    value[0] = '\0';

    while (isalnum(lexer->c)) 
    {
        char* s = lexerGetCurrentCharAsString(lexer); 
        value = realloc(value, (strlen(value) + strlen(s) + 1) * sizeof(char)); 
        strcat(value, s); 

        lexerAdvance(lexer);
    } 


    return initToken(TOKEN_ID, value);
}


token_T* lexerAdvanceWithToken (lexer_T* lexer, token_T* token)
{ 
    lexerAdvance(lexer); 

    return token;
} 


token_T* lexerGetNextToken(lexer_T* lexer)
{ 
    while (lexer->c != '\0' && lexer->i < strlen(lexer->contents)) 
    { 
        if (lexer->c == ' ' || lexer->c == 10) 
        { 
            lexerSkipWhitespace(lexer);
        }   

        if (isalnum(lexer->c))
        { 
            return lexerCollectID(lexer);
        }

        if (lexer->c == '"') 
        { 
            return lexerCollectString(lexer);
        }

        switch (lexer->c) 
        { 
            case '=': return lexerAdvanceWithToken(lexer, initToken(TOKEN_EQUALS, lexerGetCurrentCharAsString(lexer))); break; 
            case ';': return lexerAdvanceWithToken(lexer, initToken(TOKEN_SEMI, lexerGetCurrentCharAsString(lexer))); break; 
            case '(': return lexerAdvanceWithToken(lexer, initToken(TOKEN_LPAREN, lexerGetCurrentCharAsString(lexer))); break; 
            case ')': return lexerAdvanceWithToken(lexer, initToken(TOKEN_RPAREN, lexerGetCurrentCharAsString(lexer))); break;
        }
    } 

    return (void*)0;
}


char* lexerGetCurrentCharAsString(lexer_T* lexer) 
{ 
    char* str = calloc(2, sizeof(char)); 
    str[0] = lexer->c; 
    str[1] = '\0'; 

    return str;
}