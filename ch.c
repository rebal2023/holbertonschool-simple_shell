#include "main.h"

/**
* _ch - checks for executable file errors
* @argv: list of the command line arguments
* @tokens: array of user input
* @fullpath: full path of input commands
* @exit_status: exit status.
* Return: 0 or 1 or 2
*/
int _ch(char **argv, char **tokens, char **fullpath, int *exit_status)
{
char newline = '\n';
char *path = _getenv("PATH");

if (access(tokens[0], X_OK) == -1)
{
*fullpath = _which(tokens[0], path);

if (*fullpath == NULL)
{
write(STDERR_FILENO, argv[0], _strlen(argv[0]));
write(STDERR_FILENO, ": 1: ", 5);
write(STDERR_FILENO, tokens[0], _strlen(tokens[0]));
write(STDERR_FILENO, ": not found", 11);
write(STDERR_FILENO, &newline, 1);
*exit_status = 127;
return (2);
}

if (access(*fullpath, X_OK) == -1)
{
write(STDERR_FILENO, argv[0], _strlen(argv[0]));
write(STDERR_FILENO, ": 1: ", 5);
write(STDERR_FILENO, tokens[0], _strlen(tokens[0]));
write(STDERR_FILENO, ": not found", 11);
write(STDERR_FILENO, &newline, 1);
*exit_status = 127;
return (2);
}
}

return (0);
}
