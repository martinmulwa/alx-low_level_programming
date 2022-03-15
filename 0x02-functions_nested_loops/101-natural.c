#include <stdio.h>

/**
 * main - computes and prints the sum of all the multiples
 * of 3 or 5 below 1024
 *
 * Return: always 0
 */
int main(void)
{
	int total = 0;
	int i = 0;

	while (i < 1024)
	{
		if ((i % 3 == 0) || (i % 5) == 0)
			total += i;

		i++;
	}

	printf("%d\n", total);

	return (0);
}
