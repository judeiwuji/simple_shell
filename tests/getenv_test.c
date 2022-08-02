#include "../shell.h"

int main(int argc, char **argv, char **env)
{
  printf("[PATH] %s\n", _getenv("PATH"));
  printf("[PATH] %s\n", _getenv("PATH"));
  printf("[USER] %s\n", _getenv("USER"));
  printf("[USER] %s\n", _getenv("USER"));
}
