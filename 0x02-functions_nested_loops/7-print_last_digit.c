#include "main.h"

/**
 * print_last_digit - prints the last digit of a number
 * @n: number to be computed on
 *
 * Return: value of the last digit
 */
int print_last_digit(int n)
{
	int num = n % 10;

	num = (num < 0) ? (num * -1) : num;
	_putchar(num + '0');

	return (num);
}
