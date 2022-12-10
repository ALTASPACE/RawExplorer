#include<stdio.h>
#include<stdlib.h>

/**
 * @author Antoine-Matis Boudreau aka ShadyFox2004
 */

/**
 * Definition of the cr2 header format
 */
typedef struct CR2_HEADER {
	char byteOrder[2]; // II for little indian; MM for big Indian	| 0x0000
	short tiffMagicWord; // 0x002a 					| 0x0002
	long tiffOffset; // 0x0000 0010					| 0x0004
	short cr2MagicWord; // "CR" or 0x4352				| 0x0008
	char cr2MajorVersion; // Version of the cr2 format		| 0x000a
	char cr2MinorVersion; // Version of the cr2 format		| 0x000b
	long rawFIDOffset; // WHERE IS THE GOOD STUFF!			| 0x000c
} CR2_HEADER; 

int main(int argc, char** argv) {
	char data;
	char** dataStrings;
	int index = 0;
	int fieldIndex = 0;
	int lenght = 2;
	int sizeOfFields = 1;

	FILE* file = fopen(argv[0],"r");
	
	fseek(file, 0x0000, SEEK_SET); // Changes the pointer location
	
	dataStrings = malloc(sizeof(sizeOfFields));
	dataStrings[fieldIndex] = malloc(sizeof(lenght));
	for(int i=0; i < lenght; i++) {
		data = fgetc(file); // Reads the data
		if(data) {
			dataStrings[fieldIndex][index] = data;
			index++;
		} else {
			i=lenght; // Closes the loop without a break
		}
	}

	fclose(file);
}
