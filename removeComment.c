#include "shell.h"

/**
 * removeComment - Removes comments from a string
 * @str: the string containing the commands
 *
 * Return: string without comments
 */
char *removeComment(char *str)
{
	char *stripped = NULL;
	int i = 0, len;

	if (str == NULL)
		return (NULL);
	stripped = _realloc(stripped, 0, 2);
	for (i = 0; str[i] != '\0' && str[i] != '#'; i++)
	{
		len = i + 1;
		stripped[i] = str[i];
		stripped[len] = '\0';
		stripped = _realloc(stripped, len, len + 2);
	}
	return (stripped);
}
