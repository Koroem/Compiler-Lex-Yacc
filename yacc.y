
%{
#include <stdio.h>
#include <string.h>
#include "symbol_table.c"


extern FILE* yyin;
extern char* yytext;
extern int yylineno;

float float_array[100000];
int float_array_size=0;

int int_array[100000];
int int_array_size=0;

int to_flag=0;

struct expr_list arguments_stack[MAX_FUNCTION_PARAMETERS];
struct expr_list arguments;


enum array_type {INT_ARRAY, FLOAT_ARRAY};
enum array_type current_array_type;


void push_arguments() {
    arguments_stack_pointer++;
}

void pop_arguments() {
    clear_arguments(&arguments_stack[arguments_stack_pointer]);
    arguments_stack_pointer--;
    
}

void clear_arguments(expr_list *arguments) {
    arguments->nr_of_arguments=0;
    memset(arguments, 0, sizeof(expr_list));
}

void clear_float_array()
{
  memset(float_array,0,float_array_size*sizeof(float));
   float_array_size=0;
}

void clear_int_array()
{

  memset(int_array,0,int_array_size*sizeof(int));
  int_array_size=0;
}

%}

%union {

  char *string;
  int bool_value;
  int   int_value;
  float float_value;
  char character;

  struct expr_info * expr_ptr;
  
}


%token BGIN END FUNCTION  CLASS DEFINE START_CONST START_VARIABLES
%token START_FUNCTIONS START_CLASSES END_CONST END_VARIABLES END_FUNCTIONS END_CLASSES 
%token IF ELSE WHILE DO FOR BREAK CONTINUE PRINT EXIT RETURN  
%token LE GE EQ NE AND OR  EVAL TYPEOF
%token PRINT_SYMBOL_TABLES COMMENT
%start progr

%token <string> TYPE
%token <string> ID
%token <string> CONST
%token <string> ASSIGN
%token <string> STRING
%token <int_value> INT
%token <character> CHAR
%token <string> BOOL
%token <float_value> FLOAT


%type <expr_ptr>expr
%type <expr_ptr>function_call 
%type <string>declaratie

%left ',' '['
%left AND OR
%left '<' '>' LE GE EQ NE
%left '!'
%left '+''-'
%left '*''/' '%'
%left '^'

%%

progr: START_CONST constants END_CONST  BGIN statements END  {printf("\nCompiled successfuly\n");}   
| START_VARIABLES declaratii END_VARIABLES  BGIN statements END {printf("\nCompiled successfuly\n");}
| START_FUNCTIONS functions END_FUNCTIONS  BGIN statements END {printf("\nCompiled successfuly\n");}
| START_CLASSES classes END_CLASSES  BGIN statements END {printf("\nCompiled successfuly\n");}
| START_CONST constants END_CONST START_VARIABLES declaratii END_VARIABLES BGIN statements END {printf("\nCompiled successfuly\n");}
| START_CONST constants END_CONST START_FUNCTIONS functions END_FUNCTIONS  BGIN statements END {printf("\nCompiled successfuly\n");}
| START_CONST constants END_CONST START_CLASSES classes END_CLASSES  BGIN statements END {printf("\nCompiled successfuly\n");}
| START_VARIABLES declaratii END_VARIABLES START_FUNCTIONS functions END_FUNCTIONS  BGIN statements END {printf("\nCompiled successfuly\n");}
| START_VARIABLES declaratii END_VARIABLES START_CLASSES classes END_CLASSES  BGIN statements END {printf("\nCompiled successfuly\n");}
| START_FUNCTIONS functions END_FUNCTIONS START_CLASSES classes END_CLASSES  BGIN statements END {printf("\nCompiled successfuly\n");}
| START_CONST constants END_CONST START_VARIABLES declaratii END_VARIABLES START_FUNCTIONS functions END_FUNCTIONS  BGIN statements END {printf("\nCompiled successfuly\n");}
| START_CONST constants END_CONST START_VARIABLES declaratii END_VARIABLES START_CLASSES classes END_CLASSES  BGIN statements END {printf("\nCompiled successfuly\n");}
| START_CONST constants END_CONST START_FUNCTIONS functions END_FUNCTIONS START_CLASSES classes END_CLASSES  BGIN statements END {printf("\nCompiled successfuly\n");}
| START_VARIABLES declaratii END_VARIABLES START_FUNCTIONS functions END_FUNCTIONS START_CLASSES classes END_CLASSES  BGIN statements END {printf("\nCompiled successfuly\n");}
| START_CONST constants END_CONST START_VARIABLES declaratii END_VARIABLES START_FUNCTIONS   functions END_FUNCTIONS START_CLASSES classes END_CLASSES  BGIN statements END {printf("\nCompiled successfuly\n");}
| BGIN END  {printf("\nCompiled successfuly\n");}
;



statements: statement
    | statements statement
    ;

statement:declaratie
         | if
         | while
         | do
         | for 
         | break
         | continue
         | typeof
         | print
         | exit
         | function_call
         | return
         | eval
         | assignment
         | coms
         ;


coms:COMMENT
    ;
assignment: ID ASSIGN expr ';' {create_assignment(0,$1,-1,$3);}
          | CONST ID ASSIGN expr';' {create_assignment(0,$2,-1,$4);}
          | ID '[' INT ']' ASSIGN expr ';'{create_assignment(1,$1,$3,$6);}
          | CONST ID '[' INT ']' ASSIGN expr ';'{create_assignment(1,$2,$4,$7);}
          | class_obj ASSIGN expr ';'
          ;
class_obj: ID '.' ID
         ;

if: IF '(' expr ')' '{' statements '}'
  | IF '(' expr ')' '{' statements '}' ELSE '{' statements '}'
  ;

while: WHILE '(' expr ')' '{' statements '}'
     ;

do: DO '{' statements '}' WHILE '(' expr ')' ';'
  ;
for: FOR '(' ID ASSIGN expr ';' expr ';' ID ASSIGN expr ')' '{' statements '}'
  |  FOR  '(' TYPE ID ASSIGN expr ';' expr ';' ID ASSIGN expr ')' '{' statements '}'
  ;

break: BREAK ';'
     ;

continue: CONTINUE ';'
        ;

print: 
     PRINT_SYMBOL_TABLES ';' {print_symbol_tables();}
    | PRINT '(' expr ')' ';'
    ;
exit: EXIT '(' INT ')' ';' 
     ;
return:RETURN ';'
      |RETURN expr ';'
      ;
eval: EVAL '(' expr ')' {eval($3);} 
    ;
constants :  /* empty */
	   | constants constant_declaration
	   ;


constant_declaration:
    DEFINE ID INT ';' {add_constant($2,$3);}
  ;

declaratii :  /* empty */
	   | declaratii declaratie 
	   ;


declaratie:
 TYPE ID ';'  {create_variable(0,$1,$2,NULL);} /* const_flag , TYPE, ID, value */ 
| CONST TYPE ID ';' {create_variable(1,$2,$3,NULL);} 

| TYPE ID ASSIGN expr ';' {create_variable(0,$1,$2,$4);}
| CONST TYPE ID ASSIGN expr ';' {create_variable(1,$2,$3,$5);}

| TYPE ID '[' INT ']' ';' {create_array(0,$1,$2,$4,NULL,NULL);}
| CONST TYPE ID '[' INT ']' ';' {create_array(1,$2,$3,$5,NULL,NULL);}

| TYPE ID '[' INT ']' ASSIGN '{' init_list '}' ';' {
      if (current_array_type == INT_ARRAY){
            create_array(0, $1, $2, $4, int_array,NULL);
            clear_int_array();
        } else if (current_array_type == FLOAT_ARRAY){
            create_array(0, $1, $2, $4, NULL,float_array);
            clear_float_array();
        }
      }
| CONST TYPE ID '[' INT ']' ASSIGN '{' init_list '}' ';'
  {
      if (current_array_type == INT_ARRAY){
          create_array(1, $2, $3, $5, int_array,NULL);
          clear_int_array();
      } else if (current_array_type == FLOAT_ARRAY){
          create_array(1, $2, $3, $5, NULL,float_array);
          clear_float_array();
      }
  }

init_list: INT { 
    current_array_type = INT_ARRAY;
    int_array[int_array_size++] = $1; 
    }
    | init_list ',' INT { 
    current_array_type = INT_ARRAY;
    int_array[int_array_size++] = $3; 
    }
    |FLOAT {
    current_array_type = FLOAT_ARRAY;
    float_array[float_array_size++] = $1; 
    }
    | init_list ',' FLOAT {
    current_array_type = FLOAT_ARRAY;
    float_array[float_array_size++] = $3; 
    }
;

/*
| TYPE ID ',' ID ';'           
| CONST TYPE ID ',' ID ';'        
| TYPE ID ',' ID ',' var_list ';'
| CONST TYPE ID ',' ID ',' var_list ';'
| TYPE ID ',' ID ',' var_list ASSIGN expr ';'
| CONST TYPE ID ',' ID ',' var_list ASSIGN expr ';'
| TYPE ID '[' INT ']' ';'
| CONST TYPE ID '[' INT ']' ';'
| TYPE ID '[' INT ']' ASSIGN '{' init_list '}' ';'
| CONST TYPE ID '[' INT ']' ASSIGN '{' init_list '}' ';'
| TYPE ID '[' INT ']' ',' ID '[' INT ']' ';'
| CONST TYPE ID '[' INT ']' ',' ID '[' INT ']' ';'
| TYPE ID '[' INT ']' ',' ID '[' INT ']' ',' var_list ';'
| CONST TYPE ID '[' INT ']' ',' ID '[' INT ']' ',' var_list ';'
| TYPE ID '[' INT ']' ',' ID '[' INT ']' ',' var_list ASSIGN expr ';'
| CONST TYPE ID '[' INT ']' ',' ID '[' INT ']' ',' var_list ASSIGN expr ';'
| TYPE ID '[' INT ']' ',' ID '[' INT ']' ASSIGN '{' init_list '}' ';'
| CONST TYPE ID '[' INT ']' ',' ID '[' INT ']' ASSIGN '{' init_list '}' ';'
;
var_list: ID
| var_list ',' ID
;
*/



expr: expr '-' expr  {$$=create_expr($1,"-",$3);}
    | expr '+' expr  {$$=create_expr($1,"+",$3);} 
    | expr '*' expr  {$$=create_expr($1,"*",$3);} 
    | expr '/' expr  {$$=create_expr($1,"/",$3);}   
    | expr '^' expr  {$$=create_expr($1,"^",$3);}            
    | expr '%' expr  {$$=create_expr($1,"%",$3);}       
    | '(' expr ')'   {$$=$2;}   
    | expr '<' expr    {$$=create_expr($1,"<",$3);}  
    | expr '>' expr   {$$=create_expr($1,">",$3);} 
    | expr LE expr    {$$=create_expr($1,"<=",$3);}   
    | expr GE expr    {$$=create_expr($1,">=",$3);}
    | expr EQ expr   {$$=create_expr($1,"==",$3);}  
    | expr NE expr    {$$=create_expr($1,"!=",$3);}
    | expr AND expr   {$$=create_expr($1,"&&",$3);}  
    | expr OR expr     {$$=create_expr($1,"||",$3);}
    | function_call   
    | STRING          {$$=create_string($1);}
    | INT             {$$=create_int($1);}
    | FLOAT             {$$=create_float($1);} 
    | CHAR             {$$=create_chr($1);} 
    | BOOL              {if(yylval.bool_value==1)$$=create_bool(1);else $$=create_bool(0);}
    | ID                {$$=create_id($1);}
    | ID '[' INT ']'    {$$=create_arr($1,$3);}
    //| class_obj 
    ;





function_call: ID '('{push_arguments();} ')'  {$$=function_call($1, &arguments_stack[arguments_stack_pointer]);pop_arguments();}
             | ID  '('{push_arguments();}  expr_list ')' {$$=function_call($1, &arguments_stack[arguments_stack_pointer]); pop_arguments();}
             //| ID '.' ID '(' expr_list ')' //{push_arguments(); function_call($1, &arguments); pop_arguments();}
             ;

expr_list: expr {arguments_stack[arguments_stack_pointer].nr_of_arguments = 1; arguments_stack[arguments_stack_pointer].function_call_arguments[0] = *$1; }
         | expr_list ',' expr { arguments_stack[arguments_stack_pointer].nr_of_arguments++;
                                arguments_stack[arguments_stack_pointer].function_call_arguments[arguments_stack[arguments_stack_pointer].nr_of_arguments - 1] = *$3;}
         ;

typeof: TYPEOF '('expr')' ';' { printf("Type: %s\n",$3->type);}
      ;
functions :  function_declaration
	   |  functions function_declaration 
	   ;       

function_declaration:
    FUNCTION TYPE ID '(' function_parameters')' '{' function_body '}' {
        create_function($2, $3);
        function_parameter_count = 0;
    }
function_parameters:/* Empty */ {}
    | TYPE ID { 
        function_parameters[function_parameter_count].type = $1;
        function_parameters[function_parameter_count].name = $2;
        function_parameter_count++;
    }
    | function_parameters ',' TYPE ID { 
        function_parameters[function_parameter_count].type = $3;
        function_parameters[function_parameter_count].name = $4;
        function_parameter_count++;
    }

function_body:
        | statements
        ;


classes:
       | classes class
        ;
class: CLASS ID '{' '}' ';'
    | CLASS ID ';'
    |CLASS ID '{' class_body '}' ';'
    ;

class_body:
        declaratie
        |function_declaration
        | class_body declaratie 
        | class_body function_declaration
        ;
%%
void yyerror(char * s){
  printf("\nSyntax error: %s at line :%d\n",s,yylineno);
}

int main(int argc, char** argv){
  yyin=fopen(argv[1],"r");
  yyparse();
} 