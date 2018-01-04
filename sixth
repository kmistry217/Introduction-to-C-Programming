#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>


int main (int argc, char** argv) {
	
	char *str = argv[1];
	int i;
	int count = 1;
	int newstrlen = 0;
	char new[50];
	
	if (argv[2]){
		printf("error");
		exit(0);
	}
	
	for (i=0; i<strlen(str); i++){
		if((str[i]> '/' && str[i]< ':')){
			printf("error");
			exit(0);
		}
	}
	
	for (i=0; i<strlen(str); i++){
		if (str[i] == str[i+1]){
			count++;
		}
		else{
			sprintf(new,"%c%d", str[i], count);
			newstrlen += 2;
			count = 1;
		}	
	}
	
	if(newstrlen > strlen(str)){
		printf("%s", str);
	}	
	else if (newstrlen < strlen(str)){
		for (i=0; i<strlen(str); i++){
			if (str[i] == str[i+1]){
				count++;
			}
			else{
				printf("%c%d", str[i], count);
				count = 1;
			}	
		}
	}
	
	return 0;
}


