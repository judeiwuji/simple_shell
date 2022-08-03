#include "shell.h"

/**
 * processcmd - Parse user input into command
 * @shell: The smd used to startup the shell
 * @str: User input
 * @argc: Argument count
 *
 * Return: int
 */
int processcmd(char *shell, char *str, int *argc)
{
	char **args;
	int (*cmd)(char **);
	int status = 0;

	args = parser(_trim(str), " ");
	if (args != NULL && args[0] != NULL)
	{
		cmd = get_builtins(args[0]);
		*argc = argsize(args) - 1;
		if (cmd != NULL)
			status = cmd(args);
		else
			status = execCmd(shell, args[0], args, environ);
	}
	_freeargs(args);
	return (status);
}
