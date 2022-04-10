#include "main.h"
#include <stdlib.h>
#include <stdio.h>

void print_str(char *str);
void print_num(char *str);
int is_valid_int(char *str);
int check_usage(int argc, char **argv);
void error_exit(void);
unsigned int _strlen(char *s);
char *create_str(unsigned int len);

/**
 * main - multiplies two positive numbers
 * @argc: number of commandline arguments
 * @argv: array containing all commandline arguments
 *
 * Usage: mul num1 num2
 * - num1 and num2 will be passed in base 10
 * - Print the result, followed by a new line
 * - If the number of arguments is incorrect,
 * print Error, followed by a new line, and exit with a status of 98
 * - num1 and num2 should only be composed of digits.
 * If not, print Error, followed by a new line, and exit with a status of 98
 *
 * Return: 0 if successful. Otherwise 98
 */
int main(int argc, char **argv)
{
	char *num1, *num2, *result;
	unsigned int len1, len2, len, i, j, k;
	int dig1, dig2, dig, carry, tmp;

	/* check correct usage */
	if (!check_usage(argc, argv))
		error_exit();

	num1 = argv[1];
	num2 = argv[2];
	len1 = _strlen(num1);
	len2 = _strlen(num2);
	len = len1 + len2;

	/* allocate space for result */
	result = create_str(len);
	if (result == NULL)
		error_exit();

	/* multiplication */
	for (i = 1; i <= len1; i++)
	{
		carry = 0;
		k = i;
		for (j = 1; j <= len2; j++, k++)
		{
			dig1 = num1[len1 - i] - '0';
			dig2 = num2[len2 - j] - '0';
			dig =  result[len - k] - '0';

			tmp = (dig1 * dig2) + carry;
			carry = tmp / 10;
			result[len - k] = ((dig + (tmp % 10)) % 10) + '0';
			carry += ((dig + (tmp % 10)) / 10);
		}
		result[len - k] = carry + '0';
	}

	print_num(result);

	free(result);

	return (0);
}

/**
 * error_exit - prints "Error" followed by a newline and exits with code 98
 */
void error_exit(void)
{
	print_str("Error");
	exit(98);
}

/**
 * create_str - creates a string the given size and initializes it with 0s
 * @len: length of the string to create
 *
 * Return: pointer to created string if successful. Otherwise NULL
 */
char *create_str(unsigned int len)
{
	char *result;
	unsigned int i;

	/* allocate space for result */
	result = malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);

	/* initialize result with zeroes */
	for (i = 0; i < len; i++)
		result[i] = '0';

	result[len] = '\0';

	return (result);
}

/**
 * print_str - prints a string using _putchar, followed a new line
 * @str: string to print
 */
void print_str(char *str)
{
	unsigned int i;

	if (str == NULL)
		return;

	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);

	_putchar('\n');
}

/**
 * print_num - prints a integer using _putchar, followed a new line
 * @str: string representing integer
 * skips initial 0s
 */
void print_num(char *str)
{
	unsigned int i;
	unsigned int len = _strlen(str);
	int found_int = 0;

	if (str == NULL)
		return;

	/* skip initial 0s */
	for (i = 0; i < len - 1; i++)
	{
		if (!found_int && str[i] != '0')
			found_int = 1;
		if (found_int)
			_putchar(str[i]);
	}

	/* print last character */
	_putchar(str[i]);

	_putchar('\n');
}

/**
 * is_valid_int - checks if given string is a valid integer
 * @str: string to be checked
 *
 * Return: 1 if str is a valid integer. 0 Otherwise.
 */
int is_valid_int(char *str)
{
	if (*str == '\0')
		return (0);

	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);

		str++;
	}

	return (1);
}

/**
 * check_usage - checks correct usage for the program
 * @argc: number of commandline arguments
 * @argv: array of commandline arguments
 *
 * Return: 1 if correct usage. 0 Otherwise
 */
int check_usage(int argc, char **argv)
{
	if (argc != 3)
		return (0);

	if (!(is_valid_int(argv[1]) && is_valid_int(argv[2])))
		return (0);

	return (1);
}



/**
 * _strlen - finds the length of a string
 * @s: address of first character in the string
 *
 * Return: length of the string
 */
unsigned int _strlen(char *s)
{
	unsigned int length = 0;

	while (*s)
	{
		length++;
		s++;
	}

	return (length);
}
