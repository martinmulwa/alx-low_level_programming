#include "main.h"
#include <stdio.h>

int str_len(char *str);
int str_sub_cmp(char *src, char *target, int n);

/**
 * _strstr - locates a substring
 * @haystack: string to be checked
 * @needle: substring to be located in haystack
 *
 * Return: a pointer to the beginning of the located substring,
 * or NULL if the substring is not found
 */
char *_strstr(char *haystack, char *needle)
{
	char *first_loc = NULL;
	int len_str = str_len(haystack);
	int len_sub = str_len(needle);
	int i;

	for (i = 0; i <= (len_str - len_sub); i++)
	{
		/* compare the next len_sub characters with needle */
		if (str_sub_cmp(haystack + i, needle, len_sub))
		{
			first_loc = haystack + i;
			break;
		}
	}

	return (first_loc);
}


/**
 * str_len - gets the length of a given string
 * @str: given string
 *
 * Return: length of str
 */
int str_len(char *str)
{
	int length = 0;

	while (*str)
	{
		length++;
		str++;
	}

	return (length);
}


/**
 * str_sub_cmp - compares a subsection of an array against a given string
 * @src: the source string whose subsection is being checked
 * @target: the given string we are comparing against
 * @n: length of the subsection of src
 *
 * Return: 1 if the the subsection is equal to the string. 0 otherwise
 */
int str_sub_cmp(char *src, char *target, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		if (src[i] != target[i])
			return (0);
	}

	return (1);
}
