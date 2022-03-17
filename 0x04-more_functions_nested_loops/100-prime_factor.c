#include <stdio.h>

/**
 * main -  prints the largest prime factor of the number 612852475143,
 * followed by a new line
 *
 * Return: Always 0.
 */
int main(void)
{
	long n = 612852475143;
	long max_factor = -1;
	int i;

	/* check if n is divisible by 2 */
	while (n % 2 == 0)
	{
		max_factor = 2;
		n /= 2;
	}

	for (i = 3; i * i <= n; i += 2)
	{
		/* check if n is divisible by i */
		while (n % i == 0)
		{
			max_factor = i;
			n /= i;
		}
	}

	if (n > max_factor)
		max_factor = n;

	printf("%li\n", max_factor);

	return (0);
}
