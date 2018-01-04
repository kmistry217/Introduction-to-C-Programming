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
	
	if (root == NULL){
		printf("absent\n");
		return;
	}
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


struct node* delete (struct node* root, int num){
	if (root == NULL){
		printf("fail\n");
		return root; 
	}
	else if (num < root->data){
		root->left = delete(root->left, num);
	}
	else if (num > root->data){
		root->right = delete(root->right, num);
	}
	else if (num == root->data){
		if (root->left == NULL && root->right == NULL){
			free(root);
			root = NULL;
			printf("success\n");
			return root;
		}
		else if (root->left == NULL && root->right != NULL){
			struct node* pointer = root;
			root = root->right;
			free(pointer);
			printf("success\n");
			return root; 
		}
		else if (root->right == NULL && root->left != NULL){
			struct node* pointer = root;
			root = root->left;
			free(pointer);
			printf("success\n");
			return root; 
		}
		else if (root->right != NULL && root->left != NULL){
			struct node* min = root->right;
			while(min->left != NULL){
			min = min->left;
			}
			root->data = min->data;
			root->right = delete(root->right, min->data);
		}
	}
	return root;
}


int main (int argc, char** argv){
	
	char* file = argv[1];
	FILE* fp = NULL;
	fp = fopen(file, "r");
	
	if (fp == NULL){
		printf("error");
		return 0;
	}
	
	char isd;
	int num;
	
	while(!feof(fp)){
		fscanf(fp,"%c\t",&isd);
		fscanf(fp,"%d\n", &num);
		if (isd != 'i' && isd != 's' && isd != 'd'){
			printf("error");
			return 0; 
		}
	}
	
	file = argv[1];
	fp = NULL;
	fp = fopen(file, "r");
	
	while(!feof(fp)){
		fscanf(fp,"%c\t",&isd);
		fscanf(fp,"%d\n", &num);
		if(isd == 'i'){
			insert(num);
		}
		if(isd == 's'){
			search(num);
		}
		if(isd == 'd'){
			root = delete(root, num);
		}
	}
	return 0;
}






