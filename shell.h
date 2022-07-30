#ifndef _SHELL_H_
#define _SHELL_H_

#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <stdbool.h>

#define END_OF_FILE -2
#define EXIT -3

int execCmd(char *cmd, char **args, char **env);
char *getCmdPath(char *cmd);
int _strlen(char *str);
char *_strcat(char *dest, char *src, int start);
void prompt_user(void);

struct flags
{
	bool interactive;
}flags;

#endif
