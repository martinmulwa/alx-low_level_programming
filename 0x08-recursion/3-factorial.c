#include "main.h"

/**
 * factorial - finds the factorial of a given number
 * @n: number
 *
 * Return: -1 if n is -ve. Otherwise return factorial of n
 */
int factorial(int n)
{
	if (n < 0)
		return (-1);
	else if (n == 0)
		return (1);
	else
		return (n * factorial(n - 1));
}
