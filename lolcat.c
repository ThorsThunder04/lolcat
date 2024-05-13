#include <stdio.h>
#include <stdlib.h>

void printcc(char c, int i) {
	printf("\e[38;5;%dm%c\e[0m", 18 + i%(231-18), c);
	//printf("\e[3%dm%c\e[0m", 1 + i%7, c);
}

int main(int argc, char* argv[]) {
	if (argc != 2) {
		fprintf(stderr, "Argument Error: ");
		if (argc == 1)
			fprintf(stderr, "destination filepath to read missing\n");
		else
			fprintf(stderr, "incorrect number of arguments (expected 1, %d given)\n", argc);
		exit(1);
	}
	
	FILE *fp = fopen(argv[1], "r");
	if (fp == NULL) {
		fprintf(stderr, "File Error: error opening filepath\n");
		exit(1);
	}
	
	printf("\e[0m");
	int i = 0;
	while (!feof(fp)) {
		printcc(fgetc(fp), i);
		i++;
	}
	fclose(fp);
	return 0;
}
