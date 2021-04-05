//Adding two polynomials

#include<stdio.h>
#include<stdlib.h>

struct polynode{

	int coeff, expo;
	struct polynode *next;
};

typedef struct polynode POLY;

POLY *poly1 = NULL, *poly2 = NULL, *poly3 = NULL, *temp;

void push(POLY *num);
void display();
void addpoly(POLY *poly1, POLY *poly2, POLY *poly3);

void main(){

	poly1 = (POLY*)malloc(sizeof(POLY));
	poly2 = (POLY*)malloc(sizeof(POLY));
	poly3 = (POLY*)malloc(sizeof(POLY));
	
	printf("\nEnter the first polynomial:\n");
	push(poly1);
	printf("\nEnter the second polynomial:\n");
	push(poly2);

	addpoly(poly1, poly2, poly3);
	printf("\nThe resultant polynomial is:\n");
	display();
	//printf("\n");
}

void push(POLY *num){
	
	int n = 1, choice = 1;

	while(choice){
		
		printf("\nEnter coeffecient of term %d: ", n);
		scanf("%d", &num -> coeff);
		printf("\nEnter exponent of term %d: ", n);
		scanf("%d", &num -> expo);
		num -> next = (POLY*)malloc(sizeof(POLY));
		num = num -> next;
	    num -> next = NULL;
		printf("\nDo you want to add another term? (stop = 0):\n");
		scanf("%d", &choice);
		n++;
	}
}

void display() {

	POLY *num = poly3;
	temp = num;
	
	while(temp -> next != NULL){

		if(temp -> next -> next != NULL){

			if(temp -> next -> coeff < 0){
				printf(" %dx^%d", temp -> coeff, temp -> expo);
			}

			else{
				printf(" %dx^%d +", temp -> coeff, temp -> expo);
			}

		}

		else{
			printf(" %dx^%d\n", temp -> coeff, temp -> expo);
		}

		temp = temp -> next;
	}
}


void addpoly(POLY *poly1, POLY *poly2, POLY *poly3) {

	while(poly1 -> next && poly2 -> next){

		if(poly1 -> expo > poly2 -> expo){

			poly3 -> expo = poly1 -> expo;
			poly3 -> coeff = poly1 -> coeff;
			poly1 = poly1 -> next;
		}

		else if(poly1 -> expo < poly2 -> expo){

			poly3 -> expo = poly2 -> expo;
			poly3 -> coeff = poly2 -> coeff;
			poly2 = poly2 -> next;
		}

		else{

			poly3 -> expo = poly1 -> expo;
			poly3 -> coeff = poly1 -> coeff + poly2 -> coeff;
			poly1 = poly1 -> next;
			poly2 = poly2 -> next;
		}

		poly3 -> next = (POLY*)malloc(sizeof(POLY));
		poly3 = poly3 -> next;
		poly3 -> next = NULL;
	}

	while(poly1 -> next || poly2 -> next){

		if(poly1 -> next){

			poly3 -> expo = poly1 -> expo;
			poly3 ->coeff = poly1 -> coeff;
			poly1 = poly1 -> next;
		}

		if(poly2 -> next){

			poly3 -> expo = poly2 -> expo;
			poly3 -> coeff = poly2 -> coeff;
			poly2 = poly2 -> next;
		}

		poly3 -> next = (POLY*)malloc(sizeof(POLY));
		poly3 = poly3 -> next;
		poly3 -> next = NULL;
	}
}
