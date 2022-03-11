#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/**
 * main - Print last digit of the number stored in n
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	/* generate random number */
	int n;
	int i;

	srand(time(0));
	n = rand() - RAND_MAX / 2;

	/* get last digit of n */
	i = n % 10;

	printf("Last digit of %d is %d ", n, i);

	if (i > 5)
		printf("and is greater than 5\n");
	else if (i == 0)
		printf("and is 0\n");
	else if (i < 6)
		printf("and is less than 6 and not 0\n");

	return (0);
}
