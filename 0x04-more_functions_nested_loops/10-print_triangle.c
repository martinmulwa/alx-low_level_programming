#include "main.h"

/**
* print_triangle - draws a triangle of length size in the terminal
* followed by a new line
* @size: the size of the triangle
*
* Description: If size is 0 or less, the function should print only a new line
*/
void print_triangle(int size)
{
	int i;
	int j;
	int k;

	for (i = 0; i < size; i++)
	{
		/* print ' ' n - (i + 1) times */
		for (j = 0; j < (size - (i + 1)); j++)
			_putchar(' ');

		/* print '#' (i + 1) times*/
		for (k = 0; k < (i + 1); k++)
			_putchar('#');

		_putchar('\n');
	}

	if (size <= 0)
		_putchar('\n');
}
