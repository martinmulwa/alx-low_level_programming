#include "main.h"

int sqrt_linear(int n, int guess);

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: number
 *
 * Return: -1 if n doesn't have a natural square root.
 * Otherwise return the square root of n
 */
int _sqrt_recursion(int n)
{
	return (sqrt_linear(n, 0));
}

/**
 * sqrt_linear - calculates square root recursively using linear search
 * @n: number whose square root to calculate
 * @guess: guess on the square root
 *
 * Return: natural square root of n. Otherwise -1 if it doesn't exist
 */
int sqrt_linear(int n, int guess)
{
	int square = guess * guess;

	if (square == n)
		return (guess);
	else if (square > n)
		return (-1);
	else
		return (sqrt_linear(n, guess + 1));
}
