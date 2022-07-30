#include "main.h"

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
	int i = 0;

	if (str == NULL)
		return (NULL);

	parsed = malloc(sizeof(char *));
	if (parsed == NULL)
		return (NULL);

	token = strtok(str, delim);
	while (token != NULL)
	{
		parsed[i] = malloc(sizeof(char) * _strlen(token));
		if (parsed[i] == NULL)
		{
			free(parsed);
			return (NULL);
		}
		parsed[i++] = token;
		token = strtok(NULL, delim);
	}
	if (parsed[0] != NULL && delim[0] == ' ')
		parsed[0] = getCmdPath(parsed[0]);
	parsed[++i] = NULL;
	return (parsed);
}
