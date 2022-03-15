#include "main.h"

/**
 * jack_bauer - prints every minute of the day of Jack Bauer,
 * starting from 00:00 to 23:59
 */
void jack_bauer(void)
{
	int i;
	int n;
	int hour;
	int minute;

	for (i = 0, n = 24 * 60; i < n; i++)
	{
		/* print hour digits*/
		hour = i / 60;
		_putchar('0' + (hour / 10));
		_putchar('0' + (hour % 10));

		_putchar(':');

		/* print minute digits*/
		minute = i % 60;
		_putchar('0' + (minute / 10));
		_putchar('0' + (minute % 10));

		_putchar('\n');
	}
}
