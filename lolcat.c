#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Prints a character in a certain 256 scale color depending on an inputed integer
 * @param c: char that we will print in a color
 * @param i: int index that we will use to determin the color of the character
*/
void printcc(char c, int i) {
	printf("\e[38;5;%dm%c\e[0m", 18 + i%(231-18), c);
}

int main(int argc, char* argv[]) {
	if (argc != 2) { // handle incorrect arguments
		fprintf(stderr, "Argument Error: ");
		if (argc == 1)
			fprintf(stderr, "Path missing for the file the program will display\n");
		else
			fprintf(stderr, "Incorrect number of arguments (1 expected, %d given)\n", argc);
		printf("Command Format: lolcat [filepath]\n");
		exit(1);
	}
	
	FILE *fp = fopen(argv[1], "r");
	if (fp == NULL) { // make sure file exist / was opened successfully
		fprintf(stderr, "File Error: error opening filepath\n");
		exit(1);
	}
	
	printf("\e[0m");
	int i = 0;
	while (!feof(fp)) { // loop where we parse and display the chars of the file
		printcc(fgetc(fp), i);
		i++;
	}
	fclose(fp);
	return 0;
}
