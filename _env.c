#include "shell.h"

/**
 * _env - Executes the env built command
 * @env: The enviroment list
 *
 * Return: void
 */
void _env(char **env)
{
	int i;
	char *s;

	if (env == NULL)
		return;
	for (i = 0; env[i] != NULL; i++)
	{
		s = env[i];
		write(1, s, _strlen(s));
		write(1, "\n", 1);
	}
}
