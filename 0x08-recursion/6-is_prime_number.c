#include "main.h"

int is_prime_recursive(int n, int i);

/**
 * is_prime_number - checks if a given number is prime
 * @n: number
 *
 * Return: 1 if the number is prime, otherwise 0
 */
int is_prime_number(int n)
{
	/* 2 is the smallest prime number */
	if (n < 2)
		return (0);
	else if (n % 2 == 0)
		return (0);

	/* check divisibility recursively */
	return (is_prime_recursive(n, 3));
}

/**
 * is_prime_recursive - checks if a number is prime recursively
 * @n: number
 * @i: number to test divisibility
 *
 * Return: 0 if n is divisible by any i until its square root. 1 otherwise.
 */
int is_prime_recursive(int n, int i)
{
	if (i * i > n)
		return (1);
	else if (n % i == 0)
		return (0);
	else
		return (is_prime_recursive(n, i + 2));
}
