#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

int mySubstr(char *mainString, char *substring) {
	int indexFound;
	int iterator=0;
	int subStringLength = strlen(substring);
	while(iterator<=strlen(mainString)) {
		int subIndex = 0;
		int indexFound = iterator;
		while(subIndex < subStringLength) {
			if(substring[subIndex++] != mainString[iterator++]) {
				break;
			}
		}
		if(subIndex == subStringLength) {
			return indexFound;
		}
	}
	return -1;
}



int main(){
	char *mainString;
	mainString = (char *)malloc(100*sizeof(char));
	printf("Enter a string (upto 100 characters): " );
	fgets(mainString, 100, stdin);
	//scanf("%[\n]s",mainString);
	printf("Entered String: %s\n", mainString);
	char *substring;
	substring = (char *) malloc(100*sizeof(char));
	printf("Enter the substring to match: ");
	//scanf("%[\n]s",substring);
	fgets(substring, 100, stdin);
	int result;
	result = mySubstr(mainString, substring);
	if(result == -1) {
		printf("Substring not found.");
	} else {
		printf("Substring found at %d.", result);
	}
	return 0;
}


