#include "shell.h"

/**
 * _getenv - Gets the specified environment key
 * @k: The key to get
 *
 * Return: char*
 */
char *_getenv(char *k)
{
	char *data, *token, *env;
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		env = _strdup(environ[i]);
		token = _strtok(env, "=");
		if (token != NULL && _strcmp(token, k) == 0)
		{
			data = _strtok(NULL, "=");
			return (data);
		}
	}
	return (NULL);
}
