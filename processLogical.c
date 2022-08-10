#include "shell.h"

/**
 * processLogical - Process logical operators
 * @str: The User input
 * @var: Shell variables
 *
 * Return: 1 on success, 0 otherwise
 */
int processLogical(char *str, shell_var_t *var)
{
	int done = 0, i = 0, pos = 0;
	char **cmds;
	char *op, *trimmed;
	int status = 0;

	if (str == NULL)
		return (0);

	trimmed = _trim(str);
	cmds = parser(trimmed, "&&||");
	free(trimmed);
	if (cmds != NULL && cmds[1] != NULL)
	{
		done = 1;
		for (i = 0; cmds[i] != NULL; i++)
		{
			pos += _strlen(cmds[i]);
			op = getLogicalOp(str, pos);
			pos += _strlen(op);
			if (_strcmp(op, "&&") == 0 && status != 0)
				continue;
			trimmed = _trim(cmds[i]);
			status = processcmd(trimmed, var);
			var->code = status;
			if (_strcmp(op, "&&") == 0 && status != 0)
				pos += _strlen(cmds[++i]);
			if (_strcmp(op, "||") == 0 && status == 0)
				pos += _strlen(cmds[++i]) + 2;
			free(op);
		}
		free(str);
	}
	_freeargs(cmds);
	return (done);
}

/**
 * getLogicalOp - Get the Logical Op object
 * @str: The string
 * @start: Where to start
 *
 * Return: Logical op
 */
char *getLogicalOp(char *str, int start)
{
	char *op = NULL;
	int i;

	if (str == NULL)
		return (NULL);

	str = (str + start);
	op = _realloc(op, 0, 3);
	if (op == NULL)
		return (NULL);
	for (i = 0; i < 2; i++)
		op[i] = str[i];
	op[i] = '\0';
	return (op);
}
