#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int top = -1, stack[MAX], element, flag = 0;

void push(int element);
void pop();
void palindrome();
void display();

void main() {

	int choice;

	while(1) {

		printf("\n____Menu____\n");
		printf("1. Push an element\n");
		printf("2. Pop an element\n");
		printf("3. Check for palindrome\n");
		printf("4. Display\n");
		printf("5. Exit\n");
		printf("\nEnter your choice: ");
		scanf("%d", &choice);

		switch (choice) {

			case 1: 

				printf("\nEnter element to be pushed: ");
				scanf("%d", &element);
				push(element);
				break;

			case 2: pop();
					break;

			case 3: palindrome();
					break;

			case 4: display();
					break;

			case 5: exit(1);
					break;

			default: printf("\nInvalid Choice!\n");
					break;
		}
	}
}

void push(int element) {

	if (top == MAX - 1){
		
		printf("\nStack Overflow\n");
		return;
	}

	else {

		top++;
		stack[top] = element;
		display();
	}
}

void pop() {

	if (top == -1)
		printf("\nStack Underflow\n");

	else {

		element = stack[top];
		top--;
		printf("\nThe popped element is: %d", element);
		display();
	}
}

void display() {

	if (top == -1) {
		printf("\nStack is Empty\n");
		return;
	}

	else {

		for(int i = top; i >= 0; i--)
			printf("\n|  %d  |\n", stack[i]);
	}
}

void palindrome() {

	if (top == -1)
		printf("\nStack is Empty\n");

	else {

		for(int i = 0, j = top; i <= top/2, j >= top/2; i++, j--) {

			if (stack[i] == stack[j])
				flag = 1;

			else {
				flag = 0;
				break;
			}
		}

		if (flag)
			printf("\nIt is a palindrome\n");

		else
			printf("\nIt is not a palindrome\n");
	}
}