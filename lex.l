%{
#include <stdio.h>
#include <string.h>
#include "y.tab.h"
%}
%option noyywrap
%option yylineno
%%

"program{" {ECHO; return BGIN;}
"}end_program" {ECHO; return END;}

"variables{"     {ECHO; return START_VARIABLES;}
"}end_variables" {ECHO; return END_VARIABLES;}

"constants{"      {ECHO; return START_CONST;}
"}end_constants" {ECHO; return END_CONST;}

"classes{"     {ECHO; return START_CLASSES;}
"}end_classes" {ECHO; return END_CLASSES;}

"functions{"     {ECHO; return START_FUNCTIONS;}
"}end_functions" {ECHO; return END_FUNCTIONS;}

"float"|"int"|"char"|"string"|"bool"|"void" {ECHO; yylval.string=(char*)malloc(strlen(yytext)+1); strcpy(yylval.string,yytext); return TYPE;}
"#DEFINE" {ECHO; return DEFINE;}

"function" {ECHO; return FUNCTION;}
"class"    {ECHO; return CLASS;}

"const" {ECHO; return CONST;}
"=" {ECHO; return ASSIGN;}

"print(symbol_table)" {ECHO; return PRINT_SYMBOL_TABLES;}


"if" {ECHO; return IF;}
"else" {ECHO; return ELSE;}
"while" {ECHO; return WHILE;}
"do"  {ECHO; return DO;}
"for"  {ECHO; return FOR;}
"break" {ECHO; return BREAK;}
"continue" {ECHO; return CONTINUE;}
"print"  {ECHO; return PRINT;}
"exit"   {ECHO; return EXIT;}
"return" {ECHO; return RETURN;}

"<=" {ECHO; return LE;}
">=" {ECHO; return GE;}
"==" {ECHO; return EQ;}
"!=" {ECHO; return NE;}
"&&" {ECHO; return AND;}
"||" {ECHO; return OR;}
"true"|"false" {ECHO; if(strcmp(yytext,"true")==0) yylval.bool_value=1; else yylval.bool_value=0;  return BOOL;}
"Eval" {ECHO; return EVAL;}
"TypeOf" {ECHO; return  TYPEOF;}

"/*"([^*]|\*+[^*/])*\*+"/" {return COMMENT;} /* https://stackoverflow.com/questions/13569827/complete-comments-regex-for-lex */
\"([^\\\"]|\\.)*\" {ECHO;yylval.string=(char*)malloc(strlen(yytext)+1); strcpy(yylval.string,yytext); return STRING;} /* https://stackoverflow.com/questions/2039795 */
`.` {ECHO; yylval.character=yytext[1];return CHAR;}
-?[0-9]*\.[0-9]+ {ECHO;yylval.float_value=atof(yytext); return FLOAT;}
-?[0-9]+ {ECHO;yylval.int_value= atoi(yytext); return INT;}


[_a-zA-Z][_a-zA-Z0-9]* {ECHO;yylval.string=(char*)malloc(strlen(yytext)+1); strcpy(yylval.string,yytext); return ID;}



[ \t]+ {ECHO;}

\n {ECHO;yylineno++;}

\r ;
. {ECHO;return yytext[0];}
