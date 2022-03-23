#include "main.h"

/**
* leet -  encodes a string into 1337
* @str: string to encode
*
* Return: pointer to encoded str
*/
char *leet(char *str)
{
	/* conversion tables */
	char letters[] = {'a', 'e', 'o', 't', 'l'};
	int values[] = {4, 3, 0, 7, 1};

	int i;
	int j;
	int n = sizeof(letters) / sizeof(letters[0]);

	for (i = 0; str[i] != '\0'; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (str[i] == letters[j] || str[i] == letters[j] - 32)
				str[i] = values[j] + '0';
		}
	}

	return (str);
}
