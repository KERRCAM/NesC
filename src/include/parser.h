#ifndef PARSER_H 
#define PARSER_H  
#include "AST.h"
#include "lexer.h"


typedef struct PARSER_STRUCT 
{ 
    lexer_T* lexer; 
    token_T* current_token; 
} parser_T;

parser_T* initParser(lexer_T* lexer); 

void parserEat(parser_T* parser, int tokenType);

AST_T* parserParse(parser_T* parser); 

AST_T* parserParseStatement(parser_T* parser); 

AST_T* parserParseStatements(parser_T* parser);

AST_T* parserParseExpresions(parser_T* parser); 

AST_T* parserParseFactor(parser_T* parser); 

AST_T* parserParseTerm(parser_T* parser);

AST_T* parserParseFuncCall(parser_T* parser); 

AST_T* parserParseVar(parser_T* parser); 

AST_T* parserParseStr(parser_T* parser);

#endif