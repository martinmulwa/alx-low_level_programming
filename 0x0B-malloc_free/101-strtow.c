#include "main.h"
#include <stdlib.h>

unsigned int _strlen(char *s);
int add_word(unsigned int start, unsigned int end, char *src,
			unsigned int i, char **words);
void free_words(char **words, unsigned int n);
unsigned int count_words(char **words);


/**
 * strtow - splits a string into words
 * @str: string to be split
 *
 * Each element of this array should contain a single word, null-terminated
 * The last element of the returned array should be NULL
 * Words are separated by spaces
 *
 * Return: a pointer to the resulting array of strings (words)
 * returns NULL if str == NULL or str == ""
 * if your function fails, it should return NULL
 */
char **strtow(char *str)
{
	char **words;
	unsigned int length = (str == NULL) ? 0 : _strlen(str);
	int found_word = 0;
	unsigned int word_len = 0;
	unsigned int i;
	unsigned int word_count = 0;

	/* returns NULL if str == NULL or str == "" */
	if (length == 0)
		return (NULL);

	/* allocate space for new array */
	words = (char **)malloc(sizeof(char *) * length);
	if (words == NULL)
		return (NULL);

	/* iterate over every character in str */
	for (i = 0; i < length; i++)
	{
		/* if you find a space and you have found a word */
		if (str[i] == ' ' && found_word)
		{
			/* add the new word to words */
			if (add_word(i - word_len, i, str, word_count, words))
			{
				/* increase word_count and reset found_word*/
				word_count++;
				found_word = 0;
			}
			else
			{
				return (NULL);
			}
		}
		/* if you find a non-space and you have not found a word */
		else if (str[i] != ' ' && !found_word)
		{
			word_len = 1;
			found_word = 1;
		}
		/* if you find a non-space and you have found a word */
		else if (str[i] != ' ' && found_word)
		{
			word_len++;
		}
	}

	/* add the last word */
	if (found_word)
	{
		if (add_word(i - word_len, i, str, word_count, words))
		{
			/* increase word_count and reset found_word*/
			word_count++;
			found_word = 0;
		}
		else
		{
			return (NULL);
		}
	}

	/* set the last word to NULL */
	words[word_count] = NULL;

	return (NULL);
}

/**
 * _strlen - finds the length of a string
 * @s: address of first character in the string
 *
 * Return: length og the string
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

/**
 * add_word - adds substring from a string to an array of strings
 * @start: starting index in the of the substring
 * @end: ending index of the substring
 * @src: source string
 * @i: index in which to add the substring into the array of strings
 * @words: array of strings to add substring into
 *
 * Return: 1 if successfull. 0 otherwise.
 */
int add_word(unsigned int start, unsigned int end, char *src,
			unsigned int i, char **words)
{
	unsigned int length = end - start;
	unsigned int j, k;

	/* allocate space for the new string */
	words[i] = malloc(sizeof(char) * (length + 1));
	if (words[i] == NULL)
	{
		if (i)
			free_words(words, i - 1);
		else
			free(words);

		return (0);
	}

	/* copy substring into words */
	for (j = 0, k = start; j < length; j++, k++)
		words[i][j] = src[k];

	return (1);
}

/**
 * free_words - frees an array of strings that was created dynamically
 * @words: array to be freed
 * @n: number of words in the array
 */
void free_words(char **words, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		free(words[i]);

	free(words);
}

/**
 * count_words - counts the number of words in a given array
 * @words: array
 *
 * Return: number of words in array
 */
unsigned int count_words(char **words)
{
	unsigned int i;

	while (words[i] != NULL)
		i++;

	return (i);
}
