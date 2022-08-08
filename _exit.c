#include "shell.h"

/**
 * __exit - Terminates the program
 * @args: The enviroment list
 *
 * Return: 1 on failure
 */
int __exit(char **args)
{
	int code = 0;

	if (args != NULL && args[1] != NULL)
		code = _atoi(args[1]);

	_freeargs(args);
	exit(code);
	return (1);
}
