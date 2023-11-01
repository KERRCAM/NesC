#include "include/AST.h"

AST_T* initAST(int type) 
{
    AST_T* ast = calloc(1, sizeof(struct AST_STRUCT)); 
    ast->type = type;  


    /* AST_VARIBALE_DEFINITION*/ 
    ast->variableDefinitionVariableName = (void*) 0; 
    ast->variableDefinitionValue = (void*) 0; 

    /* AST_VARABLE */ 
    ast->variableName = (void*) 0; 

    /* AST_FUNCTION_CALL */
    ast->functionCallName = (void*) 0; 
    ast->functionCallArguments = (void*) 0; 
    ast->functionCallArgumentsSize = 0;

    /* AST_STRING */ 
    ast->stringValue = (void*) 0;


    return ast;
} 