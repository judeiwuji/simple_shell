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
int processcmd(char *shell, char *str);
int processCmdSp(char *shell, char *str);
int _delimcmp(char *str, char *delim);
char *getLogicalOp(char *str, int start);
int processLogical(char *shell, char *str);

/*Jen's headers */
char *name; /*global program name*/
int hist;		/*global history counter*/

typedef struct builtin_s
{
	char *name;
	char (*f)(char **argv, char **front);
} builtin_t;

typedef struct alias_s
{
	char *name;
	char *value;
	struct alias_s *next;
} alias_t;

alias_t *aliases;

void free_args(char **args, char **front);
int shell_exit(char **args, char **front);
void free_env(void);
int create_error(char **args, int err);
void free_alias_list(alias_t *head);
int num_len(int num);
char *_itoa(int num);
int strlen_(const char *s);
int _strncmp(const char *s1, const char *s2, size_t n);
char *get_location(char *command);
char *fill_path_dir(char *path);
list_t *get_path_dir(char *path);
list_t *add_node_end(list_t **head, char *dir);
int token_len(char *str, char *delim);
int count_tokens(char *str, char *delim);
char **strtok_(char *line, char *delim);
char *strcat_(char *dest, const char *src);
char *_strncat(char *dest, const char *src, size_t n);
void free_list(list_t *head);
char **getenv_(const char *var);
int handle_args(int *exe_ret);
char *get_args(char *line, int *exe_ret);
int check_args(char **args);
int run_args(char **args, char **front, int *exe_ret);
int call_args(char **args, char **front, int *exe_ret);
void handle_line(char **line, ssize_t read);
int proc_file_commands(char *file_path, int *exe_ret);
int cant_open(char *file_path);
void variable_replacement(char **line, int *exe_ret);
char *get_pid(void);
char *get_env_value(char *beginning, int len);
ssize_t get_new_len(char *line);
void logical_ops(char *line, ssize_t *new_len);
int (*get_builtin(char *command))(char **args, char **front);
void sig_handler(int sig);
int execute(char **args, char **front);
char **_copyenv(void);
#endif
