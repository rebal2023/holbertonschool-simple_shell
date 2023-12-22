#include "main.h"

/**
* _strlen - sizes the length of a string
* @str: string to be sized
* Return: length of the string
*/
int _strlen(char *str)
{
int i = 0;

if (str == NULL)
str = "";

while (*str != '\0')
{
i++;
str++;
}

return (i);
}

/**
* _strcpy - copies strings from source to destination.
* @dest: destination
* @src: source
* Return: pointer to the copied string
*/
char *_strcpy(char *dest, char *src)
{
int i = 0;

while (i <= _strlen(src))
{
dest[i] = src[i];
i++;
}

return (dest);
}

/**
* _strcat - concatenates two strings
* @dest: destination
* @src: source
* Return: pointer to the concatenated string
*/
char *_strcat(char *dest, char *src)
{
int i = 0;
char *temp = dest;

while (*temp != '\0')
{
temp++;
}

while (i < _strlen(src))
{
*temp = src[i];
temp++;
i++;
}

*temp = '\0';

return (dest);
}

/**
 * _strdup - duplicates a string
 * @str: string to be duplicated
 * Return: pointer to the duplicated string
 */
char *_strdup(char *str)
{
char *myStr;
int i = 0;

if (str == NULL)
return (NULL);

myStr = (char *)malloc(_strlen(str) * sizeof(char) + 1);

if (myStr == NULL)
return (NULL);

while (i <= (int)_strlen(str))
{
myStr[i] = str[i];
i++;
}

return (myStr);
}
