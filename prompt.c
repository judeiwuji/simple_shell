#include "shell.h"

void prompt(char **str)
{
	size_t len = 0;

	write(1, "($) ", 4);
	getline(str, &len, stdin);
}
