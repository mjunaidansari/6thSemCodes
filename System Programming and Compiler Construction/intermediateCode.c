// 3-address code generation and quadruple table (only for operators with same precedence)
#include <stdio.h>
#include <string.h>

struct TAC {
	char res[5];
	char opr1[5];
	char opr2[5];
	char op[2];
};

void printTac(struct TAC tac) {
	printf("\n\t%s = %s %s %s", tac.res, tac.opr1, tac.op, tac.opr2);
}

void main() {

	char exp[50], temp[10], tokens[20][10];
	char *token;
	int i, j, tokenCounter = 0, tacCounter = 0;
	struct TAC tac[10];

	// operators
	char ops[4][2] = {"+\0", "-\0", "*\0", "/\0"};

	printf("\nEnter the Expression: ");
	fgets(exp, sizeof(exp), stdin);
	exp[strlen(exp)-1] = '\0';

	// tokenizing the expression
	token = strtok(exp, " ");
	while(token != NULL) {
		strcpy(tokens[tokenCounter], token);
		token = strtok(NULL, " ");
		tokenCounter++;
	}

	char ass[tokenCounter]; //array for checking if token is assigned to a three address code or not
	for(i=0; i<tokenCounter; i++) {
		ass[i] = -1;
	}

	// creating 3 address code
	for(i=0; i<tokenCounter; i++) {
		for(j=0; j<4; j++) {
			// if token equals is an operator
			if(strcmp(tokens[i], ops[j]) == 0) {
				// if both characters before and after operator are not assigned
				if(ass[i-1] == -1 && ass[i+1] == -1) {
					sprintf(temp, "t%d", tacCounter); // converting int to string
					strcpy(tac[tacCounter].res, temp);
					strcpy(tac[tacCounter].opr1, tokens[i-1]);
					strcpy(tac[tacCounter].opr2, tokens[i+1]);
					strcpy(tac[tacCounter].op, tokens[i]);
					ass[i-1] = tacCounter;
					ass[i] = tacCounter;
					ass[i+1] = tacCounter;
				}
				// else the first one is assigned to a tac 
				else {
					sprintf(temp, "t%d", tacCounter); 
					strcpy(tac[tacCounter].res, temp);
					sprintf(temp, "t%d", ass[i-1]);
					strcpy(tac[tacCounter].opr1, temp);
					strcpy(tac[tacCounter].opr2, tokens[i+1]);
					strcpy(tac[tacCounter].op, tokens[i]);
					ass[i-1] = tacCounter;
					ass[i] = tacCounter;
					ass[i+1] = tacCounter;
				}
				tacCounter++;
			}
		}
	}
	
	// creating last tac
	strcpy(tac[tacCounter].opr1, tac[tacCounter-1].res);
	strcpy(tac[tacCounter].res, tokens[0]);
	strcpy(tac[tacCounter].op, "=");

	// printing tac
	printf("\n\t\t*** 3-Address Codes ***\n");
	for(i=0; i<tacCounter; i++) {
		printTac(tac[i]);
	}
	printf("\n\t%s %s %s", tac[tacCounter].res, tac[tacCounter].op, tac[tacCounter].opr1);

	// printing quadruple table
	printf("\n\n\t\t*** Quadruple Table ***\n\n");
	printf("Operator\tOperand1\tOperand2\tResult\n");
	printf("--------\t--------\t--------\t------\n");
	for(i=0; i<=tacCounter; i++) {
		printf("%s\t\t%s\t\t%s\t\t%s\n", tac[i].op, tac[i].opr1, tac[i].opr2, tac[i].res);
	}

}

// x = a + b - c + d