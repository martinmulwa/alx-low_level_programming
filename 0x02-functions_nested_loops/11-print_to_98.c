#include "main.h"
#include <stdio.h>

/**
 * print_to_98 -   prints all natural numbers from n to 98
 * @n: number to print from
 *
 * Description:
 * Numbers must be separated by a comma, followed by a space
 * Numbers should be printed in order
 * The first printed number should be the number passed to your function
 * The last printed number should be 98
 */
void print_to_98(int n)
{
	while (n != 98)
	{
		/* print n */
		printf("%d", n);

		/* print separator */
		printf(", ");

		if (n < 98)
			n++;
		else
			n--;
	}

	printf("%d\n", n);
}
