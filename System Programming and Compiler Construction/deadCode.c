#include <stdio.h>
#include <conio.h>
#include <string.h>

void main() {

	char code[15][50];
	int n = 0;
	int i;

	printf("\nEnter your Python code (enter empty line to finish):\n\n");
	while(n < 15 && fgets(code[n], sizeof(code[0]), stdin)){
		if(code[n][0] == '\n')
			break;
		n++;
	}

	printf("Code after Dead Code Elimination: \n\n");
	for(i=0; i<n; i++){
		printf("%s", code[i]);
		if(strcmp(strtok(code[i], " "), "\treturn") == 0)
			break;
	}

	printf("\n");

}