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
char **parser(char *str, char *delim);
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

typedef struct list_s
{
	char *dir;
	struct list_s *next;
} list_t;

int _env(char **args __attribute__((unused)));
int (*get_builtins(char *name))(char **);
char *_strtok(char *str, char *delim);
int get_parsed_size(char *str, char *delim);
int _strstart(char *s1, char *s2);
extern char **environ;
int argsize(char **args);
int cd(char **args);
int processcmd(char *shell, char *str, int *argc);
int processCmdSp(char *shell, char *str, int *e, int *c);
int _delimcmp(char *str, char *delim);
char *getLogicalOp(char *str, int start);
int processLogical(char *shell, char *str, int *e, int *c);
char *_getenv(char *k);
int __exit(char **args __attribute__((unused)));
int _isdigit(int c);
int _atoi(char *s);
char *removeComment(char *str);
char *_itoa(int num);
int num_len(int num);
/**
 * Struct shell_var - shell_var
 * @code: The exit code of last command
 * @argc: The argument count of last command
 * @pid: The shell process id
 */
typedef struct shell_var
{
	int code;
	int argc;
	pid_t pid;
} shell_var_t;
char *replace_var(char *s, shell_var_t svar);
char *getVar(char *key, shell_var_t svar);
#endif
