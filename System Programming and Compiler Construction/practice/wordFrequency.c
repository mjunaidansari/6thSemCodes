#include <stdio.h>
#include <string.h>
#include <ctype.h>

void removeElement(int index, char words[20][20], int *size) {

	for(int i = index; i<*size; i++){
		strcpy(words[i], words[i+1]);
	}
	(*size)--;

}

void main() {

	char input[100], words[20][20], word[20];
	int freq[20];
	int i, j;
	int wordCounter = 0;

	scanf("%[^\n]", &input);

	char* token = strtok(input, " ");
	while(token!=NULL) {
		strcpy(words[wordCounter], token);
		wordCounter++;
		token = strtok(NULL, " ");
	}

	for(i=0; i<wordCounter; i++) {
		strcpy(word, words[i]);
		freq[i] = 1;
		for(j = i+1; j<wordCounter; j++) {
			if(strcmp(word, words[j])==0) {
				freq[i]++;
				removeElement(j, words, &wordCounter);
				j--;
			}
		}
	}

	printf("Word\t\tFrequency\n");
	printf("----\t\t---------\n");

	for(i=0; i<wordCounter; i++){
		printf("%s\t\t%d\n", words[i], freq[i]);
	}
	
	printf("WordCounter: %d\n\n", wordCounter);	

}