#include "shell.h"

/**
 * _reverse_str - Reverses a string
 * @str: The string to be reversed
 *
 * Return: (pointer)
 */
char *_reverse_str(char *str)
{
	int len, i, j;
	char *reverse;

	len = _strlen(str);

	if (len == 0)
		return (reverse);

	reverse = malloc(sizeof(char) * len + 1);
	if (reverse != NULL)
	{
		for (i = len - 1, j = 0; i >= 0; i--, j++)
			reverse[j] = str[i];
		reverse[j] = '\0';
	}
	return (reverse);
}
