#include "main.h"
/**
* main - simple shell
* @argc: integer
* @argv: array
* Return: EXITSTATUS
*/
int main(int argc __attribute__((unused)), char **argv)
{
char *line = NULL;
size_t length = 0;
char *tokens[buffer];
int cnt, result;
char *fullpath;
int EXITSTATUS = 0;
while (1)
{
result = handle_prompt(&length, &line);
if (result == 1)
break;
cnt = 0;
tokens[cnt] = strtok(line, " \t\n");
while (tokens[cnt] != NULL)
{
cnt++;
tokens[cnt] = strtok(NULL, " \t\n");
}
tokens[cnt] = NULL;
fullpath = tokens[0];
result = check_builtins(cnt, tokens, &EXITSTATUS, argv);
if (result == 1)
break;
else if (result == 2)
continue;
result = _ch(argv, tokens, &fullpath, &EXITSTATUS);
if (result == 1)
break;
else if (result == 2)
continue;
result = exec_command(&EXITSTATUS, fullpath, tokens);
if (result == 1)
break;
else if (result == 2)
continue;
}
free(line);
return (EXITSTATUS);
}
