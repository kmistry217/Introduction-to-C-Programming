#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
	int data;
	struct node* next;
};

struct node* head[10000] = {NULL};


void insert(int key){
	struct node* temp = (struct node*) malloc (sizeof(struct node));
	struct node* pointer; 
	temp->data = key;
	int index = key%10000;
	if (index < 0){
		index = -index;
	}
	if (head[index] == NULL){
		head[index] = temp;
		temp->next = NULL;
		printf("inserted\n");
	}
	else{
		pointer = head[index];
		while (pointer != NULL){
			if (pointer->data == key){
				printf("duplicate\n");
				return; 
			}
			pointer = pointer->next;
		}
		pointer = head[index];
		temp->next = head[index];
		head[index] = temp; 
		printf("inserted\n");
	}
}


void search(int key){
	int index = key%10000;
	if (index < 0){
		index = -index;
	}
	struct node* pointer = head[index];
	while (pointer != NULL){
		if (pointer->data == key){
			printf("present\n");
			return;
		}
		pointer = pointer->next;
	}
	printf("absent\n");
}


int main (int argc, char** argv){
	
	char is;
	int key;
	
	char* file = argv[1];
	FILE* fp = NULL;
	fp = fopen(file, "r");
	
	while(!feof(fp)){
		fscanf(fp,"%c\t",&is);
		fscanf(fp,"%d\n", &key);
		if(is == 'i'){
			insert(key);
		}
		if(is == 's'){
			search(key);
		}
	}
	return 0; 
}
