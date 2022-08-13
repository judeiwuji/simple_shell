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
	int hasQoute = 0;
	char c, prev_c = ' ';
	char quote;

	if (str == NULL)
		return (NULL);
	stripped = _realloc(stripped, 0, 2);
	c = str[i];
	for (i = 0; c != '\0'; i++)
	{
		c = str[i];
		if (hasQoute == 1 && c == quote)
			hasQoute = 0;
		if (hasQoute == 0)
		{
			hasQoute = c == '"' || c == '\'';
			quote = c;
		}
		if (c == '#' && prev_c == ' ' && !hasQoute)
			break;
		len = i + 1;
		stripped[i] = str[i];
		stripped[len] = '\0';
		stripped = _realloc(stripped, len, len + 2);
		prev_c = c;
	}
	return (stripped);
}
