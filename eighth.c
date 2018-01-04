#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* left;
	struct node* right;
};


struct node* root = NULL;


void insert(int num){
	struct node* child = (struct node*) malloc (sizeof(struct node));
	struct node* pointer = root;
	struct node* prev = root; 
	struct node* tempRoot = root;
	child->data = num;
	child->left = NULL;
	child->right = NULL;
	int height = 2; 
	
	if (root == NULL){
		root = child;
		printf("inserted 1\n");
		return;
	}
	
	while (pointer != NULL){
		if (child->data < tempRoot->data){
			if(pointer->left == NULL){
				prev = pointer;
				break;
			}
			prev = pointer;
			pointer = pointer->left; 
			tempRoot = tempRoot->left;
			height++;
		}
		else if (child->data > tempRoot->data){
			if(pointer->right == NULL){
				prev = pointer;
				break;
			}
			prev = pointer;
			pointer = pointer->right;
			tempRoot = tempRoot->right;
			height++;
		}
		else if (child->data == tempRoot->data) {
			printf("duplicate\n");
			return;
		}
	}
	
	if (child->data < tempRoot->data){
		prev->left = child;
		}
	else if (child->data > tempRoot->data){
		prev->right = child;
	}
	
	printf("inserted %d\n", height);
}


void search(int num){
	struct node* pointer = root;
	int height = 1; 
	
	if (num == root->data){
		printf("present 1\n");
		return;
	}
	
	while (pointer != NULL){
		if (num < pointer->data){
			if(pointer->left != NULL){
				pointer = pointer->left;
				height++;
			}
			else{
				printf("absent\n");
				return;
			}
		}
		else if (num > pointer->data){
			if(pointer->right != NULL){
				pointer = pointer->right;
				height++;
			}
			else{
				printf("absent\n");
				return;
			}
		}
		else if (num == pointer->data){
			printf("present %d\n", height);
			return;
		}
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
	
	char is;
	int num;
	
	while(!feof(fp)){
		fscanf(fp,"%c\t",&is);
		fscanf(fp,"%d\n", &num);
		if (is != 'i' && is != 's'){
			printf("error");
			return 0; 
		}
	}
		
	file = argv[1];
	fp = NULL;
	fp = fopen(file, "r");
	
	while(!feof(fp)){
		fscanf(fp,"%c\t",&is);
		fscanf(fp,"%d\n", &num);
		if(is == 'i'){
			insert(num);
		}
		if(is == 's'){
			search(num);
		}
	}
	return 0;
}



