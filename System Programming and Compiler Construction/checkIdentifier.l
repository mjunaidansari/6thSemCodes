%{
#include<stdio.h>
%}

letter [a-zA-Z]
digit [0-9]

%%
{letter}({letter}|{digit})*	{printf("\nIdentifier recognized: %s\n", yytext);}
.							{printf("\n Not an Identifier\n");}
%%

int yywrap() {
	return 1;
}

int main() {
	printf("\nEnter input: ");
	while (yylex()){}
	return 0;
}