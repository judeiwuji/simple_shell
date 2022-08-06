#include "shell.h"

/**
 * processcmd - Parse user input into command
 * @shell: The smd used to startup the shell
 * @str: User input
 * @var: shell variables
 *
 * Return: int
 */
int processcmd(char *shell, char *str, shell_var_t *var)
{
	char **args;
	int (*cmd)(char **);

	str = replace_var(_trim(str), var);
	args = parser(_trim(str), " ");
	if (args != NULL && args[0] != NULL)
	{
		cmd = get_builtins(args[0]);
		var->argc = argsize(args) - 1;
		if (cmd != NULL)
			var->code = cmd(args);
		else
			var->code = execCmd(shell, args[0], args, environ);
	}
	_freeargs(args);
	return (var->code);
}
