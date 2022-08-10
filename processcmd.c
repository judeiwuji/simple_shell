#include "shell.h"

/**
 * processcmd - Parse user input into command
 * @str: User input
 * @var: shell variables
 *
 * Return: int
 */
int processcmd(char *str, shell_var_t *var)
{
	char **args, *s, *trimmed;
	int (*cmd)(char **);

	trimmed = _trim(str);
	s = replace_var(trimmed, var);
	free(str);
	free(trimmed);
	trimmed = _trim(s);
	args = parser(trimmed, " ");
	free(s);
	free(trimmed);
	if (args != NULL && args[0] != NULL)
	{
		cmd = get_builtins(args[0]);
		var->argc = argsize(args) - 1;
		if (cmd != NULL)
			var->code = cmd(args);
		else
			var->code = execCmd(var->name, args[0], args);
	}
	_freeargs(args);
	return (var->code);
}
