#include "shell.h"

/**
 * _strstart - Checks if s1 has s2 at its beginning
 * @s1: The string
 * @s2: Sun string of s1 to be checked
 *
 * Return: 1 if true, 0 otherwise
 */
int _strstart(char *s1, char *s2)
{
	char *sub;
	int len, i, match = 0;

	if (s1 == NULL || s2 == NULL)
		return (0);

	len = _strlen(s2);
	sub = malloc(sizeof(char) * len + 1);
	if (sub == NULL)
		return (0);

	for (i = 0; i < len && s1[i] != '\0'; i++)
		sub[i] = s1[i];
	sub[i] = '\0';
	if (_strcmp(sub, s2) == 0)
		match = 1;
	free(sub);
	return (match);
}
