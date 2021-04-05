#include<stdio.h>
#include<stdlib.h>

struct node {
	
	char ssn[25], name[25], dept[10], designation[25];
	int salary;
	long int phno;
	struct node *llink;
	struct node *rlink;
};
typedef struct node  *NODE;

NODE first = NULL;
int count = 0;

NODE create();
NODE insertfront();
NODE insertend();
NODE deletefront();
NODE deleteend();
void display();
void dqdemo();

void main() {

	int choice, n;

	while(1){

		printf("\n____Menu____\n");
		printf("1. Create a DLL of employees\n");
		printf("2. Display status\n");
		printf("3. Insert at end\n");
		printf("4. Delete at end\n");
		printf("5. Insert at front\n");
		printf("6. Delete at front\n");
		printf("7. Dequeue Demo\n");
		printf("8. Exit\n");
		printf("\nEnter your choice: ");
		scanf("%d", &choice);

		switch(choice){

			case 1: printf("\nEnter number of employees: ");
					scanf("%d", &n);
					for(int i = 0; i <  n; i++)
						first = insertend();
					break;

			case 2: display();
					break;

			case 3: first = insertend();
					break;

			case 4: first = deleteend();
					break;

			case 5: first = insertfront();
					break;

			case 6: first = deletefront();
					break;

			case 7: dqdemo();
					break;

			case 8: exit(1);
					break;

			default: printf("\nInvalid Choice\n");
					 break;
		}
	}
}

NODE create() {

	NODE enode = NULL;
	enode = (NODE)malloc(sizeof(struct node));

	if(enode == NULL){
		printf("\nRunning out of memory\n");
		exit(1);
	}

	printf("\nEnter Name: ");
	scanf("%s", enode -> name);
	printf("\nEnter SSN: ");
	scanf("%s", enode -> ssn);
	printf("\nEnter department: ");
	scanf("%s", enode -> dept);
	printf("\nEnter designation: ");
	scanf("%s", enode -> designation);
	printf("\nEnter Salary: ");
	scanf("%d", &enode -> salary);
	printf("\nEnter Phone Number: ");
	scanf("%ld", &enode -> phno);

	enode -> llink = NULL;
	enode -> rlink = NULL;
	count++;
	return enode;
}

NODE insertfront() {

	NODE temp;
	temp = create();

	if(first == NULL)
		return temp;

	temp  -> rlink = first;
	first -> llink = temp;
	return temp;
}

NODE deletefront() {

	NODE temp;

	if(first == NULL){

		printf("\nDoubly Linked List is empty\n");
		return NULL;
	}

	if(first -> rlink == NULL) {

		printf("\n%s is deleted\n", first -> name);
		free(first);
		count--;
		return NULL;
	}

	temp = first;
	first = first -> rlink;
	temp -> rlink = NULL;
	first -> llink = NULL;
	printf("\n%s is deleted\n", temp -> name);
	free(temp);
	count--;
	return first;
}

NODE insertend() {

	NODE cur, temp;
	temp = create();

	if(first == NULL)
		return temp;

	cur = first;
	while(cur -> rlink != NULL)
		cur = cur -> rlink;
	cur -> rlink = temp;
	temp -> llink = cur;
	return first;
}

NODE deleteend() {

	NODE prev, cur;

	if(first == NULL) {

		printf("\nDoubly Linked List is empty\n");
		return NULL;
	}

	if(first -> rlink == NULL) {

		printf("\n%s is deleted", first -> name);
		free(first);
		count--;
		return NULL;
	}

	prev = NULL;
	cur = first;

	while(cur -> rlink != NULL) {

		prev = cur;
		cur = cur -> rlink;
	}

	cur -> llink = NULL;
	printf("\n%s is deleted\n", cur -> name);
	free(cur);
	prev -> rlink = NULL;
	count--;
	return first;
}

void dqdemo() {

	int choice;

	while(1) {

		printf("\n____Dequeue Demo____\n");
		printf("1. Insert Front\n");
		printf("2. Delete Front\n");
		printf("3. Insert Rear\n");
		printf("4. Delete Rear\n");
		printf("5. Display\n");
		printf("6. Exit\n");
		printf("\nEnter your choice: ");
		scanf("%d", &choice);

		switch(choice) {

			case 1: first = insertfront();
					break;

			case 2: first = deletefront();
					break;

			case 3: first = insertend();
					break;

			case 4: first = deleteend();
					break;

			case 5: display();
					break;

			case 6: exit(1);
					break;

			default: printf("\nInvalid choice\n");
					 break;
		}
	}
}

void display() {

	NODE cur;
	int n = 1;
	cur = first;

	if(cur == NULL)
		printf("\nDoubly Linked List is empty\n");

	while(cur != NULL) {

		printf("\n%d. Name: %s\n", n, cur -> name);
		printf("   SSN: %s\n", cur -> ssn);
		printf("   Department: %s\n", cur -> dept);
		printf("   Designation: %s\n", cur -> designation);
		printf("   Salary: %d\n", cur -> salary);
		printf("   Phone Number: %ld\n", cur -> phno);

		cur = cur -> rlink;
		n++;
	}

	printf("\nNumber of employees = %d", count);
}
