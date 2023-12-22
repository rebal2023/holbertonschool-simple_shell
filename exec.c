#include "main.h"

/**
* exec_command - creates a new child proces & executes a command
* @exit_status: exit status
* @fullpath: executable command
* @tokens: array of arguments passed
* Return: 0 or 1
*/
int exec_command(int *exit_status, char *fullpath, char *tokens[])
{
pid_t child;
int status;

child = fork();

if (child == -1)
{
perror("fork");
return (1);
}

if (child == 0)
{
execve(fullpath, tokens, environ);
*exit_status = 2;
perror("execve");
exit(*exit_status);
}
else
{
wait(&status);

if (WIFEXITED(status))
{
*exit_status = WEXITSTATUS(status);
}
}

if (fullpath != tokens[0])
free(fullpath);

return (0);
}
