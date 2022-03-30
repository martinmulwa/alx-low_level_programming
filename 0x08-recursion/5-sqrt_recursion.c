#include "main.h"

int sqrt_bisection(int n, int guess, int lower, int upper);

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: number
 *
 * Return: -1 if n doesn't have a natural square root.
 * Otherwise return the square root of n
 */
int _sqrt_recursion(int n)
{
	int guess = n / 2;

	return (sqrt_bisection(n, guess, 0, n));
}

/**
 * sqrt_bisection - calculates square root recursively using bisection search
 * @n: number whose square root to calculate
 * @guess: guess on the square root
 * @lower: lower boundary of search space
 * @upper: upper boundary of search space
 *
 * Return: natural square root of n. Otherwise -1 if it doesn't exist
 */
int sqrt_bisection(int n, int guess, int lower, int upper)
{
	int square = guess * guess;

	if (square == n)
		return (guess);
	else if (upper - lower <= 1)
		return (-1);

	/* generate new guess */
	if (square < n)
		return (sqrt_bisection(n, ((upper + lower) / 2), guess, upper));
	else
		return (sqrt_bisection(n, ((upper + lower) / 2), lower, guess));
}
