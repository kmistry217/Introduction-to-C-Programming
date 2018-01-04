#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main (int argc, char** argv) {

	char* sentence = NULL;
	int i;
	
	for(i=1; i<argc;i++){
		sentence = argv[i];
		*sentence = sentence[strlen(sentence)-1];
		printf("%c", *sentence);
	}
	
	return 0; 
	
}	
