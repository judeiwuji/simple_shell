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
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
void _freeargs(char **args);
int execCmd(char *sh, char *cmd, char **args, char **env);
char **parser(char *str, char delim);
char *getCmdPath(char *cmd);
void prompt(char **str, int *mode);
/**
 * Struct builtins - builtins
 * @name: The name of this command
 * @cmd: The command function
 */
typedef struct builtins
{
	char *name;
	int (*cmd)(char **env);
} builtins_t;
int _env(char **args __attribute__((unused)));
int (*get_builtins(char *name))(char **);
char *_strtok(char *str, char delim);
int get_parsed_size(char *str, char delim);
int _strstart(char *s1, char *s2);
char *_getenv(char *k);
extern char **environ;
int argsize(char **args);
int cd(char **args);
int processcmd(char *shell, char *str);
int processCmdSp(char *shell, char *str);

/*Jen's headers */
typedef struct builtin_s
{
	char *name;
	char (*f)(char **argv, char **front);
}builtin_t;

typedef struct alias_s
{
	char *name;
	char *value;
	struct alias_s *next;
}alias_t;

alias_t *aliases;

void free_args(char **args, char **front);
int shell_exit(char **args, char **front);
void free_env(void);
int create_error(char **args, int err);
void free_alias_list(alias_t *head);
int num_len(int num);
char *_itoa(int num);
#endif
