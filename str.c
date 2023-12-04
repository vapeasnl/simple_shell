#include "main.h"
/**
* _strcpy --
* @dest: --
* @src: --
* Return: --
*/
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/**
* _strdup --
* @str: --
* Return: --
*/
char *_strdup(const char *str)
{
	char *ptr;
	int i, lenght = 0;

	if (str == NULL)
		return (NULL);
	while (*str != '\0')
	{
		lenght++;
		str++;
	}
	str = str - lenght;
	ptr = malloc(sizeof(char) * (lenght + 1));
	if (ptr == NULL)
		return (NULL);
	for (i = 0; i <= lenght; i++)
		ptr[i] = str[i];
	return (ptr);
}
/**
* _strcat --
* @dest: --
* @src: --
* Return: --
*/
char *_strcat(char *dest, char *src)
{
	char *p = dest;

	while (*p)
		p++;

	while (*src)
	{
		*p = *src;
		p++;
		src++;
	}
	*p = *src;
	return (dest);
}
/**
* _strcmp --
* @s1: --
* @s2: --
* Return: --
*/
int _strcmp(char *s1, char *s2)
{
	int cmp;

	cmp = (int)*s1 - (int)*s2;
	while (*s1)
	{
		if (*s1 != *s2)
			break;
		s1++;
		s2++;
		cmp = (int)*s1 - (int)*s2;
	}
	return (cmp);
}
/**
* _strlen --
* @s: --
* Return: --
*/
int _strlen(char *s)
{
	int lenght = 0;

	while (s[lenght])
		lenght++;
	return (lenght);
}






