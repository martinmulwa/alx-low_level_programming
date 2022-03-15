#include <stdio.h>

/**
 * main - prints the sum of the even-valued terms in fibonacci sequence,
 * followed by a new line
 *
 * Description: the terms in the Fibonacci sequence whose values
 * do not exceed 4,000,000
 *
 * Return: always 0
 */
int main(void)
{
	unsigned long fib1 = 1;
	unsigned long fib2 = 2;
	unsigned long fib = fib1 + fib2;
	unsigned long total = 2;

	while (fib <= 4000000)
	{
		/* check if fib is even and less than 4000000 */
		if (fib % 2 == 0)
			total += fib;

		/* re-assign fibs */
		fib1 = fib2;
		fib2 = fib;

		/* get next fib */
		fib = fib1 + fib2;
	}

	/* print total */
	printf("%lu\n", total);

	return (0);
}
