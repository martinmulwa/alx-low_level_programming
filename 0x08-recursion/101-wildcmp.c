#include "main.h"
#include <stdio.h>

/**
 * wildcmp - compares two strings
 * @s1: 1st string
 * @s2: 2nd string
 *
 * Description:
 * s2 can contain the special character *
 * The special char * can replace any string (including an empty string)
 *
 * Return: 1 if the strings can be considered identical, otherwise return 0
 */
int wildcmp(char *s1, char *s2)
{
	/* base case: when both strings are empty */
	if (*s1 == '\0' && *s2 == '\0')
		return (1);

	/* compare the current characters */
	if (*s1 == *s2)
	{
		return (wildcmp(s1 + 1, s2 + 1));
	}
	/* if the current characters are not the same */
	else if (*s2 != '*')
	{
		return (0);
	}
	/* if the current character of s2 is '*' */
	else
	{
		/* find the next character in s2 that is not '*' */
		while (*s2 == '*')
			s2++;

		/* if you reach the end of s2 then the strings match */
		if (*s2 == '\0')
			return (1);

		/* move to that character in s1 */
		while (*s1 != *s2 && *s1 != '\0')
			s1++;

		/* if you reach the end of s1 then it's not a match */
		if (*s1 == '\0')
			return (0);

		/* now continue comparing characters */
		return (wildcmp(s1 + 1, s2 + 1));

	}

}
