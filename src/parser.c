#include "include/parser.h"


parser_T* initParser(lexer_T* lexer)
{ 
    parser_T* parser = calloc(1, sizeof(struct PARSER_STRUCT));
    parser->lexer = lexer; 
    parser->current_token = lexerGetNextToken(lexer);
}

void parserEat(parser_T* parser, int tokenType) 
{ 

}

AST_T* parserParse(parser_T* parser)
{

}

AST_T* parserParseStatement(parser_T* parser)
{ 

} 

AST_T* parserParseStatements(parser_T* parser)
{ 

}

AST_T* parserParseExpresions(parser_T* parser)
{ 

}

AST_T* parserParseFactor(parser_T* parser)
{ 

}

AST_T* parserParseTerm(parser_T* parser)
{ 

}

AST_T* parserParseFuncCall(parser_T* parser)
{ 

} 

AST_T* parserParseVar(parser_T* parser)
{ 

} 

AST_T* parserParseStr(parser_T* parser)
{ 
    
}