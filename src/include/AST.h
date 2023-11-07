#ifndef AST_H 
#define AST_H  
#include <stdlib.h>



typedef struct AST_STRUCT 
{
   enum{
        AST_VARIABLE_DEFINITION,
        AST_VARIABLE,
        AST_FUNCTION_CALL, 
        AST_STRING, 
        AST_COMPOUND //compound is list of ast nodes
   } type; 

    /* AST_VARIBALE_DEFINITION*/ 
    char* variableDefinitionVariableName; 
    struct AST_STRUCT* variableDefinitionValue; 

    /* AST_VARABLE */ 
    char* variableName; 

    /* AST_FUNCTION_CALL */
    char* functionCallName; 
    struct AST_STRUCT** functionCallArguments; 
    size_t functionCallArgumentsSize; //broken

    /* AST_STRING */ 
    char* stringValue; 

    /* AST_COMPOUND */ 
    struct AST_STRUCT** compound_value; 
    size_t compund_size;

} AST_T;


AST_T* initAST(int type); 


#endif