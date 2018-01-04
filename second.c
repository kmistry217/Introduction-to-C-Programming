#include<stdio.h>
#include<stdlib.h>

int main(int argc, char** argv){
	
	int arraySize;
	int i=0, j, temp;
	
	char* filename = argv[1];
	FILE* fp = NULL;
	fp = fopen(filename, "r");
	
	fscanf(fp, "%d\n",&arraySize); //sets first line of file to array size
	
	int array[arraySize];
	
	while(!feof(fp)){
		fscanf(fp, "%d\n",&array[i]); //puts numbers from file into array 
		i++;
	}
	
	for (i=0; i<arraySize; i++){ //sorts array by comparing 2 numbers and switching if 1st>2nd
		for (j=i+1; j<arraySize; j++){
			if(array[i]>array[j]){
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
	
	for (i=0; i<arraySize; i++){ //prints sorted array
		printf("%d\t", array[i]);
	}
	
	fclose(fp);
	
	return 0; 
}
