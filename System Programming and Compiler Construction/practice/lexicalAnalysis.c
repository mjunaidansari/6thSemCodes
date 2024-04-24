#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

bool isOperator(char* str) {
	if(
		strcmp(str, "+") == 0 || strcmp(str, "-") == 0 ||
		strcmp(str, "*") == 0 || strcmp(str, "/") == 0 ||
		strcmp(str, "^") == 0 || strcmp(str, "=") == 0 
	)
		return (true);
	return (false);
}

bool validIdentifier(char* str) {
	if(
		isdigit(str[0]) != 0 || isOperator(str) == true
	)
		return (false);
	return (true);
}

bool isKeyword(char* str)
{
    if (!strcmp(str, "if") || !strcmp(str, "else") ||
        !strcmp(str, "while") || !strcmp(str, "do") || 
        !strcmp(str, "break") || 
         !strcmp(str, "continue") || !strcmp(str, "int")
        || !strcmp(str, "double") || !strcmp(str, "float")
        || !strcmp(str, "return") || !strcmp(str, "char")
        || !strcmp(str, "case") || !strcmp(str, "char")
        || !strcmp(str, "sizeof") || !strcmp(str, "long")
        || !strcmp(str, "short") || !strcmp(str, "typedef")
        || !strcmp(str, "switch") || !strcmp(str, "unsigned")
        || !strcmp(str, "void") || !strcmp(str, "static")
        || !strcmp(str, "struct") || !strcmp(str, "goto"))
        return (true);
    return (false);
}

bool isInteger(char* str) {
	int i;
	for(i=0; i<strlen(str); i++) {
		if(!isdigit(str[i])) {
			return (false);
		}
	}
	return (true);
}

bool isFloat(char* str) {
	int i;
	bool hasDecimal = false;
	for(i=0; i<strlen(str); i++) {
		if(!isdigit(str[i]) && str[i]!='.')
			return (false);
		if(str[i] == '.')
			hasDecimal = true;
	}
	return (hasDecimal);
}

bool parse(char* str) {

	char lexeme[20][20], tokens[20][20];
	int i, tokenCounter = 0;

	char* token = strtok(str, " ");
	while(token!=NULL) {
		strcpy(lexeme[tokenCounter], token);
		tokenCounter++;
		token = strtok(NULL, " ");
	}

	for(i=0; i<tokenCounter; i++) {
		if(isOperator(lexeme[i]))
			strcpy(tokens[i], "Operator");
		else if(isKeyword(lexeme[i]))
			strcpy(tokens[i], "Keyword");
		else if(validIdentifier(lexeme[i]))
			strcpy(tokens[i], "Valid Identifier");
		else if(isInteger(lexeme[i]))
			strcpy(tokens[i], "Integer");
		else if(isFloat(lexeme[i]))
			strcpy(tokens[i], "Float");
	}

	printf("\nLexeme\tToken\n");
	printf("------\t-----\n");

	for(i=0; i<tokenCounter; i++){
		printf("%s\t%s\n", lexeme[i], tokens[i]);
	}
	printf("\n");

}

void main() {
	char str[100];
	scanf("%[^\n]", &str);
	parse(str);
}