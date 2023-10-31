#include "include/lexer.h"  
#include <stdlib.h> 
#include <string.h> 



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

token_T* lexerGetNextToken(lexer_T* lexer)
{ 
    while (lexer->c != '\0' && lexer->i < strlen(lexer->contents)) 
    { 
        if (lexer->c == ' ' || lexer->c == 10) 
        { 
            lexerSkipWhitespace(lexer);
        } 

        switch (lexer->c) 
        { 
            case '=': return lexerAdvanceWithToken(lexer, initToken(TOKEN_EQUALS, lexerGetCurrentCharAsString(lexer))); break;
        }
    }
}

token_T* lexerCollectString(lexer_T* lexer) 
{ 

} 

token_T* lexerAdvanceWithToken (lexer_T* lexer, token_T* token)
{ 
    lexerAdvance(lexer); 

    return token;
}

char* lexerGetCurrentCharAsString(lexer_T* lexer) 
{ 

}