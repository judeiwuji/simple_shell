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
	char *token, *s, *temp;
	char **parsed;
	int i = 0, size;

	if (str == NULL)
		return (NULL);
	size = get_parsed_size(str, delim);
	parsed = malloc(sizeof(char *) * size + sizeof(NULL));
	if (parsed == NULL)
		return (NULL);
	s = _strdup(str);
	token = _tokenize(s, delim);
	while (token != NULL)
	{
		if (_strcmp(token, " ") != 0)
			parsed[i++] = token;
		token = _tokenize(NULL, delim);
	}
	if (parsed[0] != NULL && delim[0] == ' ')
	{
		if (!_strstart(str, "/") && !_strstart(str, "./"))
		{
			temp = getCmdPath(parsed[0]);
			if (_strcmp(temp, parsed[0]) != 0)
			{
				free(parsed[0]);
				parsed[0] = temp;
			}
		}
	}
	parsed[i] = NULL;
	free(s);
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
	token = _tokenize(s, delim);
	while (token != NULL)
	{
		size++;
		free(token);
		token = _tokenize(NULL, delim);
	}
	free(s);
	return (size);
}
