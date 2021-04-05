#include<stdio.h>
#include<stdlib.h>

struct BST {

	int data;
	struct BST *lchild;
	struct BST *rchild;
};
typedef struct BST *NODE;

NODE create();
void insert(NODE root, NODE newnode);
void inorder(NODE root);
void preorder(NODE root);
void postorder(NODE root);
void search(NODE root);

NODE create() {

	NODE temp;
	temp = (NODE)malloc(sizeof(struct BST));
	printf("\nEnter a value: ");
	scanf("%d", &temp -> data);

	temp -> lchild = NULL;
	temp -> rchild = NULL;
	return temp;
}

void insert(NODE root, NODE newnode) {

	if(newnode -> data < root -> data) {

		if(root -> lchild == NULL)
			root -> lchild = newnode;
		else
			insert(root -> lchild, newnode);
	}

	if(newnode -> data > root -> data) {

		if(root -> rchild == NULL)
			root -> rchild = newnode;
		else
			insert(root -> rchild, newnode);
	}
}

void search(NODE root) {

	int key;
	NODE cur;

	if(root == NULL) {

		printf("\nBST is empty.");
		return;
	}

	printf("\nEnter element to be searched: ");
	scanf("%d", &key);
	cur = root;
	while(cur != NULL){

		if(cur -> data == key) {

			printf("\nThe element is present in the BST.\n");
			return;
		}

		if(key < cur -> data)
			cur = cur -> lchild;
		else
			cur = cur -> rchild;
	}
	printf("\nKey element is not present in the BST\n");
}

void inorder(NODE root) {

	if(root != NULL){

		inorder(root -> lchild);
		printf("%d, ", root -> data);
		inorder(root -> rchild);
	}
}

void preorder(NODE root) {

	if(root != NULL) {

		printf("%d, ", root -> data);
		preorder(root -> lchild);
		preorder(root -> rchild);
	}
}

void postorder(NODE root) {

	if(root != NULL){

		postorder(root -> lchild);
		postorder(root -> rchild);
		printf("%d, ", root -> data);
	}
}

void main() {

	int choice, key, value, n;
	NODE root = NULL, newnode;

	while(1) {

		printf("\n____Menu____\n");
		printf("\n1. Create a BST");
		printf("\n2. Search");
		printf("\n3. BST traversals");
		printf("\n4. Exit");
		printf("\nEnter your choice: ");
		scanf("%d", &choice);

		switch(choice) {

			case 1: printf("\nEnter the number of elements: ");
					scanf("%d", &n);
					for(int i = 0; i < n; i++){

						newnode = create();
						if(root == NULL)
							root = newnode;
						else
							insert(root, newnode);
					}
					break;

			case 2: search(root);
					break;

			case 3: if(root == NULL)
						printf("\nTree is not created\n");
					else {

						printf("\nPreorder Traversal: ");
						preorder(root);

						printf("\nInorder Traversal: ");
						inorder(root);

						printf("\nPostorder Traversal: ");
						postorder(root);
					}
					break;

			case 4: exit(1);
					break;

			default: printf("\nInvalid choice\n");
					 break;
		}
	}
}