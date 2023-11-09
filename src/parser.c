#include "include/parser.h"
#include <stdio.h>
#include <string.h>

parser_T* initParser(lexer_T* lexer)
{ 
    parser_T* parser = calloc(1, sizeof(struct PARSER_STRUCT));
    parser->lexer = lexer; 
    parser->current_token = lexerGetNextToken(lexer);
}

void parserEat(parser_T* parser, int tokenType) 
{ 
    if (parser->current_token->type == tokenType)
    { 
        parser->current_token = lexerGetNextToken(parser->lexer);
    } 
    else 
    {
        printf(
            "Unexpected token '%s', with type %d",
            parser->current_token->value, 
            parser->current_token->type
        );
        exit(1);
    }
}

AST_T* parserParse(parser_T* parser)
{
    return parserParseStatements(parser);
}

AST_T* parserParseStatement(parser_T* parser)
{ 
    switch (parser->current_token->type)
    { 
        case TOKEN_ID: return parserParseID(parser);
    }
} 

AST_T* parserParseStatements(parser_T* parser)
{ 
    AST_T* compound = initAST(AST_COMPOUND);
    compound->compound_value = calloc(1, sizeof(struct AST_STRUCT*));

    AST_T* ast_statement = parserParseStatement(parser);
    compound->compound_value[0] = ast_statement;

    while (parser->current_token->type == TOKEN_SEMI)
    { 
        parserEat(parser, TOKEN_SEMI);

        AST_T* ast_statement = parserParseStatement(parser);
        compound->compund_size += 1;
        compound->compound_value = realloc(compound->compound_value, compound->compund_size * sizeof(struct AST_STRUCT));
        compound->compound_value[compound->compund_size-1] = ast_statement;
    }

    return compound;
}

AST_T* parserParseExpresions(parser_T* parser)
{ 
    switch (parser->current_token->type)
    { 
        case TOKEN_STRING: return parserParseStr(parser);
    }
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

AST_T* parserParseVarDef(parser_T* parser)
{ 
    parserEat(parser, TOKEN_ID); //var
    char* variableDefinitionVariableName = parser->current_token->value; 
    parserEat(parser, TOKEN_ID); //var name
    parserEat(parser, TOKEN_EQUALS); // = sign
    AST_T* variableDefinitionValue = parserParseExpresions(parser);

    AST_T* variable_def = initAST(AST_VARIABLE_DEFINITION);
    variable_def->variableDefinitionVariableName = variableDefinitionVariableName;
    variable_def->variableDefinitionValue = variableDefinitionValue; 

    return variable_def;
}

AST_T* parserParseVar(parser_T* parser)
{ 
    char* token_value = parser->current_token->value;
    parserEat(parser, TOKEN_ID); 

    if (parser->current_token->type == TOKEN_LPAREN)
    { 
        return parserParseFuncCall(parser); 
    }

    AST_T* ast_variabe = initAST(AST_VARIABLE);
    ast_variabe->variableName = token_value;

    return ast_variabe;
} 

AST_T* parserParseStr(parser_T* parser)
{ 
    AST_T* ast_string = initAST(AST_STRING); 
    ast_string->stringValue = parser->current_token->value;

    parserEat(parser, TOKEN_STRING);

    return ast_string;
}

AST_T* parserParseID(parser_T* parser)
{
    if (strcmp(parser->current_token->value, "var") == 0)
    { 
        return parserParseVarDef(parser);
    }
    else 
    {
        return parserParseVar(parser);
    }
}