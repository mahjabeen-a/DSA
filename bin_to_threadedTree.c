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
	    
	if (val < root->data) 
		root->left = insertNode(root->left, val); 
		
	else
		root->right = insertNode(root->right, val); 
		
	return root; 
} 

struct node* createThreadedTree(struct node* root) { 
    if (root == NULL) 
        return NULL; 
        
    if (root->left == NULL && root->right == NULL) 
        return root;
        
    if (root->left != NULL) { 
        struct node* link = createThreadedTree(root->left); 
        link->right = root; 
        link->thread = 1; 
    } 
 
    if (root->right == NULL) 
        return root;
        
    return createThreadedTree(root->right); 
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
	printf("Enter the number of elements you want to enter in the binary tree: ");
	scanf("%d", &n);
	printf("Enter the elements:\n");
	while (n--){
	    int d;
	    scanf("%d", &d);
	    root = insertNode(root, d); 
	}
	createThreadedTree(root);
	
	printf("Threaded tree is:\n");
	inorder_threaded_display(root);

	return 0; 
} 
