#include "shell.h"

/**
 * main - A simple shell program
 * @argc: The total arguments
 * @argv: List of arguments passed to main
 *
 * Return: 0
 */
int main(int argc, char **argv)
{
	char *str, *nocomments, *trimmed;
	int mode = 1;
	shell_var_t var = {0, 0, 0};

	var.pid = getpid();
	while (mode)
	{
		str = NULL;
		if (argc > 1)
		{
			if (processFile(argv[1], &str) == 0)
				exit(0);
		}
		else
		{
			if ((int)prompt(&str, &mode) == -1)
				exit(0);
		}

		trimmed = _trim(str);
		nocomments = removeComment(trimmed);
		free(str);
		free(trimmed);
		str = nocomments;
		if (processLogical(argv[0], str, &var) == 1)
			continue;
		else if (processCmdSp(argv[0], str, &var) == 1)
			continue;
		else
			processcmd(argv[0], str, &var);
	}
	return (0);
}
