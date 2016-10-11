#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char **stringToArray(char *str, int *size) {
	char **sWords;
	sWords = (char **)malloc(10000);
	char * tok = strtok(str," ");
	int i=0;
	while(tok!= NULL) {
		sWords[i] = (char*)malloc(20);
		sWords[i++] = tok;
		*size += 1;
		tok = strtok(NULL," ");
	}
	return sWords;
 }

int main ()
{
	char *s;
	s = (char *)malloc(10000);
	strcpy(s,"1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19");
	char **sWords;
	int size=0;
	sWords = stringToArray(s, &size);
	int j = size;
	while(j>=0) {
		printf("%s\n",sWords[j--]);
	}
	return 0;
}




