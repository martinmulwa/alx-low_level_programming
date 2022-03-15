#include "main.h"

/**
 * times_table - prints the 9 times table, starting with 0
 */
void times_table(void)
{
	int row;
	int col;
	int num;

	for (row = 0; row < 10; row++)
	{
		for (col = 0; col < 10; col++)
		{
			num = row * col;

			/* print num */
			if (num < 10)
			{
				_putchar(' ');
				_putchar('0' + num);
			}
			else
			{
				_putchar('0' + (num / 10));
				_putchar('0' + (num % 10));
			}

			/* print separator */
			if (col == 9)
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
