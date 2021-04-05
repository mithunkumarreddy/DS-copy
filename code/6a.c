#include<stdio.h>

int stack[20], top = -1, element;

void push(int element);
int pop();

void main() {

	char POST[25], symbol;
	int op1, op2;

	printf("\nEnter Postfix Expression: ");
	scanf("%s", POST);

	int len = 0;
	while (POST[len] != '\0')
		len++;

	for (int i = 0; i < len; i++) {

		symbol = POST[i];

		switch (symbol) {

			case '+': op2 = pop();
					  op1 = pop();
					  push(op1 + op2);
					  break;

			case '-': op2 = pop();
					  op1 = pop();
					  push(op1 - op2);
					  break;

			case '*': op2 = pop();
					  op1 = pop();
					  push(op1 * op2);
					  break;

			case '/': op2 = pop();
					  op1 = pop();
					  push(op1 / op2);
					  break;

			case '^': op2 = pop();
					  op1 = pop();
					  push(op1 ^ op2);
					  break;

			default: push(symbol - '0');
					 break;
		}
	}

	printf("\nThe value for the given Postfix expression is %d\n", pop());
}

void push(int element) {

	top++;
	stack[top] = element;
}

int pop() {

	element = stack[top];
	top--;
	return element;
}