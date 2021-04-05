#include<stdio.h>

int ndisk;
char source, temp, dest;

void tofh(int ndisk, char source, char temp, char dest);

void main() {

	source = 'A', temp = 'B', dest = 'C';

	printf("\nEnter number of disks: ");
	scanf("%d", &ndisk);
	printf("\nThe sequence is:\n");
	tofh(ndisk, source, temp, dest);
}

void tofh(int ndisk, char source, char temp, char dest) {

	if (ndisk == 1){
		printf("\nMove disk %d from %c to %c\n", ndisk, source, dest);
		return;
	}

	tofh((ndisk - 1), source, dest, temp);
	printf("\nMove disk %d from %c to %c\n", ndisk, source, dest);
	tofh((ndisk - 1), temp, source, dest);
}