#ifndef __MAIN__H
#define __MAIN__H
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
void prompt(char *str);
int execCmd(char *cmd, char **args, char **env);
char *getCmdPath(char *cmd);
int _strlen(char *str);
char *_strcat(char *dest, char *src, int start);
#endif
