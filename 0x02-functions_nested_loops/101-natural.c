#include "main.h"
#include <stdio.h>

/**
 * print_sum_multiples - computes and prints the sum of all the multiples
 * of 3 or 5 below 1024
 */
void print_sum_multiples(void)
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
}
