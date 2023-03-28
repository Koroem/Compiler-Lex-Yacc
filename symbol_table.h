#include <stdlib.h>
#include <string.h>

#define MAX 10000
#define MAX_FUNCTION_PARAMETERS 100


typedef struct constant
{
   char *name;
   int  value; 
}constant;

typedef struct variable
{
   int initialized;
   
   int constant;
   char *type;   
   char *name;

   int bool_val;
   int int_val;
   int void_val;

   float float_val;
   char  char_val;
   char* string_val;
}variable;

typedef struct array
{
   int constant;
   char *type;
   char* name;
   int initialized;
   int size;
   union {
        int *int_array;
        float *float_array;
    };
}array;

typedef struct function_parameter {
    char *type;
    char *name;
}function_parameter;

struct function {
    char *name;
    char *return_type;
    struct function_parameter parameters[MAX_FUNCTION_PARAMETERS];
    int parameter_count;
};

typedef struct class
{
   char * name;

}class;


typedef struct expr_info
{

   int int_value;
   int bool_value;
   float float_value;
   char chr_value;
   char *str_value;
   char* type;
}expr_info;

typedef struct expr_list
{
   struct expr_info function_call_arguments[MAX_FUNCTION_PARAMETERS];
   int nr_of_arguments;
}expr_list;

typedef struct {
    expr_info function_call_arguments[MAX_FUNCTION_PARAMETERS];
    int nr_of_arguments;
    int top;
} expr_list_stack;

struct constant symbol_table_constants[MAX];
struct variable symbol_table_variables[MAX];
struct array    symbol_table_arrays[MAX];
struct function symbol_table_functions[MAX];
struct class symbol_table_classes[MAX];


struct function_parameter function_parameters[100];
int function_parameter_count = 0;

int constants=-1;
int variables=-1;
int arrays=-1;
int functions=-1;
int classes=-1;
int arguments_stack_pointer = -1;