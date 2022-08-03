/**
 * main - Runs a simple UNIX command interpreter.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: The return value of the last executed command.
 */

int main(int argc, char *argv[])
{
  int ret = 0, retn;
  int *exe_ret = &retn;
  char *prompt = "$ ", *new_line = "\n";

  name = argv[0];
  hist = 1;
  aliases = NULL;
  signal(SIGINT, sig_handler);

  *exe_ret = 0;
  environ = _copyenv();

  if (!environ)
    exit(-100);

  if (argc != 1)
  {
    ret = proc_file_commands(argv[1], exe_ret);
    free_env();
    free_alias_list(aliases);
    return (*exe_ret);
  }

  if (!isatty(STDIN_FILENO))
  {
    while (ret != END_OF_FILE && ret != EXIT)
      ret = handle_args(exe_ret);
    free_env();
    free_alias_list(aliases);
    return (*exe_ret);
  }
  while (1)
  {
    write(STDOUT_FILENO, prompt, 2);
    ret = handle_args(exe_ret);
    if (ret == END_OF_FILE || ret == EXIT)
    {
      if (ret == END_OF_FILE)
        write(STDOUT_FILENO, new_line, 1);
      free_env();
      free_alias_list(aliases);
      exit(*exe_ret);
    }
  }
  free_env();
  free_alias_list(aliases);
  return (*exe_ret);
}
