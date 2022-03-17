#include "main.h"

/**
 * print_number - prints an integer using _putchar(using recursion)
 * @n: integer to be printed
 *
 */
void print_number(int n)
{
    /* print '-' in front of -ve integers and ensure n is +ve*/
	if (n < 0)
	{
		_putchar('-');
		n *= -1;
	}

	if (n >= 10)
		print_number(n / 10);

	_putchar('0' + (n % 10));

}
