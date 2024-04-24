#include <stdio.h>
#include <string.h>

struct ProductionRule {
	char left[10];
	char right[10];
};

void main() {

	char input[20], stack[20], temp[50], ch[2];
	char *token1, *token2, *substring;
	int i, j, k, stackLength, substringLength, stackTop, ruleCount = 0;
	struct ProductionRule rules[10];

	stack[0] = '\0';

	// get number of production rules
	printf("Number of Production rules: ");
	scanf("%d", &ruleCount);

	// get production rules in form of left->right
	printf("\nEnter the Production rules: ");
	for(i=0; i<ruleCount; i++) {
		scanf("%s", temp);
		token1 = strtok(temp, "->");
		token2 = strtok(NULL, "->");
		strcpy(rules[i].left, token1);
		strcpy(rules[i].right, token2);
	}

	// get input string 
	printf("\nEnter the input string: ");
	scanf("%s", input);

	printf("\nStack\tInput\tAction");
	printf("\n$\t%s$\n", input);

	i=0; 
	while(1) {

		// if there are more chars in input, add the next to char in stack
		if(i < strlen(input)) {
			ch[0] = input[i];
			ch[1] = '\0';
			i++;
			strcat(stack, ch);
			// to print the current stack
			printf("$%s\t", stack);
			// to print the remaining inputs
			for(k=i; k<strlen(input); k++) {
				printf("%c", input[k]);
			}
			// indicating shift
			printf("$\tShift %s\n", ch);

		}

		// iterate through the production rules for reduce operation
		for(j=0; j<ruleCount; j++) {
			
			// check if any substring of stack matches right side of production rule
			substring = strstr(stack, rules[j].right);
			if(substring != NULL) {
				// replace the matched substring with left-hand side of production rule
				stackLength = strlen(stack);
				substringLength = strlen(substring);
				// we are sure that substring will be from top of the stack, so replacing it from top
				stackTop = stackLength - substringLength;
				stack[stackTop] = '\0';
				strcat(stack, rules[j].left);
				// to print the current stack
				printf("$%s\t", stack);
				// to print the remaining inputs
				for(k=i; k<strlen(input); k++) {
					printf("%c", input[k]);
				}
				// indicating reduce
				printf("$\tReduce %s->%s\n", rules[j].left, rules[j].right);
				j = -1; // restart the reduction for updated stack
			}

		}

		// check if stack contains only the start symbol and entire input has been processed 
		if(strcmp(stack, rules[0].left) == 0 && i == strlen(input)) {
			printf("\nAccepted");
			break;
		} 

		// check if just the entire string has been processed
		if(i == strlen(input)) {
			printf("\nNot Accepted");
			break;
		} 

	}

}