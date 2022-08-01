#include "shell.h"

/**
 * _strcmp - compares two strings.
 * @s1: the first string
 * @s2: the second string
 *
 * Return: int
 */
int _strcmp(char *s1, char *s2)
{
	int res, i, len1, len2;

	len1 = _strlen(s1);
	len2 = _strlen(s2);
	res = 0;
	i = 0;

	if (s1 == NULL || s2 == NULL)
		return (-1);

	if (len1 < len2)
		res = -1;
	else if (len1 > len2)
		res = 1;
	else
	{
		for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
		{
			if (s1[i] != s2[i])
			{
				res = -1;
				break;
			}
		}
	}

	return (res);
}
