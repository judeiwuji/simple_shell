#include "shell.h"

/**
 * prompt - Prompts for input
 * @str: The pointer to store user input
 * @mode: The mode of the shell
 *
 * Return: void
 */
size_t prompt(char **str, int *mode)
{
	size_t len = 0;
	size_t status;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
	else
		*mode = 0;

	status = getline(str, &len, stdin);
	return (status);
}
