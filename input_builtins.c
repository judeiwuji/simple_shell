#include "shell.h"

/**
 * get_builtin - Matches a command with a corresponding
 *               shellby builtin function.
 * @command: The command to match.
 *
 * Return: A function pointer to the corresponding builtin.
 */

int (*get_builtin(char *command))(char **args, char **front)
{
	builtin_t funcs[] = {

		{ "exit", shellby_exit },
		{ "env", shellby_env },
		{ "cd", shellby_cd },
		{ NULL, NULL }
	};
	int i;

	for (i = 0; funcs[i].name; i++)
	{
		if (_strcmp(funcs[i].name, command) == 0)
			break;
	}
	return (funcs[i].f);
}
