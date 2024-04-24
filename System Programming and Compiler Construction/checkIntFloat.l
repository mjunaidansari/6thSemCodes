%{
#include<stdio.h>	
%}

digit [0-9]

%%
{digit}				{printf("\nInteger Recognized: %s\n", yytext);}
{digit}+"."+{digit}	{printf("\nFloat Recognized: %s\n", yytext);}
.					{printf("neither integer nor float!");}
%%

int yywrap() {
	return 1; // end of input
}

int main () {
	printf("\nEnter Input to Recognize: ");
	yylex();
	return 0;
}