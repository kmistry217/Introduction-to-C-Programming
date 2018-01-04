#include<stdio.h>
#include<stdlib.h>

int main (int argc, char** argv){
	
	int matrixSize, power;
	int i, r, c, p;
	int** matrix;
	int** matrix2;
	int** temp;
	
	char* file = argv[1];
	FILE* fp = NULL;
	fp = fopen(file, "r");
	
	fscanf(fp, "%d\n", &matrixSize);
	
	matrix = (int**) malloc (matrixSize * sizeof(int*));
	for (i=0; i<matrixSize; i++){
		matrix[i] = (int*) malloc (matrixSize * sizeof(int));
	}
	
	matrix2 = (int**) malloc (matrixSize * sizeof(int*));
	for (i=0; i<matrixSize; i++){
		matrix2[i] = (int*) malloc (matrixSize * sizeof(int));
	}
	
	temp = (int**) malloc (matrixSize * sizeof(int*));
	for (i=0; i<matrixSize; i++){
		temp[i] = (int*) malloc (matrixSize * sizeof(int));
	}
	
	for (r=0; r<matrixSize; r++){
		for (c=0; c<matrixSize; c++){
			fscanf(fp, "%d\n", &matrix[r][c]);			
		}
	}
	for (r=0; r<matrixSize; r++){
		for (c=0; c<matrixSize; c++){
			matrix2[r][c] = matrix[r][c];
		}
	}
	
	fscanf(fp, "%d\n", &power);
	
	for(p=0; p<power-1;p++){
		for (r=0; r<matrixSize; r++){
			for (c=0; c<matrixSize; c++){
				temp[r][c] = 0; 
				for (i=0; i<matrixSize; i++){
					temp[r][c] += matrix2[r][i]*matrix[i][c];
				}
			}
		}
	
		for (r=0; r<matrixSize; r++){
			for (c=0; c<matrixSize; c++){
				matrix2[r][c] = temp[r][c];
			}
		}
	}
	
	
	for (r=0; r<matrixSize; r++){
		for (c=0; c<matrixSize; c++){
				printf("%d", matrix2[r][c]);
				if (c < matrixSize-1){
					printf("\t");
			}
		}
		if (r<matrixSize-1){
			printf("\n");
		}
	}


	fclose(fp);

	return 0;
}


