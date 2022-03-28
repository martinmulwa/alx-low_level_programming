#include "main.h"
#include <stdio.h>

/**
 * print_diagsums -  prints the sum of the two diagonals
 * of a square matrix of integers
 * @a: square matrix of integers
 * @size: size of the given square matrix
 */
void print_diagsums(int *a, int size)
{
	int i;
	unsigned int sum1 = 0;
	unsigned int sum2 = 0;

	for (i = 0; i < size; i++)
	{
		sum1 += a[(size * i) + i];
		sum2 += a[(size * (i + 1)) - (i + 1)];
	}

	printf("%u, %u\n", sum1, sum2);
}
