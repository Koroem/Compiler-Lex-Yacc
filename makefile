all:
	clear
	yacc -d  -v yacc.y
	lex lex.l
	gcc lex.yy.c y.tab.c -lm -w -o compiler.bin
	./compiler.bin correct_example.txt


