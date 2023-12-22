#include "main.h"

/**
* check_builtins - verifies if a given command is a shell builtin or not
* @cnt: number of arguments passed to the shell
* @tokens: list of shell arguments
* @exit_status: exit status
* @argv: array of the command line arguments
* Return: 0 or 1 or 2
*/
int check_builtins(int cnt, char **tokens, int *exit_status, char **argv)
{
char newline = '\n';
if (cnt < 1)
{
return (2);
}
if (_strcmp(tokens[0], "exit") == 0)
{
if (tokens[1] != NULL)
{
if (_atoi(tokens[1]))
{
if (_atoi(tokens[1]) >= 0)
*exit_status = _atoi(tokens[1]);
else
error_message(tokens, argv, exit_status);
}
else
{
error_message(tokens, argv, exit_status);
}
}
return (1);
}
if (_strcmp(tokens[0], "env") == 0)
{
char **env = environ;
while (*env != NULL)
{
write(STDOUT_FILENO, *env, _strlen(*env));
write(STDOUT_FILENO, &newline, 1);
env++;
}
return (2);
}
if (_strcmp(tokens[0], "unsetenv") == 0)
{
_unsetenv(tokens[1]);
return (2);
}
return (0);
}
