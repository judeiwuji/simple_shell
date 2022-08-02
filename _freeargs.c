#include "shell.h"

/**
 * _freeargs - Free the memory alloctaed to args
 * @args: The argument list
 *
 * Return: void
 */
void _freeargs(char **args)
{
	int i;

	if (args == NULL)
		return;
	for (i = 0; args[i] != NULL; i++)
		free(args[i]);
	free(args);
}
