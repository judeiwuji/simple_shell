#include "shell.h"

/**
 * _tokenize - Tokenizes a string using a given delim
 * @str: The string
 * @delim: The Delimiter
 *
 * Return: char*
 */
char *_tokenize(char *str, char *delim)
{
	static char *data;
	char *res = NULL;
	int i = 0, len;
	int moves;

	if (str != NULL)
		data = str;

	if (data == NULL)
		return (NULL);
	while (data[0] != '\0')
	{
		moves = _delimcmp(data, delim);
		len = _strlen(res);
		if (moves != -1)
		{
			data = (data + moves);
			if (data && res == NULL)
			{
				res = _realloc(res, len, len + 2);
				res[i++] = ' ';
				res[i] = '\0';
			}
			break;
		}
		res = _realloc(res, len, len + 2);
		res[i++] = data[0];
		res[i] = '\0';
		++data;
	}
	return (res);
}

/**
 * _delimcmp - Checks if a string includes some part of
 * delim
 * @str: the string
 * @delim: the delimiter
 *
 * Return: index on success, otherwise -1
 */
int _delimcmp(char *str, char *delim)
{
	int found = 0, j, i;

	if (str == NULL || delim == NULL)
		return (-1);

	for (j = 0, i = 0; delim[j] != '\0'; j++)
	{
		if (str[i] == delim[j])
		{
			found = 1;
			++i;
		}

		if (str[i] != delim[j] && found == 1)
		{
			break;
			++i;
		}
	}
	if (found == 0)
		i = -1;
	return (i);
}
