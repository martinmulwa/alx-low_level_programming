#include "main.h"

void print_num(int n);

/**
 * print_times_table - prints the n times table, starting with 0
 * @n: number whose times table to print
 *
 * Description: If n is greater than 15 or less than 0
 * the function should not print anything
 */
void print_times_table(int n)
{
	int row;
	int col;
	int num;

	if (n > 15 || n < 0)
		return;

	for (row = 0; row < n + 1; row++)
	{
		for (col = 0; col < n + 1; col++)
		{
			num = row * col;

			/* print num */
			if (col > 0)
				print_num(num);
			else
				_putchar('0' + num);

			/* print separator */
			if (col == n)
			{
				_putchar('\n');
			}
			else
			{
				_putchar(',');
				_putchar(' ');
			}
		}
	}
}


/**
 * print_num - prints n using _putchar
 * @n: number to be printed
 *
 * Description:
 * only works for n >= 0 or n <= 999
 */
void print_num(int n)
{
	/* print 3-digit number */
	if (n > 99)
	{
		_putchar('0' + (n / 100));
		_putchar('0' + ((n / 10) % 10));
		_putchar('0' + (n % 10));
	}

	/* print 2-digit number */
	else if (n > 9)
	{
		_putchar(' ');
		_putchar('0' + (n / 10));
		_putchar('0' + (n % 10));
	}

	/* print 1-digit number */
	else
	{
		_putchar(' ');
		_putchar(' ');
		_putchar('0' + n);
	}
}
