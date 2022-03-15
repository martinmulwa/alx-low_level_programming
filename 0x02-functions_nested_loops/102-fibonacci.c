#include <stdio.h>

/**
 * main - prints the first 50 Fibonacci numbers, starting with 1 and 2,
 * followed by a new line
 *
 * Description:
 * The numbers must be separated by comma, followed by a space
 *
 * Return: always 0
 */
int main(void)
{
	unsigned long fib1 = 1;
	unsigned long fib2 = 2;
	unsigned long fib;
	int i = 2;

	/* print first 2 fibs */
	printf("%lu, ", fib1);
	printf("%lu, ", fib2);

	while (i < 50)
	{
		/* print next fib */
		fib = fib1 + fib2;
		printf("%lu, ", fib);

		/* re-assign fibs */
		fib1 = fib2;
		fib2 = fib;

		i++;
	}

	/* print last fib */
	printf("%lu\n", fib1 + fib2);

	return (0);
}
