#include "main.h"

/**
* _strcmp - Compares two strings.
* @str1: String 1.
* @str2: String 2.
* Return: 0 if they are the same
* positive value if str1 is greater
* negative value if str2 is greater
*/
int _strcmp(char *str1, char *str2)
{
int x = 0;
int len1, len2;

if (str1 == NULL)
str1 = "";

if (str2 == NULL)
str2 = "";

len1 = _strlen(str1);
len2 = _strlen(str2);

if (len1 > len2)
return (1);
else if (len1 < len2)
return (-1);

while (x < len1)
{
if (str1[x] != str2[x])
return (-1);

x++;
}

return (0);
}

/**
* _strncmp - compare n character of str1 and str2
* @str1: string 1
* @str2: string 2
* @n: number of characters
* Return: 0
*/
int _strncmp(char *str1, char *str2, int n)
{
int i = 0;
while (i < n)
{
if (str1[i] != str2[i])
return (-1);
i++;
}
return (0);
}
