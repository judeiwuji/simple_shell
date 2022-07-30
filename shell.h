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
int _strlen(char *str);
char *_strcat(char *dest, const char *const src, int start);
char *_strcpy(char *dest, char *src);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *_reverse_str(char *str);
char *_trim_right(char *str);
char *_trim_left(char *str);
char *_trim(char *str);
int execCmd(char *cmd, char **args, char **env);
char **parser(char *str, char *delim);
char *getCmdPath(char *cmd);
void prompt(char **str);
/**
 * Struct flags - flags
 *
 * @interactive: a flag
 */
struct flags
{
	bool interactive;
} flags;
#endif
