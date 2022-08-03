#include "shell.h"

/**
 * parser - Parses the input and seperate it into
 * command and args
 * @str: The string to be parsed
 * @delim: The delimiter which can either be space or pipe
 *
 * Return: an array of pointers, the first is the command
 */
char **parser(char *str, char *delim)
{
	char *token;
	char **parsed;
	int i = 0, size;

	if (str == NULL)
		return (NULL);
	size = get_parsed_size(str, delim);
	parsed = malloc(sizeof(char *) * size + sizeof(NULL));
	if (parsed == NULL)
		return (NULL);

	token = _strtok(str, delim);
	while (token != NULL)
	{
		parsed[i] = malloc(sizeof(char) * _strlen(token));
		if (parsed[i] == NULL)
		{
			free(parsed);
			return (NULL);
		}
		parsed[i++] = token;
		token = _strtok(NULL, delim);
	}
	if (parsed[0] != NULL && delim[0] == ' ')
	{
		if (str[0] != '/' || (str[0] != '.' && str[1] != '/'))
			parsed[0] = getCmdPath(parsed[0]);
	}
	parsed[i] = NULL;
	return (parsed);
}

/**
 * get_parsed_size - Gets the size to be allocated to parsed
 * @str: The string to be parsed
 * @delim: the delimiter
 *
 * Return: int
 */
int get_parsed_size(char *str, char *delim)
{
	char *s, *token;
	int size = 0;

	if (str == NULL)
		return (0);
	s = _strdup(str);
	token = _strtok(s, delim);
	while (token != NULL)
	{
		size++;
		token = _strtok(NULL, delim);
	}
	free(s);
	return (size);
}
