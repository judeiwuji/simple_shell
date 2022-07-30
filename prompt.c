#include "shell.h"

void prompt(char **str)
{
	size_t len = 0;
	char *username;

	username = getenv("USER");

	write(1, "#", 1);
	write(1, username, _strlen(username));
	write(1, "$ ", 2);
	getline(str, &len, stdin);
}
