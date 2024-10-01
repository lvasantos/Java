%{
#include <stdio.h>
#include <ctype.h>
int yylex(void);
#define YYSTYPE double
int yyerror(const char*);
%}
%error-verbose

%token EOL
%token expr
%token NB

%%
input:

    |input ligne
;
ligne: expr '\n' {printf("%f\n",$1);}
| EOL {}
;

%%
#include "lex.yy.c"
int main()
{
return yyparse();
}
int yyerror( const char *s )
{
fprintf( stderr, "Erreur: %s\n", s);
return 0;
}