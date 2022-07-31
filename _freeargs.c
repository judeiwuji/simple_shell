#include "shell.h"

/**
 * _freeargs - Free the memory alloctaed to args
 * @args: The argument list
 *
 * Return: void
 */
void _freeargs(char **args)
{
	if (args == NULL)
		return;
	if (args[0] != NULL)
		free(args[0]);
	free(args);
}
