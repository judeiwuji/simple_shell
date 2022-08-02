#include "shell.h"

int _strlen(char *str);


void main(void)
{

	char *msg = "exit: exit [STATUS]\n\tExits the shell.\n\n\tThe ";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "STATUS argument is the integer used to exit the shell.";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = " If no argument is given, the command is interpreted as";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = " exit 0.\n";
	write(STDOUT_FILENO, msg, _strlen(msg));

}
