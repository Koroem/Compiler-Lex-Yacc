# Compiler with Lex and Yacc


[![License](https://img.shields.io/badge/license-MIT-blue.svg)](LICENSE)

## Description

This project is an implementation of an original programming language designed using YACC. The language incorporates various features such as type declarations, control statements, arithmetic and boolean expressions, and function calls. It also includes semantic analysis, symbol tables, and evaluation functionality. The project aims to provide a comprehensive and efficient programming language for various applications.

## Features

- Type declarations for predefined types (int, float, char, string, bool), arrays, and user-defined data types
- Variable and constant definitions
- Control statements (if, for, while, etc.) and assignment statements
- Arithmetic and boolean expressions with support for different operators
- Function calls with parameters
- Predefined functions Eval(arg) and TypeOf(arg)
- Program structure with sections for global variables, functions, and user-defined data types

## Symbol Tables

The project includes symbol tables to store information about variables and functions. The tables can be printed to `symbol_table.txt` and `symbol_table_functions.txt` for variables and functions, respectively. These files provide insights into the defined symbols and their corresponding details.

## Semantic Analysis

Semantic analysis is implemented to ensure correct usage of variables and functions within the language. It checks for variable and function declarations, duplicate variable declarations, consistent operand types in expressions, and proper function call parameters. Detailed error messages are generated to aid in identifying and fixing any semantic errors in the code.

## Eval and TypeOf

The project provides the Eval and TypeOf functions. Eval evaluates arithmetic expressions and returns their actual values. TypeOf determines the type of an expression. Both functions enhance the functionality and utility of the programming language.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.
