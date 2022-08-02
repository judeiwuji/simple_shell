#include "shell.h"

/**
 * free_env - Frees the the environment copy.
 */

void free_env(void)
{
	int index;

	for (index = 0; environ[index]; index++)
		free(environ[index]);
	free(environ);
}
