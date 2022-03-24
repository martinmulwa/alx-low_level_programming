#include "main.h"

/**
* rot13 -  encodes a string using rot13
* @str: string to be encoded
*
* Return: pointer to the encoded string
*/
char *rot13(char *str)
{
	int i;
	int j;

	for (i = 0; str[i] != '\0'; i++)
	{
		for (j = 0; j < 26; j++)
		{
			if ((str[i] - 65 == j) || (str[i] - 97 == j))
			{
				str[i] = (str[i] - j) + ((j + 13) % 26);
				break;
			}
		}
	}

	return (str);
}
