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
	struct stat st;

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
		else if (stat(args[0], &st) == 0)
			var->code = execCmd(var->name, args[0], args);
		else
		{
			write(1, var->name, _strlen(var->name));
			write(1, ": 1: ", 5);
			write(1, args[0], _strlen(args[0]));
			write(1, ": not found\n", 12);
			var->code = 1;
		}
	}
	_freeargs(args);
	return (var->code);
}
