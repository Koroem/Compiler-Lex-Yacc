#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <math.h>

#include "symbol_table.h"

void print_symbol_tables()
{
   int contor;

   FILE *file = fopen("symbol_table.txt", "r");
   if (file != NULL)
      if (file != NULL)
      {
         remove("symbol_table.txt");
      }
   file = fopen("symbol_table.txt", "a");
   if (constants >= 0)
   {
      fprintf(file, "Constants:\n------------------------------------------\n");
      for (contor = 0; contor <= constants; contor++)
      {
         fprintf(file, "%s : %d \n", symbol_table_constants[contor].name, symbol_table_constants[contor].value);
      }
      fprintf(file, "------------------------------------------\n\n");
   }
   if (variables >= 0)
   {
      fprintf(file, "Variables:\n------------------------------------------\n");
      for (contor = 0; contor <= variables; contor++)
      {
         if (strcmp(symbol_table_variables[contor].type, "int") == 0)
         {
            if (symbol_table_variables[contor].constant == 0)
               fprintf(file, "%s : %s : %d \n", symbol_table_variables[contor].type, symbol_table_variables[contor].name, symbol_table_variables[contor].int_val);
            if (symbol_table_variables[contor].constant == 1)
               fprintf(file, "const :%s : %s : %d \n", symbol_table_variables[contor].type, symbol_table_variables[contor].name, symbol_table_variables[contor].int_val);
         }
      }
      fprintf(file, "\n");
      for (contor = 0; contor <= variables; contor++)
      {

         if (strcmp(symbol_table_variables[contor].type, "float") == 0)
         {
            if (symbol_table_variables[contor].constant == 0)
               fprintf(file, "%s : %s : %f \n", symbol_table_variables[contor].type, symbol_table_variables[contor].name, symbol_table_variables[contor].float_val);
            if (symbol_table_variables[contor].constant == 1)
               fprintf(file, "const :%s : %s : %f \n", symbol_table_variables[contor].type, symbol_table_variables[contor].name, symbol_table_variables[contor].float_val);
         }
      }
      fprintf(file, "\n");
      for (contor = 0; contor <= variables; contor++)
      {
         if (strcmp(symbol_table_variables[contor].type, "bool") == 0)
         {
            if (symbol_table_variables[contor].constant == 0)
               fprintf(file, "%s : %s : %d \n", symbol_table_variables[contor].type, symbol_table_variables[contor].name, symbol_table_variables[contor].bool_val);
            if (symbol_table_variables[contor].constant == 1)
               fprintf(file, "const :%s : %s : %d \n", symbol_table_variables[contor].type, symbol_table_variables[contor].name, symbol_table_variables[contor].bool_val);
         }
      }
      fprintf(file, "\n");
      for (contor = 0; contor <= variables; contor++)
      {
         if (strcmp(symbol_table_variables[contor].type, "char") == 0)
         {
            if (symbol_table_variables[contor].constant == 0)
               fprintf(file, "%s : %s : %c \n", symbol_table_variables[contor].type, symbol_table_variables[contor].name, symbol_table_variables[contor].char_val);
            if (symbol_table_variables[contor].constant == 1)
               fprintf(file, "const :%s : %c : %d \n", symbol_table_variables[contor].type, symbol_table_variables[contor].name, symbol_table_variables[contor].char_val);
         }
      }
      fprintf(file, "\n");
      for (contor = 0; contor <= variables; contor++)
      {
         if (strcmp(symbol_table_variables[contor].type, "string") == 0)
         {
            if (symbol_table_variables[contor].constant == 0)
               fprintf(file, "%s : %s : %s \n", symbol_table_variables[contor].type, symbol_table_variables[contor].name, symbol_table_variables[contor].string_val);
            if (symbol_table_variables[contor].constant == 1)
               fprintf(file, "const :%s : %s : %s \n", symbol_table_variables[contor].type, symbol_table_variables[contor].name, symbol_table_variables[contor].string_val);
         }
      }
      fprintf(file, "\n");
      for (contor = 0; contor <= variables; contor++)
      {
         if (strcmp(symbol_table_variables[contor].type, "void") == 0)
         {
            if (symbol_table_variables[contor].constant == 0)
               fprintf(file, "%s : %s : %d \n", symbol_table_variables[contor].type, symbol_table_variables[contor].name, symbol_table_variables[contor].void_val);
            if (symbol_table_variables[contor].constant == 1)
               fprintf(file, "const :%s : %s : %d \n", symbol_table_variables[contor].type, symbol_table_variables[contor].name, symbol_table_variables[contor].void_val);
         }
      }

      fprintf(file, "------------------------------------------\n\n");
   }
   if (arrays >= 0)
   {
      fprintf(file, "Arrays:\n------------------------------------------\n");
      for (contor = 0; contor <= arrays; contor++)
      {
         if (symbol_table_arrays[contor].initialized == 0)
         {
            if (symbol_table_arrays[contor].constant == 1)
               fprintf(file, "const : ");
            fprintf(file, "%s : %s[%d]\n", symbol_table_arrays[contor].type, symbol_table_arrays[contor].name, symbol_table_arrays[contor].size);
         }
      }
      fprintf(file, "\n");
      for (contor = 0; contor <= arrays; contor++)
      {
         if (symbol_table_arrays[contor].initialized == 1)
         {
            if (symbol_table_arrays[contor].constant == 1)
               fprintf(file, "const : ");
            fprintf(file, "%s : %s[%d] : [", symbol_table_arrays[contor].type, symbol_table_arrays[contor].name, symbol_table_arrays[contor].size);
            for (int sub_contor = 0; sub_contor < symbol_table_arrays[contor].size; sub_contor++)
               if (strcmp(symbol_table_arrays[contor].type, "int") == 0)
                  sub_contor < symbol_table_arrays[contor].size - 1 ? fprintf(file, "%d,", symbol_table_arrays[contor].int_array[sub_contor]) : fprintf(file, "%d]", symbol_table_arrays[contor].int_array[sub_contor]);
               else
                  sub_contor < symbol_table_arrays[contor].size - 1 ? fprintf(file, "%f,", symbol_table_arrays[contor].float_array[sub_contor]) : fprintf(file, "%f]", symbol_table_arrays[contor].float_array[sub_contor]);
            fprintf(file, "\n");
         }
      }
      fprintf(file, "------------------------------------------\n\n");
   }

   fclose(file);

   file = fopen("symbol_table_functions.txt", "r");
   if (file != NULL)
   {
      if (file != NULL)
         remove("symbol_table_functions.txt");
   }
   file = fopen("symbol_table_functions.txt", "a");
   fprintf(file, "Functions:\n------------------------------------------\n");
   for (contor = 0; contor <= functions; contor++)
   {
      fprintf(file, "Function %d : %s : %s : (%d)\n", contor + 1, symbol_table_functions[contor].return_type, symbol_table_functions[contor].name, symbol_table_functions[contor].parameter_count);
      if (symbol_table_functions[contor].parameter_count > 0)
      {
         fprintf(file, "Parameters:\n");
         for (int index = 0; index < symbol_table_functions[contor].parameter_count; index++)
            fprintf(file, "%s : %s \n", symbol_table_functions[contor].parameters[index].type, symbol_table_functions[contor].parameters[index].name);
      }
      if (contor < functions)
         fprintf(file, "\n");
   }
   fprintf(file, "------------------------------------------\n\n");

   fclose(file);
}
int search_constants(char *id)
{
   int index;

   for (index = 0; index <= constants; index++)
      if (strcmp(id, symbol_table_constants[index].name) == 0)
         return index;

   return -1;
}

void add_constant(char *id, int value)
{
   int index = search_constants(id);

   if (index < 0)
   {
      constants++;

      symbol_table_constants[constants].name = (char *)malloc(strlen(id) + 1);
      symbol_table_constants[constants].value = value;
      strcpy(symbol_table_constants[constants].name, id);
   }
   else
   {
      symbol_table_constants[constants].value = value;
   }
}

int search(char *id)
{
   int index;

   for (index = 0; index <= constants; index++)
      if (strcmp(id, symbol_table_constants[index].name) == 0)
         return index;

   for (index = 0; index <= variables; index++)
      if (strcmp(id, symbol_table_variables[index].name) == 0)
         return index;

   for (index = 0; index <= arrays; index++)
      if (strcmp(id, symbol_table_arrays[index].name) == 0)
         return index;

   for (index = 0; index <= functions; index++)
      if (strcmp(id, symbol_table_functions[index].name) == 0)
         return index;

   for (index = 0; index <= classes; index++)
      if (strcmp(id, symbol_table_classes[index].name) == 0)
         return index;
   return -1;
}

void create_array(int constant, char *type, char *id, int size, int *ar1, float *ar2)
{
   if (arrays >= MAX)
   {
      printf("Error: Exceeded maximum number of arrays\n");
      exit(0);
   }

   int add = search(id);

   if (add >= 0)
   {
      printf("\n%s Already declared!\n");
      exit(0);
   }

   if (constant)
   {
      symbol_table_arrays[arrays].constant = 1;
   }
   if (ar1 != NULL || ar2 != NULL)
   {

      arrays++;
      symbol_table_arrays[arrays].type = (char *)malloc(strlen(type) + 1);
      symbol_table_arrays[arrays].name = (char *)malloc(strlen(id) + 1);
      strcpy(symbol_table_arrays[arrays].type, type);
      strcpy(symbol_table_arrays[arrays].name, id);
      symbol_table_arrays[arrays].size = size;
      symbol_table_arrays[arrays].initialized = 1;
      if (ar1 != NULL)
      {
         symbol_table_arrays[arrays].int_array = (int *)malloc(size * sizeof(int));
         memcpy(symbol_table_arrays[arrays].int_array, ar1, size * sizeof(int));
      }
      if (ar2 != NULL)
      {
         symbol_table_arrays[arrays].float_array = (float *)malloc(size * sizeof(float));
         memcpy(symbol_table_arrays[arrays].float_array, ar2, size * sizeof(float));
      }
   }
   else
   {
      arrays++;
      symbol_table_arrays[arrays].type = (char *)malloc(strlen(type) + 1);
      symbol_table_arrays[arrays].name = (char *)malloc(strlen(id) + 1);
      strcpy(symbol_table_arrays[arrays].type, type);
      strcpy(symbol_table_arrays[arrays].name, id);
      symbol_table_arrays[arrays].size = size;
      symbol_table_arrays[arrays].initialized = 0;
   }
}

void create_variable(int constant, char *type, char *id, expr_info *expr1)
{
   if (variables >= MAX)
   {
      printf("Error: Exceeded maximum number of variables\n");
      exit(0);
   }

   int add = search(id);

   if (add >= 0)
   {
      printf("\n%s Already declared!\n");
      exit(0);
   }
   variables++;
   symbol_table_variables[variables].name = (char *)malloc(strlen(id) + 1);
   symbol_table_variables[variables].type = (char *)malloc(strlen(type) + 1);
   strcpy(symbol_table_variables[variables].name, id);
   strcpy(symbol_table_variables[variables].type, type);

   if (constant == 1)
   {
      symbol_table_variables[variables].constant = 1;
   }
   else
      symbol_table_variables[variables].constant = 0;

   if (expr1 != NULL)
   {
      symbol_table_variables[variables].initialized = 1;
      if (strcmp(type, "int") == 0)
      {
         symbol_table_variables[variables].int_val = expr1->int_value;
      }
      if (strcmp(type, "bool") == 0)
         symbol_table_variables[variables].bool_val = expr1->bool_value;
      if (strcmp(type, "float") == 0)
      {
         symbol_table_variables[variables].float_val = expr1->float_value;
      }

      if (strcmp(type, "char") == 0)
         symbol_table_variables[variables].char_val = expr1->chr_value;

      if (strcmp(type, "string") == 0)
      {
         symbol_table_variables[variables].string_val = (char *)malloc(strlen(expr1->str_value) + 1);
         strcpy(symbol_table_variables[variables].string_val, expr1->str_value);
      }
   }
   else
      symbol_table_variables[variables].initialized = 0;
   return;
}
void create_function(char *type, char *name)
{
   if (functions >= MAX)
   {
      printf("Error: Exceeded maximum number of functions\n");
      exit(0);
   }
   int add = search(name);
   if (add >= 0)
   {
      printf("\n%s Already declared!\n");
      exit(0);
   }
   functions++;
   symbol_table_functions[functions].name = (char *)malloc(strlen(name) + 1);
   strcpy(symbol_table_functions[functions].name, name);
   symbol_table_functions[functions].return_type = (char *)malloc(strlen(type) + 1);
   strcpy(symbol_table_functions[functions].return_type, type);
   symbol_table_functions[functions].parameter_count = function_parameter_count;
   for (int i = 0; i < function_parameter_count; i++)
   {
      symbol_table_functions[functions].parameters[i].type = (char *)malloc(strlen(function_parameters[i].type) + 1);
      strcpy(symbol_table_functions[functions].parameters[i].type, function_parameters[i].type);
      symbol_table_functions[functions].parameters[i].name = (char *)malloc(strlen(function_parameters[i].name) + 1);
      strcpy(symbol_table_functions[functions].parameters[i].name, function_parameters[i].name);
   }
   memset(function_parameters, 0, sizeof(function_parameters));
}

void create_function_parameter(char *type, char *name)
{
   function_parameters[function_parameter_count].type = (char *)malloc(strlen(type) + 1);
   strcpy(function_parameters[function_parameter_count].type, type);
   function_parameters[function_parameter_count].name = (char *)malloc(strlen(name) + 1);
   strcpy(function_parameters[function_parameter_count].name, name);
   function_parameter_count++;
}
void create_assignment(int type, char *id, int array_index, expr_info *expr)
{
   int index;
   if (type == 0)
   {
      for (index = 0; index <= variables; index++)
         if (strcmp(id, symbol_table_variables[index].name) == 0)
         {
            if (symbol_table_variables[index].constant == 1)
            {
               printf("\nCannot modify constant value\n");
               exit(0);
            }
            if (strcmp(symbol_table_variables->type, expr->type) != 0)
            {
               printf("\Cannot assign a value of different type (%s to %s)\n", expr->type, symbol_table_variables->type);
               exit(0);
            }
            if (symbol_table_variables[index].initialized == 0)
               symbol_table_variables[index].initialized = 1;

            if (strcmp(symbol_table_variables[index].type, "int") == 0)
            {
               symbol_table_variables[index].int_val = expr->int_value;
            }
            printf("5\n");
            if (strcmp(symbol_table_variables[index].type, "float") == 0)
            {
               symbol_table_variables[index].float_val = expr->float_value;
            }
            if (strcmp(symbol_table_variables[index].type, "bool") == 0)
            {
               symbol_table_variables[index].bool_val = expr->bool_value;
            }
            if (strcmp(symbol_table_variables[index].type, "char") == 0)
            {
               symbol_table_variables[index].char_val = expr->chr_value;
            }
            if (strcmp(symbol_table_variables[index].type, "string") == 0)
            {
               strcpy(symbol_table_variables[index].string_val, expr->str_value);
            }
            return;
         }
      printf("\nVariable %s is not declared\n", id);
      exit(0);
   }
}

expr_info *eval(expr_info *expression)
{
   if (strcmp(expression->type, "int") == 0)
   {
      printf("Evaluation result: %d\n", expression->int_value);
      return;
   }
   printf("Unallowed evaluation operands.Only int operands allowed\n");
   exit(0);
}

expr_info *create_int(int value)
{
   expr_info *expr = (expr_info *)malloc(sizeof(expr_info));
   expr->int_value = value;
   expr->type = (char *)malloc(sizeof("int") + 1);
   strcpy(expr->type, "int");
   return expr;
}
expr_info *create_float(float value)
{

   expr_info *expr = (expr_info *)malloc(sizeof(expr_info));
   expr->float_value = value;
   expr->type = (char *)malloc(sizeof("float") + 1);
   strcpy(expr->type, "float");
   return expr;
}

expr_info *create_chr(char chr)
{

   expr_info *expr = (expr_info *)malloc(sizeof(expr_info));
   expr->chr_value = chr;
   expr->type = (char *)malloc(sizeof("char") + 1);
   strcpy(expr->type, "char");
   return expr;
}

expr_info *create_string(char *str)
{
   expr_info *expr = (expr_info *)malloc(sizeof(expr_info));

   expr->str_value = (char *)malloc(sizeof(char) * (strlen(str)) + 1);
   strcpy(expr->str_value, str);
   expr->type = (char *)malloc(sizeof("string") + 1);
   strcpy(expr->type, "string");
   return expr;
}

expr_info *create_bool(int *boolean_value)
{
   expr_info *expr = (expr_info *)malloc(sizeof(expr_info));
   expr->bool_value = ((boolean_value >= 1) ? 1 : 0);
   expr->type = (char *)malloc(sizeof("bool") + 1);
   strcpy(expr->type, "bool");
   return expr;
}

expr_info *function_call(char *id, expr_list *arguments)
{
   int index, sub_index;
   for (index = 0; index <= functions; index++)
   {
      if (strcmp(id, symbol_table_functions[index].name) == 0)
      {
         if (arguments->nr_of_arguments != symbol_table_functions[index].parameter_count)
         {
            printf("Invalid number of arguments for function %s. Expected %d arguments, got %d\n", id, symbol_table_functions[index].parameter_count, arguments->nr_of_arguments);
            exit(0);
         }
         for (sub_index = 0; sub_index < arguments->nr_of_arguments; sub_index++)
         {
            if (strcmp(arguments->function_call_arguments[sub_index].type, symbol_table_functions[index].parameters[sub_index].type) != 0)
            {
               printf("Invalid argument type %s.Expecteded argument type: %s\n", arguments->function_call_arguments[sub_index].type, symbol_table_functions[index].parameters[sub_index].type);
               exit(0);
            }
         }
         if (strcmp(symbol_table_functions[index].return_type, "int") == 0)
         {
            return create_int(9876789);
         }
         if (strcmp(symbol_table_functions[index].return_type, "bool") == 0)
         {
            return create_bool(1);
         }
         if (strcmp(symbol_table_functions[index].return_type, "float") == 0)
         {
            return create_float(1234.4321);
         }
         if (strcmp(symbol_table_functions[index].return_type, "char") == 0)
         {
            return create_chr('X');
         }
         if (strcmp(symbol_table_functions[index].return_type, "string") == 0)
         {
            return create_string('STRING');
         }
         if (strcmp(symbol_table_functions[index].return_type, "void") == 0)
         {
            return create_bool(0);
         }
      }
   }
   printf("\nFunction %s is not declared\n", id);
   exit(0);
}

expr_info *create_expr(expr_info *expr1, const char *OP, expr_info *expr2)
{
   /*if(to_flag==1)
   {
      if (strcmp(expr1->type, expr2->type) != 0)
      {

         printf("\n%s - %s \n", expr1->type, expr2->type);
         printf("\nInvalid operation between 2 operands of different types\n");
         exit(0);
      }
   }*/

   expr_info *expr = (expr_info *)malloc(sizeof(expr_info));
   if (strcmp(expr1->type, expr2->type) != 0)
   {

      printf("\n%s - %s \n", expr1->type, expr2->type);
      printf("\nInvalid operation between 2 operands of different types\n");
      exit(0);
   }

   if (strcmp(OP, "+") == 0)
   {
      if (strcmp(expr1->type, "int") == 0)
         return create_int(expr1->int_value + expr2->int_value);

      if (strcmp(expr1->type, "float") == 0)
         return create_float(expr1->float_value + expr2->float_value);

      if (strcmp(expr1->type, "char") == 0)
         return create_chr(expr1->chr_value + expr2->chr_value);

      if (strcmp(expr1->type, "string") == 0)
      {
         int len = strlen(expr1->str_value) + strlen(expr2->str_value);
         char *aux = (char *)malloc(len + 1);
         strcpy(aux, expr1->str_value);
         strcat(aux, expr2->str_value);
         return create_string(aux);
      }
      if (strcmp(expr1->type, "bool") == 0)
         return create_bool(expr1->bool_value || expr2->bool_value);

      printf("\nError at operation %s %s %s\n", expr1->type, OP, expr2->type);
      exit(0);
   }

   if (strcmp(OP, "-") == 0)
   {
      if (strcmp(expr1->type, "int") == 0)
         return create_int(expr1->int_value - expr2->int_value);

      if (strcmp(expr1->type, "float") == 0)
         return create_float(expr1->float_value - expr2->float_value);

      if (strcmp(expr1->type, "char") == 0)
         return create_chr(abs(expr1->chr_value - expr2->chr_value));

      if (strcmp(expr1->type, "bool") == 0)
         return create_bool(abs(expr1->bool_value - expr2->bool_value));

      printf("\nError at operation %s %s %s\n", expr1->type, OP, expr2->type);
      exit(0);
   }

   if (strcmp(OP, "*") == 0)
   {
      if (strcmp(expr1->type, "int") == 0)
         return create_int(expr1->int_value * expr2->int_value);

      if (strcmp(expr1->type, "float") == 0)
         return create_float(expr1->float_value * expr2->float_value);

      printf("\nError at operation %s %s %s\n", expr1->type, OP, expr2->type);
      exit(0);
   }

   if (strcmp(OP, "/") == 0)
   {
      if (strcmp(expr1->type, "int") == 0)
         if (expr2->int_value == 0)
         {
            printf("\nCannot divide by 0\n");
            exit(0);
         }
         else
            return create_int(expr1->int_value / expr2->int_value);

      if (strcmp(expr1->type, "float") == 0)
         return create_float(expr1->float_value / expr2->float_value);

      printf("\nError at operation %s %s %s\n", expr1->type, OP, expr2->type);
      exit(0);
   }

   if (strcmp(OP, "<") == 0)
   {
      if (strcmp(expr1->type, "int") == 0)
         return create_bool(expr1->int_value < expr2->int_value);

      if (strcmp(expr1->type, "float") == 0)
         return create_bool(expr1->float_value < expr2->float_value);

      if (strcmp(expr1->type, "char") == 0)
         return create_bool(expr1->chr_value < expr2->chr_value);

      if (strcmp(expr1->type, "bool") == 0)
         return create_bool(expr1->bool_value < expr2->bool_value);

      if (strcmp(expr1->type, "string") == 0)
         return create_bool((strcmp(expr1->str_value, expr2->str_value) < 0));

      printf("\nError at operation %s %s %s\n", expr1->type, OP, expr2->type);
      exit(0);
   }

   if (strcmp(OP, ">") == 0)
   {
      if (strcmp(expr1->type, "int") == 0)
         return create_bool(expr1->int_value > expr2->int_value);

      if (strcmp(expr1->type, "float") == 0)
         return create_bool(expr1->float_value > expr2->float_value);

      if (strcmp(expr1->type, "char") == 0)
         return create_bool(expr1->chr_value > expr2->chr_value);

      if (strcmp(expr1->type, "bool") == 0)
         return create_bool(expr1->bool_value > expr2->bool_value);

      if (strcmp(expr1->type, "string") == 0)
         return create_bool((strcmp(expr1->str_value, expr2->str_value) > 0));

      printf("\nError at operation %s %s %s\n", expr1->type, OP, expr2->type);
      exit(0);
   }

   if (strcmp(OP, "<=") == 0)
   {
      if (strcmp(expr1->type, "int") == 0)
         return create_int(pow(expr1->int_value, expr2->int_value));

      if (strcmp(expr1->type, "float") == 0)
         return create_float(powf(expr1->float_value, expr2->float_value));

      printf("\nError at operation %s %s %s\n", expr1->type, OP, expr2->type);
      exit(0);
   }

   if (strcmp(OP, ">=") == 0)
   {
      if (strcmp(expr1->type, "int") == 0)
         return create_bool(expr1->int_value >= expr2->int_value);

      if (strcmp(expr1->type, "float") == 0)
         return create_bool(expr1->float_value >= expr2->float_value);

      if (strcmp(expr1->type, "char") == 0)
         return create_bool(expr1->chr_value >= expr2->chr_value);

      if (strcmp(expr1->type, "bool") == 0)
         return create_bool(expr1->bool_value >= expr2->bool_value);
      if (strcmp(expr1->type, "string") == 0)
         return create_bool((strcmp(expr1->str_value, expr2->str_value) >= 0));

      printf("\nError at operation %s %s %s\n", expr1->type, OP, expr2->type);
      exit(0);
   }

   if (strcmp(OP, "==") == 0)
   {
      if (strcmp(expr1->type, "int") == 0)
         return create_bool(expr1->int_value == expr2->int_value);

      if (strcmp(expr1->type, "float") == 0)
         return create_bool(expr1->float_value == expr2->float_value);

      if (strcmp(expr1->type, "char") == 0)
         return create_bool(expr1->chr_value == expr2->chr_value);

      if (strcmp(expr1->type, "bool") == 0)
         return create_bool(expr1->bool_value == expr2->bool_value);
      if (strcmp(expr1->type, "string") == 0)
         return create_bool((strcmp(expr1->str_value, expr2->str_value) == 0));

      printf("\nError at operation %s %s %s\n", expr1->type, OP, expr2->type);
      exit(0);
   }

   if (strcmp(OP, "!=") == 0)
   {
      if (strcmp(expr1->type, "int") == 0)
         return create_bool(expr1->int_value != expr2->int_value);

      if (strcmp(expr1->type, "float") == 0)
         return create_bool(expr1->float_value != expr2->float_value);

      if (strcmp(expr1->type, "char") == 0)
         return create_bool(expr1->chr_value != expr2->chr_value);

      if (strcmp(expr1->type, "bool") == 0)
         return create_bool(expr1->bool_value != expr2->bool_value);

      if (strcmp(expr1->type, "string") == 0)
         return create_bool((strcmp(expr1->str_value, expr2->str_value) != 0));

      printf("\nError at operation %s %s %s\n", expr1->type, OP, expr2->type);
      exit(0);
   }

   if (strcmp(OP, "&&") == 0)
   {
      if (strcmp(expr1->type, "int") == 0)
         return create_bool((expr1->int_value != 0) && (expr2->int_value) != 0);

      if (strcmp(expr1->type, "float") == 0)
         return create_bool((expr1->float_value) != 0 && (expr2->float_value) != 0);

      if (strcmp(expr1->type, "bool") == 0)
         return create_bool(expr1->bool_value && expr2->bool_value);

      printf("\nError at operation %s %s %s\n", expr1->type, OP, expr2->type);
      exit(0);
   }

   if (strcmp(OP, "||") == 0)
   {
      if (strcmp(expr1->type, "int") == 0)
         return create_bool(expr1->int_value || expr2->int_value);

      if (strcmp(expr1->type, "float") == 0)
         return create_bool(expr1->float_value || expr2->float_value);

      if (strcmp(expr1->type, "bool") == 0)
         return create_bool(expr1->int_value || expr2->int_value);

      printf("\nError at operation %s %s %s\n", expr1->type, OP, expr2->type);
      exit(0);
   }
   if (strcmp(OP, "^") == 0)
   {
      if (strcmp(expr1->type, "int") == 0)
         return create_int(pow(expr1->int_value, expr2->int_value));

      if (strcmp(expr1->type, "float") == 0)
         return create_float(powf(expr1->float_value, expr2->float_value));

      printf("\nError at operation %s %s %s\n", expr1->type, OP, expr2->type);
      exit(0);
   }
   if (strcmp(OP, "%") == 0)
   {
      if (strcmp(expr1->type, "int") == 0)
         return create_int(expr1->int_value % expr2->int_value);

      printf("\nError at operation %s %s %s\n", expr1->type, OP, expr2->type);
      exit(0);
   }
}
expr_info *create_arr(char *id, int index)
{
   int index1 = 0;
   for (index1 = 0; index1 <= arrays; index1++)
      if (strcmp(symbol_table_arrays[index1].name, id) == 0)
      {
         if (symbol_table_arrays[index1].initialized == 1)
         {
            if (index < 0 || index >= symbol_table_arrays[index1].size)
            {
               index < 0 ? printf("\nInvalid index %d\n", index) : printf("\nIndex %d outside of array with size %d\n", index, symbol_table_arrays[index1].size);
               exit(0);
            }
            if (strcmp(symbol_table_arrays[index1].type, "int") == 0)
            {
               return create_int(symbol_table_arrays[index1].int_array[index]);
            }
            if (strcmp(symbol_table_arrays[index1].type, "float") == 0)
            {
               return create_float(symbol_table_arrays[index1].float_array[index]);
            }
            printf("\nError getting array value\n");
            exit(0);
         }
         else
         {

            printf("\nArray %s not initialized\n", id);
            exit(0);
         }
      }
   printf("\nVariable %s not declared\n", id);
   exit(0);
}
expr_info *create_id(char *id)
{
   int index = 0;
   for (index = 0; index <= variables; index++)
      if (strcmp(symbol_table_variables[index].name, id) == 0)
      {
         if (symbol_table_variables[index].initialized == 1)
         {
            if (strcmp(symbol_table_variables[index].type, "int") == 0)
               return create_int(symbol_table_variables[index].int_val);
            if (strcmp(symbol_table_variables[index].type, "float") == 0)
               return create_float(symbol_table_variables[index].float_val);
            if (strcmp(symbol_table_variables[index].type, "char") == 0)
               return create_chr(symbol_table_variables[index].char_val);
            if (strcmp(symbol_table_variables[index].type, "string") == 0)
               return create_string(symbol_table_variables[index].string_val);
            if (strcmp(symbol_table_variables[index].type, "bool") == 0)
               return create_bool(symbol_table_variables[index].bool_val);
         }
         else
         {
            printf("\nVariable %s not initialized\n", id);
            exit(0);
         }
      }

   printf("\nVariable %s not declared\n", id);
   exit(0);
}
