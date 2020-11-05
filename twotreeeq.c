#include <stdio.h> 
#include <stdlib.h> 

struct node { 
	int data; 
	struct node* left; 
	struct node* right; 
}; 

struct node* newNode(int val) { 
	struct node* node = (struct node*)malloc(sizeof(struct node)); 
	node->data = val; 
	node->left = node->right = NULL; 

	return node; 
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

int areTreesEqual(struct node* r1, struct node* r2) { 
	if (r1 == NULL && r2 == NULL) return 1; 
	
	if (r1 != NULL && r2 != NULL) { 
	    int dataeq = r1->data == r2->data;
	    int left_eq = areTreesEqual(r1->left, r2->left);
	    int right_eq = areTreesEqual(r1->right, r2->right); 
	    
	    return dataeq && left_eq && right_eq;
	} 
	else return 0; 
} 

int main() { 
	struct node *root1 = NULL; 
	struct node *root2 = NULL; 
	int n1, n2, d;
	printf("Enter the no. of elements you want to enter in the binary tree T1: ");
	scanf("%d", &n1);
	printf("Enter the elements:\n");
	while (n1--){
	    scanf("%d", &d);
	    root1 = insertNode(root1, d); 
	}
	printf("Enter the no. of elements you want to enter in the binary tree T2: ");
	scanf("%d", &n2);
	printf("Enter the elements:\n");
	while (n2--){
	    scanf("%d", &d);
	    root2 = insertNode(root2, d); 
	}

	if(areTreesEqual(root1, root2)) printf("Tree are equal"); 
	else printf("Trees are not equal"); 
	
	return 0; 
} 
