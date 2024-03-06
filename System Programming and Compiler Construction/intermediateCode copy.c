// 3-address code generation and quadruple table (only for operators with same precedence)
#include <stdio.h>
#include <string.h>

struct TAC {
	char left[5];
	char opr1[5];
	char opr2[5];
	char op[2];
};

void main() {

	char exp[50], temp[10], tokens[20][10];
	char tac[10][20];
	char *token;
	int i, j, tokenCounter = 0, tacCounter = 0;
	// struct TAC tac[10];

	// operators
	char ops[4][2] = {"+\0", "-\0", "*\0", "/\0"};

	printf("Enter the Expression: ");
	fgets(exp, sizeof(exp), stdin);
	exp[strlen(exp)-1] = '\0';
	printf("%s\n", exp);

	// tokenizing the expression
	token = strtok(exp, " ");
	while(token != NULL) {
		strcpy(tokens[tokenCounter], token);
		token = strtok(NULL, " ");
		tokenCounter++;
	}

	printf("Printing %d tokens: \n", tokenCounter);
	for(i=0; i<tokenCounter; i++) {
		printf("%s\t", tokens[i]);
	}

	char ass[tokenCounter]; //array for checking if token is assigned to a three address code or not
	for(i=0; i<tokenCounter; i++) {
		ass[i] = -1;
	}

	// initializing 3 address codes with empty string
	for(i=0; i<10; i++) {
		tac[i][0] = '\0';
	}

	// creating 3 address code
	for(i=0; i<tokenCounter; i++) {
		for(j=0; j<4; j++) {
			// if token equals is an operator
			if(strcmp(tokens[i], ops[j]) == 0) {
				// if both characters before and after operator are not assigned
				if(ass[i-1] == -1 && ass[i+1] == -1) {
					strcat(tac[tacCounter], tokens[i-1]);
					strcat(tac[tacCounter], tokens[i]);
					strcat(tac[tacCounter], tokens[i+1]);
					ass[i-1] = tacCounter;
					ass[i] = tacCounter;
					ass[i+1] = tacCounter;
				}
				// else the first one is assigned to a tac 
				else {
					sprintf(temp, "t%d", ass[i-1]); // converting int to string
					strcat(tac[tacCounter], temp);
					strcat(tac[tacCounter], tokens[i]);
					strcat(tac[tacCounter], tokens[i+1]);
					ass[i] = tacCounter;
					ass[i+1] = tacCounter;
				}
				tacCounter++;
			}
		}
	}

	printf("\nTAC Counter: %d\n", tacCounter);
	for(i=0; i<tacCounter; i++) {
		printf("t%d = %s\t", i, tac[i]);
	}

}