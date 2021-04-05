#include<stdio.h>
#include<stdlib.h>

int top = -1;
char stack[20], element, symbol, temp;

void push(char element);
char pop();
int PREC(char symbol);

int main() {

	char POST[25], INF[25];
	int pos = 0, len = 0;
	printf("\nEnter an Infix Expression: ");
	scanf("%s", INF);
	
	push('#');

	while (INF[len] != '\0')
		len++;
	for(int i = 0; i < len; i++) {

		symbol =INF[i];
		
		switch (symbol){

			case '(': push(symbol);
					  break;

			case ')': temp = pop();

				while (temp != '('){

					POST[pos++] = temp;
					temp = pop();
				}
					  
				break;

			case '+': case '-': case '*': case '/': case '^':

						while(PREC(stack[top]) >= PREC(symbol)) {

							temp = pop();
							POST[pos++] = temp;
						}

						push(symbol);
						break;

			default: POST[pos++] = symbol;
			     	 break;
		}
	}

	while (top > 0) {

		temp = pop();
		POST[pos++] = temp;
	}

	POST[pos] = '\0';
	printf("The Postfix expression is: %s\n", POST);

}

void push(char element) {

	top++;
	stack[top] = element;
}

char pop() {

	temp = stack[top];
	top--;
	return temp;
}

int PREC(char symbol) {

	int p;

	switch (symbol) {

		case '^': p = 3;
				  break;

		case '/': case '*': p = 2;
							break;

		case '+': case '-': p = 1;
							break;

		case '(': case ')': p = 0;
							break;

		case '#': p = -1;
				  break;
	}

	return p;
}
