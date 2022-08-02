#include "shell.h"

/**
 * cd - Changes directory
 * @args:
 */
void cd(char **args)
{
	int size;
	char *path, *arg;

	if (args == NULL)
	{
		write(1, "no arguments\n", 14);
		return;
	}
	size = argsize(args);
	if (size > 2)
	{
		write(1, "too many arguments\n", 20);
		return;
	}

	arg = args[1];
	if (size == 1 || _strcmp(arg, "~") == 0)
		path = _getenv("HOME");
	else if (_strcmp(arg, "-") == 0)
		path = _getenv("OLDPWD");
	else
		path = args[1];

	if (chdir(path) < 0)
		write(1, "No such file or directory\n", 26);
}
