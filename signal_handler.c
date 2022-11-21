#include "shell.h"

void sigintHandler(int sig_num)
{
	sig_num = sig_num;
	fflush(stdout);
	fflush(stdin);
	exit(0);
}
