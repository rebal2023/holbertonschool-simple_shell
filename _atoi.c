#include "main.h"

/**
 * _atoi - converts from string to integer
 * @str: string inputted
 * Return: integer converted
 */
int _atoi(char *str)
{
int result = 0;
int is_positive = 1;
int i = 0;

if (str[0] == '-')
{
is_positive = -1;
i = 1;
}

while (str[i] != '\0')
{
if (str[i] >= '0' && str[i] <= '9')
{
result = result * 10 + (str[i] - '0');
i++;
}
else
{
break;
}
}

return (is_positive *result);
}
