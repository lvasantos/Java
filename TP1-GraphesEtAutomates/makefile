CC = clang
LEX = lex
YACC = yacc
LEXFILE = monFichier.lex
YACCFILE = monFichier.y
OBJ = y.tab.o 
OUTPUT = monFichier
LIB = -ll

# Regra principal para gerar o executável
$(OUTPUT) : $(OBJ)
	$(CC) $(OBJ) -o $@ $(LIB)

# Regra para compilar y.tab.o a partir de y.tab.c
y.tab.o : y.tab.c
	$(CC) -c y.tab.c -o y.tab.o


# Geração de lex.yy.c a partir de monFichier.lex usando lex
lex.yy.c : $(LEXFILE)
	$(LEX) $(LEXFILE)

# Geração de y.tab.c a partir de monFichier.y usando yacc
y.tab.c : $(YACCFILE)
	$(YACC) $(YACCFILE)

# Limpeza dos arquivos gerados
clean:
	rm -f $(OUTPUT) *.o lex.yy.c y.tab.c y.tab.h

# CC = clang++
# LEX = lex
# YACC = yacc
# LEXFILE = monFichier.lex
# YACCFILE = monFichier.y
# OBJ = y.tab.o
# OUTPUT = monFichier
# LIB = -ll
# $(OUTPUT) : $(OBJ)
# $(CC) $(OBJ) -o $@ $(LIB)
# y.tab.o : lex.yy.c y.tab.c
# $(CC) -c y.tab.c
# lex.yy.c : $(LEXFILE)
# $(LEX) $(LEXFILE)
# y.tab.c : $(YACCFILE)
# $(YACC) $(YACCFILE)