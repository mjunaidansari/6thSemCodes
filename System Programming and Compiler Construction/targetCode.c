// program for Target Code Generation
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TAC {
	char res[5];
	char opr1[5];
	char opr2[5];
	char op[2];
};

struct TC {
	char op[5];
	char opr1[5];
	char opr2[5];
};

void printTC(struct TC tc) {
	printf("\n%s %s, %s", tc.op, tc.opr1, tc.opr2);
}

void main() {

	char ir[15][50], tokens[10][10];
	char *token;
	int i, n = 0;
	int tokenCounter = 0; 
	int tacCounter = 0;
	int tcCounter = 0;
	int regCounter = 0;

	struct TAC tac[15];
	struct TC tc[50];

	char ops[4][5] = {"MOV\0", "ADD\0", "SUB\0", "MUL\0"};
	char reg[4][3] = {"AX\0", "BX\0", "CX\0", "DX\0"};
	int regAss[4] = {-1, -1, -1, -1};


	printf("\nEnter Intermediate Code: \n\n");
	while(n < 15 && fgets(ir[n], sizeof(ir[0]), stdin)){
		if(ir[n][0] == '\n')
			break;
		ir[n][strlen(ir[n])-1] = '\0';
		n++;
	}

	for(i=0; i<n; i++){

		// tokenizing the expression
		token = strtok(ir[i], " ");
		while(token != NULL) {
			strcpy(tokens[tokenCounter], token);
			token = strtok(NULL, " ");
			tokenCounter++;
		}
		tokenCounter = 0;

		// storing as 3 address code
		strcpy(tac[tacCounter].res, tokens[0]);
		strcpy(tac[tacCounter].opr1, tokens[2]);
		strcpy(tac[tacCounter].op, tokens[3]);
		strcpy(tac[tacCounter].opr2, tokens[4]);
		tacCounter++;

	}

	for(i=0; i<tacCounter; i++) {
		
		if(tac[i].opr1[0] == 'i') {
			// if first operand is an id variable
			// performing mov operation of id to register
			strcpy(tc[tcCounter].op, ops[0]);
			strcpy(tc[tcCounter].opr1, reg[tac[i].res[1] - '0']); // getting the register number from temp variable
			strcpy(tc[tcCounter].opr2, tac[i].opr1);
			tcCounter++;
		} else {
			// first operand is temp register
			// performing mov operation of register to register
			strcpy(tc[tcCounter].op, ops[0]);
			strcpy(tc[tcCounter].opr1, reg[tac[i].res[1] - '0']);
			strcpy(tc[tcCounter].opr2, reg[tac[i].opr1[1] - '0']);
			tcCounter++;
		}
		// performing add, sub or mul operation based on the operator
		if(strcmp(tac[i].op, "+") == 0)
			strcpy(tc[tcCounter].op, ops[1]);
		else if(strcmp(tac[i].op, "-") == 0)
			strcpy(tc[tcCounter].op, ops[2]);
		else if(strcmp(tac[i].op, "*") == 0)
			strcpy(tc[tcCounter].op, ops[3]);
		strcpy(tc[tcCounter].opr1, reg[tac[i].res[1] - '0']);
		strcpy(tc[tcCounter].opr2, tac[i].opr2);
		tcCounter++;

	}


	printf("Target Code Generated: \n");
	for(i=0; i<tcCounter; i++) {
		printTC(tc[i]);
	}
	printf("\n\n");

}

/*
t0 = id1 + id2
t1 = t0 - id3
t2 = t1 * id4
*/