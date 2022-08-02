#include "shell.h"

/**
 * processcmd - Parse user input into command
 * @shell: The smd used to startup the shell
 * @str: User input
 */
void processcmd(char *shell, char *str)
{
	char **args;
	void (*cmd)(char **);

	args = parser(_trim(str), ' ');
	if (args != NULL && args[0] != NULL)
	{
		cmd = get_builtins(args[0]);
		if (cmd != NULL)
			cmd(args);
		else
			execCmd(shell, args[0], args, environ);
	}
	_freeargs(args);
}
