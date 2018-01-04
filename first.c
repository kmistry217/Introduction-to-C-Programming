#include<stdio.h>
#include<stdlib.h>


struct node{
	int data;
	struct node *next;
};


struct node* head = NULL;

void insert(int num){
	struct node* temp = (struct node*) malloc (sizeof(struct node));
	temp-> data = num;
	if(head == NULL){
		temp-> next = NULL;
		head = temp; 
	}
	else if((temp-> data) < (head->data)){
		temp-> next = head;
		head = temp;
	}
	else{
		struct node* pointer = head;
		struct node* prev; 
		while((temp-> data) > (pointer->data) && pointer->next != NULL) {
			prev = pointer;
			pointer = pointer-> next;
		}
		if (pointer->next == NULL && (temp-> data) > (pointer->data)){
			pointer->next = temp;
			temp->next = NULL;
		}
		else if (pointer-> data == temp-> data){
			return;
		}
		else{
		prev->next = temp;
		temp->next = pointer;
		}
	}
}


void delete(int num){
	struct node* pointer = head;
	struct node* prev;
	if (head == NULL){
		return;
	}
	if (head-> data == num){
		head = pointer-> next;
		return;
	}
	while(pointer!=NULL){
		prev = pointer;
		if (pointer->next == NULL){
			prev->next = NULL;
			return;
		}
		pointer = pointer->next;
		if(pointer->data == num){
			if(pointer->next == NULL){
				prev->next = NULL;
				return;
			}
			else{ 
				prev->next = pointer->next;
				return;
			}
		}
		break;
	}
}


void nodesCount(){
	struct node* temp = head; 
	int count = 0; 
	while (temp!= NULL){
		temp = temp-> next;
		count++;
	}
	printf("%d\n", count);
	
}


void print(){
	struct node* temp = head; 
	while (temp!= NULL){
		printf("%d", temp-> data);
		if (temp->next !=NULL){
			printf("\t");
		}
		temp = temp-> next;
	}
}


int main (int argc, char** argv){
	
	char* file = argv[1];
	FILE* fp = NULL;
	fp = fopen(file, "r");
	
	if (fp == NULL){
		printf("error");
		return 0;
	}
	
	char id;
	int num;
	
	while(!feof(fp)){
		fscanf(fp,"%c\t",&id);
		fscanf(fp,"%d\n", &num);
		if(id == 'i'){
			insert(num);
		}
		if(id == 'd'){
			delete(num);
		}
	}
	nodesCount();
	print();
	
	fclose(fp);
	
	return 0; 
}
