#include "main.h"

/**
* handle_prompt - prints prompt & gets input
* @length: length of the input
* @line: user input stored
* Return: 0 or 1
*/
int handle_prompt(size_t *length, char **line)
{
ssize_t bytes_read;
char newline = '\n';
int is_interactive = isatty(STDIN_FILENO);

if (is_interactive)
{
write(STDOUT_FILENO, "$ ", 2);
}

bytes_read = getline(line, length, stdin);

if (bytes_read == -1)
{
if (is_interactive)
{
write(STDOUT_FILENO, &newline, 1);
}

return (1);
}

return (0);
}
