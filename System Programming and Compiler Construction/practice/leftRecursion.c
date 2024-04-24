#include <stdio.h>
#include <string.h>
#include <ctype.h>

void leftR(char tokens[20][10], int tokenCounter) {

	int i;
	char p = tokens[0][0], alpha[10], beta[10];

	if(p == tokens[2][0]) {
		strcpy(alpha, tokens[2]+1);
		strcpy(beta, tokens[4]);
		printf("%s %s %s%s'\n", tokens[0], tokens[1], beta, tokens[0]);
		printf("%s' %s %s%s | E\n", tokens[0], tokens[1], alpha, tokens[0]);
	} else {
		for (i = 0; i<tokenCounter; i++) {
			printf("%s ", tokens[i]);
		}
		printf("\n");
	}

}

void main() {

	char productions[10][50], tokens[20][10];
	int i = 0, j, n, tokenCounter = 0;

	printf("\nN: ");
	scanf("%d", &n);

	printf("\nProductions:\n");
	while(i<n && scanf(" %[^\n]", productions[i]) == 1)
		i++;
	
	printf("\nGrammar: \n");
	for(i=0; i<n; i++) {
		tokenCounter = 0;
		char* token = strtok(productions[i], " ");
		while(token!=NULL) {
			strcpy(tokens[tokenCounter], token);
			tokenCounter++;
			token = strtok(NULL, " ");
		}
		leftR(tokens, tokenCounter);
	}

}