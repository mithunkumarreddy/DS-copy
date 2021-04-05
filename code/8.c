#include<stdio.h>
#include<stdlib.h>

struct node {

	char name[25], usn[25], branch[25];
	int sem;
	long int phno;
	struct node *link; 
};

typedef struct node *NODE;

NODE start = NULL;
int count = 0;

NODE create();
NODE insertfront();
NODE insertend();
NODE deletefront();
NODE deleteend();
void display();
void stackdemo();

void main() {

	int choice, n;

	while (1) {

		printf("\n____Menu____\n");
		printf("1. Create SLL of student nodes\n");
		printf("2. Display Status\n");
		printf("3. Insert at End\n");
		printf("4. Delete at End\n");
		printf("5. Stack Demo\n");
		printf("6. Exit\n");
		printf("\nEnter your choice: ");
		scanf("%d", &choice);

		switch (choice) {

			case 1: printf("\nEnter number of student: ");
					scanf("%d", &n);

					for(int i = 0; i < n; i++)
						start = insertfront();
					break;

			case 2: display();
					break;

			case 3: start = insertend();
					break;

			case 4: start = deleteend();
					break;

			case 5: stackdemo();
					break;

			case 6: exit(0);
					break;

			default: printf("\nInvalid choice\n");
					 break;
		}
	}
}

NODE create() {

	NODE snode;
	snode = (NODE)malloc(sizeof(struct node));

	if(snode == NULL){

		printf("\nMemory is not available\n");
		exit(1);
	}

	printf("\nEnter Name: ");
	scanf("%s", snode -> name);
	printf("\nEnter USN: ");
	scanf("%s", snode -> usn);
	printf("\nEnter Branch: ");
	scanf("%s", snode -> branch);
	printf("\nEnter Semester: ");
	scanf("%d", &snode -> sem);
	printf("\nEnter Phone Number: ");
	scanf("%ld", &snode -> phno);

	snode -> link = NULL;
	count++;
	return snode;
}

NODE insertfront() {

	NODE temp;
	temp = create();

	if(start == NULL)
		return temp;
	temp -> link = start;
	return temp;
}

NODE deletefront() {

	NODE temp;

	if(start == NULL){

		printf("\nLinked list is empty\n");
		return NULL;
	}

	if(start -> link == NULL) {

		printf("\n%s node is deleted\n", start -> usn);
		count--;
		free(start);
		return NULL;
	}

	temp = start;
	start = start -> link;
	printf("\n%s node is deleted\n", temp -> usn);
	count--;
	free(temp);
	return start;
}

NODE insertend() {

	NODE cur, temp;
	temp = create();

	if(start == NULL)
		return temp;

	cur = start;
	while(cur -> link != NULL)
		cur = cur -> link;

	cur -> link = temp;
	return start;
}

NODE deleteend() {

	NODE cur, prev;

	if(start == NULL) {

		printf("\nLinked list is empty\n");
		return NULL;
	}

	if(start -> link == NULL) {

		printf("\n%s is deleted\n", start -> usn);
		free(start);
		count--;
		return NULL;
	}

	prev = NULL;
	cur = start;
	while(cur -> link != NULL) {

		prev = cur;
		cur = cur -> link;
	}

	printf("\n%s is deleted\n", cur -> usn);
	free(cur);
	prev -> link = NULL;
	count--;
	return start;
}

void display() {

	NODE cur;
	int n = 1;

	if(start == NULL) {

		printf("\nLinked list is empty\n");
		return;
	}

	printf("\nThe elements are:\n");
	cur = start;

	while(cur != NULL){

		printf("%d.) USN: %s\n", n, cur -> usn);
		printf("   Name: %s\n", cur -> name);
		printf("   Branch: %s\n", cur -> branch);
		printf("   Semester: %d\n", cur -> sem);
		printf("   Phone Number: %ld\n\n", cur -> phno);

		cur = cur -> link;
		n++;
	}

	printf("\nNumber of students nodes = %d\n", count);
}

void stackdemo() {

	int choice;

	while(1) {

		printf("\n____Stack Demo____\n");
		printf("1. Push an element\n");
		printf("2. Pop an element\n");
		printf("3. Display\n");
		printf("4. Exit\n");
		printf("\nEnter your choice: ");
		scanf("%d", &choice);

		switch(choice){

			case 1: start = insertfront();
					break;

			case 2: start = deletefront();
					break;

			case 3: display();
					break;

			case 4: exit(0);
					break;

			default: printf("\nInvalid choice\n");
					 break;
		}
	}

	return;
}
