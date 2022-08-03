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

	while (mode)
	{
		str = NULL;
		prompt(&str, &mode);

		str = removeComment(str);
		if (processLogical(argv[0], str) == 1)
			continue;
		else if (processCmdSp(argv[0], str) == 1)
			continue;
		else
			processcmd(argv[0], str);
		free(str);
	}
	return (0);
}
