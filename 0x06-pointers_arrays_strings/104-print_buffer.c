#include "main.h"
#include <stdio.h>

void copy_sub(char *dest, char *src, int n);
void print_sub_hex(char *b, int n);
void print_sub_str(char *str, int n);

/**
* print_buffer - prints a buffer
* @b: pointer to the buffer
* @size: number of bytes of the buffer to print
*/
void print_buffer(char *b, int size)
{
	int i = 0;
	int max_cpy;
	char sub_b[11];

	while (i < size)
	{
		printf("%08x: ", i);

		/* copy max 10 bytes from b to sub_b */
		max_cpy = (size - i) >= 10 ? 10 : (size - i);
		copy_sub(sub_b, (b + i), max_cpy);

		/* prints hex values of the characters in the specified order */
		print_sub_hex(sub_b, max_cpy);

		/* print sub_b as string */
		print_sub_str(sub_b, max_cpy);

		printf("\n");

		i += max_cpy;

	}

	if (size <= 0)
		printf("\n");

}

/**
* copy_sub - copies a string
* @dest: string to copy to
* @src: string to copy from
* @n: maximum number of characters to copy from src
*/
void copy_sub(char *dest, char *src, int n)
{
	int i;

	/* copy at most n characters to dest */
	for (i = 0; i < n; i++)
		dest[i] = src[i];

}

/**
* print_sub_hex - prints bytes of a given buffer in hex format
* @b: pointer to the buffer to print from
* @n: number of bytes to print
*
* Definition: pad with spaces to ensure even width
*/
void print_sub_hex(char *b, int n)
{
	int i;
	int width = 10;

	for (i = 0; i < width; i += 2)
	{
		/*printf("i: %d, n: %d, width: %d\n", i, n, width);*/
		if (i >= n)
		{
			printf("    ");
		}
		else
		{
			printf("%02x", b[i]);
			if (i + 1 < n)
			{
				printf("%02x", b[i + 1]);
			}
			else
			{
				printf("  ");
			}
		}

		printf(" ");
	}
}

/**
* print_sub_str - prints n printable characters in given string
* @str: string to printf
* @n: number of characters in string to print
*/
void print_sub_str(char *str, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		if (str[i] >= 32 && str[i] <= 126)
			printf("%c", str[i]);
		else
			printf(".");
	}
}
