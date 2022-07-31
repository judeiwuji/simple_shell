#include "shell.h"

/**
 * main - A simple shell program
 * @argc: The total arguments
 * @argv: List of arguments passed to main
 * @env: List of key value environment variables
 *
 * Return: 0
 */
int main(int argc __attribute__((unused)), char **argv, char **env)
{
	char **args;
	char *str;
	int mode = 1;

	while (mode)
	{
		str = NULL;
		prompt(&str, &mode);
		args = parser(_trim(str), " ");
		if (args != NULL && args[0] != NULL)
			execCmd(argv[0], args[0], args, env);
		_freeargs(args);
	}
	return (0);
}
