#include<stdio.h>
#include<stdlib.h>

#define BUFFER_SIZE 20 // Size of the buffer in bytes
/**
 * @author Antoine-Matis Boudreau aka ShadyFox2004
 */

int main(int argc, char** argv) {
	char buffer[BUFFER_SIZE];
	// Main code here
	FILE* file = fopen(argv[0],"r");

	int count = fread(&buffer, sizeof(char), BUFFER_SIZE, file);

	printf("count: %i\n", count);

	fclose(file);
}
