#ifndef TOKEN_H 
#define TOKEN_H 
typedef struct TOKEN_STRUCT 
{ 
    enum 
    { 
        TOKEN_ID, 
        TOKEN_EQUALS, 
        TOKEN_STRING, 
        TOKEN_INT,
        TOKEN_LPAREN, 
        TOKEN_RPAREN, 
        TOKEN_FLOAT
    } type; 

    char* value;
} token_T; 

token_T* initToken(int type, char* value);
#endif