#include "main.h"

int _strlen(char *s);
int is_palindrome_recursive(char *s, int end, int i, int opp_i);

/**
 * is_palindrome - checks if a given string is a palindrome
 * @s: string
 *
 * Return: 1 is s is a palindrome. 0 otherwise
 */
int is_palindrome(char *s)
{
	int len = _strlen(s);

	/* an empty string is a palindrome */
	if (len == 0)
		return (1);

	/* check if s is a palindrome recursuvely */
	return (is_palindrome_recursive(s, len / 2, 0, len - 1));

}

/**
 * _strlen - finds the length of a string
 * @s: string
 *
 * Return: length of s
 */
int _strlen(char *s)
{
	if (*s == '\0')
		return (0);
	else
		return (1 + _strlen(s + 1));
}

/**
 * is_palindrome_recursive - checks if s is a palindrome recursively
 * @s: string
 * @end: index to end checks
 * @i: index to compare agains it's opposite
 * @opp_i: opposite index of i
 *
 * Return: 0 if any index does not match with its opposite(not palindrome)
 * return 1 if every index matches with it's opposite
 */
int is_palindrome_recursive(char *s, int end, int i, int opp_i)
{
	if (i >= end)
		return (1);
	else if (s[i] != s[opp_i])
		return (0);
	else
		return (is_palindrome_recursive(s, end, i + 1, opp_i - 1));
}
