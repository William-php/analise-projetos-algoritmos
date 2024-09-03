#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void analyze(char *word, int *n) {
	printf("word: %s\n", word);
	if (strcmp("for", word) == 0) {
		*n += 1;	
		return;
	}	
}
int main() {
	char str[80];
	char word[30];
	int n = 0;
	int step = 0;
	
	FILE *stream;
	
	stream = fopen("sort.cpp", "rb");
	char *line;
	
	while (line = fgets(str, 80, stream)) {
		while (sscanf(line, "%s", word) == 1) {			
			analyze(word, &n);
			
			while (*line != '\0' && !isspace((unsigned char)*line)) *line++;
			while (*line != '\0' && isspace((unsigned char)*line)) *line++;
		}
		step += 1;
		
	}
		
	fclose(stream);
	if (n && step) printf("%dn + %d", n, step);
	return 0;
}
