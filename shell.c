#include "shell.h"

/**
 * main - A simple shell program
 * @argc: The total arguments
 * @argv: List of arguments passed to main
 *
 * Return: 0
 */
int main(int argc __attribute__((unused)), char **argv)
{
	char *str;
	int mode = 1;
	shell_var_t var = {0, 0, 0};

	var.pid = getpid();
	while (mode)
	{
		str = NULL;
		prompt(&str, &mode);
		str = replace_var(_trim(str), var);
		str = removeComment(_trim(str));
		if (processLogical(argv[0], str, &var.code, &var.argc) == 1)
			continue;
		else if (processCmdSp(argv[0], str, &var.code, &var.argc) == 1)
			continue;
		else
			var.code = processcmd(argv[0], str, &var.argc);
		if (str)
			free(str);
	}
	return (0);
}
