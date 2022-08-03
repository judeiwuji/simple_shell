#include "shell.h"

/**
 * _env - Executes the env built command
 * @args: The enviroment list
 *
 * Return: 0 on success
 */
int _env(char **args __attribute__((unused)))
{
	int i;
	char *s;

	for (i = 0; environ[i] != NULL; i++)
	{
		s = environ[i];
		write(1, s, _strlen(s));
		write(1, "\n", 1);
	}
	return (0);
}
