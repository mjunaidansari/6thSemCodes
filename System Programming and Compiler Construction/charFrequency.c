#include <stdio.h>

void charCount(char *word, int *counts) {
	while(*word) {
		counts[*word]++;
		word++;
	}
}

void main() {

	char word[20];
	int counts[256] = {0};

	scanf("%s", &word);
	charCount(word, counts);

	printf("Character counts in the word '%s':\n", word);

	for(int i = 0; i<256; i++)
		if(counts[i]>0) 
			printf("%c: %d\n", i, counts[i]);

}