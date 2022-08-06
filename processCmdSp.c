#include "shell.h"

/**
 * processCmdSp - Process Cmd separator
 * @shell: The smd used to startup the shell
 * @str: The User input
 * @var: Shell variable
 *
 * Return: 1 on success, 0 otherwise
 */
int processCmdSp(char *shell, char *str, shell_var_t *var)
{
	int done = 0, i = 0;
	char **cmds;

	if (str == NULL)
		return (0);

	cmds = parser(_trim(str), ";");
	if (cmds != NULL && cmds[1] != NULL)
	{
		done = 1;
		for (i = 0; cmds[i] != NULL; i++)
			processcmd(shell, _trim(cmds[i]), var);
	}
	_freeargs(cmds);
	return (done);
}
