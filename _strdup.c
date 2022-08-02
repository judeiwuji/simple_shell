#include "shell.h"

/**
 *  _strdup - Duplicates a string
 * @str: The string
 *
 * Return: The duplicate
 */
char *_strdup(char *str)
{
	char *dup;

	if (str == NULL)
		return (NULL);

	dup = malloc(sizeof(char) * _strlen(str) + 1);
	if (dup == NULL)
		return (NULL);
	dup = _strcpy(dup, str);
	return (dup);
}
