#include "main.h"
#include <stdlib.h>
#include <stdio.h>

void print_str(char *str);
void print_num(char *str);
int is_valid_int(char *str);
int check_usage(int argc, char **argv);
unsigned int _strlen(char *s);
char *mult_str_c(char *str, char c);
char *add_str(char *s1, char *s2);
char *mult_str_n(char *str, int n);
void error_exit(void);
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
	char *num1, *num2, *result, *tmp_result1, *tmp_result2;
	unsigned int len1, len2, len, i, j;

	/* check correct usage */
	if (!check_usage(argc, argv))
		error_exit();

	num1 = argv[1];
	num2 = argv[2];
	len1 = _strlen(argv[1]);
	len2 = _strlen(argv[2]);
	len = len1 + len2 + 1;

	/* allocate space for result */
	result = create_str(len);
	if (result == NULL)
		error_exit();

	/* multiplication */
	for (i = len2, j = 0; i >= 1; i--, j++)
	{
		/* multiply the whole of num1 with the current digit of num2 */
		tmp_result1 = mult_str_c(num1, num2[i - 1]);

		/* multiply that result with 10 ^ j */
		tmp_result2 = mult_str_n(tmp_result1, j);
		free(tmp_result1);

		/* add that result to the current result */
		tmp_result1 = add_str(result, tmp_result2);
		free(tmp_result2);
		free(result);

		result = tmp_result1;
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
 * mult_str_c - multiplies an integer in a string
 * with a single digit as a character
 * @str: string representing integer
 * @c: character representing digit
 *
 * Return: string containing result
 */
char *mult_str_c(char *str, char c)
{
	unsigned int i;
	int carry = 0;
	char *result;
	unsigned int len = _strlen(str);
	int a, b, tmp;

	result = create_str(len + 1);
	if (result == NULL)
		return (NULL);

	for (i = len; i >= 1; i--)
	{
		a = c - '0';
		b = str[i - 1] - '0';

		tmp = a * b + carry;

		result[i] = (tmp % 10) + '0';
		carry = tmp / 10;
	}

	if (carry)
		result[i] = carry + '0';

	return (result);
}

/**
 * mult_str_n - multiplies an integer represented as a strings
 * with a given multiple of 10
 * @str: string representing integer
 * @n: integer representing multiple of 10
 *
 * Return: string containing result
 */
char *mult_str_n(char *str, int n)
{
	unsigned int len = _strlen(str);
	unsigned int i;
	char *result;

	/* allocate space for result */
	result = malloc(sizeof(char) * (len + n + 1));
	if (result == NULL)
		return (NULL);

	/* copy all the content of str into result */
	for (i = 0; i < len; i++)
		result[i] = str[i];

	/* write n zeroes from the end of str */
	for (; i < len + n; i++)
		result[i] = '0';

	result[i] = '\0';

	return (result);
}

/**
 * add_str - adds two strings that represent integers
 * @s1: 1st string
 * @s2: 2nd string
 *
 * Return: pointer to the result string
 */
char *add_str(char *s1, char *s2)
{
	unsigned int len1, len2, len3;
	unsigned int i, j, k;
	int a, b, c, d, carry;
	char *s3;

	len1 = _strlen(s1);
	len2 = _strlen(s2);
	len3 = (len1 >= len2 ? len1 : len2) + 1;

	/* allocate space for the result */
	s3 = create_str(len3);
	if (s3 == NULL)
		return (NULL);

	/* addition */
	for (i = len1, j = len2, k = len3, carry = 0; i >= 1 || j >= 1; k--)
	{
		a = (i >= 1) ? s1[i - 1] - '0' : 0;
		b = (j >= 1) ? s2[j - 1] - '0' : 0;
		c = s3[k - 1] - '0';
		d = a + b + c + carry;

		s3[k - 1] = (d % 10) + '0';
		carry = d / 10;

		i = (i >= 1) ? i - 1 : i;
		j = (j >= 1) ? j - 1 : j;
	}

	if (carry)
		s3[k - 1] = carry + '0';

	return (s3);
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
