#include <stdio.h>
#include <string.h>

struct MNT
{
	int index;
	char name[8];
	int mndt;
};

void main() {

	char code[15][50];
	char *token;
	int i, n = 0, mntc = 0, mdtc = 0;
	struct MNT mnt[5];

	printf("Enter Assembly Code: \n\n");
	while(n<15 && fgets(code[n], sizeof(code[0]), stdin)) {
		if(code[n][0] == '\n') 
			break;
		code[n][strlen(code[n])-1] = '\0'; 
		n++;
	}

	for(i=0; i<n; i++) {
		token = strtok(code[i], " ");
		printf("%s\n", token);
		if(strcmp(token, "MACRO")) {
			token = strtok(code[++i], " ");
			mnt[mntc].index = mntc++;
			strcpy(mnt[mntc].name, token);
			mnt[mntc].mndt = mdtc; 
			mdtc++;
		}
		// token = strtok(NULL, " ");
	}

	for(i=0; i<mntc; i++)

}
