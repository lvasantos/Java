%{
#include <stdio.h>
%}

%option noyywrap nounput batch debug
nb [0-9]*\.[0-9]+

%%
{nb} {
    yylval=atof(yytext);
    return NB;
}
'\n' {
    printf("car rec: %c\n",yytext[0]);return EOL;
    }
. {
    printf("car rec: %c\n",yytext[0]);return yytext[0];
    }
%% 