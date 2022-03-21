#include "main.h"
#include <stdio.h>

/**
 * print_array - prints n elements of an array of integers,
 * followed by a new line
 * @a: address of the first ellement in the array
 * @n: number of first lelements to print in the given array
 *
 * Description:
 * Numbers must be separated by comma, followed by a space
 * The numbers should be displayed in the same order
 * as they are stored in the array
 * assume the given n is less than the length of the array
 */
void print_array(int *a, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		printf("%d", *(a + i));

		if (i < n - 1)
			printf(", ");
	}

	printf("\n");
}
