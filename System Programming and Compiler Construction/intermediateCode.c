// 3-address code generation and quadruple table
#include <stdio.h>
#include <conio.h>

void main () {

	char exp[50], tokens[20][10];
	char* token;
	int i, n = 0; 

	// printf("Enter the expression: ");
	// scanf(" %[^\n]", &exp);
	strcpy(exp, "a = b + c");
	printf("Expression: %s\n", exp);

	token = strtok(exp, " ");
	while(token != NULL) {
		strcpy(tokens[n], token);
		token = strtok(NULL, " ");
	}


}