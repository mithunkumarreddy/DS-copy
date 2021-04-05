#include<stdio.h>
#include<stdlib.h>
#define MAX 5

char queue[MAX];
int front = -1, rear = -1, element;

void insert(int element);
void delete();
void display();

void main() {

	int choice;

	while (1) {

		printf("\n____Menu____\n");
		printf("1. Insertion and Overflow Demo\n");
		printf("2. Deletion and Underflow Demo\n");
		printf("3. Display\n");
		printf("4. Exit");
		printf("\nEnter your choice: ");
		scanf("%d", &choice);

		switch (choice) {

			case 1: printf("\nEnter an element: ");
					scanf("%d", &element);
					insert(element);
					break;

			case 2: delete();
					break;

			case 3: display();
					break;

			case 4: exit(1);
					break;

			default: printf("\nInvalid Choice!\n");
					 break;
		}
	}
}

void insert(int element) {


	if (front == (rear + 1) % MAX)
		printf("\nCircular Queue Overflow\n");

	else {

		if (front == -1) {
			front = 0;
			rear = 0;
		}

		else
			rear = (rear + 1) % MAX;

		queue[rear] = element;
	}
}

void delete() {

	if (front == -1)
		printf("\nCircular Queue Underflow\n");
	
	else {

		element = queue[front];
		printf("\n%d is deleted", element);

		if(front == rear) {
			front = -1;
			rear = -1;
		}
		
		else
			front = (front + 1) % MAX;
	}
}

void display() {

	int i;

	if (front == -1)
		printf("\nCircular Queue is empty\n");

	else {

		printf("\nThe elements are:\n");
		printf("\nFront = %d\n\n", front);

		for (i = front; i != rear; i = (i + 1) % MAX)
			printf("|  %d  |", queue[i]);

		printf("|  %d  |", queue[i]);
		printf("\n\nRear = %d\n", rear);
	}
}