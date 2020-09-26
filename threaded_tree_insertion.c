#include<stdio.h> 
#include<stdlib.h> 

struct node { 
	int data; 
	struct node* left;
	struct node* right; 
	int thread;
}; 

struct node* newNode(int val) { 
	struct node *temp = (struct node*)malloc(sizeof(struct node)); 
	temp->data = val; 
	temp->left = temp->right = NULL; 
	return temp; 
} 

struct node* insertNode(struct node* root, int val) { 
	if (root == NULL) 
	    return newNode(val); 
	    
	struct node* temp = (struct node*)malloc(sizeof(struct node));  
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	
	if (val < root->data) {
		newNode = insertNode(root->left, val); 
		root->left = newNode;
		newNode->right = root;
		newNode->thread = 1;
	}
		
	else {
		newNode = insertNode(root->right, val);
		if (root->thread != 1){
		    if (root->right == NULL){
		        root->right = newNode;
		    }
		}
		else {
		   temp = root->right;
		   root->right = newNode;
		   newNode->right = temp;
		   newNode->thread = 1;
		   root->thread = 0;
		}
	
	}
		
	return root; 
} 

struct node* minVal(struct node* root) { 
	struct node* temp = root;
	while (temp && temp->left != NULL) 
		temp = temp->left; 
	return temp; 
}

void inorder_threaded_display(struct node* root) { 
    if (root == NULL) 
        return; 

    struct node* temp = minVal(root); 
  
    while (temp != NULL) { 
        printf("%d ", temp->data);
        if (temp->thread == 1) 
            temp = temp->right; 
        else 
            temp = minVal(temp->right); 
    } 
} 

int main() { 
	struct node *root = NULL; 
	int n;
	printf("Enter the no. of elements you want to enter in the threaded binary tree: ");
	scanf("%d", &n);
	printf("Enter the elements:\n");
	while (n--){
	    int d;
	    scanf("%d", &d);
	    root = insertNode(root, d); 
	}
	
	printf("Threaded tree is:\n");
	inorder_threaded_display(root);

	return 0; 
} 
