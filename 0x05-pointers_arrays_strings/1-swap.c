#include "main.h"

/**
 * swap_int - swaps the values of 2 integers
 * @a: address of first integer
 * @b: address of second integer
 */
void swap_int(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
