#include "dog.h"
#include <stdlib.h>

int _strlen(char *str);
char *_strcpy(char *str);

/**
 * new_dog - creates a new dog
 * @name: name of dog as string
 * @age: age of the dog as float
 * @owner: owner of the dog as string
 *
 * Return: pointer to the created dog. Otherwise NULL
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *dog;

	/* allocate space for new dog */
	dog = malloc(sizeof(dog_t));
	if (dog == NULL)
		return (NULL);

	/* initialize name field */
	dog->name = _strcpy(name);
	if (dog->name == NULL)
	{
		free(dog);
		return (NULL);
	}

	/* initialize age field */
	dog->age = age;

	/* initialize owner field */
	dog->owner = _strcpy(owner);
	if (dog->owner == NULL)
	{
		free(dog->name);
		free(dog);
		return (NULL);
	}

	return (dog);
}

/**
 * _strcpy - creates a copy of a string
 * @str: string to be copied
 *
 * Return: pointer to the new string. Otherwise NULL
 */
char *_strcpy(char *str)
{
	int length = _strlen(str);
	int i;
	char *copy;

	/* allocate space for the new string */
	copy = malloc(length + 1);
	if (copy == NULL)
		return (NULL);

	/* copy every character from str to new string */
	for (i = 0; i < length; i++)
		copy[i] = str[i];

	copy[i] = '\0';

	return (copy);
}

/**
 * _strlen - finds the length of a given string
 * @str: string whose length to calculate
 *
 * Return: length of str
 */
int _strlen(char *str)
{
	int length = 0;

	while (*str)
	{
		length++;
		str++;
	}

	return (length);
}
